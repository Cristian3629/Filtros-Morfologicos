#include <iostream> //cout
#include <string> //compare
#include <string.h> //compare
#include <list>  //list
#include "Position.h"
#include "Matrix.h"
#include "Interpreter.h"
#include "Dilatation.h"
#include "Erosion.h"

using namespace std;

Filter* identifierFilter(std::string& filterString){
  std::string dilatationString("d");
  if (!filterString.compare(dilatationString)){
    Dilatation* dilatation = new Dilatation();
    return dilatation;
  }
  Erosion* erosion = new Erosion();
  return erosion;
}

Matrix getMatrix(char* matrix){
  Interpreter interpreter;
  std::string matrixString(matrix);
  Matrix oneMatrix = interpreter.createMatrix(matrixString);
  return oneMatrix;
}
//    0      1              2           3         4          5
// ./tp <numero de hilos> <filtro 1> <patron 1> <filtro 2> <patron 2>  ...
int main(int argc, char *argv[]) {
  Interpreter interpreter;
  int cantThreads = atoi(argv[1]);
  vector<string> vectorImagen;
  std::cout << "Cantidad de hilos:" << cantThreads << std::endl;
  string input_line;
  if (argc < 2){
    std::cout << "Falta argumentos" << std::endl;
    return 1;
  }

  if(cin){
    getline(cin, input_line);
    size_t pos = input_line.find(" ");
    //cout << pos << endl;
    string col =  input_line.substr(0,pos);
    string row = input_line.substr(pos+1);
    vectorImagen.push_back(row);
    vectorImagen.push_back(col);
  }
  while(cin){
    getline(cin, input_line);
    if (input_line.compare("\n") == 1){
      //std::cout << input_line << std::endl;
      vectorImagen.push_back(input_line);
      }
  }
  Matrix matrixOrigin = interpreter.createMatrix(vectorImagen);
  Matrix& image(matrixOrigin);
  image.print();
  for (int i = 2; i <= argc-2; i++) {
    std::string filterString(argv[i]);
    Filter* filter = identifierFilter(filterString);
    std::string matrixString(argv[i+1]);
    Matrix patron = interpreter.createMatrix(matrixString);
    //std::cout << "patron" << std::endl;
    //patron.print();
    Matrix resultado = filter->aplicateFilter(image,patron);
    image.set(resultado);
    image.print();
    i++;
  }
  image.print();
  return 0;
}

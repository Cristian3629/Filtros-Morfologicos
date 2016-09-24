#include <iostream> //cout
#include <string> //compare
#include <string.h> //compare
#include <vector>  //vector
#include "Position.h"
#include "Matrix.h"
#include "Interpreter.h"
#include "Dilatation.h"
#include "Erosion.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;

Filter* identifierFilter(string& filterString, int cantThreads){
  string dilatationString("d");
  if (!filterString.compare(dilatationString)){
    Dilatation* dilatation = new Dilatation(cantThreads);
    return dilatation;
  }
  Erosion* erosion = new Erosion(cantThreads);
  return erosion;
}

//    0      1              2           3         4          5
// ./tp <numero de hilos> <filtro 1> <patron 1> <filtro 2> <patron 2>  ...
int main(int argc, char *argv[]) {
  Interpreter interpreter;
  int cantThreads = atoi(argv[1]);
  vector<string> vectorImagen;
  //cout << "Cantidad de hilos:" << cantThreads << endl;
  string input_line;
  if (argc < 2){
    cout << "Falta argumentos" << endl;
    return 1;
  }
  if (cin) {
    getline(cin, input_line);
    size_t pos = input_line.find(" ");
    //cout << pos << endl;
    string col =  input_line.substr(0,pos);
    string row = input_line.substr(pos+1);
    vectorImagen.push_back(row);
    vectorImagen.push_back(col);
  }
  while (cin){
    getline(cin, input_line);
    if (input_line.compare("\n") == 1){
      //std::cout << input_line << std::endl;
      vectorImagen.push_back(input_line);
      }
  }
  Matrix image = interpreter.createMatrix(vectorImagen);
  for (int i = 2; i <= argc-2; i++) {
    string filterString(argv[i]);
    Filter* filter = identifierFilter(filterString,cantThreads);
    string matrixString(argv[i+1]);
    Matrix patron = interpreter.createMatrix(matrixString);
    //std::cout << "patron" << endl;
    // acá no pierdo memoria?
    image = filter->aplicateFilter(image,patron);
    //image.print();
    i++;
  }
  std::cout <<image.getCantColumns()<<" "<<image.getCantRows()<< std::endl;
  image.print();
  return 0;
}

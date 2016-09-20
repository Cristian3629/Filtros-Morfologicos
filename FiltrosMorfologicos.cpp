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

Filter identifierFilter(std::string& filterString){
  std::string dilatationString("d");
  if (!filterString.compare(dilatationString)){
    Dilatation dilatation;
    return dilatation;
  }
  Erosion erosion;
  return erosion;
}

void cargarMatrizImage(Matrix& image){
  int row = image.getCantRows();
  int column = image.getCantColumns();
  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= column; j++) {
      image.setElementPos(i,j,".");
    }
  }
  image.setElementPos(2,2,"#");
  image.setElementPos(5,4,"#");
  std::cout << "Matriz imagen" << std::endl;
  image.print();
}
//
// bool comprobarDilatacion(std::list<bool> lista){
//   std::list<bool>::iterator it;
//   for (it=lista.begin(); it != lista.end(); ++it){
//     bool valor = *it;
//     if (valor){
//       return true;
//     }
//   }
//   return false;
// }

// Matrix aplicarDilatacion(Matrix& image, Matrix& patron){
//   Position pivote(0,0);
//   int row = image.getCantRows();
//   int column = image.getCantColumns();
//   std::cout << "copy" << std::endl;
//   Matrix pepe(image);
//   std::cout << "esta es la copia" << std::endl;
//   pepe.print();
//   for (int i = 1; i <= row; i++) {
//     for (int j = 1; j <= column; j++) {
//       pivote.setRow(i);
//       pivote.setColumn(j);
//       //std::cout << "la imagen esta" << std::endl;
//       //image.print();
//       std::list<bool> lista = posicionesValida(image,patron,pivote);
//       if (comprobarDilatacion(lista)){
//         pepe.setElementPos(pivote.getRow(),pivote.getColumn(),"#");
//       }
//     }
//   }
//   //pepe.print();
//   return pepe;
// }

void cargarMatrixDestino(Matrix& destino){
  int row = destino.getCantRows();
  int column = destino.getCantColumns();
  std::cout << "entrando al for" << std::endl;
  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= column; j++) {
      std::cout <<i<< "," <<j<< std::endl;
      destino.setElementPos(i,j,".");
    }
  }
}

Filter getFilter(char* filter){
  std::string filterString(filter);
  Filter one_filter = identifierFilter(filterString);
  return one_filter;
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
  Matrix image = interpreter.createMatrix(vectorImagen);
  image.print();
  for (int i = 2; i <= argc-2; i++) {
    std::string filterString(argv[i]);
    Filter filter = identifierFilter(filterString);
    std::string matrixString(argv[i+1]);
    Matrix patron = interpreter.createMatrix(matrixString);
    //std::cout << "asasa" << std::endl;
    //patron.print();
    i++;
    //std::cout << "/* ----- */" << std::endl;
  }
  //patron.print();
  //Matrix patron(3,3); //imagen patron
  // Matrix imagen(6,6);
  //cargarMatrizPatron(patron);
  // cargarMatrizImage(imagen);
  // Dilatation dilatacion;
  // Matrix other = dilatacion.aplicateFilter(imagen,patron);
  // other.print();
  //Interpreter::createMatrix();
  return 0;
}

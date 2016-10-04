#include "Interpreter.h"
#include <string>
#include <vector>
using std::string;
using std::stoi;
using std::vector;
using std::stringstream;

//Esta se encarga de interpretar una cadena y devolver la matriz
//saca el espacio redundante al principio pero no en el intermedio
Interpreter::Interpreter(){
}

Interpreter::~Interpreter(){}

Matrix Interpreter::createMatrix(const string& matrix){
  vector<string> elems;
  split(matrix,' ', elems);
  return createMatrix(elems);
}

Matrix Interpreter::createMatrix(vector<string> elems){
  std::string::size_type sz;
  vector<string>::iterator it = elems.begin();
  int row = std::stoi(*it,&sz);
  ++it;
  int colum = std::stoi(*it,&sz);
  Matrix patron(row,colum);
  ++it;
  int size = elems.size();
  for (int i = 2; i < size-1 ; i++) {
    string fila = elems[i];
    for (int j = 0 ; j < colum ; j++) {
      string elemento = fila.substr(j,1);
      patron.setElementPos(i-1,j+1,elemento);
    }
  }
  return patron;
}

void Interpreter::split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

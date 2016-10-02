#include "Interpreter.h"
#include <string>
#include <vector>
//Esta se encarga de interpretar una cadena y devolver la matriz
//saca el espacio redundante al principio pero no en el intermedio
using std::string;
using std::stoi;
using std::vector;
using std::stringstream;

Interpreter::Interpreter(){
  //std::cout << "Soy una dilatacion" << std::endl;
}

Interpreter::~Interpreter(){}

Matrix Interpreter::createMatrix(const string& matrix){
  //std::cout << "createMatrix" << std::endl;
  vector<string> elems;
  split(matrix,' ', elems);
  vector<string>::iterator it;
  string::size_type sz;
  it = elems.begin();
  int row = stoi(*it,&sz);
  ++it;
  int colum = stoi(*it,&sz);
  Matrix patron(row,colum);
  //std::cout <<row<<","<<colum<<std::endl;
  int i = 0;
  ++it;
  for (; it!=elems.end() ; ++it) {
    string fila = *it;
    for (int j = 0 ; j < colum ; j++) {
      string elemento = fila.substr(j,1);
      //std::cout << "Elemento:" <<elemento<< std::endl;
      patron.setElementPos(i+1,j+1,elemento);
    }
    i++;
  }
  return patron;
}

Matrix Interpreter::createMatrix(vector<string> elems){
  std::cout << "createMatrix from vector" << std::endl;
  std::cout << "longitud del vector" <<elems.size()<< std::endl;
  std::string::size_type sz;
  vector<string>::iterator it = elems.begin();
  int row = std::stoi(*it,&sz);
  ++it;
  int colum = std::stoi(*it,&sz);
  Matrix patron(row,colum);
  std::cout <<row<<","<<colum<<std::endl;
  std::cout << "asasa" << std::endl;
  ++it;
  int size = elems.size();
  std::cout << "size:" <<size<< std::endl;
  for (int i = 2; i < size-1 ; i++) {
    std::cout << "dentro del for" << std::endl;
    string fila = elems[i];
    std::cout <<"i="<<i<<fila<< std::endl;
    for (int j = 0 ; j < colum ; j++) {
      string elemento = fila.substr(j,1);
      //std::cout << "Elemento:" <<elemento<< std::endl;
      //std::cout << "pos:" <<i-1<<","<<j+1<< std::endl;
      patron.setElementPos(i-1,j+1,elemento);
    }
  }
  patron.print();
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

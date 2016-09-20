#include "Interpreter.h"

//Esta se encarga de interpretar una cadena y devolver la matriz
//saca el espacio redundante al principio pero no en el intermedio
using namespace std;


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
  int row = std::stoi(*it,&sz);
  ++it;
  int colum = std::stoi(*it,&sz);
  Matrix patron(row,colum);
  //std::cout <<row<<","<<colum<<std::endl;
  int i = 0;
  ++it;
  for (; it!=elems.end() ; ++it) {
    string fila = *it;
    for (int j = 0; j < colum;j++) {
      string elemento = fila.substr(j,1);
      //std::cout << "Elemento:" <<elemento<< std::endl;
      patron.setElementPos(i+1,j+1,elemento);
    }
    i++;
  }
  return patron;
}

Matrix Interpreter::createMatrix(std::vector<string> elems){
  std::cout << "createMatrix from vector" << std::endl;
  std::string::size_type sz;
  vector<string>::iterator it = elems.begin();
  int row = std::stoi(*it,&sz);
  ++it;
  int colum = std::stoi(*it,&sz);
  Matrix patron(row,colum);
  std::cout <<row<<","<<colum<<std::endl;
  int i = 0;
  ++it;
  for (; it!=elems.end() ; ++it) {
    string fila = *it;
    for (int j = 0; j < colum;j++) {
      string elemento = fila.substr(j,1);
      //std::cout << "Elemento:" <<elemento<< std::endl;
      patron.setElementPos(i+1,j+1,elemento);
    }
    i++;
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

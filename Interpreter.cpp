#include "Interpreter.h"

//Esta se encarga de interpretar una cadena y devolver la matriz
//saca el espacio redundante al principio pero no en el intermedio
using namespace std;


Interpreter::Interpreter(){
  std::cout << "Soy una dilatacion" << std::endl;
}

Interpreter::~Interpreter(){}

Matrix Interpreter::createMatrix(const string& matrix){
  std::cout << "createMatrix" << std::endl;
  vector<string> elems;
  split(matrix,' ', elems);
  vector<string>::iterator it;
  for(it = elems.begin() ; it != elems.end(); ++it){
    cout << *it << endl;
  }
  std::string::size_type sz;
  it = elems.begin();
  int row = std::stoi(*it,&sz);
  ++it;
  int colum = std::stoi(*it,&sz);
  Matrix patron(3,3);
  std::cout <<row<<","<<colum<<std::endl;
  int i = 0;
  ++it;
  for (; it!=elems.end() ; ++it) {
    string fila = *it;
    for (int j = 0; j < colum;j++) {
      string elemento = fila.substr(j,1);
      std::cout << "Elemento:" <<elemento<< std::endl;
      patron.setElementPos(i+1,j+1,elemento);
    }
    i++;
  }
  return patron;
}

void Interpreter::cargarMatrizPatron(Matrix& patron){
  std::cout << "Interpreter::cargarMatrizPatron" << std::endl;
  int row = patron.getCantRows();
  int column = patron.getCantColumns();
  std::cout << "entrando al for" << std::endl;
  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= column; j++) {
      std::cout <<i<< "," <<j<< std::endl;
      patron.setElementPos(i,j,"#");
    }
  }
  std::cout << "salir del for" << std::endl;
  patron.setElementPos(1,1,".");
  patron.setElementPos(1,3,".");
  patron.setElementPos(3,1,".");
  patron.setElementPos(3,3,".");
  std::cout << "Matrix patron" << std::endl;
  patron.print();
}

void Interpreter::split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

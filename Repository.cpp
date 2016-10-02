#include "Repository.h"
#include <list>

using std::list;

Repository::Repository(){
  lista = new list<bool>;
  cantidad = 0;
}


void Repository::addComparacion(bool valor){
  //std::cout << "addComparacion" << std::endl;
  cantidad++;
  lista->push_back(valor);
}

list<bool> Repository::getList(){
  //std::cout << "Devolvi: " <<cantidad<< std::endl;
  return *lista;
}


Repository::~Repository(){
  delete(lista);
}

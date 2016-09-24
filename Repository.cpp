#include "Repository.h"
#include <list>

using std::list;

Repository::Repository(){
  lista = new list<bool>;
}


void Repository::addComparacion(bool valor){
  lista->push_back(valor);
}

Repository::~Repository(){
  delete(lista);
}

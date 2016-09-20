#include "Dilatation.h"


Dilatation::Dilatation(){
  //std::cout << "Soy una dilatacion" << std::endl;
}

Dilatation::~Dilatation(){}

bool Dilatation::checkCoincidence(std::list<bool> lista){
  std::list<bool>::iterator it;
  for (it=lista.begin(); it != lista.end(); ++it){
    bool valor = *it;
    if (valor){
      return true;
    }
  }
  return false;
}

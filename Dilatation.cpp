#include "Dilatation.h"


Dilatation::Dilatation(){}

Dilatation::~Dilatation(){}


//Cuando se aplica erosion se necesita chequear si hay coincidencia total
//Pre:Recibe un list de valores booleanos
//Post: Chequea si existe coincidencia parcial
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

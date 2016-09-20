#include "Dilatation.h"


Dilatation::Dilatation(){}

Dilatation::~Dilatation(){}


//Cuando se aplica erosion se necesita chequear si hay coincidencia total
//Pre:Recibe un list de valores booleanos
//Post: Chequea si existe coincidencia parcial
bool Dilatation::checkCoincidence(std::list<bool> lista){
  //std::cout << "Dilatation checkCoincidence" << std::endl;
  std::list<bool>::iterator it;
  for (it=lista.begin(); it != lista.end(); ++it){
    bool valor = *it;
    //std::cout << valor;
    if (valor){
      return true;
    }
  }
  //std::cout << "" << std::endl;
  return false;
}

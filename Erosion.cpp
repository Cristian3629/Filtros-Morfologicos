#include "Erosion.h"


Erosion::Erosion(){
  //std::cout << "Soy una erosion" << std::endl;
}

Erosion::~Erosion(){}


//Cuando se aplica erosion se necesita chequear si hay coincidencia total
//Pre:Recibe un list de valores booleanos
//Post: Chequea si existe coincidencia total
bool Erosion::checkCoincidence(std::list<bool> lista){
  std::list<bool>::iterator it;
  for (it=lista.begin(); it != lista.end(); ++it){
    bool valor = *it;
    if (!valor){
      return false;
    }
  }
  return true;
}

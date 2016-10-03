#include "Erosion.h"
#include <list>
using std::list;

Erosion::Erosion(int cantidadHilos):Filter(cantidadHilos){}
Erosion::~Erosion(){}

//Cuando se aplica erosion se necesita chequear si hay coincidencia total
//Pre:Recibe un list de valores booleanos
//Post: Chequea si existe coincidencia total
bool Erosion::checkCoincidence(std::list<bool> lista){
  //std::cout << "checkCoincidence erosion" << std::endl;
  list<bool>::iterator it;
  for (it=lista.begin(); it != lista.end(); ++it){
    bool valor = *it;
    //std::cout << valor << " ";
    if (!valor){
      return false;
    }
  }
  return true;
}

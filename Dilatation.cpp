#include "Dilatation.h"

#include <list> //list
using std::list;

Dilatation::Dilatation(int cantidadHilos):Filter(cantidadHilos){}
Dilatation::~Dilatation(){}


//Cuando se aplica erosion se necesita chequear si hay coincidencia total
//Pre:Recibe un list de valores booleanos
//Post: Chequea si existe coincidencia parcial
bool Dilatation::checkCoincidence(std::list<bool> lista){
  std::cout << "Dilatation checkCoincidence" << std::endl;
  list<bool>::iterator it;
  for (it=lista.begin(); it != lista.end(); ++it){
    bool valor = *it;
    std::cout << valor << std::endl;
    if (valor){
      return true;
    }
  }
  return false;
}

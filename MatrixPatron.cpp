#include "MatrixPatron.h"



//debo ponerle const a los atributos porque una vez que se asignan no cambian

MatrixPatron::MatrixPatron(int cant){
  Matrix(cant,cant);
}

Position getHalfPosition(){
  Position newPosition(this->cantColumns/2,this->cantRows/2);
  return newPosition;
}

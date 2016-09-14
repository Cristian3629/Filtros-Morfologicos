#include <iostream> //cout
#include "Position.h"
#include "Matrix.h"


int posicionesValida(Matrix& patron,Matrix& imagen, Position position){
  Position posicionMedia(patron.getRow()/2 + 1,patron.getColumn()/2 + 1);
  int i;
}


int main(int argc, char *argv[]) {

  int a = 1;
  int b = 2;
  std::cout << a+b << std::endl;
  std::cout << "Hola soy el principal" << std::endl;
  Position position(1,1);
  Matrix patron(3,3); //matriz patron
  Matrix imagen(6,6);
  matrix.dimesions();
  std::cout << "La posicion 1 1 es:" << matrix.positionIsValid(position) << std::endl;
  Position otherPosition(4,4);
  std::cout << "La posicion 4 4 es:" << matrix.positionIsValid(otherPosition) << std::endl;
  matrix.setElementPos(0,0,"#");
  matrix.dimesions();
  matrix.setElementPos(0,1,".");
  matrix.dimesions();
  std::cout << "En la pos (0,0) tengo " << matrix.getElementPos(0,0) << std::endl;
  std::cout << "En la pos (0,1) tengo " << matrix.getElementPos(0,1) << std::endl;
  matrix.dimesions();
  std::cout << "saliendo.." << std::endl;
  Position position1(2,2);
  Position position2(1,1);
  Position position3 = position1.relativityPosition(position2);
  std::cout << "La posicion relativa es:" << position3.getColumn() <<","<< position3.getRow() << std::endl;
  return 0;
}

#include <iostream> //cout
#include <string> //compare
#include "Position.h"
#include "Matrix.h"
#include "Interpreter.h"

//posicion es la posicion donde coloco el patron
//tengo que cambiar el nombre del metodo
int posicionesValida(Matrix& imagen,Matrix& patron, Position& posicion){
  std::cout << "---posicionesValida, la posicion es:--------------" << std::endl;
  posicion.print();
  //bool fit = true; // se procesa con AND
  //bool intersect = false; //se proceso con for
  int row = patron.getCantRows();
  int column = patron.getCantColumns();
  Position posicionMedia(row/2 + 1, column/2 + 1);
  Position posicionRelativa = posicionMedia.relativityPosition(posicion);
  Position otherPosition(0,0);
  std::string asterisco("#");
  bool valor;
  int i,j;
  for (i = 1; i <= row; i++) {
    for (j = 1; j <= column; j++) {
      otherPosition.setRow(i);
      otherPosition.setColumn(j);
      Position posImagen = posicionRelativa.sum(otherPosition);
      // std::cout << "("<<i<<","<<j<<") hay " << patron.getElementPos(i,j)<< std::endl;
      // std::cout << "Y le corresponde de la matriz";
      //posImagen.print();
      if (imagen.positionIsValid(posImagen) == 1 &&  asterisco.compare(patron.getElementPos(i,j)) == 0){
        // std::cout << "La posicion es valida y hay un # en el patron" << std::endl;
        // std::cout << "En la matriz hay" << imagen.getElementPos(posImagen)<< std::endl;
        std::string elemento = imagen.getElementPos(posImagen);
        //si el elemento de la matrix es un asterico
        valor =  elemento.compare(asterisco);
        if (valor == 0){
          std::cout << "entre en el if" << std::endl;
          return 0;
        }
      }
    }
  }
  std::cout << "Analisis completo" << std::endl;
  std::cout << "No Hay coincidencia parcial" << std::endl;
  return 1;
}


void cargarMatrizImage(Matrix& image){
  int row = image.getCantRows();
  int column = image.getCantColumns();
  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= column; j++) {
      image.setElementPos(i,j,".");
    }
  }
  image.setElementPos(2,2,"#");
  image.setElementPos(5,4,"#");
  std::cout << "Matriz imagen" << std::endl;
  image.print();
}


Matrix aplicarDilatacion(Matrix& image, Matrix& patron){
  Position pivote(0,0);
  int row = image.getCantRows();
  int column = image.getCantColumns();
  std::cout << "copy" << std::endl;
  Matrix pepe(image);
  std::cout << "esta es la copia" << std::endl;
  pepe.print();
  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= column; j++) {
      pivote.setRow(i);
      pivote.setColumn(j);
      std::cout << "la imagen esta" << std::endl;
      image.print();
      if (posicionesValida(image,patron,pivote) == 0){
        std::cout << "ooooooooooo" << std::endl;
        pepe.setElementPos(pivote.getRow(),pivote.getColumn(),"#");
        pepe.print();
      }
    }
  }
  //pepe.print();
  return pepe;
}

void cargarMatrizPatron(Matrix& patron){
  int row = patron.getCantRows();
  int column = patron.getCantColumns();
  std::cout << "entrando al for" << std::endl;
  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= column; j++) {
      std::cout <<i<< "," <<j<< std::endl;
      patron.setElementPos(i,j,"#");
    }
  }
  std::cout << "salir del for" << std::endl;
  patron.setElementPos(1,1,".");
  patron.setElementPos(1,3,".");
  patron.setElementPos(3,1,".");
  patron.setElementPos(3,3,".");
  std::cout << "Matrix patron" << std::endl;
  patron.print();
}

//    0      1              2           3         4          5
// ./tp <numero de hilos> <filtro 1> <patron 1> <filtro 2> <patron 2>  ...
int main(int argc, char *argv[]) {
  Matrix patron(3,3); //imagen patron
  Matrix imagen(6,6);
  cargarMatrizPatron(patron);
  cargarMatrizImage(imagen);
  Matrix other = aplicarDilatacion(imagen,patron);
  other.print();
  return 0;
}

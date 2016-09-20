#include "Filter.h"

//Constructor
Filter::Filter(){}

//Destructor
Filter::~Filter(){}

/*Pre:Recibe una matrix imagen y patron y una posicion en la cual se debe
comparar
Post:Devuelve una lista con todos los elementos que se compararon
*/
std::list<bool> Filter::compareMatrices(Matrix& imagen,Matrix& patron,Position& position){
  std::list<bool> lista;
  int row = patron.getCantRows();
  int column = patron.getCantColumns();
  Position posicionMedia(row/2 + 1, column/2 + 1);
  Position posicionRelativa = posicionMedia.relativityPosition(position);
  Position otherPosition(0,0);
  std::string asterisco("#");
  bool valor;
  int i,j;
  for (i = 1; i <= row; i++) {
    for (j = 1; j <= column; j++) {
      otherPosition.setRow(i);
      otherPosition.setColumn(j);
      Position posImagen = posicionRelativa.sum(otherPosition);
      if (imagen.positionIsValid(posImagen) == 1 &&  asterisco.compare(patron.getElementPos(i,j)) == 0){
        std::string elemento = imagen.getElementPos(posImagen);
        valor =  elemento.compare(asterisco);
        if (valor == 0){
          lista.push_back(true);
        }else{
          lista.push_back(false);
        }
      }
    }
  }
    return lista;
  }



bool Filter::checkCoincidence(std::list<bool> lista){
  return true;
}

Matrix Filter::createImageDestin(int row,int column){
  Matrix destino(row,column);
  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= column; j++) {
      destino.setElementPos(i,j,".");
    }
  }
  return destino;
}


Matrix Filter::aplicateFilter(Matrix& image,Matrix& patron){
  Position pivote(0,0);
  int row = image.getCantRows();
  int column = image.getCantColumns();
  Matrix pepe = createImageDestin(row,column);
  for (int i = 1; i <= row; i++){
    for (int j = 1; j <= column; j++){
      pivote.setRow(i);
      pivote.setColumn(j);
      std::list<bool> lista = compareMatrices(image,patron,pivote);
      bool valor = checkCoincidence(lista);
      if (valor){
        pepe.setElementPos(pivote.getRow(),pivote.getColumn(),"#");
      }
    }
  }
  std::cout << "------------------------" << std::endl;
  return pepe;
}

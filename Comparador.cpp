#include "Comparador.h"
#include "Matrix.h"
#include "Repository.h"
#include "Position.h"

#include <string>
#include <list>
using std::string;

Comparador::Comparador(Matrix& image,Matrix& patron,Filter& filter, int section,
   Matrix& destino, int cantidad):_image(image),_patron(patron),
_filter(filter),_section(section),_destino(destino),_cantidad(cantidad){
}


Comparador::~Comparador(){}

std::list<bool> Comparador::compare(Position& position){
    std::list<bool> lista;
    int row = _patron.getCantRows();
    int column = _patron.getCantColumns();
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
         if (_image.positionIsValid(posImagen) == 0){
           lista.push_back(false);
         }else{
          if (asterisco.compare(_patron.getElementPos(i,j)) == 0){
            std::string elemento = _image.getElementPos(posImagen);
            valor =  elemento.compare(asterisco);
            if (valor == 0){
              lista.push_back(true);
            }else{
              lista.push_back(false);
            }
          }
        }
      }
    }
      return lista;
    }

void Comparador::setImageDestin(Position& position){
  _destino.setElementPos(position.getRow(),position.getColumn(),"#");
}

void Comparador::run(){
  int posInitial = _cantidad*_section;
  for (int i = posInitial; i < posInitial + _cantidad; i++){
    for (int j = 0; j < _image.getCantColumns(); j++) {
      Position position(i+1,j+1);
      std::list<bool> lista = compare(position);
      if (_filter.checkCoincidence(lista)){
        setImageDestin(position);
      }
    }
  }
}

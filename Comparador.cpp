#include "Comparador.h"
#include "Matrix.h"
#include "Repository.h"
#include "Position.h"
#include "ThreadParameters.h"

using std::string;

Comparador::Comparador(Matrix& image,Matrix& patron,Filter& filter, int section, Matrix& destino, int cantidad):_image(image),_patron(patron),
_filter(filter),_section(section),_destino(destino),_cantidad(cantidad){
  std::cout << "Constructor()" << std::endl;
  _image.print();
}


Comparador::~Comparador(){}

std::list<bool> Comparador::compare(Position& position){
  std::cout << "image" << std::endl;
    _image.print();
    std::cout << "patron" << std::endl;
    _patron.print();
    std::cout << "compare()" << std::endl;
    std::list<bool> lista;
    int row = _patron.getCantRows();
    int column = _patron.getCantColumns();
    std::cout << "row:" <<row<<" column:"<<column<< std::endl;
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
         //Posicion no valida
         if (_image.positionIsValid(posImagen) == 0){
           lista.push_back(false);
         }
        else{
          //posicion valida
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
      //std::cout << "exit compare()" << std::endl;
      return lista;
    }

void Comparador::setImageDestin(Position& position){
  std::cout << "setImageDestin()" << std::endl;
  _destino.setElementPos(position.getRow(),position.getColumn(),"#");
  _destino.print();
}

void Comparador::run(){
  std::cout << "Comparador::run()" << std::endl;
  std::cout << "cantidad de filas:" <<_cantidad<< std::endl;
  std::cout << "section:" <<_section<< std::endl;
  int posInitial = _cantidad*_section;
  for (int i = posInitial; i < posInitial + _cantidad; i++){
    for (int j = 0; j < _image.getCantColumns(); j++) {
      std::cout << "Voy a procesar la posicion:" <<i<<","<<j<< std::endl;
      Position position(i,j);
      std::list<bool> lista = compare(position);
      if (_filter.checkCoincidence(lista)){
        setImageDestin(position);
      }
    }
  }
}

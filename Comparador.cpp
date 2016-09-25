#include "Comparador.h"
#include "Matrix.h"
#include "Repository.h"
#include "Position.h"
#include "ThreadParameters.h"

using std::string;

void* Comparador::compare(void* dato){
  ThreadParameters* parameter = (ThreadParameters*)dato;
  int cantidad = 0;
  // Extraigo todos los datos
  Matrix& image = parameter->getMatrixImage();
  Matrix& patron = parameter->getMatrixPatron();
  //std::cout << "posicion de la matriz" << std::endl;
  Position& posicion = parameter->getPosition(); //posicion donde se centra el patron
  //posicion.print();
  int cantidadDeFilas = parameter->getCantidadFilas();
  int id_cto = parameter->getIdConjunto();
  Repository* repository = parameter->getRepository();
  string asterisco("#");
  Position posMedia(patron.getCantRows()/2 + 1, patron.getCantColumns()/2 + 1);
  Position posicionRelativa = posicion.relativityPosition(posMedia);
  Position positionImage(0,0);
  for (int i = 0; i < cantidadDeFilas; i++) {
    for (int j = 1; j <= image.getCantColumns(); j++) {
      //std::cout << "j:" <<j<< std::endl;
      positionImage.set(i+id_cto,j);

      //std::cout << "en la posicion de la imagen";
      //positionImage.print();
      Position positionPatron = posicionRelativa.sum(positionImage);
      //std::cout << "le corresponde";
      //positionPatron.print();
      if (patron.positionIsValid(positionPatron) && image.positionIsValid(positionImage)){
        std::cout <<positionImage.getRow()<<","<<positionImage.getColumn()<<"->"<<positionPatron.getRow()<<","<<positionPatron.getColumn()<< " ";
        string elementoPatron = patron.getElementPos(positionPatron);
        if (elementoPatron.compare(asterisco) == 0){ //hay un asterisco en la patron
          cantidad++;
          string elementoImage = image.getElementPos(positionImage);
          repository->addComparacion(!elementoImage.compare(asterisco));
        }
      }
    }
    std::cout << "" << std::endl;
  }
  std::cout << "soy soy el hilo:" <<id_cto<<"y tengo que procesar: "<<cantidadDeFilas<<"filas"<<"y procese:"<<cantidad<< std::endl;
  return (void*)NULL;
  }

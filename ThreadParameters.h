#ifndef THREADPARAMETERS_H_
#define THREADPARAMETERS_H_

#include "Position.h"
#include "Matrix.h"
#include <list>
#include "Repository.h"


/*Esta clase tendria todos los parametros necesarios para cada hilo. del cual el
hilo sabe qué cantidad y qué filas debe procesar.*/
class ThreadParameters{
private:
  Matrix& _image;
  Matrix& _patron;
  Position& _position; //posicion donde centro la matriz patron
  int _id_cto; //para definir que conjunto de filas debe procesar
  int _cantidadFilas; //para definir cuantas filas tiene que procesar
  Repository* _repo; //donde voy a guardar la información
public:
    ThreadParameters(Matrix& image,Matrix& patron,Position position,int id_cto,int
      cantidad,Repository* repo);
    Position& getPosition() const;
    Matrix& getMatrixImage() const;
    Matrix& getMatrixPatron() const;
    int getCantidadFilas() const;
    int getIdConjunto() const;
    Repository* getRepository() const;
		~ThreadParameters();
};

#endif /* THREADPARAMETERS_H_ */

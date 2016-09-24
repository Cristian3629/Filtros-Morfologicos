#include "ThreadParameters.h"


//constructor//
ThreadParameters::ThreadParameters(Matrix& image,Matrix& patron,Position
  position,int id_cto,int cantidad,Repository* repo):_image(image),_patron(patron),
_position(position),_id_cto(id_cto),_cantidadFilas(cantidad),_repo(repo){}


Position& ThreadParameters::getPosition() const{
  return _position;
}

Matrix& ThreadParameters::getMatrixImage() const{
  return _image;
}

Matrix& ThreadParameters::getMatrixPatron() const{
  return _patron;
}
int ThreadParameters::getCantidadFilas() const{
  return _cantidadFilas;
}

int ThreadParameters::getIdConjunto() const{
  return _id_cto;
}

Repository* ThreadParameters::getRepository() const{
  return _repo;
}
//destructor
ThreadParameters::~ThreadParameters(){}

#ifndef COMPARADOR_H_
#define COMPARADOR_H_

#include <iostream> //cout
#include "Thread.h"
#include "Matrix.h"
#include "Filter.h"
class Comparador: public Thread{
private:
	Matrix& _image;
	Matrix& _patron;
	Filter& _filter;
	int _section; //
	Matrix& _destino;
	int _cantidad; //cantidad de filas a procesar
	void setImageDestin(Position& position);
public:
	Comparador(Matrix& image,Matrix& patron,Filter& filter, int section, Matrix& destino, int cantidad);
  std::list<bool> compare(Position& position);
	void run();
	virtual ~Comparador();
};
#endif /* COMPARADOR_H_ */

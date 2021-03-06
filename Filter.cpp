#include "Filter.h"
#include "Comparador.h"
#include "Thread.h"
#include <vector>
//Constructor
Filter::Filter(int cantidadHilos):_cantidad(cantidadHilos){}

//Destructor
Filter::~Filter(){}

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
  std::vector<Thread*> threads;
  int cantidadFilas = image.getCantRows()/_cantidad + 1;
  int row = image.getCantRows();
  int column = image.getCantColumns();
  Matrix destino = createImageDestin(row,column);
  for (int i = 0; i < _cantidad; i++){
    Thread* thread = new Comparador(image,patron,*this,i,destino,cantidadFilas);
    threads.push_back(thread);
  }

  threads[0]->run();
  for (int i = 1; i < _cantidad; i++){
    threads[i]->start();
  }

  delete threads[0];
  for (int i = 1; i < _cantidad; ++i) {
        threads[i]->join();
        delete threads[i];
  }
  return destino;
}

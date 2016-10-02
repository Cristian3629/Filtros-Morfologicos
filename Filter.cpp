#include "Filter.h"
#include "Comparador.h"
#include "Thread.h"
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
  std::cout << "aplicateFilter" << std::endl;
  image.print();
  std::vector<Thread*> threads;
  //image.print();
  int cantidadDeFilas = image.getCantRows()/_cantidad + 1;
  //std::cout << "cantidadDeFilas:" <<cantidadDeFilas<< std::endl;
  int row = image.getCantRows();
  int column = image.getCantColumns();
  Matrix destino = createImageDestin(row,column);
  for (int i = 0; i < _cantidad; i++){
    //i es la seccion
    Thread* thread = new Comparador(image,patron,*this,i,destino,cantidadDeFilas);
    threads.push_back(thread);
  }

  threads[0]->run();
  std::cout << "_cantidad:" <<_cantidad<< std::endl;
  for (int i = 1; i < _cantidad; i++){
    std::cout << "lanzando hilos" << std::endl;
    threads[i]->start();
  }

  delete threads[0];
  for (int i = 1; i < _cantidad; ++i) {
    std::cout << "joineando hilos" << std::endl;
        threads[i]->join();
        delete threads[i];
  }
  return destino;
}

#include "Filter.h"
#include <string>
#include <list>
#include "Comparador.h"
using std::list;
using std::string;
//Constructor
Filter::Filter(int cantidadHilos):_cantidad(cantidadHilos){}

//Destructor
Filter::~Filter(){}

/*Pre:Recibe una matrix imagen y patron y una posicion en la cual se debe
comparar
Post:Devuelve una lista con todos los elementos que se compararon
*/
list<bool> Filter::compareMatrices(Matrix& image,Matrix& patron,Position& pos, int cantidadThreads){
  Repository repository; //donde cada hilo va a guardar la información de sus comparaciones
  list<Thread*> hilos;
  list<ThreadParameters*> parametros;
  int row = image.getCantRows();
  int cantRowPerTheard = row/cantidadThreads;
  int i = 1;
  while (i < row){
    std::cout << "i:" <<i<< std::endl;
    ThreadParameters* parametro = new ThreadParameters(image,patron,pos,i,cantRowPerTheard,&repository);
    Thread* thread = new Thread(Comparador::compare,parametro);
    thread->start();
    hilos.push_back(thread); //para luego hacer el join
    parametros.push_back(parametro);
    i = i + cantRowPerTheard;
  }

  list<Thread*>::iterator it;
  for (it = hilos.begin(); it != hilos.end(); it++) {
    Thread* thread = *it;
    thread->join((void**)NULL);
    delete(thread);
  }

  return repository.getList();
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
  std::cout << "aplicateFilter" << std::endl;
  Position pivote(0,0);
  int row = image.getCantRows();
  int column = image.getCantColumns();
  Matrix pepe = createImageDestin(row,column);
  for (int i = 1; i <= row; i++){
    for (int j = 1; j <= column; j++){
      pivote.set(i,j);
      list<bool> lista = compareMatrices(image,patron,pivote,_cantidad);
      bool valor = checkCoincidence(lista);
      if (valor){
        pepe.setElementPos(pivote.getRow(),pivote.getColumn(),"#");
      }
    }
  }
  //std::cout << "------------------------" << std::endl;
  return pepe;
}

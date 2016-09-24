#include "Filter.h"
#include <string>
#include <list>

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
// list<bool> Filter::compareMatrices(Matrix& imagen,Matrix& patron,Position& pos){
//   list<bool> lista;
//   int row = patron.getCantRows();
//   int column = patron.getCantColumns();
//   Position posicionMedia(row/2 + 1, column/2 + 1);
//   Position posicionRelativa = posicionMedia.relativityPosition(pos);
//   Position otherPosition(0,0);
//   string asterisco("#");
//   bool valor;
//   int i,j;
//   for (i = 1; i <= row; i++) {
//     for (j = 1; j <= column; j++) {
//       otherPosition.setRow(i);
//       otherPosition.setColumn(j);
//       Position posImagen = posicionRelativa.sum(otherPosition);
//       //Posicion no valida
//       if (imagen.positionIsValid(posImagen) == 0){
//         lista.push_back(false);
//       }else{
//         //posicion valida
//         if (asterisco.compare(patron.getElementPos(i,j)) == 0){
//           string elemento = imagen.getElementPos(posImagen);
//           valor =  elemento.compare(asterisco);
//           if (valor == 0){
//             lista.push_back(true);
//           }else{
//             lista.push_back(false);
//           }
//         }
//       }
//     }
//   }
//     return lista;
//   }
void* Filter::compare(void* dato){
  ThreadParameters* parameter = (ThreadParameters*)dato;
  // Extraigo todos los datos
  Matrix& image = parameter->getMatrixImage();
  Matrix& patron = parameter->getMatrixPatron();
  Position& position = parameter->getPosition(); //posicion donde se centra el patron
  int cantidadDeFilas = parameter->getCantidadFilas();
  int id_cto = parameter->getIdConjunto();
  Repository* repository = parameter->getRepository();
  string asterisco("#");
  Position posMedia(patron.getCantRows()/2 + 1, patron.getCantColumns()/2 + 1);
  Position posicionRelativa = position.relativityPosition(posMedia);
  Position positionImage;

  for (int i = 0; i < cantidadDeFilas; i++) {
    for (int j = 1; j <= image.getCantColumns(); j++) {
      positionImage.set(i+id_cto,j);
      Position positionPatron = posicionRelativa.sum(positionImage);
      if (patron.positionIsValid(positionPatron)){
        string elementoPatron = patron.getElementPos(positionPatron);
        if (elementoPatron.compare(asterisco) == 0){ //hay un asterisco en la patron
          string elementoImage = image.getElementPos(positionImage);
          repository->addComparacion(!elementoImage.compare(asterisco));
        }
      }
    }
  }
  return (void*)NULL;
}

list<bool> Filter::compareMatrices(Matrix& image,Matrix& patron,Position& pos, int cantidadThreads){
  Repository repository; //donde cada hilo va a guardar la información de sus comparaciones
  list<Thread*> hilos;
  list<ThreadParameters*> parametros;
  int row = image.getCantRows();
  int cantRowPerTheard = row/cantidadThreads;
  for (int i = 1 ; i < cantidadThreads; i++) {
    ThreadParameters* parametro = new ThreadParameters(image,patron,pos,i,cantRowPerTheard,&repository);
    Thread* thread = new Thread(Filter::compare,parametro);
    hilos.push_back(thread); //para luego hacer el join
    parametros.push_back(parametro);
  }
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


Matrix Filter::aplicateFilter(Matrix& image,Matrix& patron, int cantThreads){
  Position pivote(0,0);
  int row = image.getCantRows();
  int column = image.getCantColumns();
  Matrix pepe = createImageDestin(row,column);
  for (int i = 1; i <= row; i++){
    for (int j = 1; j <= column; j++){
      pivote.setRow(i);
      pivote.setColumn(j);
      list<bool> lista = compareMatrices(image,patron,pivote,cantThreads);
      bool valor = checkCoincidence(lista);
      if (valor){
        pepe.setElementPos(pivote.getRow(),pivote.getColumn(),"#");
      }
    }
  }
  //std::cout << "------------------------" << std::endl;
  return pepe;
}

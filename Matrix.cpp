#include "Matrix.h"
#include <string>
#include <mutex>
#include <iostream> //cout
#include <vector>


using std::string;
using std::cout;
using std::endl;
using std::mutex;
using std::vector;

Matrix::Matrix():cantRows(0),cantColumns(0){
  mutex mtx;
}

Matrix::Matrix(int rows, int column):cantRows(rows),cantColumns(column){
  vector<vector<string> > aux(cantRows);
  for ( int i = 0 ; i < cantRows ; i++ ){
    aux[i].resize(cantColumns);
  }
  matrix = aux;
  mutex mtx;
}

//constructor por movimiento
Matrix::Matrix(Matrix&& other):cantRows(0), cantColumns(0){
   matrix = std::move(other.matrix);
   cantRows = other.cantRows;
   cantColumns = other.cantColumns;
   other.cantRows = 0;
   other.cantColumns = 0;
}


// Asignacion por movimiento
Matrix& Matrix::operator=(Matrix&& other){
  if (this != &other){
      matrix = std::move(other.matrix);
      cantRows = other.cantRows;
      cantColumns = other.cantColumns;
      other.cantRows = 0;
      other.cantColumns = 0;
   }
   return *this;
}

//verifica si el num de columna es valido
bool Matrix::columnPositionValid(int column) const {
    return 0 < column && column <= this->cantColumns;
}

//verifica si el num de fila es valido
bool Matrix::rowPositionValid(int row) const {
    return 0 < row && row <= this->cantRows;
  }

//muestra por stdout las dimensiones de la matrix
void Matrix::dimesions(){
  cout << "Tengo col:" <<this->cantColumns<<"y fil:"<<this->cantRows<< endl;
}


void Matrix::print(){
  for (int i = 0; i < this->cantRows; i++) {
    for (int j = 0; j < this->cantColumns; j++) {
      cout << matrix[i][j] << "";
    }
    cout << "" << endl;
  }
}

//verifica si la posicion fila,colum es valida
bool Matrix::positionIsValid(const Position&  position){
    return columnPositionValid(position.getColumn()) &&
    rowPositionValid(position.getRow());
  }
  //-------------------------getters---------------------------------
int Matrix::getCantColumns() const {
  return cantColumns;
  }

int Matrix::getCantRows() const{
    return cantRows;
  }

void Matrix::setElementPos(int posRows, int posColumn, string const element){
  mtx.lock();
  if (columnPositionValid(posColumn) && rowPositionValid(posRows)){
    this->matrix[posRows-1][posColumn-1] = element;
  }
  mtx.unlock();
}

string Matrix::getElementPos(int posRows,int posColumn) const{
  return matrix[posRows-1][posColumn-1];
}

string Matrix::getElementPos(Position position) const{
  return matrix[position.getRow()-1][position.getColumn()-1];
}


Matrix::~Matrix(){
  // for (int i = 0; i < cantRows; i++) {
  //   delete[] matrix[i];
  // }
  // delete[](matrix);
}

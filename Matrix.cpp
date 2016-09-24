#include "Matrix.h"
#include <string>

using std::string;
using std::cout;
using std::endl;



Matrix::Matrix():cantRows(0),cantColumns(0){
  std::cout << "Creando matrix vacia" << std::endl;
}

Matrix::Matrix(int rows, int column):cantRows(rows),cantColumns(column){
  this->matrix = new string*[cantRows];
  for (int i = 0; i < rows ; i++){
    this->matrix[i]= new string[cantColumns];
  }
}

//constructor por movimiento
Matrix::Matrix(Matrix&& other):cantRows(0), cantColumns(0),matrix(nullptr){
  std::cout << "constructor por movimiento" << std::endl;
   matrix = other.matrix;
   cantRows = other.cantRows;
   cantColumns = other.cantColumns;
   other.matrix = nullptr;
   other.cantRows = 0;
   other.cantColumns = 0;
}


// Asignacion por movimiento
Matrix& Matrix::operator=(Matrix&& other){
std::cout << "Asignacion por movimiento" << std::endl;
std::cerr << "Dimensiones:" <<other.getCantRows()<<","<<other.getCantColumns()<< std::endl;
  if (this != &other){
      for (int i = 0; i < cantRows; i++) {
        delete[] matrix[i];
      }
      delete[](matrix);
      matrix = other.matrix;
      cantRows = other.cantRows;
      cantColumns = other.cantColumns;
      other.matrix = nullptr;
      other.cantRows = 0;
      other.cantColumns = 0;
   }
   return *this;
}

//verifica si el num de columna es valido
bool Matrix::columnPositionValid(int column){
    return 0 < column && column <= this->cantColumns;
}

//verifica si el num de fila es valido
bool Matrix::rowPositionValid(int row){
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
  //cout << "++++++++++++++" << endl;
}

//verifica si la posicion fila,colum es valida
bool Matrix::positionIsValid(Position& position){
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

void Matrix::setElementPos(int posRows, int posColumn, string element){
  matrix[posRows-1][posColumn-1] = element;
}

string Matrix::getElementPos(int posRows,int posColumn) const{
  return matrix[posRows-1][posColumn-1];
}

string Matrix::getElementPos(Position position) const{
  return matrix[position.getRow()-1][position.getColumn()-1];
}


Matrix::~Matrix(){
  //cout << "destructor called" << endl;
  for (int i = 0; i < cantRows; i++) {
    delete[] matrix[i];
  }
  delete[](matrix);
}

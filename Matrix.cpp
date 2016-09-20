#include "Matrix.h"

using namespace std;
Matrix::Matrix(int rows, int column):cantRows(rows),cantColumns(column){
  this->matrix = new string*[cantRows];
  for(int i = 0; i < rows ; i++){
    this->matrix[i]= new string[cantColumns];
  }
}

Matrix::Matrix(const Matrix& otherMatrix):cantRows(otherMatrix.getCantRows()),cantColumns(otherMatrix.getCantColumns()){
  std::cout << "asignation per copy" << std::endl;
  this->matrix = new string*[cantRows];
  for(int i = 0; i < cantRows ; i++){
    this->matrix[i]= new string[cantColumns];
  }
  int i,j;
  for (i = 1; i <= cantRows; i++) {
    for (j = 1; j <= cantColumns; j++) {
      this->setElementPos(i,j,otherMatrix.getElementPos(i,j));
    }
  }
}


void Matrix::set(const Matrix& otherMatrix){
  if (otherMatrix.getCantColumns() == this->cantColumns && otherMatrix.getCantRows() == this->cantRows){
    for (int i = 1; i <= cantRows; i++){
      for (int j = 1; j <= cantColumns; j++) {
        this->setElementPos(i,j,otherMatrix.getElementPos(i,j));
      }
    }
  }else{
    std::cout << "no se puede copiar los valores" << std::endl;
  }
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
  std::cout << "Tengo col:" <<this->cantColumns<<"y fil:"<<this->cantRows<< std::endl;
}


void Matrix::print(){
  for (int i = 0; i < this->cantRows; i++) {
    for (int j = 0; j < this->cantColumns; j++) {
      std::cout << matrix[i][j] << "";
    }
    std::cout << "" << std::endl;
  }
  std::cout << "++++++++++++++" << std::endl;
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

void Matrix::setElementPos(int posRows, int posColumn, std::string element){
  matrix[posRows-1][posColumn-1] = element;
}

std::string Matrix::getElementPos(int posRows,int posColumn) const{
  return matrix[posRows-1][posColumn-1];
}

std::string Matrix::getElementPos(Position position) const{
  return matrix[position.getRow()-1][position.getColumn()-1];
}


Matrix::~Matrix(){
  //std::cout << "destructor called" << std::endl;
  for (int i = 0; i < cantRows; i++) {
    delete[] matrix[i];
  }
  delete[](matrix);
}

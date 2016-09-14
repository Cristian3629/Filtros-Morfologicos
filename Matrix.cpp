#include "Matrix.h"

//verifica si el num de columna es valido
bool Matrix::columnPositionValid(int column){
    return 0 < column && column <= this->cantColumns;
}

//verifica si el num de fila es valido
bool Matrix::rowPositionValid(int row){
    return 0 < row && row <= this->cantRows;
  }


Matrix::Matrix(int column, int rows){
  this->cantColumns =  column;
  this->cantRows = rows;
  int i;
  matrix = (char **)malloc(cantRows*sizeof(char *));
  for(i = 0; i < rows ; i++){
    matrix[i]=(char*)malloc(cantColumns*sizeof(char));
  }
}

//muestra por stdout las dimensiones de la matrix
void Matrix::dimesions(){
  std::cout << "Tengo col:" <<this->cantColumns<<"y fil:"<<this->cantRows<< std::endl;
}

//verifica si la posicion fila,colum es valida
bool Matrix::positionIsValid(Position& position){
    return columnPositionValid(position.getColumn()) &&
    rowPositionValid(position.getRow());
  }
  //-------------------------getters---------------------------------
int Matrix::getCantColum(){
  return cantColumns;
  }

int Matrix::getCantRows(){
    return cantRows;
  }

void Matrix::setElementPos(int posColumn, int posRows, const char* element){
  matrix[posRows][posColumn] = *element;
}

char Matrix::getElementPos(int posColumn, int posRows){
  return matrix[posRows][posColumn];
}

Matrix::~Matrix(){
  int i;
  for(i = 0; i < cantRows ; i++){
    free(matrix[i]);
  }
  free(matrix);
}

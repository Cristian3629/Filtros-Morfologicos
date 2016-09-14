#include "Position.h"



Position::Position(int rowNew,int columNew){
    this->row = rowNew;
    this->column = columNew;
}


  //Método que te devuelve posicion relativa.
  Position Position::relativityPosition(Position& otherPosition){
    int columnNew = otherPosition.getColumn() - this->column;
    int rowNew = otherPosition.getRow() - this->row;
    Position newPosition(columnNew,rowNew);
    return newPosition;
  }

  Position Position::sum(Position& position){
    int newColumn = this->column + position.getColumn();
    int newRow = this->row + position.getRow();
    Position newPosition(newRow,newColumn);
    return newPosition;
  }

  int Position::getColumn(){
    return column;
  }

  int Position::getRow(){
    return row;
  }

  Position::~Position(){}

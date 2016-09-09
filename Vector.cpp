class Position(){
  int column,row;

  Position(int row,int colum){
    this.row = row;
    this.colum = colum;
  }


  //Método que te devuelve posicion relativa.
  Position relativityPosition(const Position position){
    int columnNew = position.getColumn() - this.colum;
    int rowNew = position.getRow() - this.row;
    return new Position(columnNew,rowNew);
  }

  int getColumn(){
    return column;
  }

  int getRow(){
    return row;
  }

}

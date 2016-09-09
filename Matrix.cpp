##include <.h>
class Matrix(){
  int cantColumns, cantRows;

  bool columnPositionValid(int column){
    return 0 < column && column <= cantColumns;
  }

  bool rowPositionValid(int column){
    return 0 < row && row <= cantRows;
  }

public:
   Matrix(int colum, int rows){
     //tengo que ver como creo la matrix
  }

  bool static positionIsValid(Position position){
    return columnPositionValid(position.getColumn()) &&
    rowPositionValid(position.getRow());
  }

  //-------------------------getters---------------------------------
  int getCantColum(){
    return cantColum;
  }

  int getCantRows(){
    return this.cantRows;
  }


  int getElementPos(int posColumn, int posRows){
      //
  }



}

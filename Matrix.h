#ifndef MATRIX_H_
#define MATRIX_H_

#include "Position.h"
#include <vector>
#include <stdlib.h> // malloc,free


class Matrix{
private:
	bool columnPositionValid(int column);
	bool rowPositionValid(int row);
	int cantColumns, cantRows;
	char** matrix; /*puntero a la matriz*/
public:
    Matrix(int colum, int rows);
    int getCantColum();
    int getCantRows();
    char getElementPos(int posColumn, int posRows);
		void setElementPos(int posColumn,int posRows, const char* element);
		bool positionIsValid(Position& position);
		void dimesions();
		~Matrix();
};

#endif /* MATRIX_H_ */

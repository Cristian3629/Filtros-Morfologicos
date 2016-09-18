#ifndef MATRIX_H_
#define MATRIX_H_

#include "Position.h"
#include <vector>
#include <stdlib.h> // malloc,free


class Matrix{
private:
	bool columnPositionValid(int column);
	bool rowPositionValid(int row);
	int cantRows,cantColumns;
	std::string** matrix; /*puntero a la matriz*/
public:
    Matrix(int rows, int column);
		Matrix(const Matrix& matrix);
    int getCantColumns() const;
    int getCantRows() const;
    std::string getElementPos(int posColumn, int posRows) const;
		std::string getElementPos(Position position) const;
		void setElementPos(int posRows,int posColumn, std::string element);
		bool positionIsValid(Position& position);
		void dimesions();
		void print();
		~Matrix();
};

#endif /* MATRIX_H_ */

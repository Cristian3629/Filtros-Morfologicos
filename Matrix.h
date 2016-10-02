#ifndef MATRIX_H_
#define MATRIX_H_

#include "Position.h"
#include <vector>
#include <stdlib.h> // malloc,free
#include <string>
#include <mutex>

class Matrix{
private:
	bool columnPositionValid(int column);
	bool rowPositionValid(int row);
	int cantRows,cantColumns;
	std::string** matrix; /*puntero a la matriz*/
public:
		//no copiable
		Matrix(const Matrix &other) = delete;
		Matrix& operator=(const Matrix &other) = delete;
		Matrix(Matrix&& matrix); //constructor por movimiento
		Matrix& operator=(Matrix&& other); //asignacion por movimiento
    Matrix(int rows, int column);
		Matrix();
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

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Position.h"
#include <vector>
#include <string>
#include <mutex>

class Matrix{
private:
	bool columnPositionValid(int column) const;
	bool rowPositionValid(int row) const;
	int cantRows,cantColumns;
	std::vector<std::vector<std::string>> matrix;
	std::mutex mtx;
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
		bool positionIsValid(const Position& position);
		void dimesions();
		void print();
		~Matrix();
};

#endif /* MATRIX_H_ */

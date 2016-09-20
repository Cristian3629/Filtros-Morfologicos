#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include <iostream> //cout
#include <sstream>
#include <string>
#include <vector>

#include "Matrix.h"

class Interpreter{
private:
	void split(const std::string &s, char delim, std::vector<std::string> &elems);
	void cargarMatrizPatron(Matrix& patron);
public:
	Interpreter();
	Matrix createMatrix(const std::string& matrix);
	~Interpreter();
};
#endif /* INTERPRETER_H_ */

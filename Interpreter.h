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
public:
	Interpreter();
	Matrix createMatrix(const std::string& matrix);
	Matrix createMatrix(std::vector<std::string> elems);
	~Interpreter();
};
#endif /* INTERPRETER_H_ */

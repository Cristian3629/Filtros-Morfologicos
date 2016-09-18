#include "Interpreter.h"

//Esta se encarga de interpretar una cadena y devolver la matriz
//saca el espacio redundante al principio pero no en el intermedio
using namespace std;

void Interpreter::createMatrix(){
    istringstream s("             3      3     ####          #####               ");
    string line;
    s >> ws; //saca al principio
    getline(s,line);
    std::cout << "ws + getline returns: \"" << line << "\"\n";
}

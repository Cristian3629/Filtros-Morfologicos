#ifndef MATRIXPATRON_H_
#define MATRIXPATRON_H_

#include "Position.h"
#include "Matrix.h"

class MatrixPatron : public Matrix{
public:
    MatrixPatron(int cant);
    Position getHalfPosition();
};

#endif /* MATRIXPATRON_H_ */

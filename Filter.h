#ifndef FILTER_H_
#define FILTER_H_

#include "Position.h"
#include "Matrix.h"
#include <list>


class Filter{
private:
  std::list<bool> compareMatrices(Matrix& imagen,Matrix& patron,Position& pos);
  virtual bool checkCoincidence(std::list<bool> lista) = 0;
  Matrix createImageDestin(int row,int column);
public:
    Filter();
    virtual Matrix aplicateFilter(Matrix& image,Matrix& patron);
		~Filter();
};

#endif /* FILTER_H_ */

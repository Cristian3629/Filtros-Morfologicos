#ifndef FILTER_H_
#define FILTER_H_

#include "Position.h"
#include "Matrix.h"
#include <list>



class Filter{
private:
  std::list<bool> compareMatrices(Matrix& imagen,Matrix& patron,Position& position);
  virtual bool checkCoincidence(std::list<bool> lista);
public:
    Filter();
    Matrix aplicateFilter(Matrix& image,Matrix& patron);
		~Filter();
};

#endif /* FILTER_H_ */

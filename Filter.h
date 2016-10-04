#ifndef FILTER_H_
#define FILTER_H_

#include "Position.h"
#include "Matrix.h"
#include <list>
//#include "Thread.h"

class Filter{
private:
  std::list<bool> compareMatrices(Matrix& image,Matrix& patron,Position& pos,
    int cantidadThreads);
  Matrix createImageDestin(int row,int column);
  bool outRegion(Matrix& image,Matrix& patron,Position& position);
  int _cantidad;
public:
    explicit Filter(int cantidadHilos);
    virtual Matrix aplicateFilter(Matrix& image,Matrix& patron);
    virtual bool checkCoincidence(std::list<bool> lista) = 0;
		virtual ~Filter();
};

#endif /* FILTER_H_ */

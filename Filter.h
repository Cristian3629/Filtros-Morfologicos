#ifndef FILTER_H_
#define FILTER_H_

#include "Position.h"
#include "Matrix.h"
#include <list>
#include "Repository.h"
#include "ThreadParameters.h"
#include "Thread.h"

class Filter{
private:
  std::list<bool> compareMatrices(Matrix& image,Matrix& patron,Position& pos, int cantidadThreas);
  virtual bool checkCoincidence(std::list<bool> lista) = 0;
  Matrix createImageDestin(int row,int column);
  int _cantidad;
public:
    Filter(int cantidadHilos);
    virtual Matrix aplicateFilter(Matrix& image,Matrix& patron);
    static void* compare(void*);
		~Filter();
};

#endif /* FILTER_H_ */

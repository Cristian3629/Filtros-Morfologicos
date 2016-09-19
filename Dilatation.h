#ifndef DILATATION_H_
#define DILATATION_H_
#include "Filter.h"


class Dilatation : public Filter{
private:
  std::list<bool> compareMatrices(Matrix& imagen,Matrix& patron,Position& position);
  bool checkCoincidence(std::list<bool> lista);
public:
  Dilatation();
  ~Dilatation();
};


#endif /* DILATATION_H_ */

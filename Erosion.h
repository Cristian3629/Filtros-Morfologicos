#ifndef EROSION_H_
#define EROSION_H_
#include "Filter.h"


class Erosion : public Filter{
private:
  std::list<bool> compareMatrices(Matrix& imagen,Matrix& patron,Position& position);
  bool checkCoincidence(std::list<bool> lista);
public:
  Erosion();
  ~Erosion();
};


#endif /* EROSION_H_ */

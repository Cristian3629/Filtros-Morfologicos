#ifndef EROSION_H_
#define EROSION_H_
#include "Filter.h"


class Erosion : public Filter{
private:
  bool checkCoincidence(std::list<bool> lista);
public:
  Erosion();
  ~Erosion();
};


#endif /* EROSION_H_ */

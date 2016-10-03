#ifndef EROSION_H_
#define EROSION_H_
#include "Filter.h"
#include <list>

class Erosion : public Filter{
private:
  bool checkCoincidence(std::list<bool> lista);
public:
  explicit Erosion(int cantidadHilos);
  ~Erosion();
};


#endif /* EROSION_H_ */

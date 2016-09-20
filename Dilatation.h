#ifndef DILATATION_H_
#define DILATATION_H_
#include "Filter.h"


class Dilatation : public Filter{
private:
  bool checkCoincidence(std::list<bool> lista);
public:
  Dilatation();
  ~Dilatation();
};


#endif /* DILATATION_H_ */

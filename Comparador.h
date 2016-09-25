#ifndef COMPARADOR_H_
#define COMPARADOR_H_

#include <iostream> //cout


class Comparador{
public:
	Comparador();
  static void* compare(void* dato);
	virtual ~Comparador();
};
#endif /* COMPARADOR_H_ */

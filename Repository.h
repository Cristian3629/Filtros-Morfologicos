#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include "Position.h"
#include "Matrix.h"
#include <list>

/*Esta clase modela el conteiner para que cada hilo guardo la informacion
 de las comparaciones que va llevando, lo vi necesario para que lo unico que
 pueda hacer cada hilo es guardar*/
class Repository{
private:
  std::list<bool>* lista;
public:
    Repository();
    void addComparacion(bool valor);
		~Repository();
};

#endif /* STACKTHREAD_H_ */

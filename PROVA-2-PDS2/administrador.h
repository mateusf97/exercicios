#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include "usuario.h"

class Administrador :public Usuario {

  public:
    Administrador();
    ~Administrador();
    void Remover(int);

};

#endif

#ifndef USUARIO_H
#define USUARIO_H

#include <list>
#include <iostream>

class Usuario {
  public:
    std::list<int> lista;
    Usuario();
    ~Usuario();
    void Adicionar(int);
};

#endif

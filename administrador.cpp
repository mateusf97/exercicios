#include "administrador.h"

Administrador::Administrador() {}
Administrador::~Administrador() {}

void Administrador::Remover(int num) {
  this->lista.remove(num);

  std::cout << std::endl;

  for (auto i: this->lista) {
    std::cout << i << std::endl;
  }
}
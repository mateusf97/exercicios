#include "usuario.h"

Usuario::Usuario() {}
Usuario::~Usuario() {}

void Usuario::Adicionar(int num) {
  this->lista.push_back(num);

  for (auto i: this->lista) {
    std::cout << i << std::endl;
  }
}
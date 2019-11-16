#include "usuario.h"
#include "administrador.h"

int main() {
  Administrador *admin = new Administrador();
  Usuario *user = new Usuario();

  user->Adicionar(1);

  admin->Adicionar(1);
  admin->Adicionar(2);
  admin->Adicionar(3);
  admin->Adicionar(6);

  admin->Remover(2);

  delete user;
  delete admin;

  return 0;
}
#include "usuario.h"
#include "administrador.h"

int main(int argc, char const *argv[]) {
  Administrador *admin = new Administrador();
  // Usuario *user = new Usuario();

  // user->Adicionar(1);
  // user->Adicionar(2);
  // user->Adicionar(3);

  admin->Adicionar(3);
  admin->Adicionar(4);
  admin->Adicionar(5);
  admin->Adicionar(6);

  admin->Remover(4);

  // delete user;
  delete admin;

  return 0;
}
#include "usuario.h"
#include "administrador.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

  TEST_CASE("teste método adicionar do usuario"){
    Usuario *user = new Usuario();
    CHECK(user->Adicionar(3) == 3);
    delete user;
  }

  TEST_CASE("teste método adicionar do admin"){
    Administrador *admin = new Administrador();
    CHECK(admin->Adicionar(5) == 5);
    CHECK(admin->Adicionar(6) == 6);
    delete admin;
  }

  TEST_CASE("teste método remover do admin"){
    Administrador *admin = new Administrador();
    CHECK(admin->Adicionar(5) == 5);
    CHECK(admin->Adicionar(6) == 6);
    CHECK(admin->Remover(6) == 6);
    delete admin;
  }

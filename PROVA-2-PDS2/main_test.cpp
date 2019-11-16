#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Card.hpp"

	TEST_CASE("Teste Card - Casos Base") {
		Card *a = new Card("NG5");
		Card *b = new Card("NR0");

		CHECK(a->get_value() == "N15");
		CHECK(b->get_value() == "NR0");

		delete a;
		delete b;
	}

	TEST_CASE("Teste Card – Casos Mais Complicados") {
		Card *a = new Card("NR42");
		Card *b = new Card("BCC");
		Card *c = new Card("BCC4");
		Card *d = new Card("BC43");
		Card *e = new Card("SRI2");

		CHECK(a->get_value() == "NR4");
		CHECK(b->get_value() == "BCC");
		CHECK(c->get_value() == "BCC");
		CHECK(d->get_value() == "BC4");
		CHECK(e->get_value() == "SRI");

		delete a;
		delete b;
		delete c;
		delete d;
		delete e;
	}
#include "Pack.hpp"
#include "File_Failure.hpp"

	TEST_CASE("Teste Pack - Casos Base") {
		Pack *b = new Pack();

		CHECK(b->get_number_of_cards() == 112);

		delete b;
	}

	TEST_CASE("Teste Pack - Casos Base") {
		Pack *b = new Pack();
		b->remove_first();

		CHECK(b->get_number_of_cards() == 111);

		delete b;
	}

	TEST_CASE("Teste Pack - Casos Base") {
		Pack *b = new Pack();
		std::shared_ptr<Card> a (new Card("NR0"));

		CHECK(b->return_first()->get_value() == a->get_value());

		delete b;
	}

	TEST_CASE("Teste Pack - Casos Base") {
		Pack *b = new Pack();
		std::shared_ptr<Card> a (new Card("NR0"));
		b->cards_back(a);

		CHECK(b->get_number_of_cards() == 113);

		delete b;
	}

	TEST_CASE("Teste Pack - Casos Base") {
		Pack *b = new Pack();
		std::shared_ptr<Card> a = b->return_first();
		b->shuffle();
		std::shared_ptr<Card> c = b->return_first();

		CHECK(a != c);

		delete b;
	}
#include "Player.hpp"

	TEST_CASE("Teste Player - Casos Base") {
		Player *p1 = new Player(1);

		CHECK(p1->get_index() == 1);

		delete p1;
	}

	TEST_CASE("Teste Player - Casos Mais complicado") {
		Player *p1 = new Player(1);
		Player *p2 = new Player(2);
		p1->show_cards();
		p2->show_cards();

		CHECK(p1->get_index() == 1);
		CHECK(p2->get_index() == 2);

		delete p1;
		delete p2;
	}

	TEST_CASE("Teste Player - Casos Base") {
		Player *p1 = new Player(1);

		CHECK(p1->hand_size() == 0);

		delete p1;
	}

	TEST_CASE("Teste Player - Casos Base") {
		Player *p1 = new Player(1);
		std::shared_ptr<Card> a (new Card("NR0"));
		std::shared_ptr<Card> b (new Card("NR1"));
		p1->buy_card(a);
		p1->buy_card(b);
		p1->remove_card(1);

		CHECK(p1->hand_size() == 1);

		delete p1;
	}

	TEST_CASE("Teste Player - Casos Base") {
		Player *p1 = new Player(1);
		std::shared_ptr<Card> a (new Card("NR0"));
		p1->buy_card(a);

		CHECK(p1->hand_size() == 1);

		delete p1;
	}

	TEST_CASE("Teste Player - Casos Base") {
		Player *p1 = new Player(1);
		std::shared_ptr<Card> a (new Card("NR0"));
		p1->buy_card(a);

		CHECK(p1->send_card(0) == a);

		delete p1;
	}

#include "Game.hpp"
#include "Stack.hpp"
#include "invalid_card.hpp"

	TEST_CASE("Teste Game - Caso Mais simples") {
		Game *jogo = new Game();
		jogo->start(4);
		jogo->generate_hand();

		CHECK(jogo->players[1]->get_index() == 1);

		delete jogo;
	}

	TEST_CASE("Teste Game - Casos complicado") {
		Game *jogo = new Game();
		jogo->start(2);
		jogo->generate_hand();

		CHECK(jogo->players.size() == 2);

		CHECK(jogo->players[0]->hand_size() == 7);
		CHECK(jogo->players[1]->hand_size() == 7);

		delete jogo;
	}

	TEST_CASE("Teste Game - Caso Mais Complicado") {
		Game *jogo = new Game();
		jogo->start(2);
		jogo->generate_hand();

		jogo->stack->receive_card(jogo->players[1]->send_card(1));
		jogo->players[1]->remove_card(1);
		CHECK(jogo->players[1]->hand_size() == 6);
		CHECK(jogo->game_is_running() == true);
		jogo->next_player();
		CHECK(jogo->get_index() == 1);
		jogo->next_player();
		CHECK(jogo->get_index() == 0);
		jogo->next_player();

		for (int i = 0; i < 6; ++i){
			jogo->stack->receive_card(jogo->players[1]->send_card(0));
			jogo->players[1]->remove_card(0);
		}

		CHECK(jogo->game_is_running() == false);

		delete jogo;
	}

	TEST_CASE("Teste Game - Caso Muito Mais Complicado") {
		Game *jogo = new Game();
		jogo->start(3);
		jogo->generate_hand();
		std::shared_ptr<Card> carta(new Card("SBI"));

		jogo->stack->receive_card(carta);
		jogo->apply_effect();
		jogo->apply_effect();
		jogo->apply_effect();
		jogo->next_player();
		CHECK(jogo->get_index() == 2);
		jogo->next_player();
		CHECK(jogo->get_index() == 1);

		delete jogo;
	}

	TEST_CASE("Teste Game - Caso Também Muito Mais Complicado") {
		Game *jogo = new Game();
		jogo->start(3);
		jogo->generate_hand();
		std::shared_ptr<Card> carta(new Card("SBB"));

		jogo->stack->receive_card(carta);
		jogo->next_player();
		jogo->apply_effect();
		CHECK(jogo->get_index() == 2);

		delete jogo;
	}

	TEST_CASE("Teste Stack - Casos Mais complicado") {
		Stack *pilha = new Stack();
		std::shared_ptr<Card> carta(new Card("NY3"));
		pilha->receive_card(carta);

		CHECK(pilha->show_last_card() == "NY3");

		delete pilha;
	}

	TEST_CASE("Teste Stack e Pack - Casos Bem Mais complicado") {
		Game *jogo = new Game();
		jogo->stack->receive_card(jogo->pack->return_first());
		jogo->pack->remove_first();

		jogo->stack->receive_card(jogo->pack->return_first());
		jogo->pack->remove_first();

		CHECK(jogo->pack->get_number_of_cards() == 110);
		jogo->stack->return_to_pack(jogo->pack);
		CHECK(jogo->pack->get_number_of_cards() == 111);

		delete jogo;
	}



	TEST_CASE("Teste Game e Color - Casos complicado") {
		Game *jogo = new Game();
		jogo->set_color("NG4");
		CHECK(jogo->get_color() == 'G');

		delete jogo;


		// jogo->start(2);
		// jogo->generate_hand();
		// std::shared_ptr<Card> carta = jogo->players[0]->send_card(0);
		// std::string s = carta->get_value();
    // jogo->set_color("NG5");
		// CHECK(jogo->check_move(carta, s, 0) == "TESTE DO THROW AQUI");
	}

	TEST_CASE("Teste Game - Caso Basico") {
		Game *jogo = new Game();
		jogo->start(3);
		jogo->generate_hand();
		std::shared_ptr<Card> carta(new Card("NR0"));

		jogo->stack->receive_card(carta);
		jogo->next_player();
		jogo->apply_effect();
		CHECK(jogo->get_index() == 1);

		delete jogo;
	}

	TEST_CASE("Teste Game - Caso Também Muito Mais Complicado") {
		Game *jogo = new Game();
		jogo->start(3);
		jogo->generate_hand();
		std::shared_ptr<Card> carta(new Card("SRE"));

		jogo->stack->receive_card(carta);
		jogo->apply_effect();
		CHECK(jogo->players[1]->hand_size() == 9);

		delete jogo;
	}

	TEST_CASE("Teste Game - Caso Também Muito Mais Complicado") {
		Game *jogo = new Game();
		delete jogo;
		CHECK(true);
	}

	TEST_CASE("Teste Game - Caso Também Muito Mais Complicado") {
		Game *jogo = new Game();
		jogo->start(3);
		jogo->generate_hand();
		std::shared_ptr<Card> carta(new Card("NB9"));

		CHECK_THROWS_AS(jogo->check_move(carta, "NR0", 2), Invalid_Card);

		delete jogo;
	}








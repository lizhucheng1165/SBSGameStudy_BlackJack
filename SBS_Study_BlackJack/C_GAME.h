#pragma once
#include"C_DEALER.h"
#include"C_PLAYER.h"
#include"C_DECK.h"
#include<vector>

class C_GAME
{

private:
	C_DECK m_deck;
	C_DEALER m_dealer;
	std::vector<C_PLAYER> m_players;

public:
	C_GAME();
	~C_GAME();

	void initializeGame();
	void dealInitialCards();
	void playCurrentRound();
	void determineWinner();
};


#pragma once
#include"C_DEALER.h"
#include"C_PLAYER.h"
#include"C_DECK.h"
#include<vector>

class C_GAME
{
public:
	enum E_WHOSTURN
	{
		DEALER, PLAYER
	};
	enum E_GAMESTATE
	{
		READY, PLAYING
	};
private:
	C_DECK m_deck;
	C_DEALER m_dealer;
	C_PLAYER m_player;
	E_WHOSTURN m_eWhosTurn;
	E_GAMESTATE m_eGameState;

public:
	C_GAME() = default;

	void initializeGame();
	void dealInitialCards();
	void playCurrentRound();
	void determineWinner();
	void displayCards(bool hideDealerFirstCard = true);
};


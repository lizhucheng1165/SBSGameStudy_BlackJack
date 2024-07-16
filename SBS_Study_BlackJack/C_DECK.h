#pragma once
#include<vector>
#include"C_CARD.h"

class C_DECK
{
private:
	std::vector<C_CARD> m_cards;
	

public:
	C_DECK();
	~C_DECK();

	bool shuffle();
	C_CARD dealCard();
};


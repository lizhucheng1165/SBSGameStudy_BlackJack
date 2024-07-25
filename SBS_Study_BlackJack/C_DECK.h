#pragma once
#include<vector>
#include"C_CARD.h"

class C_DECK
{
private:
	std::vector<C_CARD> m_vCards;
	

public:
	C_DECK() = default;

	bool shuffle();
	C_CARD& dealCard();
	void init();
};


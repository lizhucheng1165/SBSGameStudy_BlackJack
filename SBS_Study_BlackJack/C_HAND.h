#pragma once
#include<vector>
#include"C_CARD.h"
class C_HAND
{

private:
	std::vector<C_CARD> m_cards;
public:
	C_HAND();
	~C_HAND();

	void addCard(C_CARD card);
	int getTotalValue();
	bool isBusted();
	void clearHand();
};


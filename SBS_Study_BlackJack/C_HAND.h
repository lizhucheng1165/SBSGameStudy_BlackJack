#pragma once
#include<vector>
#include"C_CARD.h"
class C_HAND
{

private:
	std::vector<C_CARD> m_cards;
public:
	C_HAND() = default;

	void addCard(C_CARD card);
	int getTotalValue() const;
	bool isBusted();
	void clearHand();
	void init();
	int getCardCount() const;
	void displayCards() const;
};


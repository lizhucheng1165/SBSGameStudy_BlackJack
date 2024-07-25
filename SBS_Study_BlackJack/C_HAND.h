#pragma once
#include<vector>
#include"C_CARD.h"
class C_HAND
{

private:
	std::vector<C_CARD> m_vCards;
public:
	C_HAND() = default;

	void addCard(const C_CARD& cCard);
	int getTotalValue() const;
	bool isBusted();
	void clearHand();
	void init();
	int getCardCount() const;
	void displayCards(bool bHideFirstCard, bool bShowTotal, bool bShowHiddenTotal) const;
};


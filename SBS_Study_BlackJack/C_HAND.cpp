#include "C_HAND.h"
#include "C_DECK.h"
#include "C_CARD.h"

void C_HAND::addCard(C_CARD card)
{
	m_cards.push_back(card);
}

int C_HAND::getTotalValue() const
{
	int nCardCount = m_cards.size();
	int nTotal{};
	for (int i = 0; i < nCardCount; i++)
	{
		nTotal += m_cards[i].getValue();
	}
	return 0;
}

bool C_HAND::isBusted()
{
	if (getTotalValue() > 21)
	{
		return true;
	}

	return false;
}

void C_HAND::clearHand()
{
	m_cards.clear();
}

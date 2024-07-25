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
	int nAceCount{};
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

void C_HAND::init()
{
	clearHand();
}

int C_HAND::getCardCount() const
{
	return m_cards.size();
}

void C_HAND::displayCards(bool bHideFirstCard) const
{
	for (int i = 0; i < getCardCount(); i++)
	{
		if (i == 0 && bHideFirstCard)
		{
			printf("* ");
		}
		else
		{
			printf("%d ", m_cards[i].getValue());
		}
	}
	printf("\n");
}




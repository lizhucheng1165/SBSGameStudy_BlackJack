#include "C_HAND.h"
#include "C_DECK.h"
#include "C_CARD.h"

void C_HAND::addCard(C_CARD card)
{
	m_cards.push_back(card);//여기가 문제
	printf("카드 추가됨. 현재 카드 수: %d\n", m_cards.size());
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

void C_HAND::init()
{
	clearHand();
}

int C_HAND::getCardCount() const
{
	return m_cards.size();
}

void C_HAND::displayCards() const
{
		printf("카드카운트 %d\n" , getCardCount());
	for (int i = 0; i < getCardCount(); i++)
	{
		printf("%d", m_cards[i].getValue());
	}
}



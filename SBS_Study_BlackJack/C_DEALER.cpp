#include "C_DEALER.h"

bool C_DEALER::makeDecision() const
{
	int nTotalValue = m_hand.getTotalValue();
	if (nTotalValue >= 17)
	{
		return false;
	}

	return true;
}

C_HAND C_DEALER::getHand() const
{
	return m_hand;
}

void C_DEALER::init()
{
	printf("µÙ∑Ø¿Œ¿’\n");
	m_hand.init();
}




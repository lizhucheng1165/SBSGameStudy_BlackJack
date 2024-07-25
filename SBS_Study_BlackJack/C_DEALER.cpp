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

C_HAND& C_DEALER::getHand()
{
	return m_hand;
}

void C_DEALER::init()
{
	m_hand.init();
}




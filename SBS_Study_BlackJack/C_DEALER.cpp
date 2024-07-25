#include "C_DEALER.h"

bool C_DEALER::makeDecision() const
{
	int nTotalValue = m_cHand.getTotalValue();
	if (nTotalValue >= 17)
	{
		return false;
	}

	return true;
}

C_HAND& C_DEALER::getHand()
{
	return m_cHand;
}

void C_DEALER::init()
{
	m_cHand.init();
}




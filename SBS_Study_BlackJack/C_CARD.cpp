#include "C_CARD.h"

int C_CARD::getValue() const
{
	return (int)m_eValue;
}

C_CARD::E_SUIT C_CARD::getSuit() const
{
	return m_eSuit;
}

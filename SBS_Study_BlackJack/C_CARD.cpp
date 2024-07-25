#include "C_CARD.h"

int C_CARD::getValue() const
{
	return (int)m_eValue;
}

C_CARD::E_SUIT C_CARD::getSuit() const
{
	return m_eSuit;
}

void C_CARD::init(const E_SUIT& eSuit, const E_VALUE& eValue)
{
	m_eSuit = eSuit;
	m_eValue = eValue;
}

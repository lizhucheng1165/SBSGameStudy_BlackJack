#include "C_CARD.h"

C_CARD::C_CARD(C_CARD::E_SUIT suit, C_CARD::E_VALUE value)
{
	m_eSuit = suit;
	m_eValue = value;
}

C_CARD::~C_CARD()
{

}

int C_CARD::getValue() const
{
	return (int)m_eValue;
}

C_CARD::E_SUIT C_CARD::getSuit() const
{
	return m_eSuit;
}

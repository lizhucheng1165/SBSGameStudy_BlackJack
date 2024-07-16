#pragma once

class C_CARD
{

public:
	enum E_SUIT
	{
		HEART, DIAMOND, CLUB, SPADE
	};
	enum E_VALUE
	{
		ONE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10, ACE = 11
	};

	C_CARD(E_SUIT suit,E_VALUE value);
	~C_CARD();
private:
	E_SUIT m_eSuit;
	E_VALUE m_eValue;
	
public:

	int getValue() const;
	E_SUIT getSuit() const;
	
};


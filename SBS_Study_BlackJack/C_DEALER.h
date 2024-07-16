#pragma once
#include "C_HAND.h"
class C_DEALER
{
private:
	C_HAND m_hand;
public:
	C_DEALER();
	~C_DEALER();

	bool makeDecision() const;
	void addCard(C_CARD card);
	C_HAND getHand() const;
};


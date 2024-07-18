#pragma once
#include "C_HAND.h"
class C_DEALER
{
private:
	C_HAND m_hand;
public:
	C_DEALER() = default;

	bool makeDecision() const;
	C_HAND getHand() const;
};


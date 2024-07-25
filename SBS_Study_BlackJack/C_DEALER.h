#pragma once
#include "C_HAND.h"
class C_DEALER
{
private:
	C_HAND m_cHand;
public:
	C_DEALER() = default;

	bool makeDecision() const;
	C_HAND& getHand();
	void init();
};


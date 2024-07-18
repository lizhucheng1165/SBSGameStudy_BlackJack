#pragma once
#include <string>
#include <stdio.h>
#include "C_HAND.h"
class C_PLAYER
{
private:
	C_HAND m_hand{};
	int m_nPlayerIndex;

public:
	C_PLAYER() = default;


	int getPlayerIndex() const;
	C_HAND getHand() const;
	bool makeDecision() const;
};


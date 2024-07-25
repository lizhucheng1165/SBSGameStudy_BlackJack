#pragma once
#include <string>
#include <stdio.h>
#include "C_HAND.h"
class C_PLAYER
{
private:
	C_HAND m_cHand;

public:
	C_PLAYER() = default;


	C_HAND& getHand();
	bool makeDecision() const;
	void init();
	
};


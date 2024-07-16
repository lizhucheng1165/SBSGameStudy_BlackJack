#pragma once
#include <string>
#include "C_HAND.h"
class C_PLAYER
{
private:
	C_HAND m_hand;
	int m_nPlayerIndex;

public:
	C_PLAYER(int playerIndex);
	~C_PLAYER();


	void getPlayerIndex() const;
	void getHand() const;
	std::string makeDecision() const;
};


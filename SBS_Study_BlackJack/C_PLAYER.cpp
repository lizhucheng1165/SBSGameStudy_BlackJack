#include "C_PLAYER.h"

C_PLAYER::C_PLAYER(int nPlayerIndex)
{
	m_nPlayerIndex = nPlayerIndex;
}

C_PLAYER::~C_PLAYER()
{
}

void C_PLAYER::getPlayerIndex() const
{
}

void C_PLAYER::getHand() const
{
}

std::string C_PLAYER::makeDecision() const
{
	return std::string();
}

#include "C_PLAYER.h"

C_HAND C_PLAYER::getHand() const
{
	return m_hand;
}

bool C_PLAYER::makeDecision() const
{
	int nDecisionIndex{};
	
	printf("1.Hit  2.Stand\n");
	scanf_s("%d", &nDecisionIndex);
	
	if (nDecisionIndex != 1 && nDecisionIndex != 2)
	{
		printf("입력이 잘못됐습니다. 다시 입력해주십시오\n");
		while (getchar() != '\n'); // 입력 버퍼 비우기
		return false;
	}
	if (nDecisionIndex == 1)
	{
		return true;
	}

	return false;
}

void C_PLAYER::init()
{
	printf("플레이어 인잇\n");
	m_hand.init();
}

#include "C_PLAYER.h"


int C_PLAYER::getPlayerIndex() const
{
	return m_nPlayerIndex;
}

C_HAND C_PLAYER::getHand() const
{
	return m_hand;
}

bool C_PLAYER::makeDecision() const
{
	int nDecisionIndex{};
	
	printf("1.Hit  2.Stand");
	scanf_s("%d", &nDecisionIndex);
	while (nDecisionIndex != 1 && nDecisionIndex != 2)
	{
		printf("�Է��� �߸��ƽ��ϴ�. �ٽ� �Է����ֽʽÿ�");
		printf("1.Hit  2.Stand");
		scanf_s("%d", &nDecisionIndex);
	}
	if (nDecisionIndex == 1)
	{
		return true;
	}


	return false;
}

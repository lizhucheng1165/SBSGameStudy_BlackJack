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
		printf("�Է��� �߸��ƽ��ϴ�. �ٽ� �Է����ֽʽÿ�\n");
		while (getchar() != '\n'); // �Է� ���� ����
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
	printf("�÷��̾� ����\n");
	m_hand.init();
}

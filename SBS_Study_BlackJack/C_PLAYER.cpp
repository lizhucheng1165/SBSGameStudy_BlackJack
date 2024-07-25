#include "C_PLAYER.h"

C_HAND& C_PLAYER::getHand()
{
    return m_hand;
}

bool C_PLAYER::makeDecision() const
{
    int nDecisionIndex{};

    printf("1. Hit  2. Stand\n");
    scanf_s("%d", &nDecisionIndex);

    while (nDecisionIndex != 1 && nDecisionIndex != 2)
    {
        printf("잘못된 입력입니다 1또는 2를 입력해주세요.\n");
        while (getchar() != '\n');
        scanf_s("%d", &nDecisionIndex);
    }

    return nDecisionIndex == 1;
}

void C_PLAYER::init()
{
    m_hand.init();
}

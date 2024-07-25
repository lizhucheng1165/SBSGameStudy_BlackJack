#include "C_PLAYER.h"

C_HAND& C_PLAYER::getHand()
{
    return m_cHand;
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
    if (nDecisionIndex == 1)
    {
        return true;
    }

    return false;
}

void C_PLAYER::init()
{
    m_cHand.init();
}

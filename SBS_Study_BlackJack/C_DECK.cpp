#include "C_DECK.h"
#include <random>

C_DECK::C_DECK()
{
}

C_DECK::~C_DECK()
{
}

bool C_DECK::shuffle()
{
    int nCardCount = m_cards.size();

    //카드 갯수가 1이하라면 셔플할 필요가 없다
    if (nCardCount <= 1) 
    {
        //예외처리 피드백
        return false;
    }

    // 무작위 숫자 생성을 위한 장치와 엔진 초기화
    std::random_device randomDevice;   // 무작위 시드
    std::mt19937 randomEngine(randomDevice());  // Mersenne Twister 엔진

    // 특정 범위 내에서 무작위 숫자를 생성하기 위한 분포 정의
    std::uniform_int_distribution<> distribution(0, nCardCount - 1);

    //0번 인덱스부터 cards의 마지막 인덱스까지 반복
    for (int i = 0; i < nCardCount; i++)
    {
        // 무작위 인덱스 생성
        int nRandomNumber = distribution(randomEngine);

        // 현재 인덱스와 무작위 인덱스의 요소를 교환
        std::swap(m_cards[i], m_cards[nRandomNumber]);
    }

    return true;
}


C_CARD C_DECK::dealCard()
{
	return 	m_cards.back();
}

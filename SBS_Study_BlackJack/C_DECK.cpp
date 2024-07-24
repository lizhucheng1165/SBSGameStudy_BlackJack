#include "C_DECK.h"
#include <random>

bool C_DECK::shuffle()
{
    printf("셔플\n");
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
    /*printf("0번째 카드 : %d\n", m_cards[0].getValue());
    printf("1번째 카드 : %d\n", m_cards[1].getValue());*/
    
    return true;
}


C_CARD C_DECK::dealCard()
{
    C_CARD cardToDeal = m_cards.back();
    m_cards.pop_back();
	return 	cardToDeal;
}

void C_DECK::init()
{
    printf("덱 인잇\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            C_CARD card{};
            C_CARD::E_SUIT suit = (C_CARD::E_SUIT)i;
            C_CARD::E_VALUE value = (C_CARD::E_VALUE)j;
            card.init(suit, value);
            m_cards.push_back(card);
            //printf("suit : %d, Value : %d\n", suit, value);
        }
    }
}



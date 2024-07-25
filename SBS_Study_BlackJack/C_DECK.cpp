#include "C_DECK.h"
#include <random>

bool C_DECK::shuffle()
{
    int nCardCount = m_vCards.size();

    //카드 갯수가 1이하라면 셔플할 필요가 없다
    if (nCardCount <= 1) 
    {
        printf("카드 갯수가 1 이하이므로 셔플이 필요 없습니다");
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
        std::swap(m_vCards[i], m_vCards[nRandomNumber]);
    }

    
    return true;
}


C_CARD& C_DECK::dealCard()
{
    C_CARD cardToDeal = m_vCards.back();
    m_vCards.pop_back();
	return 	cardToDeal;
}

void C_DECK::init()
{
    for (int i = 0; i < 4; i++)
    {
        C_CARD::E_SUIT eSuit = (C_CARD::E_SUIT)i;
        for (int j = 2; j <= 10; j++)
        {
            //숫자카드추가
            C_CARD card{};
            C_CARD::E_VALUE value = (C_CARD::E_VALUE)j;
            card.init(eSuit, value);
            m_vCards.push_back(card);
        }

        //그림카드추가
        C_CARD faceCard;

        faceCard.init(eSuit, C_CARD::JACK);
        m_vCards.push_back(faceCard);

        faceCard.init(eSuit, C_CARD::QUEEN);
        m_vCards.push_back(faceCard);

        faceCard.init(eSuit, C_CARD::KING);
        m_vCards.push_back(faceCard);

        faceCard.init(eSuit, C_CARD::ACE);
        m_vCards.push_back(faceCard);
    }
}



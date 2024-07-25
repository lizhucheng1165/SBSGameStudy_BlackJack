#include "C_DECK.h"
#include <random>

bool C_DECK::shuffle()
{
    int nCardCount = m_cards.size();

    //ī�� ������ 1���϶�� ������ �ʿ䰡 ����
    if (nCardCount <= 1) 
    {
        //����ó�� �ǵ��
        return false;
    }

    // ������ ���� ������ ���� ��ġ�� ���� �ʱ�ȭ
    std::random_device randomDevice;   // ������ �õ�
    std::mt19937 randomEngine(randomDevice());  // Mersenne Twister ����

    // Ư�� ���� ������ ������ ���ڸ� �����ϱ� ���� ���� ����
    std::uniform_int_distribution<> distribution(0, nCardCount - 1);

    //0�� �ε������� cards�� ������ �ε������� �ݺ�
    for (int i = 0; i < nCardCount; i++)
    {
        // ������ �ε��� ����
        int nRandomNumber = distribution(randomEngine);

        // ���� �ε����� ������ �ε����� ��Ҹ� ��ȯ
        std::swap(m_cards[i], m_cards[nRandomNumber]);
    }

    
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
    for (int i = 0; i < 4; i++)
    {
        C_CARD::E_SUIT suit = (C_CARD::E_SUIT)i;
        for (int j = 1; j < 11; j++)
        {
            C_CARD card{};
            C_CARD::E_VALUE value = (C_CARD::E_VALUE)j;
            card.init(suit, value);
            m_cards.push_back(card);
        }

        C_CARD faceCard{};
        faceCard.init(suit, C_CARD::JACK);
        m_cards.push_back(faceCard);
        faceCard.init(suit, C_CARD::QUEEN);
        m_cards.push_back(faceCard);
        faceCard.init(suit, C_CARD::KING);
        m_cards.push_back(faceCard);
    }
}



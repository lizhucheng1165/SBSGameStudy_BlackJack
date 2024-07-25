#include "C_DECK.h"
#include <random>

bool C_DECK::shuffle()
{
    int nCardCount = m_vCards.size();

    //ī�� ������ 1���϶�� ������ �ʿ䰡 ����
    if (nCardCount <= 1) 
    {
        printf("ī�� ������ 1 �����̹Ƿ� ������ �ʿ� �����ϴ�");
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
            //����ī���߰�
            C_CARD card{};
            C_CARD::E_VALUE value = (C_CARD::E_VALUE)j;
            card.init(eSuit, value);
            m_vCards.push_back(card);
        }

        //�׸�ī���߰�
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



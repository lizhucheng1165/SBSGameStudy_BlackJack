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
	return 	m_cards.back();
}

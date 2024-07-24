#include"C_GAME.h"



void C_GAME::initializeGame()
{
	printf("�̴ϼȶ����� ����\n");
	//���ʱ�ȭ
	m_deck.init();
	//������
	m_deck.shuffle();
	//���� �ʱ�ȭ
	m_dealer.init();
	//�÷��̾� �ʱ�ȭ
	m_player.init();
	//���� �� = �÷��̾�
	m_eWhosTurn = PLAYER;
	m_eGameState = PLAYING;
}

void C_GAME::dealInitialCards()
{
	for (int i = 0; i < 2; i++)
	{
		m_player.getHand().addCard(m_deck.dealCard());
		m_dealer.getHand().addCard(m_deck.dealCard());

	}
}

void C_GAME::playCurrentRound()
{
	//initī�� �����ֱ�
	dealInitialCards();
	m_dealer.getHand().displayCards();
	//�÷��̾� ����
	while (m_eWhosTurn == PLAYER)
	{

		//hit -> �÷��̾� ī���߰�
		if (m_player.makeDecision())
		{
			m_player.getHand().addCard(m_deck.dealCard());
			determineWinner();
		}
	}
	//stand -> ������
	while (m_dealer.makeDecision())
	{
		m_dealer.getHand().addCard(m_deck.dealCard());
		m_dealer.getHand().displayCards();
	}
	determineWinner();
}

void C_GAME::determineWinner()
{
	int nPlayerTotal = m_player.getHand().getTotalValue();
	int nDealerTotal = m_dealer.getHand().getTotalValue();

	//�÷��̾ 21�� ���� -> �й�
	if (m_player.getHand().isBusted())
	{
		printf("�÷��̾� �й�");
		m_eGameState = READY;
	}
	else if (m_dealer.getHand().isBusted())
	{
		printf("�÷��̾� �¸�");
		m_eGameState = READY;
	}
	else if (nPlayerTotal > nDealerTotal)
	{
		printf("�÷��̾� �¸�");
		m_eGameState = READY;
	}
	else
	{
		printf("�÷��̾� �й�");
		m_eGameState = READY;
	}
}



#include"C_GAME.h"



void C_GAME::initializeGame()
{
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
	//m_dealer.getHand().displayCards();
	//�÷��̾� ����
	while (m_eWhosTurn == PLAYER)
	{
		displayCards();
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
		displayCards();
		m_dealer.getHand().addCard(m_deck.dealCard());
		//m_dealer.getHand().displayCards();
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
		printf("�÷��̾� �й�1");
		m_eGameState = READY;
	}
	else if (m_dealer.getHand().isBusted())
	{
		printf("�÷��̾� �¸�1");
		m_eGameState = READY;
	}
	else if (nPlayerTotal > nDealerTotal)
	{
		printf("�÷��̾� �¸�2");
		m_eGameState = READY;
	}
	else
	{
		printf("�÷��̾� �й�2");
		m_eGameState = READY;
	}
}

void C_GAME::displayCards(bool hideDealerFirstCard)
{
	printf("Dealer's cards: ");
	m_dealer.getHand().displayCards(hideDealerFirstCard);
	printf("Player's cards: ");
	m_player.getHand().displayCards(false);
}





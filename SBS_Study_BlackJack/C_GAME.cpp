#include"C_GAME.h"



void C_GAME::initializeGame()
{
	//���ʱ�ȭ
	m_cDeck.init();
	//������
	m_cDeck.shuffle();
	//���� �ʱ�ȭ
	m_cDealer.init();
	//�÷��̾� �ʱ�ȭ
	m_cPlayer.init();
	//���� �� = �÷��̾�
	m_eWhosTurn = PLAYER;
	m_eGameState = PLAYING;
}

void C_GAME::dealInitialCards()
{
	for (int i = 0; i < 2; i++)
	{
		C_CARD cPlayerCard = m_cDeck.dealCard();
		C_HAND& cPlayerHand = m_cPlayer.getHand();
		cPlayerHand.addCard(cPlayerCard);

		C_CARD cDealerCard = m_cDeck.dealCard();
		C_HAND& cDealerHand = m_cDealer.getHand();
		cDealerHand.addCard(cDealerCard);
	}
}

void C_GAME::playCurrentRound()
{
	dealInitialCards();
	displayCards(true);

	while (m_eWhosTurn == PLAYER)
	{
		if (m_cPlayer.makeDecision())
		{
			C_CARD cNewCard = m_cDeck.dealCard();
			C_HAND& cPlayerHand = m_cPlayer.getHand();
			cPlayerHand.addCard(cNewCard);
			displayCards(true);
			if (cPlayerHand.isBusted())
			{
				determineWinner();
				return;
			}
		}
		else
		{
			m_eWhosTurn = DEALER;
		}
	}

	displayCards(false);
	while (m_eWhosTurn == DEALER)
	{
		if (m_cDealer.makeDecision())
		{
			C_CARD cNewCard = m_cDeck.dealCard();
			C_HAND& cDealerHand = m_cDealer.getHand();
			cDealerHand.addCard(cNewCard);
			displayCards(false);
			if (cDealerHand.isBusted())
			{
				determineWinner();
				return;
			}
		}
		else
		{
			break;
		}
	}
	determineWinner();
}



void C_GAME::determineWinner()
{
	C_HAND& cPlayerHand = m_cPlayer.getHand();
	C_HAND& cDealerHand = m_cDealer.getHand();
	int nPlayerTotal = cPlayerHand.getTotalValue();
	int nDealerTotal = cDealerHand.getTotalValue();


	//�÷��̾ 21�� ���� -> �й�
	if (cPlayerHand.isBusted())
	{
		printf("�÷��̾� �й�\n");
		m_eGameState = READY;
	}
	else if (cDealerHand.isBusted())
	{
		printf("�÷��̾� �¸�\n");
		m_eGameState = READY;
	}
	else if (nPlayerTotal > nDealerTotal)
	{
		printf("�÷��̾� �¸�\n");
		m_eGameState = READY;
	}
	else
	{
		printf("�÷��̾� �й�\n");
		m_eGameState = READY;
	}
}

void C_GAME::displayCards(bool bHideDealerFirstCard)
{
	bool bHideFirstCard = bHideDealerFirstCard;
	bool bShowTotal = !bHideDealerFirstCard;
	bool bShowHidden = bHideDealerFirstCard;
	printf("Dealer's cards: ");
	m_cDealer.getHand().displayCards(bHideFirstCard, bShowTotal, bShowHidden);
	printf("Player's cards: ");
	m_cPlayer.getHand().displayCards(false, true,false);
}





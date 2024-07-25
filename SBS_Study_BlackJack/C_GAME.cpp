#include"C_GAME.h"



void C_GAME::initializeGame()
{
	//덱초기화
	m_deck.init();
	//덱셔플
	m_deck.shuffle();
	//딜러 초기화
	m_dealer.init();
	//플레이어 초기화
	m_player.init();
	//시작 턴 = 플레이어
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
	dealInitialCards();
	displayCards(true);

	while (m_eWhosTurn == PLAYER)
	{
		if (m_player.makeDecision())
		{
			m_player.getHand().addCard(m_deck.dealCard());
			displayCards(true);
			if (m_player.getHand().isBusted())
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
		if (m_dealer.makeDecision())
		{
			m_dealer.getHand().addCard(m_deck.dealCard());
			displayCards(false);
			if (m_dealer.getHand().isBusted())
			{
				determineWinner();
				return;
			}
		}
		else
		{
			m_eWhosTurn = PLAYER; // To exit the loop
			break;
		}
	}
	determineWinner();
}



void C_GAME::determineWinner()
{
	int nPlayerTotal = m_player.getHand().getTotalValue();
	int nDealerTotal = m_dealer.getHand().getTotalValue();

	//플레이어가 21이 넘음 -> 패배
	if (m_player.getHand().isBusted())
	{
		printf("플레이어 패배1");
		m_eGameState = READY;
	}
	else if (m_dealer.getHand().isBusted())
	{
		printf("플레이어 승리1");
		m_eGameState = READY;
	}
	else if (nPlayerTotal > nDealerTotal)
	{
		printf("플레이어 승리2");
		m_eGameState = READY;
	}
	else
	{
		printf("플레이어 패배2");
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





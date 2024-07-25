#include "C_HAND.h"
#include "C_DECK.h"
#include "C_CARD.h"

void C_HAND::addCard(const C_CARD& cCard)
{
	m_vCards.push_back(cCard);
}

int C_HAND::getTotalValue() const
{
	const int nAceValue = 11;
	const int nAceReductionValue = 10;
	const int nBustThreshold = 21;

	int nTotal = 0;
	int nAces = 0;

	for (const auto& cCard : m_vCards)
	{
		int nValue = cCard.getValue();
		if (nValue == nAceValue)
		{
			++nAces;
		}
		nTotal += nValue;
	}
	
	while (nTotal > nBustThreshold && nAces > 0)
	{
		nTotal -= nAceReductionValue;
		--nAces;
	}

	return nTotal;
}


bool C_HAND::isBusted()
{
	if (getTotalValue() > 21)
	{
		return true;
	}

	return false;
}

void C_HAND::clearHand()
{
	m_vCards.clear();
}

void C_HAND::init()
{
	clearHand();
}

int C_HAND::getCardCount() const
{
	return (int)m_vCards.size();
}

/// <summary>
/// ���� ī�� ��Ȳ�� �����ش�
/// </summary>
/// <param name="bHideFirstCard"></param> ������ ù��° ī�� �����
/// <param name="bShowTotal"></param> ������ Total �����ֱ�
/// <param name="bShowHiddenTotal"></param> ������ -> ������ total ����
void C_HAND::displayCards(bool bHideFirstCard, bool bShowTotal, bool bShowHiddenTotal) const
{
	int nCardCount = getCardCount();
	for (int i = 0; i < nCardCount; ++i)
	{
		if (i == 0 && bHideFirstCard)
		{
			printf("* ");
		}
		else
		{
			int nCardValue = m_vCards[i].getValue();
			// Ace�� 11�� �ƴ� 1�� ǥ�õǵ��� ó��
			if (nCardValue == 11)
			{
				nCardValue = 1;
			}
			printf("%d ", nCardValue);
		}
	}

	if (bShowTotal)
	{
		int nTotalValue = getTotalValue();
		printf("  Total: %d", nTotalValue);
	}
	else if (bShowHiddenTotal)
	{
		printf("  Total: ???");
	}
	printf("\n");
}




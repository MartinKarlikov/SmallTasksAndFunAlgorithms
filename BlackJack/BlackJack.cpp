#include <vector>
#include <iostream>

const unsigned minNeededCards = 4;

int getScore(const unsigned playerScore, const unsigned dealerScore)
{

	if ((playerScore > dealerScore || dealerScore > 21) && playerScore <= 21)
	{
		return 1;
	}
	else if (playerScore > 21 && dealerScore <= 21 || dealerScore > playerScore)
	{
		return -1;
	}
	else
	{
		return 0;
	}

}

int bestBlackJackScore(const std::vector<unsigned>& deck, unsigned currPos)
{

	if (deck.size() - currPos < minNeededCards)
	{
		return 0;
	}

	unsigned playerCardOne = deck[currPos], playerCardTwo = deck[currPos + 1];

	unsigned dealerCardOne = deck[currPos + 2], dealerCardTwo = deck[currPos + 3];

	unsigned playerScore = playerCardOne + playerCardTwo;

	unsigned dealerScore = dealerCardOne + dealerCardTwo;

	currPos += 4;

	int bestSoFar = getScore(playerScore,dealerScore);

	for (size_t i = 0; i + currPos < deck.size(); ++i)
	{

		int currBest = 0;

		unsigned newCurrPos = currPos;

		unsigned addedPlayerScore = playerScore;

		unsigned addedDealerScore = dealerScore;

		for (size_t j = 0; j < i && addedPlayerScore < 21 && newCurrPos<deck.size(); ++j)
		{
			addedPlayerScore += deck[newCurrPos];
			newCurrPos++;
		}

		while (addedDealerScore <= 16 && newCurrPos < deck.size())
		{
			addedDealerScore += deck[newCurrPos];
			newCurrPos++;
		}

		currBest = getScore(addedPlayerScore, addedDealerScore) + bestBlackJackScore(deck, newCurrPos);

		if (currBest > bestSoFar)
		{
			bestSoFar = currBest;
		}

	}

	return bestSoFar;

}

int main()
{
	std::vector<unsigned> deck{ 2,1,1,10,10,4,5,6,10,5,3,7,8,9 };

	std::cout << bestBlackJackScore(deck, 0) << std::endl;
}
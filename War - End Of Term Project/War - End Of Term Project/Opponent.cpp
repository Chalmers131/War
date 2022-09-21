#include "Opponent.h"
#include <iostream>

using namespace std;

constexpr int firstCard = 0;

Opponent::Opponent()
{

}

int Opponent::PlayCard(int* opponentDeck, int playedCardsCount, int* playedCardsArray)
{
	int playedCard = opponentDeck[firstCard];

	cout << playedCard;

	opponentDeck[firstCard] = 0;

	for (int i = 0; i < cardCount - 1; i++)
	{
		opponentDeck[i] = opponentDeck[i + 1];
	}

	int lastCard = cardCount - 1;

	opponentDeck[lastCard] = 0;

	playedCardsArray[playedCardsCount] = playedCard;

	cardCount -= 1;

	return playedCard;
}
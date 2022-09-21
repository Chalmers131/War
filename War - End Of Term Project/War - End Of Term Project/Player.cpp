#include "Player.h"
#include "Dealer.h"
#include <iostream>

using namespace std;

constexpr int firstCard = 0;

Player::Player()
{

}

Player::~Player()
{

}

int Player::PlayCard(int* PlayerDeck, int playedCardsCount, int* playedCardsArray)
{
	int playedCard = PlayerDeck[firstCard];

	cout << playedCard;

	PlayerDeck[firstCard] = 0;

	for (int i = 0; i < cardCount - 1; i++)
	{
		PlayerDeck[i] = PlayerDeck[i + 1];
	}

	int lastCard = cardCount - 1;

	PlayerDeck[lastCard] = 0;

	playedCardsArray[playedCardsCount] = playedCard;

	cardCount -= 1;

	return playedCard;
}
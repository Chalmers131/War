#pragma once

class Player
{
public:
	int cardCount = 26;

	Player();

	~Player();

	int PlayCard(int* PlayerDeck, int playedCardsCount, int* playedCardsArray);
};

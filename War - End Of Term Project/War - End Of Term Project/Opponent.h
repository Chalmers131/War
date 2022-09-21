#pragma once

class Opponent
{
public:
	int cardCount = 26;

	Opponent();

	int PlayCard(int* opponentDeck, int playedCardsCount, int* playedCardsArray);
};

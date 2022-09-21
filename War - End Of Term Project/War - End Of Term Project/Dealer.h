#pragma once

class Dealer
{
public:
	int playedCardsCount = 0;
	int playerCard = 0;
	int opponentCard = 0;
	int playedCards[6] = {0, 0, 0, 0, 0, 0};

	Dealer();

	~Dealer();

	void BuildDeck(int* DeckOfCards);

	void DealCards(int* DeckOfCards, int* newHand);

	bool CheckDraw();

	bool CheckHigher();

	bool CheckReady();

	bool CheckWinner(int playerCardCount, int opponentCardCount);

	void Shuffle(int* Deck, int deckCardCount);

};

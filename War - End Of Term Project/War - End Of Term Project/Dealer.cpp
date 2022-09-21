#include "Dealer.h"
#include "Player.h"
#include "Opponent.h"
#include <iostream>
#include <time.h>

using namespace std;

constexpr int SizeOfDeck = 52;
constexpr int HalfOfDeck = 26;

Dealer::Dealer()
{

}

Dealer::~Dealer()
{

}

bool Dealer::CheckDraw()
{
	return playerCard == opponentCard;
}

bool Dealer::CheckHigher()
{
	return playerCard > opponentCard;
}

bool Dealer::CheckWinner(int playerCardCount, int opponentCardCount)
{
	if (playerCardCount == SizeOfDeck || opponentCardCount == SizeOfDeck)
	{
		return true;
	}
	return false;
}

bool Dealer::CheckReady()
{
	int input;
	bool isReady = false;
	do
	{
		cout << "Are you ready to continue? " << endl;
		cout << "1 for Yes, 2 for No: ";
		cin >> input;

		//validate the input
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(99, '\n');
			system("cls");
			cout << "That is not a number!" << endl;
		}
		else if (input == 1)
		{
			isReady = true;
		}
		else if (input == 2)
		{
			isReady = false;
			system("cls");
		}
		else
		{
			system("cls");
			cout << "Input was invalid. Try Again." << endl;
			isReady = false;
		}
	}
	while (isReady == false);

	return true;
}

void Dealer::BuildDeck(int* DeckOfCards)
{
	int cardIndex = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int c = 1; c < 14; c++)
		{
			DeckOfCards[cardIndex] = c;
			cardIndex++;
		}
	}

}

void Dealer::DealCards(int* DeckOfCards, int* newDeck)
{
	int cardCount = 0;

	srand((unsigned)time(0));

	int randomNumber;

	while (cardCount < HalfOfDeck)
	{
		randomNumber = rand() % SizeOfDeck;
		int index = randomNumber;

		int card;
		if (DeckOfCards[index] != 0)
		{
			card = DeckOfCards[index];
			newDeck[cardCount] = card;
			DeckOfCards[index] = 0;
			cardCount += 1;
		}
		else
		{
			for (int i = index + 1; i < SizeOfDeck; i++)
			{
				if (DeckOfCards[i] != 0)
				{
					card = DeckOfCards[i];
					newDeck[cardCount] = card;
					DeckOfCards[i] = 0;
					cardCount += 1;
					break;
				}
			}
		}
	}

	for (int i = HalfOfDeck; i < 51; i++)
	{
		newDeck[i] = 0;
	}
}

void Dealer::Shuffle(int* Deck, int deckCardCount)
{
	int tempDeck[SizeOfDeck] = {0};

	int tempcardCount = 0;

	srand((unsigned)time(0));

	int randomNumber;

	while (tempcardCount < deckCardCount)
	{
		randomNumber = rand() % deckCardCount;
		int index = randomNumber;

		int tempCard = Deck[index];

		int card;
		if (Deck[index] != 0)
		{
			card = Deck[index];
			tempDeck[tempcardCount] = card;
			Deck[index] = 0;
			tempcardCount += 1;
		}
		else
		{
			for (int i = index + 1; i < deckCardCount; i++)
			{
				if (Deck[i] != 0)
				{
					card = Deck[i];
					tempDeck[tempcardCount] = card;
					Deck[i] = 0;
					tempcardCount += 1;
					break;
				}
			}
		}
	}

	for (int i = 0; i < SizeOfDeck; i++)
	{
		Deck[i] = tempDeck[i];
	}
}
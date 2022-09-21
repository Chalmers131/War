#include <iostream>
#include <time.h>
#include "Dealer.h"
#include "Player.h"
#include "Opponent.h"
#include "Machine.h"

using namespace std;

enum MenuCases {
	PlayGame = 1,
	ExitGame
};

enum RestartCases {
	Restart = 1,
	EndGame
};

enum WinCases {
	PlayerWin = 1,
	OpponentWin
};

enum AutoPlayCases {
	AutoPlay = 1,
	NoAutoPlay,
};

constexpr int SizeOfDeck = 52;
constexpr int HalfOfDeck = 26;

int main()
{
	bool playAgain = false;
	bool autoPlay = false;
	bool fullAutoGame = false;
	do{
		playAgain = false;
	Dealer* dealer = new Dealer();
	Player* player = new Player();
	Player* opponent = new Player();
	//Opponent* opponent = new Opponent();
	Machine* machine = new Machine();

	//Opening Sequence

	int input = machine -> OpeningSequence(PlayGame, ExitGame);	

	switch (input)
	{
	case PlayGame:
	{
		//Setup Cards
		system("cls");

		int DeckOfCards[SizeOfDeck];

		int playerCards[SizeOfDeck] = { 0 };
		int opponentCards[SizeOfDeck] = { 0 };

		dealer->BuildDeck(DeckOfCards);

		//Deal Cards
		int cardCount = 0;
		dealer->DealCards(DeckOfCards, playerCards);
		dealer->DealCards(DeckOfCards, opponentCards);

		//Start Game Loop
		bool isWinner = false;
		int roundCount = 1;
		do
		{
			if (roundCount % 5 == 0)
			{
				cout << roundCount << " rounds have passed, SHUFFLE!" << endl;
				//make each deck shuffle

				dealer->Shuffle(playerCards, player->cardCount);
				dealer->Shuffle(opponentCards, opponent->cardCount);

				cout << endl;
				cout << "Current Player Card Count: " << player->cardCount << endl;
				cout << "Current Opponent Card Count: " << opponent->cardCount << endl;
				cout << endl;

				int autoPlayInput;
				machine->AskForAutoPlay();
				autoPlayInput = machine->GetInput();
				machine->ValidateIntegerInput(input, AutoPlay, NoAutoPlay);

				if (autoPlayInput == AutoPlay)
				{
					autoPlay = true;
				}
				else {
					autoPlay = false;
				}

				system("cls");
			}

			cout << "Round " << roundCount << endl;
			cout << endl;

			bool isDraw = false;
			int isDrawCount = 0;
			do
			{
				if (isDrawCount == 3)
				{
					cout << "Three draws" << endl;
					break;
				}
				cout << "Player Card: ";
				dealer->playerCard = player->PlayCard(playerCards, dealer->playedCardsCount, dealer->playedCards);
				dealer->playedCardsCount += 1;
				cout << endl;

				cout << "Opponent Card: ";
				dealer->opponentCard = opponent->PlayCard(opponentCards, dealer->playedCardsCount, dealer->playedCards);
				dealer->playedCardsCount += 1;
				cout << endl;

				for (int i = 0; i < dealer->playedCardsCount; i++)
				{
					cout << dealer->playedCards[i] << ", ";
				}
				cout << endl;
				cout << endl;

				//If draw go back to Start of Loop

				isDraw = dealer->CheckDraw();
				if (isDraw == true)
				{
					system("cls");
					isDrawCount += 1;
				}
			} while (isDraw == true);
			//Check if one is higher than the other

			bool isPlayerWinner = dealer->CheckHigher();
			if (isPlayerWinner)
			{
				//Player win
				cout << "Player Won The Round" << endl;
				for (int i = 0; i < dealer->playedCardsCount; i++)
				{
					if (dealer->playedCards[i] > 0)
					{
						int nextOpenSlot = player->cardCount;
						playerCards[nextOpenSlot] = dealer->playedCards[i];
						dealer->playedCards[i] = 0;
						player->cardCount += 1;
					}
				}
				cout << "Players Cards: ";
				for (int i = 0; i < SizeOfDeck; i++)
				{
					if (playerCards[i] == 0)
					{
						break;
					}
					cout << playerCards[i] << " ";
				}
				cout << endl;

				cout << "Players Card Count: " << player->cardCount << endl;

				dealer->playedCardsCount = 0;

				cout << endl;
				if (!autoPlay)
				{
					dealer->CheckReady();
				}

				system("cls");

				//break;
			}
			else
			{
				//Opponent win
				cout << "Opponent Won The Round" << endl;
				for (int i = 0; i < dealer->playedCardsCount; i++)
				{
					if (dealer->playedCards[i] != 0)
					{
						int nextOpenSlot = opponent->cardCount;
						opponentCards[nextOpenSlot] = dealer->playedCards[i];
						dealer->playedCards[i] = 0;
						opponent->cardCount += 1;
					}
				}
				cout << "Opponents Cards: ";
				for (int i = 0; i < SizeOfDeck; i++)
				{
					if (opponentCards[i] == 0)
					{
						break;
					}
					cout << opponentCards[i] << " ";
				}
				cout << endl;

				cout << "Opponent Card Count: " << opponent->cardCount << endl;

				dealer->playedCardsCount = 0;

				cout << endl;
				if (!autoPlay)
				{
					dealer->CheckReady();
				}
				system("cls");

				//break;
			}
			//If one players points = 52, End Loop

			isWinner = dealer->CheckWinner(player->cardCount, opponent->cardCount);
			roundCount += 1;
		} while (isWinner != true);

		if (player->cardCount == SizeOfDeck)
		{
			cout << "You won after " << roundCount << " rounds." << endl;
			cout << endl;
		}
		else
		{
			cout << "You lost after " << roundCount << " rounds." << endl;
			cout << endl;
		}

		//Ask for Restart
		int input;
		machine->AskForRestart();
		input = machine->GetInput();
		machine->ValidateIntegerInput(input, Restart, EndGame);

		if (input == Restart)
		{
			playAgain = true;
			system("cls");
		}

		break;
	}
	case ExitGame:
	{
		cout << "Exiting now. Goodbye." << endl;
		break;
	}
	default:
		cout << "Something went wrong. Exiting now. Goodbye." << endl;
		break;
	}

	}while (playAgain);

	cout << "Goodbye!" << endl;
}
#include "Machine.h"
#include <iostream>

using namespace std;

Machine::Machine()
{

}

Machine::~Machine()
{

}

int Machine::OpeningSequence(int low, int high)
{
	int input;

		DisplayIntro();

		input = GetInput();

		ValidateIntegerInput(input, low, high);

	return input;
}

void Machine::DisplayIntro()
{
	cout << "Welcome to WAR!" << endl;
	cout << endl;

	cout << "1) Play" << endl;
	cout << "2) Exit" << endl;
	cout << endl;

	cout << "(Please enter a 1 or 2.)";
}

int Machine::GetInput()
{
	int tempInput;
	cin >> tempInput;
	return tempInput;
}

void Machine::AskForRestart()
{
	cout << "Would you like to play again? " << endl;
	cout << "1) Yes" << endl;
	cout << "2) No" << endl;
	cout << "(Type 1 for Yes or 2 for No)" << endl;
}

void Machine::AskForAutoPlay()
{
	cout << "Would you like to automatically continue the rounds? " << endl;
	cout << "(You wont have to confirm for the next round to start.)" << endl;
	cout << "1) Yes" << endl;
	cout << "2) No" << endl;
	cout << "(Type 1 for Yes or 2 for No.)" << endl;
}

void Machine::ValidateIntegerInput(int input,int low, int high)
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(99, '\n');
		system("cls");
		cout << "That is not a number!" << endl;
	}
	else if (input < low || input > high)
	{
		system("cls");
		cout << "That is not a valid input, try again." << endl;
	}
}
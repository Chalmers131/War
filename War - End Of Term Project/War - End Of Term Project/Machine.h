#pragma once

class Machine
{
public:
	Machine();

	~Machine();

	int OpeningSequence(int low, int high);

	void DisplayIntro();

	int GetInput();

	void AskForRestart();

	void AskForAutoPlay();

	void ValidateIntegerInput(int input, int low, int high);
};
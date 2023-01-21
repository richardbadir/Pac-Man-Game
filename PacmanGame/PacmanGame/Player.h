#pragma once

class Player
{
public:
	Player(char);
	char getCharacter();
	void Move(int);
	void SetCurrentYPosition(int);
	int GetCurrentYPosition();
	void SetCurrentXPosition(int);
	int GetCurrentXPosition();
private:
	char Character;
	int CurrentYPosition;
	int CurrentXPosition;
};


#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(char a)
{
	Character = a;
}

char Player::getCharacter()
{
	return Character;
}

void Player::Move(int move)
{
	switch(move){
		case 1:
			CurrentXPosition++;
		case 2:
			CurrentXPosition--;
		case 3:
			CurrentYPosition++;
		case 4:
			CurrentYPosition--;
	}
}

void Player::SetCurrentYPosition( int a)
{
	CurrentYPosition = a;
}

int Player::GetCurrentYPosition()
{
	return CurrentYPosition;
}

void Player::SetCurrentXPosition(int b)
{
	CurrentXPosition = b;
}

int Player::GetCurrentXPosition()
{
	return CurrentXPosition;
}

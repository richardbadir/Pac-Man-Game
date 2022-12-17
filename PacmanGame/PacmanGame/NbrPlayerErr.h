#pragma once
class NbrPlayerErr //exception for when the number of players is invalid.
{
public: 
	NbrPlayerErr(int a, int b);
	void TooLoworTooHigh();
private: 
	int NbrofPlayers;
	int MaxNbrofPlayers;

};


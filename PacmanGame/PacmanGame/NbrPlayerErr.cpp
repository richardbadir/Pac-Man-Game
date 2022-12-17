#include "NbrPlayerErr.h"
#include <iostream>
using namespace std;

NbrPlayerErr::NbrPlayerErr(int a, int b)
{
	NbrofPlayers = a;
	MaxNbrofPlayers = b;
}

void NbrPlayerErr::TooLoworTooHigh()
{
	if (NbrofPlayers <= 0) {
		cout << "Please enter a valid amount of players."<< endl;
	}
	else {
		cout << "Sorry! The game currently only allows a maximum of " << MaxNbrofPlayers << " players." << endl;
	}
}

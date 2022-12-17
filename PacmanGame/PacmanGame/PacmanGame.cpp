#include <iostream>
//#include"Map.h"
#include"NbrPlayerErr.h"
using namespace std;

int NbrofPlayersCheck(int maxnplay);

int main()
{
    const int maxNumplayers=1;

    cout << "Welcome to the game! How many players are you?" << endl; // This is to initialize the number of players 
    int numPlayers=NbrofPlayersCheck( maxNumplayers);

        while (numPlayers <= 0 || numPlayers > maxNumplayers) { // this is to repeatedly ask for the number of players until a valid number is inputted
            cout << "How many players are you?" << endl;
            numPlayers = NbrofPlayersCheck(maxNumplayers);
        }

}

int NbrofPlayersCheck( int maxnplay) {// this function throws and handles the exceptions of when the input for number of players is invalid and returns the number of players
    int nplay;
    try {
        
        cin >> nplay;
        if (nplay > maxnplay || nplay <= 0) {
            throw NbrPlayerErr(nplay, maxnplay);
        }
    }
       catch (NbrPlayerErr a) {
            a.TooLoworTooHigh();
            cin.clear();
            cin.ignore(100, '\n');
            
        }
       return nplay;
}

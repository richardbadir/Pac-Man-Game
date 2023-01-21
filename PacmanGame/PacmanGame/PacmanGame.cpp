#include <iostream>
#include"Map.h"
#include"Player.h"
#include"NbrPlayerErr.h"
#include <vector>
using namespace std;

int NbrofPlayersCheck(int maxnplay);
char PlayerCharacterCheck(int b, vector<char> vec);

int main()
{
    const int maxNumplayers=3;

    cout << "Welcome to the game! How many players are you?" << endl; // This is to initialize the number of players 
    int numPlayers=NbrofPlayersCheck( maxNumplayers);
    
    while (numPlayers <= 0 || numPlayers > maxNumplayers) { // this is to repeatedly ask for the number of players until a valid number is inputted
        cout << "How many players are you?" << endl;
        numPlayers = NbrofPlayersCheck(maxNumplayers);
        system("cls");
    }
    vector <Player> PlayerVector;//keeps in memory the player objects
    vector <char> Characters;// keeps in memory all the player charcters to make sure that two players don'y use the same character.


    for (int i = 1; i <= numPlayers; i++) {//set up the player objects and store them in a vector
        char PlayerCharacter = PlayerCharacterCheck(i, Characters);
        while (PlayerCharacter == '#' || PlayerCharacter == '.' || PlayerCharacter == '<' || PlayerCharacter == '>' || PlayerCharacter == ' ' || PlayerCharacter == '@') {
            PlayerCharacter = PlayerCharacterCheck(i, Characters);
        }
        for (int j = 0; j < Characters.size(); j++) {
            while (Characters[j] == PlayerCharacter) {
                PlayerCharacter = PlayerCharacterCheck(i, Characters);
            }
        }
        PlayerVector.push_back(Player(PlayerCharacter));
        Characters.push_back(PlayerCharacter);
        system("cls");

    }
   /* Map MapObject(numPlayers);
    while (true) {
        int move = cin.getchar();
        PlayerVector[0].Move(move);
        MapObject.show(PlayerVector);
    }*/
    Map MapObject(numPlayers);
    MapObject.show(PlayerVector);

}

int NbrofPlayersCheck( int maxnplay) {// this function throws and handles the exceptions of when the input for number of players is invalid and returns the number of players
    int nplay;
    try {
        
        cin >> nplay;
        system("cls");
        cin.clear();
        cin.ignore(100, '\n');
        if (nplay > maxnplay || nplay <= 0) {
            throw NbrPlayerErr(nplay, maxnplay);
        }
    }
       catch (NbrPlayerErr a) {
            a.TooLoworTooHigh();
         
        }
       return nplay;
}
char PlayerCharacterCheck(int b, vector <char> vec) { //checks if the character entered is valid until a valid one is entered and returns that character
    char PlayerCharacterF;
    try {
        cout << "Player " << b << ", please enter a character to represent you other than '#', '@' '<', '>', '.' or space: ";
        cin >> PlayerCharacterF;
        cin.clear();
        cin.ignore(1000, '\n');
        if (PlayerCharacterF == '#' || PlayerCharacterF == '.' || PlayerCharacterF == '<' || PlayerCharacterF == '>' || PlayerCharacterF == ' ' || PlayerCharacterF == '@') {
            throw PlayerCharacterF;
        }
    }
    catch (char a) {
        cout << a << " is not an acceptable character." << endl; 
    }
    try {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == PlayerCharacterF) {
                system("cls");
                throw PlayerCharacterF;
            }
        }
    }
   
    catch(char c) {
        cout << "\'" << c << "\'" << " is already chosen by player ";
    } 
    try {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == PlayerCharacterF) {
                throw i;
            }
        }
    }
    catch (int d) {
        cout << d+1 << "."<< endl;
    }
    return PlayerCharacterF;
}
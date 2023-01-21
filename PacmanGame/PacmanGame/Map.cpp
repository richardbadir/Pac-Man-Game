#include "Map.h"


Map::Map(int a)
{
	if (a == 1) {
		TxtFile = "OnePlayerMap.txt";
	}
	if (a == 2) {
		TxtFile = "TwoPlayerMap.txt";
	}
	if (a == 3) {
		TxtFile = "3PlayerMap.txt";
	}
}

void Map::show(vector <Player> a)
{
	string ReadString;
	ifstream ReadFile(TxtFile);
	int PlayerN = 0;
	int NbrStringsRead = 0;
	
	while (getline(ReadFile, ReadString)) {
		
		for (int i = 0; i < ReadString.length(); i++) {
			if (ReadString[i] == '$') {//  change the dollar signs to the character chosen by the players
				ReadString[i] = a[PlayerN].getCharacter();
				PlayerN++;
			}
			/*for (int u = 0; u < a.size(); u++) {
				if (a[u].GetCurrentYPosition() == NbrStringsRead) {
					if (a[u].GetCurrentXPosition() == ReadString[i]) {
						ReadString[i] = a[u].getCharacter();
					}
				}
			}*/
			
		}
		//Positions will contain a vector of strings (so vector of character arrays) to be able to move around and change things
		cout << ReadString << endl;
		//Positions.push_back(ReadString);
		NbrStringsRead++;
	}
	
	ReadFile.close();
}

void Map::PandEPositions(vector<Player> a)
{
	for (int i = 0; i < Positions.size(); i++) {
		for (int o = 0; o < Positions[i].length(); o++) {
			for (int y = 0; i < a.size(); y++) {
				if (a[y].getCharacter() == Positions[i][o]) {
					a[y].SetCurrentXPosition(o);
					a[y].SetCurrentYPosition(i);
				}
			}
		}
	}
}



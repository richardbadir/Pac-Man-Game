#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Player.h"
using namespace std;

class Map
{
public:
	Map(int);
	void show(vector <Player> a);
	void PandEPositions(vector<Player> a);
private:
	string TxtFile;
	vector<string> Positions;

};


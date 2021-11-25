#ifndef GAMECLASS_H
#define GAMECLASS_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "Inventory.h"
#include "Locations.h"
#include "InputValidation.h"
using namespace std;
/*
	GameClass contains different functions for game methods like minigames, and events, as well as other methods that are used through the game but don't involve other classes
*/
class GameClass
{
private:

	//string Locations[3] = { "Village Entrance", "Tavern", "Abandoned Shack" }; //, {"Village Entrance Info", "Tavern Info", "Abandoned Shack Info"} };
	string playerLocation;
	InputValidation validate;
	
public:
//	void Location();
	GameClass();
	void Quit();
	bool TunnelPuzzle();
	void FirstDeath();
	string UseMenu(Inventory, string);

};
#endif
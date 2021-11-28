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
	bool GameOver=false;


	InputValidation validate;
	
public:

	void Quit();
	bool TunnelPuzzle();
	void FirstDeath();
	bool IsGameOver();
	void setGameOver(bool);
	string UseMenu(Inventory, string);

};
#endif
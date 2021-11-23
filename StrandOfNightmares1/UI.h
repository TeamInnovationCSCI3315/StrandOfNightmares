#ifndef UI_H
#define UI_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "GameClass.h"
#include "Inventory.h"
#include "PlayerClass.h"
#include "Locations.h"
#include <fstream>
using namespace std;
/*
	This constructs the display for the choices, player input and location and returns it to cpp file to be displayed
*/
class UI
{
private:
	enum PlayerMenuChoices
	{
		Interact, 
		Move,
		ShowInventory,
		QuitGame
	};
	int playerInput;

public: 
	void SaveGame(Inventory&,Locations&);
	void LoadGame(Inventory&, Locations&, Locations[],int);
	void DisplayStartScreen(Inventory&, Locations&, Locations[],int);
	void DisplayIntroduction();
	void Menu(Locations[], Locations&, Inventory&, GameClass&, int);
	void MoveOptions(Locations[], Locations&, int);

};
#endif






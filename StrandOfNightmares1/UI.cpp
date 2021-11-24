#include "GameClass.h"
#include "UI.h"
#include "PlayerClass.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include "InputValidation.h"
#include <fstream>
#include <regex>
using namespace std;

InputValidation validate;
PlayerClass player1;
/*
	Displays the introduction to the game
*/
void UI::DisplayStartScreen(Inventory& playerInventory, Locations& playerLocation, Locations AllLocations[], int AllLocationsSize)
{
	GameClass Game;
	cout << "-----------------------A Strand of Nightmares--------------------------" << endl;
	cout << "                   | |--|                       |--| |                 " << endl << "                   |-|  |-----------------------|  |-|" << endl << "                   | |  |                       |  | |                 " << endl;
	cout << "------------------(Press 1 to Start the Nightmare)---------------------"<<endl;
	cout << "-----------------(Press 2 to Continue the Nightmare)-------------------" << endl;
	cout << "---------------(Press Anything Else to End the Dream)------------------" << endl;
	string playerinputst = "";
	cin >> playerinputst;
		if (playerinputst == "1")
		{
			DisplayIntroduction();
		}
		else if (playerinputst == "2")
		{
			LoadGame(playerInventory, playerLocation, AllLocations, AllLocationsSize);
		}
		else
		{
			exit(0);
		}
}
void UI::DisplayIntroduction()
{
	system("CLS");
	string name;
	cout << "Who are you Dreamer?\n";
	cin >> name;
	player1.setName(name);
	cout << "Interesting, I believe I am familiar.\n" 
		 << "You were busy " << player1.getName() << ", your life had been going along as it was, you were tired.\nSo very tired.\n" 
		 << "You went to sleep on one of your worse days, and when you slept you dreamt.\n" 
		 << "You fell into such a terrible nightmare, one that you cannot wake up from it.\n";
	system("pause");
	cout << "You fell into a world known as 'The First Strand', along The Bridge to the world of Fiction.\n"
		 << "You'll learn more of what I mean in due time " << player1.getName() << " all in due time.\n";
	system("pause");
	cout << "I will be your guide through this bridge, think of me as your deep concious, in a way I am that.\n"
		 << "Your goal as you know it is to find a way to wake up, to return to reality in the only way you know that is to dive into the dream.\n"
	     << "I wish you the best of luck, I know you can navigate the knots of this world, you'll find them, they pull you to them.\n I shall be seeing you very soon.\n";
	system("pause");
	system("CLS");
}
/*
Displays the user interface for the game as a whole. Player can:
		Case 1: Interact (Location Actions),
		Case 2: Move Locations (MoveOptions),
		Case 3: Show Inventory (DisplayInventory),
		Case 0: Quit Game (Quit)
*/
void UI::Menu(Locations AllLocations[], Locations& PlayerLocation, Inventory& PlayerInventory, GameClass& Game, int AllLocationsSize)
{
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "You are currently at: " << PlayerLocation.getLocationName() << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "[1] Interact\n" << "[2] Move\n" << "[3] Inventory \n" << "[4] Look \n" << "[5] Save Game \n" << "[0] Quit Game\n";
	cout << "--------------------------------------------------------------------------" << endl;
	//cout << "\t [1] North: " << PlayerLocation.getNorthDoor() << endl << "\t [2] South: " << PlayerLocation.getSouthDoor() << endl << "\t [3] East: " << PlayerLocation.getEastDoor() << endl << "\t [4] West: " << PlayerLocation.getWestDoor() << endl << "\t [5] View Inventory" << endl << "\t [0] Quit Game" << endl << endl;
	playerInput = validate.inputValidation();
	switch (playerInput)
	{
	case 1:
		PlayerLocation.LocationActions(AllLocations, PlayerInventory, AllLocationsSize);
		break;
	case 2:
		MoveOptions(AllLocations, PlayerLocation, AllLocationsSize);
		break;
	case 3:
		PlayerInventory.DisplayInventory();
		break;
	case 4:
		PlayerLocation.LocationLook(AllLocations, PlayerInventory, AllLocationsSize);
	case 5:
		SaveGame(PlayerInventory, PlayerLocation);
		break;
	case 0:
		Game.Quit();
		break;
	default:
		cout << "Invalid";
		break;
	}
}
/*
Switch Statement to move between:
	Case 1: North
	Case 2: South
	Case 3: East
	Case 4: West
*/
void UI::MoveOptions(Locations AllLocations[], Locations& PlayerLocation, int AllLocationsSize)
{
	cout << "\t [1] North: " << PlayerLocation.getNorthDoor() << endl << "\t [2] South: " << PlayerLocation.getSouthDoor() << endl << "\t [3] East: " << PlayerLocation.getEastDoor() << endl << "\t [4] West: " << PlayerLocation.getWestDoor() << endl << endl;
	int playerChoice;
	playerInput = validate.inputValidation();
	switch (playerInput)
	{
	case 1: // North
		if (PlayerLocation.getNorthDoor() == "")
		{
			cout << "Invalid\n";
		}
		else
		{
			PlayerLocation.CheckLocation(AllLocations, "North", AllLocationsSize);
			//cout << PlayerLocation.getLocationName() << endl << PlayerLocation.getLocationDesc();

		}
		break;
	case 2: // South
		if (PlayerLocation.getSouthDoor() == "")
		{
			cout << "invalid\n";
		}
		else
		{
			PlayerLocation.CheckLocation(AllLocations, "South", AllLocationsSize);
			//cout << PlayerLocation.getLocationName() << endl << PlayerLocation.getLocationDesc();
		}
		break;
	case 3: // East
		if (PlayerLocation.getEastDoor() == "")
		{
			cout << "invalid\n";
		}
		else
		{
			PlayerLocation.CheckLocation(AllLocations, "East", AllLocationsSize);
			//cout << PlayerLocation.getLocationName() << endl << PlayerLocation.getLocationDesc();
		}
		break;
	case 4: // West
		if (PlayerLocation.getWestDoor() == "")
		{
			cout << "invalid\n";
		}
		else
		{
			PlayerLocation.CheckLocation(AllLocations, "West", AllLocationsSize);
			//cout << PlayerLocation.getLocationName() << endl << PlayerLocation.getLocationDesc();
		}
		break;
	}
}
/*
SaveGame takes in the playerInventory, and playerLocation, and saves the item information, and name of the location the player is currently at to a file wherever the play downloads the game to.
These 2 saved files are TeamInnovationSaveInventory.txt, and TeamInnovationSaveLocation.txt. Every time the player saves, the file will be overwrited.
*/
void UI::SaveGame(Inventory& playerInventory, Locations& playerLocation)
{
	ofstream inventoryFile;
	inventoryFile.open("TeamInnovationSaveInventory.txt");
	for (int i = 0; i < playerInventory.GetInventorySize(); i++)
	{
		inventoryFile << playerInventory.GetItemAt(i + 1) << endl;
	}
	//inventoryFile.close();
	ofstream locationFile;
	locationFile.open("TeamInnovationSaveLocation.txt");
	locationFile << playerLocation.getLocationName();
	cout << "Game was successfully saved!\n";
	//locationFile.close();

}
/*
LoadGame reads 2 files TeamInnovationSaveInventory.txt, and TeamInnovationSaveLocation.txt, and if found, will set the players location to the location read by the file, and adds previous items to their inventory.

*/
void UI::LoadGame(Inventory& playerInventory, Locations& playerLocation, Locations AllLocations[],int AllLocationsSize)
{
	string inventoryData;
	string northDoor;
	string southDoor;
	string eastDoor;
	string westDoor;
	string locationName;
	string locationDesc;
	string item;
	string roomObject;
	string e;
	vector<string> items;
	fstream inventoryLoad;
	fstream locationLoad;
	inventoryLoad.open("TeamInnovationSaveInventory.txt");
	locationLoad.open("TeamInnovationSaveLocation.txt");
	if (!inventoryLoad || !locationLoad)
	{
		cout << "Error, no file found";
	}
	else
	{
		while (inventoryLoad >> inventoryData)
		{
			items.push_back(inventoryData);
		}
		for (int i = 0; i < items.size(); i++)
		{
			playerInventory.AddItem(items[i]);
		}
		getline(locationLoad, locationName);
		for (int i = 0; i < AllLocationsSize; i++)
		{
			if (locationName == AllLocations[i].getLocationName())
			{
				playerLocation = AllLocations[i];
			}
		}
		cout << "Game was succesfully loaded!\n";
	}


}
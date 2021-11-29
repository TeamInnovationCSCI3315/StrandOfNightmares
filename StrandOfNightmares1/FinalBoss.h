#ifndef FINALBOSS_H
#define FINALBOSS_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "Inventory.h"
#include "Locations.h"
#include "InputValidation.h"
#include "GameClass.h"
#include <vector>
using namespace std;

class FinalBoss
{
private:
	bool GameOver = false;
	InputValidation Validate;
	vector<string> playerOptions = { "Shield","Dodge","Revolver","Water","Sword","Wall"};
	string finalBossOptions[6][2] = {
		{"Sword",playerOptions[0]}, {"Pistol",playerOptions[1]}, {"Shield",playerOptions[2]}, {"Firebomb",playerOptions[3]}, {"Dagger",playerOptions[4]}, {"Rifle",playerOptions[5]}
	};
public:
	
	FinalBoss();
	bool IsFinalBossBeaten();
	void DisplayPlayerOptions();
	bool IsGameOver();
	void setGameOver(bool);


};
#endif
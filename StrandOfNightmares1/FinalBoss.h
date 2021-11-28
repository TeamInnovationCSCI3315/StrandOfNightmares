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
	vector<string> playerOptions = { "Counter1","Counter2","Counter3","Counter4","Counter5","Counter6"};
	string finalBossOptions[6][2] = {
		{"Weapon1",playerOptions[0]}, {"Weapon2",playerOptions[1]}, {"Weapon3",playerOptions[2]}, {"Weapon4",playerOptions[3]}, {"Weapon5",playerOptions[4]}, {"Weapon6",playerOptions[5]}
	};
public:
	
	FinalBoss();
	bool IsFinalBossBeaten();
	void DisplayPlayerOptions();
	bool IsGameOver();
	void setGameOver(bool);


};
#endif
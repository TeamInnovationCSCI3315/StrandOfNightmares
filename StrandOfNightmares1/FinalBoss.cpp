#include <iostream>
#include <cstdlib>
#include <string>
#include "Inventory.h"
#include "Locations.h"
#include "InputValidation.h"
#include "GameClass.h"
#include "FinalBoss.h"
#include <vector>
#include <random>
using namespace std;
FinalBoss::FinalBoss()
{
	
}
void FinalBoss::DisplayPlayerOptions()
{
	random_shuffle(playerOptions.begin(), playerOptions.end());
	for (int i = 0; i < playerOptions.size(); i++)
	{
		cout << i + 1 << ". " << playerOptions[i] << endl;
	}
}
bool FinalBoss::IsFinalBossBeaten()
{
	
	int input;
	int MAX = 4;
	srand(time(0));
	int tempvalue;
	int i = 0;
	while(i<playerOptions.size())
	{
		
		tempvalue = (rand() % MAX);
		cout << "They are about to use: " << "\033[1;33m" << finalBossOptions[tempvalue][0] << "\033[0m" << ". What will you do? Choose an option below: " << endl;
		DisplayPlayerOptions();
		input=Validate.inputValidation();
		while (input > 5)
		{
			cout << "Invalid selection, try again: \n";
			input = Validate.inputValidation();
		}
		if (input > 0) input = input - 1;
		if (playerOptions[input] == finalBossOptions[tempvalue][1])
		{
			cout << "You successfully countered the enemy\n";
		}
		else
		{
			return false;
			
		}
		i++;
	}
	return true;
}

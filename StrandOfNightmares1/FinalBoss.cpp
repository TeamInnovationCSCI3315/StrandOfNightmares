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
/*
Displays available items to use against boss to player
*/
void FinalBoss::DisplayPlayerOptions()
{
	random_shuffle(playerOptions.begin(), playerOptions.end());
	for (int i = 0; i < playerOptions.size(); i++)
	{
		cout << i + 1 << ". " << playerOptions[i] << endl;
	}
}
/*
Final Boss Fight. If boss is defeated, returns true.
Randomly chooses an option of what the boss will use against the player, introducing a randomness to the game so it cant be beat unless the players learn the counters.
*/
bool FinalBoss::IsFinalBossBeaten()
{
	
	int input;
	int MAX = 6;
	srand(time(0));
	int tempvalue;
	int i = 0;
	while(i<playerOptions.size())
	{
		
		tempvalue = (rand() % MAX);
		cout << "They are about to use: " << "\033[1;33m" << finalBossOptions[tempvalue][0] << "\033[0m" << ". What will you do? Choose an option below: " << endl;
		DisplayPlayerOptions();
		input=Validate.inputValidation();
		while (input > playerOptions.size())
		{
			cout << "Invalid selection, try again: \n";
			input = Validate.inputValidation();
		}
		if (input > 0) input = input - 1;
		if (playerOptions[input] == finalBossOptions[tempvalue][1])
		{
			if (tempvalue==0)
			{
				cout << "You concentrate and picture a way to get out of this.\nThe heavy shield forms in your hand blocking my attack. \nYou're using our power here aren't you? A shield to defend against my sword. Impressive. Both of our weapons vanish in a blink.\nThey've done their purpose in this dream." << endl;
			}
			if (tempvalue==1)
			{
				cout << "You realized you would have no time to imagine a weapon needed for this.\n You jump out of the way of the pistol's shot, hurling yourself behind the throne. \nI will have to form another weapon for you.\nAs I concentrate the revolver vanishes." << endl;
			}
			if (tempvalue==2)
			{
				cout << "My massive shield stands unflinchingly before you as you realize you have no way around this.\nYou struggle to picture how you can beat it, if only you had a weapon from reality. \nFrustrated you form the weapon in your hands, you aim it and fire.\n My shield may as well be cast iron in comparison. Damn you. \nYour gun vanishes into smoke with the shield" << endl;
			}
			if (tempvalue==3)
			{
				cout << "You see me light the fuse on the firebomb and hurl it at you.\nHastily you use our skill to make anything to imagine a splash of water, this skill likely gained from my presence. \nIt forms out of thin air in a swirl before dropping to the ground extingushing it.\nBoth items vanish into smoke." << endl;
			}
			if (tempvalue==4)
			{
				cout << "After having seen my sword before, you recall. You pull out the rusty sword to combat my dagger, it is ours.\nI am able to parry for a time, but your reach ultimately wounds me. \nI dismiss the lesser weapon, you follow suit." << endl;
			}
			if (tempvalue==5)
			{
				cout << "A dark rifle forms in my hands, panicking you wish for the walls between me and you to close in on themselves to prevent it.\n If it weren't for this overwhelming fear, I don't think this would've worked.\nMy gunshots pitter patter on it as you struggle to hold the thought. \nI dismiss it relunctantly, with it gone you release the concept." << endl;
			}
			cout << "You successfully countered the enemy\n";
		}
		else
		{
			if (tempvalue == 0)
			{
				cout << "I am able to close the distance with you, whatever weapon you have formed to face me I parry away.\nI drive my sword through your heart, our heart, hopefully for the last time...." << endl;
			}
			if (tempvalue == 1)
			{
				cout << "Whatever weapon you think you can combat me with, end that thought.\n I have been doing this long enough. \nI land each of the 6 shots into you, granted only the first two were needed as you bled out on the floor. \nBut I wanted you to know I shot your corpse with the rest..." << endl;
			}
			if (tempvalue == 2)
			{
				cout << "I form a shield blocking your strikes, only bullets would ever pierce the metal.\nI proceed to beat our skull in with the rim, as your bleed out onto the tile, bones snapping and cracking as you scream. \nFinally you grow silent..." << endl;
			}
			if (tempvalue == 3)
			{
				cout << "The bomb falls to your feet, in this closed room, and with your speed you cannot evade.\nIn a sweetly sounding boom your flesh scars with smoke and ash. Luckily for you it all ended within about 3 minutes. \nThe last time was longer..." << endl;
			}
			if (tempvalue == 4)
			{
				cout << "I quickly move past your defenses, a shield or a ranged weapon, doesn't matter.\n You were foolish to think you can hide from me now instead of fight.\nI knock out your feet severing your wrists before holding us down and finishing you off.\n I slice your throat to end it forever..." << endl;
			}
			if (tempvalue == 5)
			{
				cout << "A shield cannot block this, no shield would be thick enough for modern rounds.\n I have summoned the best weapon, you don't have the advantage of first strike.\n Thus I riddle your body with bullets before mutilating your corpse.\nI know that one day you'll give up, this will discourage trying another day perhaps..." << endl;
			}
			return false;
			
		}
		i++;
	}
	return true;
}
/*
Functions to decide if the game is over. If boss is defeats the player, the game will be over.
*/
bool FinalBoss:: IsGameOver()
{
	return GameOver;
}
void FinalBoss::setGameOver(bool i)
{
	GameOver = i;
}

#include "GameClass.h"
#include "UI.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "Inventory.h"
#include "Locations.h"
#include "PlayerClass.h"
using namespace std;
/*
	GameClass contains different functions for game methods like minigames, and events, as well as other methods that are used through the game but don't involve other classes
*/
GameClass::GameClass()
{
	
}
string GameClass::UseMenu(Inventory playerInventory, string s)
{
	string itemToUse;
	string usedOn;
	playerInventory.DisplayInventory();
	cout << "Select item to use on" << s << endl;
	int playerchoice = validate.inputValidation();
	while(playerchoice > playerInventory.GetInventorySize())
	{
		cout << "Invalid Selection, Try Again: \n";
		playerchoice = validate.inputValidation();
	}
	itemToUse = playerInventory.GetItemAt(playerchoice); 
	return itemToUse;
}

void GameClass::Quit()
{
	string tempinput="";

		cout << "Are you sure you would like to quit the game? Remember to save if you haven't yet! (Press Y to quit) \n";
		cin >> tempinput;
		if (tempinput == "Y" || tempinput ==  "y")
		{
			exit(0);
	}
}

bool GameClass::TunnelPuzzle()
{
	/*
		Displays puzzle questions
		If answer is right, move to next question. If all questions are complete, return true. Else, return false.
		*/
	int playerchoice = 0;
	cout << "Solve this puzzle, unlock the next room\n" << endl;
	cout << "Who is reading this to you?" << endl;
	cout << "-----------------" << endl;
	cout << "1.) The Narrator " << endl;
	cout << "2.) I am (me) " << endl;
	cout << "3.) Nobody " << endl;
	cout << "4.) Deep Consciousness " << endl;
	cout << "Choose your answer: ";
	playerchoice = validate.inputValidation();
	if (playerchoice == 4)
	{
		cout << "You are correct! Onto the next one..." << endl;
		playerchoice = 0;

		cout << "What is down the other tunnel path?" << endl;
		cout << "-----------------" << endl;
		cout << "1.) Nothing " << endl;
		cout << "2.) The way out " << endl;
		cout << "3.) A shadow " << endl;
		cout << "4.) A light source " << endl;
		playerchoice = validate.inputValidation();

		if (playerchoice == 3)
		{
			cout << "You are correct! Onto the next one..." << endl;
			playerchoice = 0;

			cout << "Where are you right now? Truly, " << endl;
			cout << "-----------------" << endl;
			cout << "1.) Shack outside of town " << endl;
			cout << "2.) A knot between strands " << endl;
			cout << "3.) The first strand " << endl;
			cout << "4.) Home, in bed " << endl;
			playerchoice = validate.inputValidation();
			if (playerchoice == 2)
			{
				cout << "You are correct!" << endl;
				playerchoice = 0;
				return true;
			}
		}
	}
	cout << "You are incorrect! Speak to me again and try my riddles from the beginning." << endl;
	return false;

}
void GameClass::FirstDeath()
{
	cout << "As you approach the figure up ahead a chill follows your spine but you press on." << endl;
	cout << "When the figure is about to come into the light of your lantern, you witness a strange occurance." << endl;
	cout << "As if a puff of midnight the glow causes you to blink, then you find yourself staring ahead at a dead end." << endl;
	cout << "You turn to leave when you see it." << endl;
	system("pause");
	cout << "A cloaked figure draped in shadow as if it were it's own hair stretching to the floor." << endl;
	cout << "The hood revealing a face of dripping skin as if it were wax, loose aged teeth and bone." << endl;
	cout << "An eyeball falls out of it's socket, it steps on it as if it's inconsequential." << endl;
	cout << "Approaching you as you finally take it in, you'd scream before if you knew what just happened." << endl;
	system("pause");
	cout << "The figure had a blade already sunk within you." << endl;
	system("pause");
	cout << "You paint the floor with a steady drip of crimson, shaking you try to move." << endl;
	cout << "It unsheathes it's blade from your chest, releasing a bright red current out from you." << endl;
	cout << "This is followed swiftly by the standing corpse slashing at you." << endl;
	system("pause");
	cout << "You find your vision in the air, you see your dismembered corpse from above." << endl;
	system("pause");
	cout << "Your head falls to the ground, and the last thing you see is it sinking back into the shadows." << endl;
	cout << "Ready to dream again, you sleep." << endl;
	system("pause");
}

/*void GameClass::VillageDescr()
{
	cout << "You find yourself looking at a village as you sit at the entrance of it. There is the light hooting of an owl as you start walking." << endl;
	cout << "As you look around you notice how dark it is, the village allows you to barely maneuver around with the faint candlelight from the street lamps." << endl;
	cout << "In one direction, following the road to the east you notice a tavern up ahead with bright lights and the sounds of commerce. This could be a good place to find information and help and it is probably the brightest place." << endl;
	cout << "In the other direction you notice the lights grow scarcer and scarcer until you can barely see the outline of what seems to be an abandoned shack, something draws you to it's shadow, curiosity maybe?" << endl;
	cout << "Where do you go?" << endl;
}
void GameClass::TavernDescr()
{
	cout << "You enter into a tavern with bright almost blinding light. It is noisy as people chat around at the bar and entrance." << endl;
	cout << "You are able to squeeze your way into the main room, most people have not taken notice of you and proceed about their bussiness." << endl;
	cout << "There lays the bar to your right that carries the smells of beer to you alongside other aromas." << endl;
	cout << "You also see on your left a fine finished table with a lantern on it." << endl;
	cout << "Where do you go?" << endl;
}
void GameClass::AbandonDescr()
{
	cout << "After walking you arrive at the pitch black shack, it's presence alone stands as if you could die and it wouldn't so much as creek." << endl;
	cout << "As you approach it closer to inspect the strange building you find that it becomes far too dark to see and proceed forward, at least safely." << endl;
	cout << "Do you decide to exit now?" << endl;
}
void GameClass::AbandonDescrL()
{
	//This the description for the player when they have the lantern and go to the Abandoned Shack it SHOULD NOT be used otherwise
	cout << "With the lantern in hand you head towards the abandoned shack once again." << endl;
	cout << "It seems to be made out of a rotting, creeping willow of some kind or another, though it splinters out as a thorny hide." << endl;
	cout << "It has a flimsy door held together by sheer luck, and a rusted doorknob is the only thing standing between you and the inside." << endl;
	cout << "Do you open the door and proceed inside?"<<endl;
}*/
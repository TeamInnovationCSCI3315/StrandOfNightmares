#include "Locations.h"
#include "GameClass.h"
#include "Inventory.h"
#include "UI.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "InputValidation.h"

using namespace std;
/*
	Constructors for the location and instances for location description and name, and returns these values.
	Location Constructor stores Location Name, Description, and Adjacent doors North, South, East, and West, a well as an Item, and an NPC/Object to interact with
*/
Locations::Locations(string n, string d, string north, string south, string east, string west, string i,string o)
{
	item = i;
	LocationInventory.AddItem(i);
	locationName = n;
	locationDesc = d;
	northDoor = north;
	southDoor = south;
	eastDoor = east;
	westDoor = west;
	roomObject = o;
}
string Locations::getRoomObject()
{
	return roomObject;
}
void Locations::setRoomObject(string r)
{
	roomObject = r;
}
string Locations::getEastDoor()
{
	return eastDoor;
}
string Locations::getWestDoor()
{
	return westDoor;
}
string Locations::getNorthDoor()
{
	return northDoor;
}
string Locations::getSouthDoor()
{
	return southDoor;
}
string Locations::getLocationName()
{
	return locationName;
}
string Locations::getLocationDesc()
{
	return locationDesc;
}
string Locations::getItem()
{
	return item;
}
void Locations::setLocationDesc(string d)
{
	locationDesc = d;
}
void Locations::setLocationName(string n)
{
	locationName = n;
}
/*
	CheckLocation compares the location of a player to all other locations to determine its relation in direction to other rooms
*/ 
/*
Check Location sets a new location to the player's location based on the direction and nearby rooms
*/
void Locations::CheckLocation(Locations TempLocation[], string direction, int size)
{
	int index=0;

	if (direction == "North")
	{

		for (int i = 0; i < size; i++)
		{

			if (northDoor == TempLocation[i].getLocationName())
			{
				index = i;
				//cout << TempLocation[index].getLocationName() << endl;
			}
		}
	}
	if (direction == "South")
	{
		for (int i = 0; i < size; i++)
		{

			if (southDoor == TempLocation[i].getLocationName())
			{
				index = i;
				//cout << TempLocation[index].getLocationName() << endl;
			}
		}

	}
	if (direction == "East")
	{
		for (int i = 0; i < size; i++)
		{

			if (eastDoor == TempLocation[i].getLocationName())
			{
				index = i;
				//cout << TempLocation[index].getLocationName() << endl;
			}
		}
	}
	if (direction == "West")
	{
		for (int i = 0; i < size; i++)
		{

			if (westDoor == TempLocation[i].getLocationName())
			{
				index = i;
				//cout << TempLocation[index].getLocationName() << endl;
			}
		}
	}
	locationName = TempLocation[index].getLocationName();
	locationDesc = TempLocation[index].getLocationDesc();
	northDoor = TempLocation[index].getNorthDoor();
	southDoor = TempLocation[index].getSouthDoor();
	eastDoor = TempLocation[index].getEastDoor();
	westDoor = TempLocation[index].getWestDoor();
	LocationInventory.AddItem(TempLocation[index].getItem());
	index = 0;

}
/*
LocationActions displays different actions specific to every room
If(locationName == "Room"
{
Do this:
}

*/
void Locations::LocationActions(Locations TempLocation[], Inventory& playerinventory, int locationsize)
{
	
	int playerchoice=1;
	if (locationName == "Village Entrance")
	{
		
		locationDesc = "You find yourself looking at a village as you sit at the entrance of it. There is the light hooting of an owl as you start walking.\nAs you look around you notice how dark it is, the village allows you to barely maneuver around with the faint candlelight from the street lamps.\nIn one direction, following the road to the east you notice a tavern up ahead with bright lights and the sounds of commerce. This could be a good place to find information and help and it is probably the brightest place.\nIn the other direction you notice the lights grow scarcer and scarcer until you can barely see the outline of what seems to be an abandoned shack, something draws you to it's shadow, curiosity maybe?\n ";
		cout << locationDesc;
	}
	else if (locationName == "Abandoned Shack")
	{
			if (playerinventory.SearchInventory("Lantern"))
			{	
				southDoor = "Tunnel";
				locationDesc = "With the lantern in hand you head towards the abandoned shack once again.\nIt seems to be made out of a rotting, creeping willow of some kind or another, though it splinters out as a thorny hide.\nIt has a flimsy door held together by sheer luck, and a rusted doorknob is the only thing standing between youand the inside.\nYou pull open the wooden door as you do the door comes off of it's hinges with a loud thunk.\nYou step to the side with an inexplicable calmness as it falls where you were previously standing.\nThe inside of it is  hard to take in as you enter, still wondering.\nThe walls seem warped and as if waves of fabric compared to it's porcupine exterior.\nAn ocean of fine willow, sandedand well maintained like it's floors and a nearby bed.\nThe candles with their wax drapping over windowsills greet you with the faintest flicker, before extinguishing.\nStartled, you notice the new wax drips just below a trapdoor not just a foot away from you.\nIt's fine finished wood and golden knocker whisper to you almost in a wordless alure.\nYou wonder finally, why ? \nThe door, the candles, the words, this shack.\nAnd it's with these thoughts you wonder, should you go down the trapdoor? There seems to be some sort of tunnel underneith the door, but it doesnt seem possible to return. \n:	";
				cout << locationDesc;
			}
			else
			{
				
				locationDesc = "After walking you arrive at the pitch black shack, it's presence alone stands as if you could die and it wouldn't so much as creek.\nAs you approach it closer to inspect the strange building you find that it becomes far too dark to see and proceed forward, at least safely.\nDo you decide to exit now ? \n";
				southDoor = "";
				cout << locationDesc;
			}
	}
	else if (locationName == "Village Garden")
	{
		if (!playerinventory.SearchInventory("Sage"))
		{
			locationDesc = "You enter the garden.\n You smell a strong herb nearby.\n There is flora all around you.\n\n[1] Admire garden \n[2] Pick herb \n[3] Exit\n";

		}
		if (playerinventory.SearchInventory("Sage"))
		{
			locationDesc = "[1] Admire the Garden \n [3] Go back to Village Entrance\n \n";
		}
		cout << locationDesc;
		while (playerchoice != 3)
		{
			//cout << locationDesc;
			playerchoice = validate.inputValidation();
			switch (playerchoice)
			{
			case 1:
				cout << "You look at the garden, the flowers are colorful and smell delightful. \n";
				break;

			case 2:
				if (!playerinventory.SearchInventory("Sage"))
				{
					cout << "You have picked the Sage Herb from the garden! \n ";
					playerinventory.AddItem(TempLocation[3].getItem());
					//playerinventory.DisplayInventory();
					//Player.DisplayInventory();
					//TempLocation[2].setLocationDesc("[1] Go to bar\n [3] Go back to Village Entrance\n \n");
					locationDesc = "[1] Admire the garden \n [3] Go back to Village Entrance\n \n";
					//TempLocation[1].setLocationDesc("With the lantern in hand you head towards the abandoned shack once again.\nIt seems to be made out of a rotting, creeping willow of some kind or another, though it splinters out as a thorny hide.\nIt has a flimsy door held together by sheer luck, and a rusted doorknob is the only thing standing between you and the inside.\nYou pull open the wooden door as you do the door comes off of it's hinges with a loud thunk.\nYou step to the side with an inexplicable calmness as it falls where you were previously standing.\nThe inside of it is  hard to take in as you enter, still wondering.\nThe walls seem warped and as if waves of fabric compared to it's porcupine exterior.\nAn ocean of fine willow, sanded and well maintained like it's floors and a nearby bed.\nThe candles with their wax drapping over windowsills greet you with the faintest flicker, before extinguishing.\nStartled, you notice the new wax drips just below a trapdoor not just a foot away from you.\nIt's fine finished wood and golden knocker whisper to you almost in a wordless alure.\nYou wonder finally, why?\nThe door, the candles, the words, this shack.\nAnd it's with these thoughts, this pause, this hesitation, this fear.\nIt happens.\nWhat do you do?\n Press [1] to open it, Press [2] to return to the village entrance:");
				}
				break;
			}
		}

	}
	else if (locationName == "Tavern")
	{
		if (!playerinventory.SearchInventory("Lantern"))
		{
			locationDesc= "You enter into a tavern with bright almost blinding light.It is noisy as people chat around at the bar and entrance.\nYou are able to squeeze your way into the main room, most people have not taken notice of youand proceed about their bussiness.\nThere lays the bar to your right that carries the smells of beer to you alongside other aromas.\nYou also see on your left a fine finished table with a lantern on it.\n \n[1] Go to bar \n[2] Pick up lantern from table \n[3] Exit\n";
			
		}
		if (playerinventory.SearchInventory("Lantern"))
		{
			locationDesc = "[1] Go to bar\n [3] Go back to Village Entrance\n \n";
		}
		cout << locationDesc;
		while (playerchoice != 3)
		{
			//cout << locationDesc;
			playerchoice = validate.inputValidation();
			switch (playerchoice)
			{
			case 1:
				cout << "You sit at the bar, and grab a quick drink. None of the locals are very friendly. \n";
				break;

			case 2:
				if (!playerinventory.SearchInventory("Lantern"))
				{
					cout << "You have picked up the lantern from the table! \n ";
					playerinventory.AddItem(TempLocation[2].getItem());
					//playerinventory.DisplayInventory();
					//Player.DisplayInventory();
					//TempLocation[2].setLocationDesc("[1] Go to bar\n [3] Go back to Village Entrance\n \n");
					locationDesc = "[1] Go to bar\n [3] Go back to Village Entrance\n \n";
					//TempLocation[1].setLocationDesc("With the lantern in hand you head towards the abandoned shack once again.\nIt seems to be made out of a rotting, creeping willow of some kind or another, though it splinters out as a thorny hide.\nIt has a flimsy door held together by sheer luck, and a rusted doorknob is the only thing standing between you and the inside.\nYou pull open the wooden door as you do the door comes off of it's hinges with a loud thunk.\nYou step to the side with an inexplicable calmness as it falls where you were previously standing.\nThe inside of it is  hard to take in as you enter, still wondering.\nThe walls seem warped and as if waves of fabric compared to it's porcupine exterior.\nAn ocean of fine willow, sanded and well maintained like it's floors and a nearby bed.\nThe candles with their wax drapping over windowsills greet you with the faintest flicker, before extinguishing.\nStartled, you notice the new wax drips just below a trapdoor not just a foot away from you.\nIt's fine finished wood and golden knocker whisper to you almost in a wordless alure.\nYou wonder finally, why?\nThe door, the candles, the words, this shack.\nAnd it's with these thoughts, this pause, this hesitation, this fear.\nIt happens.\nWhat do you do?\n Press [1] to open it, Press [2] to return to the village entrance:");
				}
				else
				{
					cout << "Invalid!";
				}
				break;
			}
		}
			
	}
	else if (locationName == "Tunnel")
	{
		
		if (isinTunnel == 1)
		{
			locationDesc = "You see two pathways ahead of you, one to the left and one that continues straight. \n ";
		}
		cout << locationDesc;
		if (!playerinventory.SearchInventory("Sword"))
		{
			cout << "A rusty sword lays on the ground in front of you.\n It looks like it was left long ago by a weary traveler.\n[1] Pick up sword \n[3] Continue onward\n";
			
		}
		if(playerinventory.SearchInventory("Sword"))
		{
			cout << "[3] Continue Onward\n";
		}
		
		while (playerchoice != 3)
		{
			//cout << locationDesc;
			playerchoice = validate.inputValidation();
			switch (playerchoice)
			{
			case 1:
				if (!playerinventory.SearchInventory("Sword"))
				{
					cout << "You have picked up the Rusty Sword from the ground! \n ";
					playerinventory.AddItem(TempLocation[4].getItem());
					locationDesc = "[3] Continue Onwards\n \n";
				}
				
				else
				{
					cout << "Invalid";
				}
				break;

			case 3:
				if (!playerinventory.SearchInventory("Sword"))
				{
					cout << "You glance over the sword and decide you will leave it there.\n";
				}
				break;
			default:
				cout << "Invalid";
				break;
			}
		}
	}
	else if (locationName == "Left Tunnel Room")
	{
		GameClass Death1;
		isinTunnel = 1;
		string playerchoice = "";
		cout << locationDesc << endl;
		cout <<"(Y for yes, anything else for no)\n ";
		cin >> playerchoice;
		if (playerchoice == "Y" || playerchoice == "y")
		{
			Death1.FirstDeath();
			locationName = "...";
			locationDesc = "You find your eyes are hazy, you open them. Theres nothing around you but what appears to be a door back to where you started...";
			northDoor = "Village Entrance";
			southDoor = "";
			westDoor = "";
			eastDoor = "";
			taskDone[locationsize] = { false };
			playerinventory.RemoveAllItems();
		}
		else
		{
			locationDesc = "You stand just far enough away from danger, you are able to go back from where you are standing. ";
		}
		cout << locationDesc;
	}
	else if (locationName == "Mysterious Room")
	{
		string playerchoice = "";
		GameClass Puzzle;
		cout << "You are in a rigid, uneven granite room difficult to walk in. You see up ahead of you a dead end across the granite with nothing left to show signs of life or means of escape however,\n as you get close you start to notice that there may be something to this. You see etchings into the granite with your lantern." << endl;
		if (!taskDone[5])
		{
			cout << "There seems to be some sort of puzzle written into this wall. Should you try to solve it? (Y for yes, anything else for no)\n ";
			cin >> playerchoice;
			if (playerchoice == "Y" || playerchoice == "y")
			{
				Puzzle.TunnelPuzzle();
				cout << "A Door Appears to open from within the wall in front of you. Would you like to go through it?\n";
				northDoor = "Staircase Room";
				taskDone[5] = true;
			}
		}
		if (taskDone[5])
		{
			northDoor = "Staircase Room";
		}
		else
		{

		}

	}
	else if (locationName == "Staircase Room")
	{
	
		GameClass Game;
		STAIRS:
		if (!taskDone[7])
		{
			cout << "A ghostly presence is in the room. A wraith appears in front of you\n What would you like to do?\n ";
			
			while (playerchoice != 3)
			{
				locationDesc = "[1] Use an Item \n[2] Talk to the Wraith\n[3] Leave\n";
				cout << locationDesc;
				playerchoice = validate.inputValidation();
				switch (playerchoice)
				{
				case 1:
				{
					string use = Game.UseMenu(playerinventory, roomObject);
					if (use == "Sword")
					{
						cout << "You lunge towards the Wraith with your sword, but it goes right through it! \n";
					}
					else if (use == "Sage")
					{
						cout << "You put the Sage herbs to the lantern, lighting it on fire. Smoke fills the room and the Wraith shrieks as it fades away. \n";
						//playerinventory.RemoveItem("Sage");
						northDoor = "Mysterious Door";
						taskDone[7] = true;
						locationDesc = "Press [3] to exit";
						goto STAIRS;
						break;
					}
					else
					{
						cout << "Nothing Happens\n";
					}
					break;
				}
				case 2:
				{
					cout << "You try to talk to the Wraith, but it screams in your face\n";
					break;
				}
				default:
					cout << "Invalid";
					break;
				}
			}
		}
		else if (taskDone[7])
		{
			cout << "The path to the staircase is clear, and a mysterious door with light surrounding its edges is at the top\n";
			northDoor = "Mysterious Door";
		}
	}
	else if (locationName == "Mysterious Door")
	{
		locationDesc = "You approach the mysterious door you managed to open, you can peel back the slab to head outside it seems.\n";
		cout << locationDesc;
	}
	else if (locationName == "Hilly Fields")
	{
		locationDesc = "As you step outside you squint from the morning haze, it only takes you another moment to notice the fog.\nIt's thick enough that on any other morning you'd be blinded by it's light.\nInstead you're blinded by this mist. You can barely see in front of you.\nYour fire is going down from your lamp, you need more light.\nYou see the silhoutte of a large structure to your north, and a long path that winds across the hills towards it.\nYou see a shadowy structure to the west that appears to be a bit closer.\nIt is difficult to make it all out clearly.\nWhere do you go?\n";
		cout << locationDesc;
	}
	else if (locationName == "Cemetary")
	{
		//bool ThiefisAlive = true;
		GameClass Game;
		cout << locationDesc;
		while (playerchoice != 3)
		{

			if (!taskDone[10])
			{
				
				cout<<"\n[1] Talk to the figure \n[2] Use item\n[3] Leave\n";
				playerchoice = validate.inputValidation();
				switch (playerchoice)
				{
					case 1:
					{
						cout << "You approach the figure until you can just barely make out their face. They reveal themselves to be a thief graverobber.\n They casually go about their business digging up and peeling jewelry off of various corpses.\n They happen to have what looks like children's toys and other knick-knacks from the recently deceased on their person.\n He asks you if you're new around here, casually indifferent to the actions he is doing.\n";
						break;
					}
					case 2:
					{
						string use = Game.UseMenu(playerinventory, roomObject);
						if (use == "Sword")
						{
							cout << "You lunge towards the thief with your sword, stabbing him straight through his twisted heart.\n He doubles back in pain, slumping to the ground like a sack of grain, and like one he spills to the ground. Instead of grain, he spills out blood from his wound and mouth.\n He is now dead, his ill-gotten goods are now yours.\n Unfortunately, you have little use for most of his wares, except for a small stash of lamp oil. You take it hastily.\n\n[1] Inspect the Graves \n[2] Inspect Body\n[3] Leave\n";
							//ThiefisAlive = false;
							taskDone[10] = true;
							playerinventory.AddItem("Lamp Oil");
							//cout << "Is the theif alive????????" << ThiefisAlive;
							break;
						}
						else if (use == "Lantern")
						{
							cout << " 'Watch where you're swingin' that thing lad. I don't need new scars.' ";
						}
						else if (use == "Sage")
						{
							cout << " 'I have no time for witchy things.' ";
						}
						else
						{
							cout << "Nothing Happens\n";
						}	
						break;
					}
					default:
					cout << "Invalid";
					break;
				}
				
			}
			else if (taskDone[10])
			{
				locationDesc = "You are in the decrepid cemetary.\n The dates indicate that some of these graves have been here for hundreds of years.\n Most are too weathered to be legible anymore.\n The thief's lifeless body lays on the ground.\n\n[1] Inspect the Graves \n[2] Inspect Body\n[3] Leave\n";
				cout << locationDesc;
				playerchoice = validate.inputValidation();
				switch (playerchoice)
				{
					case 1:
					{
						cout << "The graves are weathered.\n";
						break;
					}
					case 2:
					{
						cout << "The thief's body is already being violated by various bugs and insects. The sight of it all reminds you of what just took place and you gag. Best to not look.\n";
						
						break;
					}
					default:
					cout << "Invalid\n\n";
					break;
				}			
			}
		}
	}
	else if (locationName == "Winding Path")
	{
		if (playerinventory.SearchInventory("Lamp Oil"))
		{
			northDoor = "Castle Gate";
			locationDesc = "";
			cout << locationDesc;
		}
		else
		{
			locationDesc = "You keep walking forward, but the fog becomes too much for you to handle, you're certain that there has to be another way through the fog. You luckily still know the way back.\n";
			northDoor = "";
			cout << locationDesc;
		}
	}
	else if (locationName == "Castle Gate")
	{
	cout << locationDesc;
	}
	else if (locationName == "Castle Courtyard")
	{
	cout << locationDesc;
	}
	else if (locationName == "Castle Waiting Room")
	{
	cout << locationDesc;
	}
	else if (locationName == "Castle Throne Room")
	{
		cout<< "You stand before the castle throne room.\nFrustrated, desperate you approach the throne.\nIt is a gilded majestic sight to behold.\nBut you have no care for these things\nYou want to just have this over.\nYou want to wake up.\nBut I won't let you.";
		system("pause");
		cout<< "\nOh you're surprised?\nDon't be, you saw this coming no doubt.\nOr have you regressed so far?\nI suppose you would've had to.\nI sit up and walk towards you.\nI share your frustrations.\nYour horror.\nThat is why I made this place.\nLook at it.";
		system("pause");
		cout << "\nIt's home.\nIt's peaceful.\nIt's everything a dream could ask for.\nI only had to subject myself to sleep.";
		system("pause");
		cout << "\nI knew you would have to pass the final strand and fall into the abyss.\nSo I set up this fort and waited.\nI got so bored I guided you here.\nBecause I mean to end this.";
		system("pause");
		cout << "\nYou pulled out your trump card though haven't you?\nYou forgot.\nYou were so close to giving in.\Just finally letting me live in fantasy.\nBut you forgot and thus now intend to wake up.\nOr you would anyway in time.\nSo I gave you your 'quest'....";
		system("pause");
		cout << "\nYou understand?\nI embraced our nightmare.\nWipe that expression off your face.\nDon't you understand how ugly we look like that?\nMust I spell it out again.\nI am your deep conscience.\nI AM YOU.";
		system("pause");
		cout << "\nI would rather spend our entire lives in this nightmare.\nIt's so much better than the reality we subjected ourselves to.\nIn time it's ugly now but I may be able to make it beautiful.\nBecause it's ours.\nNobody else's.";
		system("pause");
		cout << "\nBut you, you always insist on awaking.\nSo I'll keep killing you until you give in.\nI'd do this for an eternity if I must.";
		system("pause");
		cout << "\nI will scar myself if need be.\nI will be the worst nightmare of myself.\nI give a devilish smirk to you as you find it revolting.\nYou ready yourself to fight as always.\nOh how I can't wait to finish this.\n[Enter the combat]\n";
	}

	else
	{
		cout << "No Options Currently Available" << endl;
	}
}
	
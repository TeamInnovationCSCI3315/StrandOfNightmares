#include "Locations.h"
#include "GameClass.h"
#include "Inventory.h"
#include "UI.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "InputValidation.h"
#include "FinalBoss.h"

using namespace std;
/*
	Constructors for the location and instances for location description and name, and returns these values.
	Location Constructor stores Location Name, Description, and Adjacent doors North, South, East, and West, a well as an Item, and an NPC/Object to interact with
*/
bool trollEating = false;

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
If(locationName == "Room")
{
Do this:
}

*/
void Locations::LocationActions(Locations TempLocation[], Inventory& playerinventory, int locationsize, FinalBoss& GameOver)
{

	int playerchoice = 1;
	if (locationName == "Village Entrance")
	{

	}
	else if (locationName == "Abandoned Shack")
	{
		if (playerinventory.SearchInventory("Lantern"))
		{
			southDoor = "Tunnel";
		}
		else
		{
			southDoor = "";
		}
	}
	else if (locationName == "Village Garden")
	{
		if (!playerinventory.SearchInventory("Sage"))
		{
			cout << "[1] Admire garden \n[2] Pick herb \n[3] Return to menu\n";
		}
		if (playerinventory.SearchInventory("Sage"))
		{
			cout << "[1] Admire garden \n [3] Return to menu\n \n";
		}

		while (playerchoice != 3)
		{
			playerchoice = validate.inputValidation();
			switch (playerchoice)
			{
			case 1:
				cout << "You look at the garden, the flowers are colorful and smell delightful. \n You wonder who is responsible for the upkeep of this garden.\n";
				break;

			case 2:
				if (!playerinventory.SearchInventory("Sage"))
				{
					cout << "You have picked the Sage Herb from the garden! \n ";
					playerinventory.AddItem(TempLocation[3].getItem());
					cout << "\n[1] Admire the garden \n[3] Return to menu\n \n";

				}
				break;
			}
		}

	}
	else if (locationName == "Tavern")
	{
		if (!playerinventory.SearchInventory("Lantern"))
		{
			cout << "\n[1] Go to bar \n[2] Pick up lantern from table \n[3] Exit\n";
		}
		if (playerinventory.SearchInventory("Lantern"))
		{
			cout << "[1] Go to bar\n [3] Go back to Village Entrance\n \n";
		}

		while (playerchoice != 3)
		{
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
					cout << "[1] Go to bar\n [3] Go back to Village Entrance\n \n";
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
		if (!playerinventory.SearchInventory("Sword"))
		{
			cout << "\n[1] Pick up sword \n[3] Continue onward\n";
		}
		if (playerinventory.SearchInventory("Sword"))
		{

		}

		while (playerchoice != 3)
		{
			playerchoice = validate.inputValidation();
			switch (playerchoice)
			{
			case 1:
				if (!playerinventory.SearchInventory("Sword"))
				{
					cout << "You have picked up the Rusty Sword from the ground! \n ";
					playerinventory.AddItem(TempLocation[4].getItem());
					cout << "[3] Continue Onwards\n \n";
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
		cout << "Do you approach the shadow to inspect it ?" << "\n(Y for yes, anything else for no)\n ";
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

		}
	}
	else if (locationName == "Mysterious Room")
	{
		string playerchoice = "";
		GameClass Puzzle;
		if (!taskDone[5])
		{
			cout << "There seems to be some sort of puzzle written into this wall. Should you try to solve it? (Y for yes, anything else for no)\n ";
			cin >> playerchoice;
			if (playerchoice == "Y" || playerchoice == "y")
			{
				if (Puzzle.TunnelPuzzle())
				{
					cout << "A Door Appears to open from within the wall in front of you. Would you like to go through it?\n";
					northDoor = "Staircase Room";
					taskDone[5] = true;
				}
			}
			else
			{
				northDoor = "";
				taskDone[5] = false;
			}
		}
		else if (taskDone[5])
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
			cout << "A ghostly presence is in the room. A wraith appears in front of you\n";

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
	else if (locationName == "Cemetary")
	{
		GameClass Game;
		cout << locationDesc;
		while (playerchoice != 3)
		{

			if (!taskDone[10])
			{

				cout << "\n[1] Talk to the figure \n[2] Use item\n[3] Leave\n";
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
						cout << "You lunge towards the thief with your sword, stabbing him straight through his twisted heart.\n He doubles back in pain, slumping to the ground like a sack of grain, and like one he spills to the ground. Instead of grain, he spills out blood from his wound and mouth.\n He is now dead, his ill-gotten goods are now yours.\n Unfortunately, you have little use for most of his wares, except for a small stash of lamp oil. You take it hastily.";
						taskDone[10] = true;
						playerinventory.AddItem("Lamp-oil");
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
				cout << "\n\n[1] Inspect the Graves \n[2] Inspect Body\n[3] Leave\n";
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
		if (playerinventory.SearchInventory("Lamp-oil"))
		{
			northDoor = "Castle Gate";
		}
		else
		{

			northDoor = "";
		}
	}

	else if (locationName == "Castle Foyer")
	{
		
		while (playerchoice != 4)
		{
			if (!taskDone[17])
			{
				{
					cout << "\n[1] Talk to troll \n[2] Inspect chandelier\n[3] Use item\n[4] Leave\n";
					playerchoice = validate.inputValidation();
					switch (playerchoice)
					{
					case 1:
					{
						cout << "You approach the troll with peaceful intentions, but he quickly gets in your face. Pressing his spear across your body, he yells: \n'Oy! I don't know who you are, or how you trekked out this far, but you need to go away. \nNo one should be at this castle. There are forces at work here you cannot understand.\n Although, without people it's kinda hard to get a break to eat around here...'\n The troll continues to ramble about his hunger and trails off, forgetting the conversation he was in.";
						break;
					}
					case 2:
					{
						cout << "Taking a closer look at the chandelier, you notice it hangs directly over the bottom of the staircase. \nIf such a thing fell, its sheer size and force could be deadly.";
						break;
					}
					case 3:
					{
						GameClass Game;
						string use = Game.UseMenu(playerinventory, roomObject);
						if (use == "Lantern")
						{
							cout << "The room is already pretty well lit.\n";
							break;
						}
						else if (use == "Sword")
						{
							cout << "There's nothing to swing your sword at here. \nAnd that troll looks like it would swiftly end whatever you try to start with it.\n";
						}
						else if (use == "Sage")
						{
							cout << "Smells nice and fills you with a sense of goodness. But it doesn't do much else right now.\n";
						}
						else
						{
							cout << "Nothing Happens\n";
						}
						break;
					}
					case 4:
					{
						break;
					}
					default:
						cout << "Invalid";
						break;
					}
				}
			}
			if (taskDone[17])
			{
				if (!taskDone[14])
				{
					cout << "\n[1] Talk to troll \n[2] Inspect chandelier\n[3] Use item\n[4] Leave\n";
					playerchoice = validate.inputValidation();
					switch (playerchoice)
					{
					case 1:
					{
						cout << "With the hot soup in hand, you try to bribe the troll. This is unsuccessful.\n Looking just as surprised as the first time he saw you, he questions why you're still loitering but dismisses you before you can answer.\n It seems like his attention span isn't all that great.\n";
						break;
					}
					case 2:
					{
						cout << "Taking a closer look at the chandelier, you notice it hangs directly over the bottom of the staircase. \nIf such a thing fell, its sheer size and force could be deadly.";
						break;
					}
					case 3:
					{
						GameClass Game;
						string use = Game.UseMenu(playerinventory, roomObject);
						if (use == "Soup")
						{
							cout << "You place the bowl soup at the bottom of the stairs and walk just out of view.\n It's not long before the troll catches a whiff and runs down the stairs to it. He digs his face in ravenously. \nHe is too engaged with eating to notice anything going on around him.\n";
							taskDone[14] = true;
							trollEating = true;
							playerinventory.RemoveItem("Soup");
							break;
						}
						else if (use == "Sword")
						{
							cout << "There's nothing to swing your sword at here. \nAnd that troll looks like it would swiftly end whatever you try to start with it.\n";
						}
						else if (use == "Sage")
						{
							cout << "Smells nice and fills you with a sense of goodness. But it doesn't do much else right now.\n";
						}
						else if (use == "Lantern")
						{
							cout << "The room is just as well lit as it was earlier.\n";
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
				else if (trollEating == true)
				{
					if (!taskDone[15])
					{
						cout << "[1] Talk to troll \n[2] Inspect chandelier \n[3] Use item \n[4] Leave\n";
						playerchoice = validate.inputValidation();
						switch (playerchoice)
						{
						case 1:
						{
							cout << "The troll is busy stuffing his face. He barely realizes that you are next to him. \n";
							break;
						}
						case 2:
						{
							cout << "The chandelier is hanging exactly where it was earlier. The troll is standing underneath it licking the soup bowl inside and out.\n";
							break;
						}
						case 3:
						{
							GameClass Game;
							string use = Game.UseMenu(playerinventory, roomObject);
							if (use == "Lantern")
							{
								cout << "With the troll gorging himself, you quietly make your way over to the nearby rope connected to the chandelier. \nYou open your lantern and watch as the fire slowly climbs up the fibers of the rope. \nThe final support snaps and the light fixture comes crashing down on the troll with a massive thud, painting the surrounding walls with his insides.\n The force was so strong it shook loose the door to the throne room, revealing the entrance.\n";
								northDoor = "Castle Throne Room";
								taskDone[15] = true;
								break;
							}
							else if (use == "Sword")
							{
								cout << "The chandelier is sitting at a height that you couldn't possibly reach with your sword. \nYou consider hitting the troll, but without he's moving around too much to get a worthwhile hit. Anything you do would probably just anger him.\n";
							}
							else if (use == "Sage")
							{
								cout << "Smells nice and fills you with a sense of goodness. But it doesn't do much else right now.\n";
							}
							else
							{
								cout << "Nothing Happens\n";
							}
							break;
						}
						default:
							cout << "Invalid\n\n";
							break;
						}
					}
					else if (taskDone[15])
					{
						cout << "\n\n[1] Admire gore \n[2] Inspect shattered chandelier \n[3] Use item \n[4] Leave\n";
						playerchoice = validate.inputValidation();
						switch (playerchoice)
						{
						case 1:
						{
							cout << "There is an unholy amount of blood everywhere. You are in shock at the sight of it all.\n";
							break;
						}
						case 2:
						{
							cout << " All that is left is a pile of broken, twinkling crystal glass.\n";
							break;
						}
						case 3:
						{
							cout << "You've already done enough damage in this room. \nSave your items for whatever lies through the door to the throne room.";
							break;
						}
						default:
							cout << "Invalid\n\n";
							break;
						}

					}
				}
			}
		}
	}

	else if (locationName == "Castle Kitchen")
	{
	while (playerchoice != 3)
	{
		if (!taskDone[17])
		{

			cout << "\n[1] Inspect stove \n[2] Use item\n[3] Leave\n";
			playerchoice = validate.inputValidation();
			switch (playerchoice)
			{
			case 1:
			{
				cout << "You peer into the pot on the stove.\nUsing the light from your lantern, you identify a hearty stew.\nIt doesn't look that old.\nHungry from your journey, you try to turn it on. \nThere is no electrical power, but you hear the hiss of gas.\n";
				break;
			}
			case 2:
			{
				GameClass Game;
				string use = Game.UseMenu(playerinventory, roomObject);
				if (use == "Lantern")
				{
					cout << "You open your lantern and slowly move it close to the stove. \nAll of a sudden, the fire catches the gas and huge flame erupts! \nYou duck as quickly as you can to avoid the fireball, and upon standing back up, you see a bubbling pot of soup.\n You procure a nearby bowl and ladle and serve yourself, but there's no time to eat just yet!";
					taskDone[17] = true;
					playerinventory.AddItem("Soup");
					break;
				}
				else if (use == "Sword")
				{
					cout << "Now you have a sword with soup dripping off the end. You're making a mess of the kitchen.\n";
				}
				else if (use == "Sage")
				{
					cout << "This soup smells like it has more than enough seasoning.\n";
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
		else if (taskDone[17])
		{
			cout << "\n\n[3] Leave\n";
			playerchoice = validate.inputValidation();
			switch (playerchoice)
			{
			case 1:
			{
				cout << "Invalid\n\n";
				break;
			}
			case 2:
			{
				cout << "Invalid\n\n";
				break;
			}
			case 3:
			{
				break;
			}
			default:
				cout << "Invalid\n\n";
				break;
			}

		}
	}
		
	}
	else if (locationName == "Castle Throne Room")
	{
		if (!taskDone[15])
		{
			cout << "You stand before the castle throne room.\nFrustrated, desperate you approach the throne.\nIt is a gilded majestic sight to behold.\nBut you have no care for these things\nYou want to just have this over.\nYou want to wake up.\nBut I won't let you.";
			system("pause");
			cout << "\nOh you're surprised?\nDon't be, you saw this coming no doubt.\nOr have you regressed so far?\nI suppose you would've had to.\nI sit up and walk towards you.\nI share your frustrations.\nYour horror.\nThat is why I made this place.\nLook at it.";
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
			cout << "\nI will scar myself if need be.\nI will be the worst nightmare of myself.\nI give a devilish smirk to you as you find it revolting.\nYou ready yourself to fight as always.\nOh how I can't wait to finish this.\n\n";
			FinalBoss Boss;
			if (Boss.IsFinalBossBeaten())
			{
				system("pause");
				cout << endl << "\033[1;32m" << "You have defeated the boss\n" << "\033[0m";
				//northDoor = "Wake Up";
				taskDone[15] = true;
			}
			else
			{
				cout << endl << "\033[1;31m" << "You have been defeated\n" << endl << endl << "Game Over" << endl << endl << "\033[0m";

				system("pause");
				system("CLS");
				GameOver.setGameOver(true);

			}
		}
		else
		{
			cout << "You stand before the corpse of yourself, finally it's over.\nYou feel the dream fadding from you, the walls of the castle crumble into nothingness as the world around you fades.\nThis fantasy, this illusion, this nightmare, was nothing more than such after all.\nYou stand before the pit of emptiness.\nWaiting.\nWaiting.\nAnd waiting.\nIt too fades, you close your eyes for what seems to be the last time.\nAnd that is when they open, the sun peering through the window, your surroundings familiar to you.\nYou are back in reality.\nFinally after the struggle.\nYou can take on the day knowing that, everything you do is real.\n \n Thank you for waking now go out and face the world.";
			system("pause");
			system("CLS");
			GameOver.setGameOver(true);
		}
	}

	else
	{
		cout << "No Options Currently Available" << endl;
	}
}

/*
* This function allows a player to replay the description of the area they are, without having to open the interact menu.
*
*/
void Locations::LocationLook(Locations TempLocation[], Inventory& playerinventory, int locationsize)
{

	int playerchoice = 1;
	if (locationName == "Village Entrance")
	{
		locationDesc = "You find yourself looking at a village as you sit at the entrance of it. There is the light hooting of an owl as you start walking.\nAs you look around you notice how dark it is, the village allows you to barely maneuver around with the faint candlelight from the street lamps.\nIn one direction, following the road to the east you notice a tavern up ahead with bright lights and the sounds of commerce. This could be a good place to find information and help and it is probably the brightest place.\nIn the other direction you notice the lights grow scarcer and scarcer until you can barely see the outline of what seems to be an abandoned shack, something draws you to it's shadow, curiosity maybe?\n ";
		cout << locationDesc;
	}
	else if (locationName == "Abandoned Shack")
	{
		if (playerinventory.SearchInventory("Lantern"))
		{
			locationDesc = "With the lantern in hand you head towards the abandoned shack once again.\nIt seems to be made out of a rotting, creeping willow of some kind or another, though it splinters out as a thorny hide.\nIt has a flimsy door held together by sheer luck, and a rusted doorknob is the only thing standing between youand the inside.\nYou pull open the wooden door as you do the door comes off of it's hinges with a loud thunk.\nYou step to the side with an inexplicable calmness as it falls where you were previously standing.\nThe inside of it is  hard to take in as you enter, still wondering.\nThe walls seem warped and as if waves of fabric compared to it's porcupine exterior.\nAn ocean of fine willow, sandedand well maintained like it's floors and a nearby bed.\nThe candles with their wax drapping over windowsills greet you with the faintest flicker, before extinguishing.\nStartled, you notice the new wax drips just below a trapdoor not just a foot away from you.\nIt's fine finished wood and golden knocker whisper to you almost in a wordless alure.\nYou wonder finally, why ? \nThe door, the candles, the words, this shack.\nAnd it's with these thoughts you wonder, should you go down the trapdoor? There seems to be some sort of tunnel underneith the door, but it doesnt seem possible to return. \n";
			cout << locationDesc;
		}
		else
		{
			locationDesc = "After walking you arrive at the pitch black shack, it's presence alone stands as if you could die and it wouldn't so much as creek.\nAs you approach it closer to inspect the strange building you find that it becomes far too dark to see and proceed forward, at least safely.\nDo you decide to exit now ? \n";
			cout << locationDesc;
		}
	}
	else if (locationName == "Village Garden")
	{

			locationDesc = "You enter the garden.\nIt is full of fresh smelling herbs, but one scent is particularly strong. \nThere is flora all around you.\n\n";// [1] Admire garden \n[2] Pick herb \n[3] Exit\n";
			cout << locationDesc;

	}
	else if (locationName == "Tavern")
	{
		if (!playerinventory.SearchInventory("Lantern"))
		{
			locationDesc = "You enter into a tavern with bright almost blinding light. It is noisy as people chat around at the bar and entrance.\nYou are able to squeeze your way into the main room, most people have not taken notice of you  and proceed about their bussiness.\nThere lays the bar to your right that carries the smells of beer to you alongside other aromas.\nYou also see on your left a fine finished table with a lantern on it.\n";
			cout << locationDesc;
		}
		if (playerinventory.SearchInventory("Lantern"))
		{
			locationDesc = "You enter into a tavern with bright almost blinding light. It is noisy as people chat around at the bar and entrance.\nYou are able to squeeze your way into the main room, most people have not taken notice of you and proceed about their bussiness.\nThere lays the bar to your right that carries the smells of beer to you alongside other aromas.\n";
			cout << locationDesc;
		}
	}
	else if (locationName == "Tunnel")
	{
		if (isinTunnel == 1)
		{

		}
		cout << locationDesc;
		if (!playerinventory.SearchInventory("Sword"))
		{
			locationDesc = "You look up to find the trapdoor you entered from, out of reach.\n Looking around you notice you're in a cramped cavern.\n It is granite like with it's soft shimmer the walls give off as your lantern's light hits and exits the speckled walls.\n You see two pathways ahead of you, one to the left and one that continues straight.\n";
			cout << locationDesc;
			cout << "A rusty sword lays on the ground in front of you.\n It looks like it was left long ago by a weary traveler.\n";  // \n[1] Pick up sword \n[3] Continue onward\n";

		}
		if (playerinventory.SearchInventory("Sword"))
		{
			cout << locationDesc;
		}
	}
	else if (locationName == "Left Tunnel Room")
	{
		GameClass Death1;
		isinTunnel = 1;
		string playerchoice = "";
		locationDesc = "As you go down the pathway to the left the granite gives way to finished stonework.\n You see at the end a shadow.\n But not just any shadow, a darkness your light fails to illuminate from where you're standing.\nIt's disorienting to your eyes, and startles your stomach as you try to make out what it is.\n A faint moaning can be heard, it seems to be alive\n You consider approaching the shadow to inspect it, but you have no idea how deadly this encounter could be.\n";
		cout << locationDesc << endl;
	}
	else if (locationName == "Mysterious Room")
	{
		string playerchoice = "";
		GameClass Puzzle;
		locationDesc = "You are in a rigid, uneven granite room difficult to walk in. You see up ahead of you a dead end across the granite with nothing left to show signs of life or means of escape however,\n as you get close you start to notice that there may be something to this. You see etchings into the granite with your lantern.\n";
		cout << locationDesc;
	}
	else if (locationName == "Staircase Room")
	{

		GameClass Game;

		if (!taskDone[7])
		{
			cout << "A ghostly presence is in the room. A wraith appears in front of you\n";
		}
		else if (taskDone[7])
		{
			cout << "The path to the staircase is clear, and a mysterious door with light surrounding its edges is at the top\n";
		}
	}
	else if (locationName == "Mysterious Door")
	{
		locationDesc = "You approach the mysterious door you managed to open, you can peel back the slab to head outside it seems.\n";
		cout << locationDesc;
	}
	else if (locationName == "Hilly Fields")
	{
		locationDesc = "As you step outside you squint from the morning haze, it only takes you another moment to notice the fog.\nIt's thick enough that on any other morning you'd be blinded by it's light.\nInstead you're blinded by this mist. You can barely see in front of you.\nYour fire is going down from your lamp, you need more light.\nYou see the silhoutte of a large structure to your north, and a long path that winds across the hills towards it.\nYou see a shadowy structure to the west that appears to be a bit closer.\nIt is difficult to make it all out clearly.\n";
		cout << locationDesc;
	}
	else if (locationName == "Cemetary")
	{
		GameClass Game;
		cout << locationDesc;
	}
	else if (locationName == "Winding Path")
	{
		if (playerinventory.SearchInventory("Lamp-oil"))
		{
			locationDesc = "You see northward what seems to be a castle of some sorts, it's shape you're barely able to make out in the distance.\n";
			cout << locationDesc;
		}
		else
		{
			locationDesc = "You keep walking forward, but the fog becomes too much for you to handle, you're certain that there has to be another way through the fog. You luckily still know the way back.\n";
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
	else if (locationName == "Castle Foyer")
	{
		if (!taskDone[17])
		{
			{
				cout << locationDesc;
			}
		}
		if (taskDone[17])
		{
			if (!taskDone[14])
			{
				cout << locationDesc;
			}
			else if (trollEating == true)
			{
				if (!taskDone[15])
				{
					locationDesc = "You enter the waiting room of the castle.\nIt is warm, everywhere has been uncomfortably chilly.\nOr they made your spine shiver at least.\nWhy not this place?\nYou find no obvious gateway to the throne room.\nThere are, however, doorways to your left and right. The troll is at the bottom of the stairs, eating as though he hadn't in years.\n Above the staircase hangs a gigantic, precarious chandelier.\nFollowing the top of the fixture, you see a rope that follows the slant of the ceiling and hangs along the wall. \n";
					cout << locationDesc;
				}
				else if (taskDone[15])
				{
					locationDesc = "The walls are dripping with hot, bubbling red liquid.\n The troll's body has been spread out across the room in a waythat you can't tell what chunks came from where. Broken glass is everywhere at your feet.\n";
					cout << locationDesc;
				}
			}
		}
	}
	else if (locationName == "Castle Gallery")
	{
		cout << locationDesc;
	}	
	else if (locationName == "Castle Hall")
	{
		cout << locationDesc;
	}
	else if (locationName == "Castle Kitchen")
	{
		if (playerinventory.SearchInventory("Soup"))
		{
			locationDesc = "You are in a large stone kitchen. \nA pleasant heat radiates from every brick in the wall.\n";
		}
		cout << locationDesc;
	}
	else
	{
	cout << locationDesc;
	}
}

	
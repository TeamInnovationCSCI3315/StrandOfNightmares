// TeamInnovationAdventureGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "PlayerClass.h"
#include "GameClass.h"
#include "UI.h"
#include "Locations.h"
#include "Inventory.h"
#include "FinalBoss.h"
#include <iostream>
using namespace std;
/*
This file in particular contains the player choice, calls locations, UI and GameClass from the respective header file.
This is done to run the game for the user and provides the main code, such as asking for the player choice to be 
processed in the GameClass, Locations and UI.
*/
int main()
{
	int playerchoice;
	/*Inventory VillageEntranceInventory;
	Inventory AbandonedShackInventory;
	Inventory TavernInventory;
	Inventory TunnelInventory;*/
	Inventory PlayerInventory;
	GameClass Game;
	FinalBoss Final;
	/*
	Multiple rooms are created Location(Location Name, Location Description, North Room, South Room, East Room, West Room, item within room, object within room: NPC);
	All will be strings, if there is no value for one, set to ""
	*/
	Locations VillageEntrance("Village Entrance", "You find yourself sitting at the entrance of a village. \nThere is the light hooting of an owl as you start walking.\nAs you look around you notice how dark it is.\nThe village allows you to barely maneuver around with candlelight from street lamps.\nIn one direction, following the road to the east you notice a tavern. \nIt has bright lights and the sounds of commerce. \nThis could be a good place to find information and help and it is probably the brightest place. \nIn the path directly in front of you lies a well lit garden. \nIn the other direction you notice the lights grow scarcer and scarcer. \nYou can barely see the outline of what seems to be an abandoned shack. \nSomething draws you to it's shadow, curiosity maybe?\n ", "Village Garden", "", "Tavern", "Abandoned Shack", "","");
	Locations AbandonedShack("Abandoned Shack", "After walking you arrive at the pitch black shack, it's presence alone stands as if you could die and it wouldn't so much as creek.\nAs you approach it closer to inspect the strange building you find that it becomes far too dark to see and proceed forward, at least safely.\nDo you decide to exit now? \n ", "", "", "Village Entrance", "", "", "");
	Locations Tavern("Tavern", "You enter into a tavern with bright almost blinding light. It is noisy as people chat around at the bar and entrance.\nYou are able to squeeze your way into the main room, most people have not taken notice of you and proceed about their bussiness.\nThere lays the bar to your right that carries the smells of beer to you alongside other aromas.\nYou also see on your left a fine finished table with a lantern on it.\n \n [1] Go to bar \n [2] Pick up lantern from table \n [3] Exit\n ", "", "", "", "Village Entrance", "Lantern","");
	Locations VillageGarden("Village Garden", "Village Garden description", "", "Village Entrance", "", "", "Sage", "");
	Locations Tunnel("Tunnel", "You awake on the floor, a throbbing pain coming from your head.\nAs you open your eyes by some miracle the lantern is lit next to your head.\nYou arise, lantern in hand to find a crimson streak on the ground where you laid.\nYou look up to find the trapdoor you entered from, out of reach.\nLooking around you notice you're in a cramped cavern.\nIt is granite like with it's soft shimmer the walls give off as your lantern's light hits and exits the speckled walls.\nYou see two pathways ahead of you, one to the left and one that continues straight\n", "Mysterious Room", "", "", "Left Tunnel Room", "Sword","");
	Locations MysteriousRoom("Mysterious Room", "You are in a rigid, uneven granite room difficult to walk in.\n", "", "Tunnel", "", "Left Tunnel Room", "","");
	Locations LeftTunnelRoom("Left Tunnel Room", "As you go down the pathway to the left the granite gives way to finished stonework.\n You see at the end a shadow.\n But not just any shadow, a darkness your light fails to illuminate from where you're standing.\nIt's disorienting to your eyes, and startles your stomach as you try to make out what it is.\n A faint moaning can be heard, it seems to be alive\n This could be deadly. Do you approach the shadow to inspect? \n", "", "", "Tunnel", "Mysterious Room", "","");
	Locations StaircaseRoom("Staircase Room", "Staircase Room Description", "", "Mysterious Room", "", "", "", "Wraith");
	Locations MysteriousDoor("Mysterious Door", "You approach the mysterious door you managed to open, you can peel back the slab to head outside it seems.", "", "", "Hilly Fields", "Staircase Room", "","");
	Locations HillyFields("Hilly Fields", "As you step outside you squint from the morning haze, it only takes you another moment to notice the fog.\nIt's thick enough that on any other morning you'd be blinded by it's light.\nInstead you're blinded by this mist. You can barely see in front of you.\nYour fire is going down from your lamp, you need more light.\nYou see the silhoutte of a large structure to your north, and a long path that winds across the hills towards it.\nYou see a shadowy structure to the west that appears to be a bit closer.\nIt is difficult to make it all out clearly.\nWhere do you go?\n", "Winding Path", "", "Mysterious Door", "Cemetary", "","");
	Locations Cemetary("Cemetary", "You are in the decrepid cemetary.\nThe dates indicate that some of these graves have been here for hundreds of years.\nMost are too weathered to be legible anymore.\nYou see a figure walking around, perhaps they are here visiting someone.\n", "", "", "Hilly Fields", "", "","graverobber");
	Locations WindingPath("Winding Path", "You see no clear way ahead the fog is too thick, if your lamp was a bit brighter it may help.", "", "Hilly Fields", "","","","");
	Locations CastleGate("Castle Gate", "The gate of the shadowy structure is an intimidating sight.\nYou realize this is a large, stone castle.\nThe largest you’ve ever seen in your life.\nThe entire structure stands over a large abyss.\nYou expect to see the ocean but as you look down it is simply a void.\nThe gate could never open, you'd think.\nIt’s steel portcullis is rusted and aged to a point.\nYet the gate, like a malicious maw, opens widely for you.\nAs you approach the gate the courtyard is in sight.\nWhere do you go?\n", "Castle Courtyard", "Winding Path", "", "", "", "");
	Locations CastleCourtyard("Castle Courtyard", "As you enter the courtyard the sight of the palace is ominously peaceful.\nFlowers grow in the courtyard.\nRose bushes, though with many thorns, border the courtyard.\nA light rain falls on the courtyard.\nThe rest of this world feels so twisted.\nBirds chirp, leaves rustle.\nAnd it is almost as disturbing as it is beautiful.\nThe grand doors to the castle lay on the path.\n", "Castle Foyer", "Castle Gate", "", "", "", "");
	Locations CastleFoyer("Castle Foyer", "You enter the waiting room of the castle.\nIt is warm, everywhere has been uncomfortably chilly.\nOr they made your spine shiver at least.\nWhy not this place?\nYou find no obvious gateway to the throne room.\nThere are, however, doorways to your left and right. A troll-ish looking guard at the top of a staircase facing north.\n Above the staircase hangs a gigantic, precarious chandelier.\nFollowing the top of the fixture, you see a rope that follows the slant of the ceiling and hangs along the wall. \n", "", "Castle Courtyard", "Castle Gallery", "Castle Hall", "", "");
	Locations CastleGallery("Castle Gallery", "You are surrounded by wonderful and valuable looking paintings.\nOnly someone with a deep passion for the arts would have such a collection.\n You once again question where you are, and who owns this?\n", "", "", "", "Castle Foyer", "", "");
	Locations CastleHall("Castle Hall", "You find yourself in a long, empty room. Judging by the massive table and the chairs lined up on either side, you figure that this place once housed great meals... \nBut for whom?\n", "Castle Kitchen", "", "Castle Foyer", "", "", "Rope");
	Locations CastleKitchen("Castle Kitchen", "You are in a large stone kitchen. \nIt is cold, and feels like a flame hasn't been lit here in ages.\n There is an ancient pot on the stove with something in it.\n ", "", "Castle Hall", "", "", "", "Stove");
	Locations CastleThroneRoom("Castle Throne Room", "You look around at a tranquil throne room, it's throne turned away from you.\nAs you stare at the black and white marble floor, you cleanly see your reflection cleanly bounce off of it.\nThe moonlight glistens across the room as a variety of artifacts lay strewn across it, tools mostly.\nStrangely this room bares a familiar feeling to it you cannot shake.\nYou had to have seen this before.\n", "", "", "", "", "", "");

	Locations PlayerLocation("", "", "", "", "", "", "", "");
	Locations AllLocations[] = { VillageEntrance , AbandonedShack , Tavern , VillageGarden, Tunnel , MysteriousRoom , LeftTunnelRoom, StaircaseRoom, MysteriousDoor, HillyFields, Cemetary, WindingPath, CastleGate, CastleCourtyard, CastleFoyer, CastleGallery, CastleHall, CastleKitchen, CastleThroneRoom };
	const int AllLocationsSize = 19;
	
	// Player starts at Village Entrance, so their initial location is Village Entrance;
	PlayerLocation = VillageEntrance;
	
	// Testing commands. Replace with desired commands below, comment out above starting location:
	/*
	PlayerLocation = HillyFields; // Change location to whatever starting area you want
	PlayerInventory.AddItem("Lantern"); // add items you want
	PlayerInventory.AddItem("Sage");
	PlayerInventory.AddItem("Sword");
	*/
	UI Interface;
	PlayerClass Player();
		cout << "Game Version 1.0" << endl;
		// Display Start Screen
		Interface.DisplayStartScreen(PlayerInventory, PlayerLocation,AllLocations,AllLocationsSize);
		// Display Introduction
		// Interface.DisplayIntroduction();
		while (!Final.IsGameOver()) //Will later be switched to !GameOver
			{
				// Display interface with options
				Interface.Menu(AllLocations, PlayerLocation, PlayerInventory, Game, AllLocationsSize, Final);
			}
		cout << "***********************************************************************************************\n";
		cout << "Thank you for playing! You may open the game again to replay it, or start from a previous save!\n" << endl;
		cout << "***********************************************************************************************\n";
	return 0;
}
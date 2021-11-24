#include "pch.h"
#include "CppUnitTest.h"
#include "../Inventory.cpp"
#include "../Locations.cpp"
#include "../Locations.h"
#include "../Inventory.h"
#include "../GameClass.cpp"
#include "../PlayerClass.cpp"
#include "../InputValidation.cpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TeamInnovationUnitTests
{
	TEST_CLASS(TeamInnovationUnitTests)
	{
	public:
/*Proposed automated tests
	* Verify starting inventory is empty
	* Add a few items to inventory, verify items are present in inventory
	* Verify inventory is NOT empty after adding one item to inventory, adding two items to inventory
	* Clear inventory, verify inventory is empty after removing all items from inventory
	* Add item to inventory, verify item with one letter changed(case) is NOT in inventory
	* Add same item to inventory twice, should see item listed multiple times(but no way to currently verify this in auto test)
	* Add items to inventory with strange(e.g.non - printable characters), verify items are in inventory
	*/
		
		
		TEST_METHOD(VerifyStartingInventoryEmpty)
		{
				// verify initial inventory is empty
			Inventory playerInventory;

			Assert::IsTrue(playerInventory.IsInventoryEmpty());
			// Assert::IsFalse(playerInventory.IsInventoryEmpty()); -- would fail if starting inventory empty
		}

		TEST_METHOD(AddItemsToInventory)		{
				// add items to inventory, verify they exist in inventory
			Inventory playerInventory;

			playerInventory.AddItem("Axe");
			Assert::IsFalse(playerInventory.IsInventoryEmpty());   // verify inventory no longer empty
			playerInventory.AddItem("Mace");

			    // search for items in inventory
			Assert::IsTrue(playerInventory.SearchInventory("Axe"));
			Assert::IsTrue(playerInventory.SearchInventory("Mace"));
			Assert::IsFalse(playerInventory.SearchInventory("Goblin"));

			   // verify inventory is NOT empty
			Assert::IsFalse(playerInventory.IsInventoryEmpty());
		}

		TEST_METHOD(AddItemsToInventoryThenRemoveTheItems) {
			// add items to inventory, verify they exist in inventory
			Inventory playerInventory;

			playerInventory.AddItem("HUMMER");
			Assert::IsFalse(playerInventory.IsInventoryEmpty());   // verify inventory no longer empty
			playerInventory.RemoveAllItems();
			Assert::IsTrue(playerInventory.IsInventoryEmpty());   // verify inventory now empty
			playerInventory.AddItem("Baby Monitor");
			Assert::IsFalse(playerInventory.IsInventoryEmpty());   // verify inventory no longer empty

			// verify that inventory at

		}
		TEST_METHOD(TestGettingItemFromInventory)
		{
			Inventory playerInventory;
			playerInventory.AddItem("Flower");
			playerInventory.AddItem("Pickaxe");
			string getitem = playerInventory.GetItemAt(1);
			Assert::AreEqual(getitem,playerInventory.GetItemAt(1));
		}

		
		TEST_METHOD(TestInventoryForOddCharacters) {
			Inventory playerInventory;
			playerInventory.AddItem("*@#$@a");
			playerInventory.AddItem("&%$$&");
			playerInventory.AddItem("CTRL+C");
			Assert::IsTrue(playerInventory.SearchInventory("*@#$@a"));
			Assert::IsTrue(playerInventory.SearchInventory("&%$$&"));
			Assert::IsTrue(playerInventory.SearchInventory("CTRL+C"));
		}
		/*
		Test if player changes locations. If they go west, they should be moved to Room, if they select North, they should be moved to Room 2 after going to Room
		*/
		TEST_METHOD(TestPlayerLocationChange)
		{
			Locations PlayerLocation("Village", "", "", "", "", "Room", "", "");
			Locations Room("Room", "", "Room 2", "", "Village", "", "", "");
			Locations Room2("Room 2", "", "Village", "", "", "", "", "");
			Locations AllLocations[2] = { Room,Room2 };
			PlayerLocation.CheckLocation(AllLocations, "West", 2);
			string room = "Room";
			Assert::AreEqual(PlayerLocation.getLocationName(), room);
			room = "Village";
			Assert::AreNotEqual(PlayerLocation.getLocationName(), room);
			PlayerLocation.CheckLocation(AllLocations, "North", 2);
			room = "Room 2";
			Assert::AreEqual(PlayerLocation.getLocationName(), room);
			room = "Room 3";
			Assert::AreNotEqual(PlayerLocation.getLocationName(), room);

		}
	};
}

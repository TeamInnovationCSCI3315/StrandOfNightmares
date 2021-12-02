#include "Inventory.h"
#include "UI.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
/*
 * Inventory Class
 *      Maintains inventory (vector<string>) in instance
 *      inventory item is specified as a string, no validation or constraints on string
 *      inventory initialized to <empty> in the Inventory.h file
 *      allows same item name to be added and exist in inventory multiple times
 *      Currently checks user input for display inventory command (hardcoded as 5)
 * 
 * AddItem(string) - pushes an item by its ID (string) into a vector
 * SearchInventory(string) - returns true if item in inventory, false if not (exact match - e.g. case sensitive, white space sensitive)
 *  *** (old description) searchInventory searches to see if an item is within the player's inventory
 * DisplayInventory() - displays the inventory's contents to cout separated by "|" character
 * CallInventory(int) - checks if int == 5 (ie request to display inventory)
 * RemoveAllItems() - clears inventory
 * 
 * New methods:
 *  isUserRequestingToDisplayInventory(int) - returns true if user enters command to display inventory, else returns false
 *  isInventoryEmpty() - returns true if no items in inventory, else returns false
 * 
 * ToDo:
 *    Deprecate CallInventory & replace calls with isUser...() & DisplayInventory()
 *
 * Proposed automated tests
 *   Verify starting inventory is empty
 *   Add a few items to inventory, verify items are present in inventory
 *   Verify inventory is NOT empty after adding one item to inventory, adding two items to inventory
 *   Clear inventory, verify inventory is empty after removing all items from inventory
 *   Add item to inventory, verify item with one letter changed (case) is NOT in inventory
 *   Add same item to inventory twice, should see item listed multiple times (but no way to currently verify this in auto test)
 *   Add items to inventory with strange (e.g. non-printable characters), verify items are in inventory
*/
void Inventory::AddItem(string itemID)
{
	inventory.push_back(itemID);
}

bool Inventory::IsInventoryEmpty() {
	if (inventory.empty()) {
		return true;
	}
	else {
		return false;
	}
}
void Inventory::RemoveAllItems()
{
	while (!inventory.empty())
	{
		inventory.pop_back();
	}
}
/*void Inventory::RemoveItem(string item)
{
	inventory.pop_back(item);
}
*/

void Inventory::DisplayInventory()
{
	int e=0;
	cout << endl << "\033[1;33mInventory: " << endl;
	cout << "--------------------" << endl;

	// loop through all items in inventory
	for (const string i : inventory)
	{
		cout << e+1 << ": " << i << " ";

		// print | after printing item name, except for last item
		if (i != inventory.at(inventory.size() - 1))
		{
			cout << " | ";
		}
		e++;
	}
	if (inventory.empty())
	{
		cout << "INVENTORY IS EMPTY";
	}
	cout << endl << "--------------------" << endl << endl;
	cout << "\033[0m";
}
bool Inventory::SearchInventory(string item)
{
	for (const string i : inventory)
	{
		if (i == item)
		{
			return true;
		}
	}
	return false;
}
/*
Keybind for player to display the inventory
*/
void Inventory::CallInventory(int i)
{
	if (i == 5)
	{
		DisplayInventory();
	}
}
string Inventory::GetItemAt(int i)
{
	return inventory[i-1];
}
int Inventory::GetInventorySize()
{
	return inventory.size();
}
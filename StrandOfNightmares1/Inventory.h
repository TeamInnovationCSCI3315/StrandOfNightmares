#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Inventory
{
private:
	vector<string> inventory = {};
public:
	//string GetInventory();
	// void Choice();
	void DisplayInventory();
	void AddItem(string);
	void RemoveItem(string);
	bool IsInventoryEmpty();
	bool SearchInventory(string);
	void CallInventory(int);
	void RemoveAllItems();
	string GetItemAt(int);
	int GetInventorySize();

};
#endif
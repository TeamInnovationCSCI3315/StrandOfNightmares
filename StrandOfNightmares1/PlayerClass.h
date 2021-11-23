#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Inventory.h"
using namespace std;

class PlayerClass
{
private:
//	vector<string> inventory = {};
	string playername;
public:
	PlayerClass();
	// void Choice();
	void setName(string);
	string getName();
//	void DisplayInventory();
//	void AddItem(string);
//	bool searchInventory(string);
//	void CallInventory(int);
};
#endif
#ifndef LOCATIONS_H
#define LOCATIONS_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "PlayerClass.h"
#include "GameClass.h"
#include "Inventory.h"
#include "InputValidation.h"
#include "FinalBoss.h"
using namespace std;

class Locations
{
private:
	int isinTunnel=0;
	string northDoor;
	string southDoor;
	string eastDoor;
	string westDoor;
	string locationName;
	string locationDesc;
	string item;
	string roomObject;

	bool taskDone[16] = { false };
	Inventory LocationInventory;
	InputValidation validate;


public:
	string getRoomObject();
	string getNorthDoor();
	string getSouthDoor();
	string getEastDoor();
	string getWestDoor();
	string getLocationName();
	string getLocationDesc();
	string getItem();
	void setRoomObject(string);
	void setLocationName(string);
	void setLocationDesc(string);
	Locations(string, string, string, string, string, string, string, string);
	void CheckLocation(Locations[], string, int);
	void LocationActions(Locations[], Inventory&, int, FinalBoss&);
	void LocationLook(Locations[], Inventory&, int);
};
#endif
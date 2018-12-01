#include "Controller.h"
#include <iostream>
#include <cstdlib>

int Controller::ListenSize()
{
	int  value;
	std::cin >> value;
	std::cin.ignore();
	return  value;
}



Labyrinth Controller::GenerateLevel(int width, int height)
{
	Labyrinth lab;
	Item additem;
	lab.LabCreation(width, height);				//initializing labyrthing
	lab.enterx = std::rand() % lab.width;		//adding core obj (enter chest key)
	lab.entery = std::rand() % lab.height;
	do
	{
		lab.keyx = std::rand() % lab.width;
		lab.keyy = std::rand() % lab.height;
	} while (lab.enterx == lab.keyx && lab.keyy == lab.entery);
	additem.CreateItem(1); // 1-key
	lab.rooms[lab.keyx * lab.height + lab.keyy].AddToStash(additem);
	do
	{
		lab.chestx = std::rand() % lab.width;
		lab.chesty = std::rand() % lab.height;
	} while ((lab.enterx == lab.chestx && lab.entery == lab.chesty) || (lab.keyx == lab.chestx && lab.keyy == lab.chesty));

	additem.CreateItem(2); // 2-chest
	lab.rooms[lab.chestx * lab.height + lab.chesty].AddToStash(additem);

	if (lab.enterx > lab.keyx) 						//adding path between core obj
	{
		for (int i = lab.enterx; i > lab.keyx; i--)
		{
			lab.OpenSide(i, lab.entery, 0);
		}
	}
	if (lab.enterx < lab.keyx)
	{
		for (int i = lab.enterx; i < lab.keyx; i++)
		{
			lab.OpenSide(i, lab.entery, 2);
		}
	}
	if (lab.entery > lab.keyy)
	{
		for (int i = lab.entery; i > lab.keyy; i--)
		{
			lab.OpenSide(lab.keyx, i, 3);
		}
	}
	if (lab.entery < lab.keyy)
	{
		for (int i = lab.entery; i < lab.keyy; i++)
		{
			lab.OpenSide(lab.keyx, i, 1);
		}
	}
	if (lab.enterx > lab.chestx)
	{
		for (int i = lab.enterx; i > lab.chestx; i--)
		{
			lab.OpenSide(i, lab.entery, 0);
		}
	}
	if (lab.enterx < lab.chestx)
	{
		for (int i = lab.enterx; i < lab.chestx; i++)
		{
			lab.OpenSide(i, lab.chesty, 2);
		}
	}
	if (lab.entery > lab.chesty)
	{
		for (int i = lab.entery; i > lab.chesty; i--)
		{
			lab.OpenSide(lab.chestx, i, 3);
		}
	}
	if (lab.entery < lab.chesty)
	{
		for (int i = lab.chesty; i < lab.chesty; i++)
		{
			lab.OpenSide(lab.chestx, i, 1);
		}
	}
	for (int i = 0; i < (lab.width * lab.height); i++) //add random doors
	{
		lab.OpenSide(rand() % lab.width, rand() % lab.height, rand() % 4);
	}
	return lab;
}

int Controller::ListenCommand()   // 0-no such command, 1 - move, 2 - get, 3 - drop.
{
	std::getline(std::cin, lastcommand);
	if (lastcommand == "W" || lastcommand == "N" || lastcommand == "E" || lastcommand == "S")
	{
		return 1;
	}
	if (lastcommand.substr(0, 4) == "get ")
	{
		lastcommand = lastcommand.substr(4, lastcommand.length());
		return 2;
	}
	if (lastcommand.substr(0, 5) == "drop ")
	{
		lastcommand = lastcommand.substr(5, lastcommand.length());
		return 3;
	}
	return 0;
}

Controller::Controller()
{
}


Controller::~Controller()
{
}


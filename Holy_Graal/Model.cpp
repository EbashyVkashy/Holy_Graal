#include "Model.h"
#include <iostream>
bool Model::CheckWidth(int x)
{
	if (x > 3 && x < 50)
	{
		return true;
	}
	return false;
}

bool Model::CheckHeight(int y)
{
	if (y > 3 && y < 50)
	{
		return true;
	}
	return false;
}

void Model::GenerateLevel()
{
	Item additem;
	labyrinth.LabCreation(labyrinth.width, labyrinth.height);				//initializing labyrthing
	
	labyrinth.enterx = std::rand() % labyrinth.width;		//adding core obj (enter chest key)
	labyrinth.entery = std::rand() % labyrinth.height;
	do
	{
		labyrinth.keyx = std::rand() % labyrinth.width;
		labyrinth.keyy = std::rand() % labyrinth.height;
	} while (labyrinth.enterx == labyrinth.keyx && labyrinth.keyy == labyrinth.entery);
	additem.CreateItem(1); // 1-key
	labyrinth.rooms[labyrinth.keyx * labyrinth.height + labyrinth.keyy].AddToStash(additem);
	do
	{
		labyrinth.chestx = std::rand() % labyrinth.width;
		labyrinth.chesty = std::rand() % labyrinth.height;
	} while ((labyrinth.enterx == labyrinth.chestx && labyrinth.entery == labyrinth.chesty) || (labyrinth.keyx == labyrinth.chestx && labyrinth.keyy == labyrinth.chesty));

	additem.CreateItem(2); // 2-chest
	labyrinth.rooms[labyrinth.chestx * labyrinth.height + labyrinth.chesty].AddToStash(additem);

	if (labyrinth.enterx > labyrinth.keyx) 						//adding path between core obj
	{
		for (int i = labyrinth.enterx; i > labyrinth.keyx; i--)
		{
			labyrinth.OpenSide(i, labyrinth.entery, 0);
		}
	}
	if (labyrinth.enterx < labyrinth.keyx)
	{
		for (int i = labyrinth.enterx; i < labyrinth.keyx; i++)
		{
			labyrinth.OpenSide(i, labyrinth.entery, 2);
		}
	}
	if (labyrinth.entery > labyrinth.keyy)
	{
		for (int i = labyrinth.entery; i > labyrinth.keyy; i--)
		{
			labyrinth.OpenSide(labyrinth.keyx, i, 3);
		}
	}
	if (labyrinth.entery < labyrinth.keyy)
	{
		for (int i = labyrinth.entery; i < labyrinth.keyy; i++)
		{
			labyrinth.OpenSide(labyrinth.keyx, i, 1);
		}
	}
	if (labyrinth.enterx > labyrinth.chestx)
	{
		for (int i = labyrinth.enterx; i > labyrinth.chestx; i--)
		{
			labyrinth.OpenSide(i, labyrinth.entery, 0);
		}
	}
	if (labyrinth.enterx < labyrinth.chestx)
	{
		for (int i = labyrinth.enterx; i < labyrinth.chestx; i++)
		{
			labyrinth.OpenSide(i, labyrinth.chesty, 2);
		}
	}
	if (labyrinth.entery > labyrinth.chesty)
	{
		for (int i = labyrinth.entery; i > labyrinth.chesty; i--)
		{
			labyrinth.OpenSide(labyrinth.chestx, i, 3);
		}
	}
	if (labyrinth.entery < labyrinth.chesty)
	{
		for (int i = labyrinth.chesty; i < labyrinth.chesty; i++)
		{
			labyrinth.OpenSide(labyrinth.chestx, i, 1);
		}
	}
	
	for (int i = 0; i < (labyrinth.width * labyrinth.height); i++) //add random doors
	{
		labyrinth.OpenSide(rand() % labyrinth.width, rand() % labyrinth.height, rand() % 4);
	}
	
	for (int i = 0; i < (labyrinth.width * labyrinth.height / 3); i++)  //add dark rooms
	{
		labyrinth.rooms[rand() % (labyrinth.width * labyrinth.height)].light = 0;
	}
	for (int i = 0; i < (labyrinth.width * labyrinth.height / 3); i++)//add torches
	{
		int tempx = rand() % labyrinth.width;
		int tempy = rand() % labyrinth.height;
		Item tempitem;
		tempitem.CreateItem(3);
		labyrinth.rooms[tempx * labyrinth.height + tempy].AddToStash(tempitem);
		if (labyrinth.rooms[tempx * labyrinth.height + tempy].light == 0)
		{
			labyrinth.rooms[tempx * labyrinth.height + tempy].light = 2;
		}
	}
}

int Model::Move(std::string dir) //0-wrong name of door, 1-succes, 2-no door
{
	if (dir == "W" && labyrinth.rooms[player.pospoint].walls[0] == 1)
	{
		player.posx -= 1;
		player.pospoint -= labyrinth.height;
		player.life -= 1;
		return 1;
	}
	else if (dir == "N" && labyrinth.rooms[player.pospoint].walls[1] == 1)
	{
		player.posy += 1;
		player.pospoint += 1;
		player.life -= 1;
		return 1;
	}
	else if (dir == "E" && labyrinth.rooms[player.pospoint].walls[2] == 1)
	{
		player.posx += 1;
		player.pospoint += labyrinth.height;
		player.life -= 1;
		return 1;
	}
	else if (dir == "S" && labyrinth.rooms[player.pospoint].walls[3] == 1)
	{
		player.posy -= 1;
		player.pospoint -= 1;
		player.life -= 1;
		return 1;
	}
	else if (dir == "W" || dir == "N" || dir == "E" || dir == "S")
	{
		return 2;
	}
	return 0;
}

int Model::GetItem(std::string itemname) //0-wrong item name, 1-no such item, 2-get chest, 3-key
{
	int stashpointer = labyrinth.rooms[player.pospoint].CheckStash(1);
	if (itemname == "key" && stashpointer >= 0)
	{
		Item tempitem;
		tempitem = labyrinth.rooms[player.pospoint].PassFromStash(stashpointer);
		labyrinth.rooms[player.pospoint].RemoveFromStash(stashpointer);
		player.AddToInventory(tempitem);
		return 3;
	}
	else if (itemname == "key" && stashpointer < 0)
	{
		return 1;
	}
	stashpointer = labyrinth.rooms[player.pospoint].CheckStash(2);
	if (itemname == "chest" && stashpointer >= 0)
	{
		return 2;
	}
	else if (itemname == "chest" && stashpointer < 0)
	{
		return 1;
	}
	stashpointer = labyrinth.rooms[player.pospoint].CheckStash(3);
	if (itemname == "torch" && stashpointer >= 0)
	{
		Item tempitem;
		tempitem = labyrinth.rooms[player.pospoint].PassFromStash(stashpointer);
		labyrinth.rooms[player.pospoint].RemoveFromStash(stashpointer);
		player.AddToInventory(tempitem);
		if (labyrinth.rooms[player.pospoint].light == 2)
		{
			labyrinth.rooms[player.pospoint].light = 0;
		}
		return 3;
	}
	else if (itemname == "torch" && stashpointer < 0)
	{
		return 1;
	}
	return 0;
}
int Model::DropItem(std::string itemname) // 0-wrong item name, 1-no such item, 2-drop
{
	int inventorypointer = player.CheckInventory(1);
	if (itemname == "key" && inventorypointer >= 0)
	{
		Item tempitem;
		tempitem =  player.PassFromInv(inventorypointer);
		player.RemoveFromInv(inventorypointer);
		labyrinth.rooms[player.pospoint].AddToStash(tempitem);
		return 2;
	}
	else if (itemname == "key" && inventorypointer < 0)
	{
		return 1;
	}
	inventorypointer = player.CheckInventory(3);
	if (itemname == "torch" && inventorypointer >= 0)
	{
		Item tempitem;
		tempitem = player.PassFromInv(inventorypointer);
		player.RemoveFromInv(inventorypointer);
		labyrinth.rooms[player.pospoint].AddToStash(tempitem);
		if (labyrinth.rooms[player.pospoint].light == 0)
		{
			labyrinth.rooms[player.pospoint].light = 2;
		}
		return 2;
	}
	else if (itemname == "torch" && inventorypointer < 0)
	{
		return 1;
	}
	return 0;
}

int Model::OpenChest() // 0 - no chest, 1 - no key, 2 - succes
{
	int stashpointer = labyrinth.rooms[player.pospoint].CheckStash(2);
	if (stashpointer < 0)
	{
		return 0;
	}
	int inventorypointer = player.CheckInventory(1);
	if (inventorypointer < 0)
	{
		return 1;
	}
	return 2;
}

Model::Model()
{
}


Model::~Model()
{
}

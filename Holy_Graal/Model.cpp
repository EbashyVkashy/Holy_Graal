#include "Model.h"
#include <iostream>
void Model::PrevPosition()
{
	player.prevposx = player.posx;
	player.prevposy = player.posy;
	player.prevpospoint = player.pospoint;
}
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

int Model::CheckCommand(std::string command, int commandtype)  // 0 - no such command, 1 - move, 2 - get, 3 - drop, 4 - open, 5 - eat
{
	switch (commandtype)
	{
	case 0:
		return -1;
		break;
	case 1:
	{
		if ((command == "W" && labyrinth.rooms[player.pospoint].walls[0] == 1) || (command == "N" && labyrinth.rooms[player.pospoint].walls[1] == 1) ||
			(command == "E" && labyrinth.rooms[player.pospoint].walls[2] == 1) || (command == "S" && labyrinth.rooms[player.pospoint].walls[3] == 1))
		{
			return 1;
			break;
		}
		return 0;
		break;
	}
	case 2:  //0-wrong item name, 1-success, 2-no such item
	{
		int stashpointer = labyrinth.rooms[player.pospoint].CheckStash(1);
		if (command == "key" && stashpointer >= 0)
		{
			return 1;
		}
		else if (command == "key" && stashpointer < 0)
		{
			return 2;
		}
		stashpointer = labyrinth.rooms[player.pospoint].CheckStash(2);
		if (command == "chest" && stashpointer >= 0)
		{
			return 1;
		}
		else if (command == "chest" && stashpointer < 0)
		{
			return 2;
		}
		stashpointer = labyrinth.rooms[player.pospoint].CheckStash(3);
		if (command == "torch" && stashpointer >= 0)
		{
			return 1;
		}
		else if (command == "torch" && stashpointer < 0)
		{
			return 2;
		}
		return 0;
		break;
	}
	case 3: //0-wrong item name, 1-success, 2-no such item
	{
		int inventorypointer = player.CheckInventory(1);
		if (command == "key" && inventorypointer >= 0)
		{	
			return 1;
		}
		else if (command == "key" && inventorypointer < 0)
		{
			return 2;
		}
		inventorypointer = player.CheckInventory(3);
		if (command == "torch" && inventorypointer >= 0)
		{
			return 1;
		}
		else if (command == "torch" && inventorypointer < 0)
		{
			return 2;
		}
		return 0;
		break;
	}
	case 4: //0 - no chest 1 -success 2 - no key
	{
		int stashpointer = labyrinth.rooms[player.pospoint].CheckStash(2);
		if (stashpointer < 0)
		{
			return 0;
		}
		int inventorypointer = player.CheckInventory(1);
		if (inventorypointer < 0)
		{
			return 2;
		}
		return 1;
		break;	
	}
	case 5: // 0 - no such food; 1 -success
	{
		int stashpointer = labyrinth.rooms[player.pospoint].CheckStashFood(command);
		if (stashpointer >= 0)
		{
			return 1;
		}
		return 0;
		break;
	}
	default:
		break;
	}
	return -1;
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
	
	for (int i = 0; i < (labyrinth.width * labyrinth.height / 2); i++)  //add dark rooms
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
	for (int i = 0; i < (labyrinth.width * labyrinth.height / 3); i++)		//add food
	{
		Item tempitem;
		tempitem.CreateItem(4);
		labyrinth.rooms[rand() % (labyrinth.width * labyrinth.height)].AddToStash(tempitem);
	}
	for (int i = 0; i < (labyrinth.width * labyrinth.height / 3); i++)		//add Monsters
	{
		Monster tempmonster;
		tempmonster.CreateMonster();
		int tempx = rand() % labyrinth.width;
		int tempy = rand() % labyrinth.height;
		if (tempx != labyrinth.enterx || tempy != labyrinth.entery)
		{
			labyrinth.rooms[tempx * labyrinth.height + tempy].monster = tempmonster;
			labyrinth.rooms[tempx * labyrinth.height + tempy].monsterexistence = true;
		}
	}
}

void Model::PlayerGotHit()
{
	player.life = player.life - (player.initlife % 10);
}

void Model::Move(std::string dir) //0-wrong name of door, 1-succes, 2-no door
{
	if (dir == "W" && labyrinth.rooms[player.pospoint].walls[0] == 1)
	{
		PrevPosition();
		player.posx -= 1;
		player.pospoint -= labyrinth.height;
		player.life -= 1;
	}
	else if (dir == "N" && labyrinth.rooms[player.pospoint].walls[1] == 1)
	{
		PrevPosition();
		player.posy += 1;
		player.pospoint += 1;
		player.life -= 1;
	}
	else if (dir == "E" && labyrinth.rooms[player.pospoint].walls[2] == 1)
	{
		PrevPosition();
		player.posx += 1;
		player.pospoint += labyrinth.height;
		player.life -= 1;
	}
	else if (dir == "S" && labyrinth.rooms[player.pospoint].walls[3] == 1)
	{
		PrevPosition();
		player.posy -= 1;
		player.pospoint -= 1;
		player.life -= 1;
	}
}

void Model::FailAtMonster()
{
	int tempx;
	int tempy;
	int temppos;
	tempx = player.prevposx;
	tempy = player.prevposy;
	temppos = player.prevpospoint;
	PrevPosition();
	player.posx = tempx;
	player.posy = tempy;
	player.pospoint = temppos;
}

bool Model::DoCommand(std::string command,int commandtype) //  1 - move, 2 - get, 3 - drop, 4 - open, 5 - eat
{
	switch (commandtype)
	{
	case 1:
		Move(command);
		return false;
		break;
	case 2:
		GetItem(command);
		return false;
		break;
	case 3:
		DropItem(command);
		return false;
		break;
	case 4:
		return true;
		break;
	case 5:
		EatFood(command);
		return false;
		break;
	default:
		return false;
		break;
	}
	return false;
}


void Model::GetItem(std::string itemname) //0-wrong item name, 1-no such item, 2-get chest, 3-key
{
	int stashpointer = labyrinth.rooms[player.pospoint].CheckStash(1);
	if (itemname == "key" && stashpointer >= 0)
	{
		Item tempitem;
		tempitem = labyrinth.rooms[player.pospoint].PassFromStash(stashpointer);
		labyrinth.rooms[player.pospoint].RemoveFromStash(stashpointer);
		player.AddToInventory(tempitem);
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
	}
}
void Model::DropItem(std::string itemname) // 0-wrong item name, 1-no such item, 2-drop
{
	int inventorypointer = player.CheckInventory(1);
	if (itemname == "key" && inventorypointer >= 0)
	{
		Item tempitem;
		tempitem =  player.PassFromInv(inventorypointer);
		player.RemoveFromInv(inventorypointer);
		labyrinth.rooms[player.pospoint].AddToStash(tempitem);
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
	}
}

void Model::EatFood(std::string itemname) // 0 - no such food; 1 -success
{
	int stashpointer = labyrinth.rooms[player.pospoint].CheckStashFood(itemname);
	if (stashpointer >= 0)
	{
		labyrinth.rooms[player.pospoint].RemoveFromStash(stashpointer);
		player.life = player.life + (player.initlife % 10);
	}
}

Model::Model()
{
}


Model::~Model()
{
}


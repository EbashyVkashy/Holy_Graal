#include "Viev.h"
#include "Model.h"
#include <iostream>

void Viev::Wellcome()
{
	std::cout << "Wellcome travaler! You are about to enter great Labyrinth of the Holy Graal!" << std::endl;
}

void Viev::Rules()
{
	std::cout << "Rules: to move use W (west), N (north), E (east), S (south)." << std::endl;
	std::cout << "To get item - 'get [item]', to drop - 'drop [item]'" << std::endl;
	std::cout << "To open chest - 'open' (you need to have key in your inventory to open)" << std::endl;
	std::cout << "Use 'eat [food]' - to restore 10% of your life" << std::endl;
	std::cout << "Use 'fight' - to fight a monster (you need to have a sword in your inventory" << std::endl;
}

void Viev::AskWidth()
{
	std::cout << "Please enter width of the Labyrinth: ";
}

void Viev::AskHeight()
{
	std::cout << "Please enter height of the Labyrinth: ";
}

void Viev::WritePosition(const Model &mod)
{
	std::cout << "You are in the room [" << mod.player.posx << "." << mod.player.posy << "]. There are [";
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (mod.labyrinth.rooms[mod.player.posx * mod.labyrinth.height + mod.player.posy].walls[i] != 0)
		{
			count += 1;
		}

	}
	std::cout << count << "] doors:";
	if (mod.labyrinth.rooms[mod.player.posx * mod.labyrinth.height + mod.player.posy].walls[0] != 0)
	{
		std::cout << " west";
	}
	if (mod.labyrinth.rooms[mod.player.posx * mod.labyrinth.height + mod.player.posy].walls[1] != 0)
	{
		std::cout << " north";
	}
	if (mod.labyrinth.rooms[mod.player.posx * mod.labyrinth.height + mod.player.posy].walls[2] != 0)
	{
		std::cout << " east";
	}
	if (mod.labyrinth.rooms[mod.player.posx * mod.labyrinth.height + mod.player.posy].walls[3] != 0)
	{
		std::cout << " south";
	}
	count = mod.labyrinth.rooms[mod.player.posx * mod.labyrinth.height + mod.player.posy].stash.size();
	if (count == 0)
	{
		std::cout << ". No items in this room." << std::endl;
	}
	else
	{
		std::cout << ". Items in this room:";
		count = mod.labyrinth.rooms[mod.player.posx * mod.labyrinth.height + mod.player.posy].stash.size();
		for (int i = 0; i < count; i++)
		{
			std::cout << " " << mod.labyrinth.rooms[mod.player.posx * mod.labyrinth.height + mod.player.posy].stash[i].name;
		}
		std::cout << "." << std::endl;
	}
}

Viev::Viev()
{
}


Viev::~Viev()
{
}

#pragma once
#include "Labyrinth.h"
#include "Item.h"

class Controller
{
public:
	std::string lastcommand;
	int ListenSize();
	int ListenCommand(); // 0-no such command, 1 - move, 2 - get, 3 - drop.
	Controller();
	~Controller();
};


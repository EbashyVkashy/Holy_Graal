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

int Controller::ListenCommand()   // 0-no such command, 1 - move, 2 - get, 3 - drop, 4 - open, 5 - eat
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
	if (lastcommand == "open")
	{
		return 4;
	}
	if (lastcommand.substr(0, 4) == "eat ")
	{
		lastcommand = lastcommand.substr(4, lastcommand.length());
		return 5;
	}
	return 0;
}

Controller::Controller()
{
}


Controller::~Controller()
{
}


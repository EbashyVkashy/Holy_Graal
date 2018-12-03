#include "Controller.h"
#include "Viev.h"
#include "Model.h"
#include <iostream>
#include <ctime>

Controller controller;
Viev view;
Model model;
int commandid;
bool victoryflag = false;
void StandardRoom();
void DarkRoom();
void MonsterRoom();

int main()
{
	view.Welcome();
	view.Rules();
	do
	{
		view.AskWidth();
		model.labyrinth.width = controller.ListenSize();
	} while (model.CheckWidth(model.labyrinth.width) != true);
	do
	{
		view.AskHeight();
		model.labyrinth.height = controller.ListenSize();
	} while (model.CheckHeight(model.labyrinth.height) != true);

	model.GenerateLevel();
	model.player.PlacePlayer(model.labyrinth.enterx, model.labyrinth.entery, model.labyrinth.height);


	while (model.player.life > 0 && victoryflag == false)
	{
		if (model.labyrinth.rooms[model.player.pospoint].light == 0 && model.player.CheckInventory(3) < 0)
		{
			DarkRoom();
		}
		else if (model.labyrinth.rooms[model.player.pospoint].monsterexistence == true)
		{
			MonsterRoom();
		}
		else
		{
			StandardRoom();
		}
	}
	if (model.player.life < 1)
	{
		view.YouDied();
	}
	if (victoryflag == true)
	{
		view.GotGraal();
		view.YouWon();
	}
	std::cin >> commandid;
}

void StandardRoom()
{
	int temp;
	view.WritePosition(model);
	view.YourCommand();
	commandid = controller.ListenCommand();
	temp = model.CheckCommand(controller.lastcommand, commandid);
	if (temp == -1)
	{
		view.WrongCommand();
		return;
	}
	else if (commandid == 1 && temp == 0)
	{
		view.NoDoor();
	}
	else if (commandid == 2 && temp == 0)
	{
		view.WrongItemName();
	}
	else if (commandid == 2 && temp == 2)
	{
		view.NoItem();
	}
	else if (commandid == 3 && temp == 0)
	{
		view.WrongItemName();
	}
	else if (commandid == 3 && temp == 2)
	{
		view.NoItem();
	}
	else if (commandid == 4 && temp == 0)
	{
		view.NoChest();
	}
	else if (commandid == 4 && temp == 2)
	{
		view.DontHaveKey();
	}
	else if (commandid == 5 && temp == 0)
	{
		view.NoSuchFood();
	}
	else
	{
		victoryflag = model.DoCommand(controller.lastcommand, commandid);
	}
}
void DarkRoom()
{
	int temp;
	view.CantSee();
	view.YourCommand();
	commandid = controller.ListenCommand();
	temp = model.CheckCommand(controller.lastcommand, commandid);
	if (temp == -1)
	{
		view.WrongCommand();
		return;
	}
	else if (commandid == 1 && temp == 0)
	{
		view.NoDoor();
	}
	else if (commandid == 1 && temp == 1)
	{
		model.DoCommand(controller.lastcommand, commandid);
	}
	else
	{
		view.YouCanOnlyMove();
	}
}
void MonsterRoom()
{
	int temp;
	clock_t timer;
	view.WritePosition(model);
	view.MonsterHere(model.labyrinth.rooms[model.player.pospoint].monster.name);
	timer = clock();
	view.YourCommand();
	commandid = controller.ListenCommand();
	temp = model.CheckCommand(controller.lastcommand, commandid);
	if ((clock() - timer) < 5000)
	{
		int rollonmob;
		rollonmob = rand() % 3;
		if (rollonmob == 0)
		{
			model.FailAtMonster();
			view.MoveToPrev();
			return;
		}
		if (rollonmob == 1)
		{
			model.PlayerGotHit();
			commandid = controller.ListenCommand();
			temp = model.CheckCommand(controller.lastcommand, commandid);
			if (temp == -1)
			{
				view.WrongCommand();
			}
			else if (commandid == 1 && temp == 0)
			{
				view.NoDoor();
			}
			else if (commandid == 1 && temp == 1)
			{
				model.FailAtMonster();
				return;
			}
			else if (commandid == 2 && temp == 0)
			{
				view.WrongItemName();
			}
			else if (commandid == 2 && temp == 2)
			{
				view.NoItem();
			}
			else if (commandid == 3 && temp == 0)
			{
				view.WrongItemName();
			}
			else if (commandid == 3 && temp == 2)
			{
				view.NoItem();
			}
			else if (commandid == 4 && temp == 0)
			{
				view.NoChest();
			}
			else if (commandid == 4 && temp == 2)
			{
				view.DontHaveKey();
			}
			else if (commandid == 5 && temp == 0)
			{
				view.NoSuchFood();
			}
			else
			{
				victoryflag = model.DoCommand(controller.lastcommand, commandid);
			}
			model.FailAtMonster();
		}
		if (rollonmob == 2)
		{
			commandid = controller.ListenCommand();
			temp = model.CheckCommand(controller.lastcommand, commandid);
			if (temp == -1)
			{
				view.WrongCommand();
			}
			else if (commandid == 1 && temp == 0)
			{
				view.NoDoor();
			}
			else if (commandid == 2 && temp == 0)
			{
				view.WrongItemName();
			}
			else if (commandid == 2 && temp == 2)
			{
				view.NoItem();
			}
			else if (commandid == 3 && temp == 0)
			{
				view.WrongItemName();
			}
			else if (commandid == 3 && temp == 2)
			{
				view.NoItem();
			}
			else if (commandid == 4 && temp == 0)
			{
				view.NoChest();
			}
			else if (commandid == 4 && temp == 2)
			{
				view.DontHaveKey();
			}
			else if (commandid == 5 && temp == 0)
			{
				view.NoSuchFood();
			}
			else
			{
				victoryflag = model.DoCommand(controller.lastcommand, commandid);
			}
		}
	}
	else
	{
		view.TooSlow();
		model.PlayerGotHit();
		model.FailAtMonster();
	}
}
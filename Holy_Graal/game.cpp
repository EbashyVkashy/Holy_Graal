#include "Controller.h"
#include "Viev.h"
#include "Model.h"
#include <iostream>

Controller controller;
Viev view;
Model model;
int commandid;
bool victoryflag = false;
void StandardRoom();
void DarkRoom();

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
		view.YouWon();
	}
	std::cin >> commandid;
}

void StandardRoom()
{
	view.WritePosition(model);
	view.YourCommand();
	commandid = controller.ListenCommand();
	switch (commandid) // 0-no such command, 1 - move, 2 - get, 3 - drop, 4 - open, 5 - eat
	{
	case 0:
		view.WrongCommand();
		break;
	case 1:
	{
		int temp = model.Move(controller.lastcommand);  //0-wrong name of door, 1-succes, 2-no door
		switch (temp)
		{
		case 0:
			view.WrongNameDoor();
			break;
		case 1:
			break;
		case 2:
			view.NoDoor();
			break;
		default:
			break;
		}
		break;
	}
	case 2:
	{
		int temp = model.GetItem(controller.lastcommand); //0-wrong item name, 1-no such item, 2-get chest, 3-get key
		switch (temp)
		{
		case 0:
			view.WrongItemName();
			break;
		case 1:
			view.NoItem();
			break;
		case 2:
			view.ChestLift();
			break;
		case 3:
			break;
		default:
			break;
		}
		break;
	}
	case 3:
	{
		int temp = model.DropItem(controller.lastcommand); // 0-wrong item name, 1-no such item, 2-drop
		switch (temp)
		{
		case 0:
			view.WrongItemName();
			break;
		case 1:
			view.NoItem();
			break;
		case 2:
			break;
		default:
			break;
		}
		break;
	}
	case 4:
	{
		int temp = model.OpenChest();
		switch (temp)
		{
		case 0:
			view.NoChest();
			break;
		case 1:
			view.DontHaveKey();
			break;
		case 2:
			view.GotGraal();
			victoryflag = true;
			break;
		default:
			break;
		}
		break;
	}
	case 5:
	{
		int temp = model.EatFood(controller.lastcommand);  //0 - no such food; 1 - success
		switch (temp)
		{
		case 0:
			view.NoSuchFood();
			break;
		case 1:
			view.YouAte(controller.lastcommand);
			break;
		default:
			break;
		}
	}
	default:
		break;
	}
}

void DarkRoom()
{
	view.CantSee();
	view.YourCommand();
	commandid = controller.ListenCommand();
	switch (commandid)
	{
	case 0:
		view.WrongCommand();
		break;
	case 1:
	{
		int temp = model.Move(controller.lastcommand);  //0-wrong name of door, 1-succes, 2-no door
		switch (temp)
		{
		case 0:
			view.WrongNameDoor();
			break;
		case 1:
			break;
		case 2:
			view.NoDoor();
			break;
		default:
			break;
		}
		break;
	}
	default:
		view.YouCanOnlyMove();
		break;
	}
}
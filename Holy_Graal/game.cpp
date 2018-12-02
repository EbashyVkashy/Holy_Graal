#include "Controller.h"
#include "Viev.h"
#include "Model.h"
#include <iostream>
int main()
{
	Controller controller;
	Viev viev;
	Model model;
	int commandid;
	bool victoryflag = false;
	viev.Wellcome();
	viev.Rules();

	do
	{
		viev.AskWidth();
		model.labyrinth.width = controller.ListenSize();
	} while (model.CheckWidth(model.labyrinth.width) != true);
	do
	{
		viev.AskHeight();
		model.labyrinth.height = controller.ListenSize();
	} while (model.CheckHeight(model.labyrinth.height) != true);

	model.GenerateLevel();
	model.player.PlacePlayer(model.labyrinth.enterx, model.labyrinth.entery, model.labyrinth.height);


	while (model.player.life > 0 && victoryflag == false)
	{
		viev.WritePosition(model);
		viev.YourCommand();
		commandid = controller.ListenCommand();
		switch (commandid) // 0-no such command, 1 - move, 2 - get, 3 - drop, 4 - open
		{
		case 0:
			viev.WrongCommand();
			break;
		case 1:
		{
			int temp = model.Move(controller.lastcommand);  //0-wrong name of door, 1-succes, 2-no door
			switch (temp)
			{
			case 0:
				viev.WrongNameDoor();
				break;
			case 1:
				break;
			case 2:
				viev.NoDoor();
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
				viev.WrongItemName();
				break;
			case 1:
				viev.NoItem();
				break;
			case 2:
				viev.ChestLift();
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
				viev.WrongItemName();
				break;
			case 1:
				viev.NoItem();
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
				viev.NoChest();
				break;
			case 1:
				viev.DontHaveKey();
				break;
			case 2:
				viev.GotGraal();
				victoryflag = true;
				break;
			default:
				break;
			}
			break;
		}
		default:
			break;
		}
	}
	if (model.player.life < 1)
	{
		viev.YouDied();
	}
	if (victoryflag == true)
	{
		viev.YouWon();
	}
	std::cin >> commandid;
}

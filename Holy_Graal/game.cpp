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

	model.labyrinth = controller.GenerateLevel(model.labyrinth.width, model.labyrinth.height);
	model.player.PlacePlayer(model.labyrinth.enterx, model.labyrinth.entery);


	while (model.player.life > 0)
	{
		viev.WritePosition(model);
		viev.YourCommand();
		commandid = controller.ListenCommand();
		switch (commandid) // 0-no such command, 1 - move, 2 - get, 3 - drop.
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
			break;
		case 3:
			break;
		default:
			break;
		}
	}
}

#include "Controller.h"
#include "Viev.h"
#include "Model.h"
#include <iostream>
int main()
{
	Controller controller;
	Viev viev;
	Model model;

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
		
		controller.ListenCommand();
	}
}

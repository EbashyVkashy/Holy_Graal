#pragma once
#include "Labyrinth.h"
#include "Player.h"


class Model
{
private:
	void PrevPosition();
public:
	Player player;
	Labyrinth labyrinth;
	bool CheckWidth(int x);
	bool CheckHeight(int y);
	int CheckCommand(std::string command, int commandtype);
	void Move(std::string dir);
	void FailAtMonster();
	bool DoCommand(std::string command, int commandtype);
	void GetItem(std::string itemname);
	void DropItem(std::string itemname);
	void EatFood(std::string itemname);
	void GenerateLevel();
	void PlayerGotHit();
	Model();
	~Model();
};


#pragma once
#include "Model.h"
#include <string>

class Viev
{
public:
	void Welcome();
	void Rules();
	void AskWidth();
	void AskHeight();
	void YourCommand();
	void WrongCommand();
	void WrongNameDoor();
	void NoDoor();
	void WrongItemName();
	void ChestLift();
	void NoItem();
	void NoChest();
	void DontHaveKey();
	void GotGraal();
	void YouDied();
	void YouWon();
	void CantSee();
	void YouCanOnlyMove();
	void NoSuchFood();
	void TooSlow();
	void MonsterHere(const std::string &);
	void WritePosition(const Model &);
	Viev();
	~Viev();
};


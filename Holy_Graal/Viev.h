#pragma once
#include "Model.h"


class Viev
{
public:
	void Wellcome();
	void Rules();
	void AskWidth();
	void AskHeight();
	void YourCommand();
	void WrongCommand();
	void WrongNameDoor();
	void NoDoor();
	void WritePosition(const Model &);
	Viev();
	~Viev();
};


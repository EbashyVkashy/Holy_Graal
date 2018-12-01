#pragma once
#include "Model.h"


class Viev
{
public:
	void Wellcome();
	void Rules();
	void AskWidth();
	void AskHeight();
	void WritePosition(const Model &);
	Viev();
	~Viev();
};


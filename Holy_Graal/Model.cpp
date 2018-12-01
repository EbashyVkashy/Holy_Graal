#include "Model.h"

bool Model::CheckWidth(int x)
{
	if (x > 3 && x < 50)
	{
		return true;
	}
	return false;
}

bool Model::CheckHeight(int y)
{
	if (y > 3 && y < 50)
	{
		return true;
	}
	return false;
}

Model::Model()
{
}


Model::~Model()
{
}

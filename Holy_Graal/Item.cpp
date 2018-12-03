#include "Item.h"



void Item::CreateItem(int id)
{
	itemid = id;
	switch (id)
	{
	case 1:
		name = "key";
		break;
	case 2:
		name = "chest";
		break;
	case 3:
		name = "torch";
		break;
	case 4:
	{
		int tempvalue = rand() % 3;
		switch (tempvalue)
		{
		case 0:
			name = "bread";
			break;
		case 1:
			name = "egg";
			break;
		case 2:
			name = "milk";
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

Item::Item()
{
}


Item::~Item()
{
}

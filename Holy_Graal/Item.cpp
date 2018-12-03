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

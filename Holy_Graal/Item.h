#pragma once
#include <string>

class Item
{
public:
	int itemid; // 1-key, 2-chest, 3-torch, 4-food
	std::string name;
	void CreateItem(int id);
	Item();
	~Item();
};


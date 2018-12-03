#pragma once
#include <string>

class Item
{
public:
	int itemid; // 1-key, 2-chest, 3-torch
	std::string name;
	void CreateItem(int id);
	Item();
	~Item();
};


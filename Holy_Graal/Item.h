#pragma once
#include <string>

class Item
{
public:
	int itemid; // 1-key, 2-chest
	std::string name;
	void CreateItem(int id);
	Item();
	~Item();
};


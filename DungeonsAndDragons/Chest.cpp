#include "stdafx.h"
#include "Chest.h"


Chest::Chest()
{
}


Chest::~Chest()
{
}

std::string Chest::ListItems()
{
	std::string output = "Chest contents: \n";
	for (auto i : chestItems)
	{
		std::string incrementType;
		switch (i.second.GetItemType())
		{
		case ItemType::WeaponItem: incrementType = "damage"; break;
		case ItemType::HealthItem: incrementType = "health"; break;
		case ItemType::ArmourItem: incrementType = "armour"; break;
		}
		output.append("- " + i.first + " (Level " + i.second.GetLevel() + ", adds " + std::to_string(i.second.GetIncrement()) + " " + incrementType + ") \n");
	}
	return output;
}

Item Chest::GetItem(std::string itemName)
{
	chestMap::iterator it = chestItems.find(itemName);
	if (it != chestItems.end())
		return chestItems[itemName];
	else
		return Item();
}
void Chest::AddItem(Item item)
{
	chestItems.insert(std::pair<std::string, Item>(Utils::ToLowerCase(item.GetName()), item));
}
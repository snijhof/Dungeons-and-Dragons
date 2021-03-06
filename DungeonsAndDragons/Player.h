#pragma once

#include <vector>

#include "Character.h"
#include "Item.h"
#include "Armour.h"
#include "Weapon.h"

class Player : public Character
{
private:
	int xp;
	int attack;
	int defence;
	int exploring;
	bool leveled;
	std::vector<Item> backpack;
	Weapon weapon;
	Armour armour;

public:
	Player();
	Player(std::string name);
	virtual ~Player();

	// Functions
	void AddToBackpack(Item toAdd);
	std::vector<Item> GetBackpack();
	std::string ListBackpackContents();
	Weapon GetEquipedWeapon();
	Armour GetEquipedArmour();
	void SetWeapon(Weapon weapon);
	void SetArmour(Armour armour);
	std::string EquipItem(std::string itemName);
	std::string EquipItem(Item item);
	std::string UsePotion();
	bool ContainsPotion();
	int GetExploring();

	std::string GainedXp(int gained_xp);
	bool IsLeveled();
	void LevelUp();

	int Attack();
	int Hit(int damage);
	void Rest();
	std::string Print();

	std::string SaveString();
	void LoadPlayer(std::string name, int level, int xp, int hp, int maxHp, int attack, int defence, int exploring);
	void LoadGear(int weaponId, int weaponLvl, int armourId, int armourLvl);
	void LoadBackpack(std::string backpack);
};


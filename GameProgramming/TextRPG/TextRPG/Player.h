#pragma once

#include "Item.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player {
	string m_strName;
	Status m_sStatus;
	int m_nLv = 1;
	int m_nExp = 0;
	int m_nGold;

	vector<Item*> m_listIventory;
	vector<Item*> m_listEqument;
public:
	void SetIventory(Item* item);
	Item* GetIventoryIdx(int idx);
	void DeleteIventory(int idx);

	bool UseItem(int idx);

	void ReleaseEqument(int idx);

	bool Buy(Player& target, int idx);

	void Sell(int idx);

	Player(const char* strName = "NONE", int _gold = 0, int _hp = 100, int _mp = 100, int _str = 20, int  _int = 10, int _def = 10, int _exp = 0, int equmentCount = 3);

	void Set(string strName, int _hp, int _mp, int _str, int _int, int _def, int _exp);

	void Attack(Player& taget);

	void StillExp(Player& taget);

	void StillItem(Player& target, int idx = 0);

	bool LvUp();

	bool Dead();

	void Show();
};
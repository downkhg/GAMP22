#pragma once
#include "Player.h"

class GameManager
{
public:
	enum E_PLACE { EXIT = -1, CRATE, IVNETORY, SHOP, TOWN, FILED, BATTLE, GAME_OVER, THE_END, MAX };
	enum E_MONSTER { SILME, SKELETON, BOSS, MON_MAX };

	E_PLACE GetPlace();

	void Init();

	void EventCreate();
	void EventInventory();
	void EventShop();
	void EventTown();
	void EvnetFiled();
	void EventBattle();
	void EventGameOver();
	void EventTheEnd();

	void Updata();
private:
	Player cPlayer = Player("Player", 100000);
	Player cMonster = Player("Monster");
	Player cShop;
	ItemManager cItemManager;

	E_PLACE ePlace = E_PLACE::CRATE;
};
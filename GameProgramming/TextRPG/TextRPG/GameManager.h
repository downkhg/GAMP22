#pragma once

class Player;
//class ItemManager;

class GameManager
{
public:
	enum E_PLACE { EXIT = -1, CRATE, IVNETORY, SHOP, TOWN, FILED, BATTLE, GAME_OVER, THE_END, MAX };
	enum E_MONSTER { SILME, SKELETON, BOSS, MON_MAX };

	E_PLACE GetPlace();

	void Init();
	void Release();

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
	Player* m_pPlayer;
	Player* m_pMonster;
	Player* m_pShop;
	class ItemManager* m_pItemManager;

	E_PLACE ePlace = E_PLACE::CRATE;
public:
	const Player* GetPlayer()
	{
		return m_pPlayer;
	}
};
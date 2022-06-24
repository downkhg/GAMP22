#include "GameManager.h"

GameManager::E_PLACE GameManager::GetPlace()
{
	return ePlace;
}

void GameManager::Init()
{
	cItemManager.LoadFile(); //파일에서 데이터을 읽어서 초기화한다.

	Item* pTempItem = cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD);
	cShop.SetIventory(pTempItem);
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_ARMOR));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::WOOD_RING));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::BONE_SOWRD));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::BONE_AMROR));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::BONE_RING));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::HP_POTION));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::MP_POTION));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::STONE));
	cShop.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::BOOM));

	cMonster.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::HP_POTION));

	cPlayer.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::BONE_AMROR));
}
void GameManager::EventCreate()
{
	string name;
	cout << "케릭터 이름을 입력하세요!:";
	cin >> name;
	cPlayer.Set(name, 100, 100, 20, 10, 10, 0);
	ePlace = E_PLACE::TOWN;
}
void GameManager::EventInventory()
{
	cPlayer.Show();
	int nSelect;
	cout << "메뉴를 선택하세요!(1: 아이템사용. 2: 장비해제 etc: 마을):";
	cin >> nSelect;
	if (nSelect == 1)
	{
		cout << "사용할 아이템을 구하세요!:";
		cin >> nSelect;
		cout << "Select:" << nSelect << endl;
		if (!cPlayer.UseItem(nSelect))
			cout << "사용할수없습니다!" << endl;
	}
	else if (nSelect == 2)
	{
		cout << "장비해제할 장비함에서 선택하세요!:";
		cin >> nSelect;
		cPlayer.ReleaseEqument(nSelect);
	}
	else
		ePlace = E_PLACE::TOWN;
}
void GameManager::EventShop()
{
	cShop.Show();
	int nInput;
	cout << "상점입니다. 무엇을 하시겠습니까? 1: 구매, 2: 팔기, etc:마을";
	cin >> nInput;
	switch (nInput)
	{
	case 1:
	{
		cout << "구매할 아이템을 목록에서 선택하세요! -1:마을";
		cin >> nInput;
		if (nInput != -1)
		{
			if (cPlayer.Buy(cShop, nInput))
				cout << "구매: " << nInput << endl;
			else
				cout << "구매 실패!" << endl;
		}
	}
	break;
	case 2:
	{
		cPlayer.Show();
		cout << "판매할 아이템을 목록에서 선택하세요! -1:마을";
		cin >> nInput;
		if (nInput != -1)
		{
			cPlayer.Sell(nInput);
			cout << "판매: " << nInput << endl;
		}
	}
	break;
	}
	ePlace = E_PLACE::TOWN;
}
void GameManager::EventTown()
{
	int nInput;
	const char* strStageName[] = { "CRATE", "INVENTORY","SHOP","TOWN", "FILED", "BATTLE", "GAME_OVER", "THE_END" };
	cout << "마을 입니다." << endl;
	cout << "어디로 가시겠습니까?" << endl;
	for (int i = E_PLACE::CRATE + 1; i < E_PLACE::BATTLE; i++)
		cout << i << ":" << strStageName[i] << ",";
	cin >> nInput;
	ePlace = (E_PLACE)nInput;
}
void GameManager::EvnetFiled()
{
	int nSelect;
	const char* strMonsterName[] = { "SILME", "SKELETON", "BOSS" };
	cout << "어디로 가시겠습니까?";
	for (int i = 0; i < E_MONSTER::MON_MAX; i++)
		cout << i << ":" << strMonsterName[i] << ",";
	cin >> nSelect;
	switch (nSelect)
	{
	case E_MONSTER::SILME:
		cMonster.Set("Slime", 100, 100, 20, 10, 10, 100);
		break;
	case E_MONSTER::SKELETON:
		cMonster.Set("Skeleton", 200, 200, 30, 10, 10, 100);
		break;
	case E_MONSTER::BOSS:
		cMonster.Set("Boss", 300, 100, 50, 10, 10, 100);
		break;
	}
	ePlace = E_PLACE::BATTLE;
}
void GameManager::EventBattle()
{
	const char* strMonsterName[] = { "SILME", "SKELETON", "BOSS" };
	int nSelect;
	cout << "어디로 가시겠습니까?";
	for (int i = 0; i < E_MONSTER::MON_MAX; i++)
		cout << i << ":" << strMonsterName[i] << ",";
	cin >> nSelect;
	switch (nSelect)
	{
	case E_MONSTER::SILME:
		cMonster.Set("Slime", 100, 100, 20, 10, 10, 100);
		break;
	case E_MONSTER::SKELETON:
		cMonster.Set("Skeleton", 200, 200, 30, 10, 10, 100);
		break;
	case E_MONSTER::BOSS:
		cMonster.Set("Boss", 300, 100, 50, 10, 10, 100);
		break;
	}
	ePlace = E_PLACE::BATTLE;
}

void GameManager::EventGameOver()
{
	cout << "GAME OVER" << endl;
	ePlace = E_PLACE::EXIT;
}
void GameManager::EventTheEnd()
{
	cout << "The End" << endl;
	ePlace = E_PLACE::TOWN;
}

void GameManager::Updata()
{
	switch (GetPlace())
	{
	case GameManager::E_PLACE::CRATE: //이름을 입력받는다.
		EventCreate();
		break;
	case GameManager::E_PLACE::IVNETORY://인벤토리의 목록을 보여주고, 사용할 아이템을 번호를 선택하면 사용 할 수있다. //장비를 선택하면 장비를 보여주고 해제할아이템 선택
	{
		EventInventory();
	}
	break;
	case GameManager::E_PLACE::TOWN: //인벤토리와 상점이 이용이 가능하다.
	{
		EventTown();
	}
	break;
	case GameManager::E_PLACE::SHOP:
	{
		EventInventory();
	}
	break;
	case GameManager::E_PLACE::FILED:
	{
		EvnetFiled();
	}
	break;
	case GameManager::E_PLACE::BATTLE:
	{
		EventBattle();
	}
	break;
	case GameManager::GAME_OVER:
	{
		EventBattle();
	}
	break;
	case GameManager::THE_END:
	{
		EventTheEnd();
	}
	break;
	}
}
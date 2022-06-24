#include "GameManager.h"

GameManager::E_PLACE GameManager::GetPlace()
{
	return ePlace;
}

void GameManager::Init()
{
	cItemManager.LoadFile(); //���Ͽ��� �������� �о �ʱ�ȭ�Ѵ�.

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
	cout << "�ɸ��� �̸��� �Է��ϼ���!:";
	cin >> name;
	cPlayer.Set(name, 100, 100, 20, 10, 10, 0);
	ePlace = E_PLACE::TOWN;
}
void GameManager::EventInventory()
{
	cPlayer.Show();
	int nSelect;
	cout << "�޴��� �����ϼ���!(1: �����ۻ��. 2: ������� etc: ����):";
	cin >> nSelect;
	if (nSelect == 1)
	{
		cout << "����� �������� ���ϼ���!:";
		cin >> nSelect;
		cout << "Select:" << nSelect << endl;
		if (!cPlayer.UseItem(nSelect))
			cout << "����Ҽ������ϴ�!" << endl;
	}
	else if (nSelect == 2)
	{
		cout << "��������� ����Կ��� �����ϼ���!:";
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
	cout << "�����Դϴ�. ������ �Ͻðڽ��ϱ�? 1: ����, 2: �ȱ�, etc:����";
	cin >> nInput;
	switch (nInput)
	{
	case 1:
	{
		cout << "������ �������� ��Ͽ��� �����ϼ���! -1:����";
		cin >> nInput;
		if (nInput != -1)
		{
			if (cPlayer.Buy(cShop, nInput))
				cout << "����: " << nInput << endl;
			else
				cout << "���� ����!" << endl;
		}
	}
	break;
	case 2:
	{
		cPlayer.Show();
		cout << "�Ǹ��� �������� ��Ͽ��� �����ϼ���! -1:����";
		cin >> nInput;
		if (nInput != -1)
		{
			cPlayer.Sell(nInput);
			cout << "�Ǹ�: " << nInput << endl;
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
	cout << "���� �Դϴ�." << endl;
	cout << "���� ���ðڽ��ϱ�?" << endl;
	for (int i = E_PLACE::CRATE + 1; i < E_PLACE::BATTLE; i++)
		cout << i << ":" << strStageName[i] << ",";
	cin >> nInput;
	ePlace = (E_PLACE)nInput;
}
void GameManager::EvnetFiled()
{
	int nSelect;
	const char* strMonsterName[] = { "SILME", "SKELETON", "BOSS" };
	cout << "���� ���ðڽ��ϱ�?";
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
	cout << "���� ���ðڽ��ϱ�?";
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
	case GameManager::E_PLACE::CRATE: //�̸��� �Է¹޴´�.
		EventCreate();
		break;
	case GameManager::E_PLACE::IVNETORY://�κ��丮�� ����� �����ְ�, ����� �������� ��ȣ�� �����ϸ� ��� �� ���ִ�. //��� �����ϸ� ��� �����ְ� �����Ҿ����� ����
	{
		EventInventory();
	}
	break;
	case GameManager::E_PLACE::TOWN: //�κ��丮�� ������ �̿��� �����ϴ�.
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
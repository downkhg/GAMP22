#include "GameManager.h"
#include "Player.h"

GameManager::E_PLACE GameManager::GetPlace()
{
	return ePlace;
}

void GameManager::Init()
{
	m_pPlayer = new Player("Player", 100000);
	m_pMonster = new Player("Monster");
	m_pShop = new Player();

	m_pItemManager = new ItemManager();
	m_pItemManager->LoadFile(); //���Ͽ��� �������� �о �ʱ�ȭ�Ѵ�.

	Item* pTempItem = m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD);
	m_pShop->SetIventory(pTempItem);
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::WOOD_ARMOR));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::WOOD_RING));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::BONE_SOWRD));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::BONE_AMROR));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::BONE_RING));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::HP_POTION));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::MP_POTION));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::STONE));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::BOOM));

	m_pMonster->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::HP_POTION));

	m_pPlayer->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::BONE_AMROR));
}

void GameManager::Release()
{
	delete m_pPlayer;
	delete m_pMonster;
	delete m_pShop;

	delete m_pItemManager;
}

void GameManager::EventCreate()
{
	string name;
	cout << "�ɸ��� �̸��� �Է��ϼ���!:";
	cin >> name;
	m_pPlayer->Set(name, 100, 100, 20, 10, 10, 0);
	ePlace = E_PLACE::TOWN;
}
void GameManager::EventInventory()
{
	m_pPlayer->Show();
	int nSelect;
	cout << "�޴��� �����ϼ���!(1: �����ۻ��. 2: ������� etc: ����):";
	cin >> nSelect;
	if (nSelect == 1)
	{
		cout << "����� �������� ���ϼ���!:";
		cin >> nSelect;
		cout << "Select:" << nSelect << endl;
		if (!m_pPlayer->UseItem(nSelect))
			cout << "����Ҽ������ϴ�!" << endl;
	}
	else if (nSelect == 2)
	{
		cout << "��������� ����Կ��� �����ϼ���!:";
		cin >> nSelect;
		m_pPlayer->ReleaseEqument(nSelect);
	}
	else
		ePlace = E_PLACE::TOWN;
}
void GameManager::EventShop()
{
	m_pShop->Show();
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
			if (m_pPlayer->Buy(*m_pShop, nInput))
				cout << "����: " << nInput << endl;
			else
				cout << "���� ����!" << endl;
		}
	}
	break;
	case 2:
	{
		m_pPlayer->Show();
		cout << "�Ǹ��� �������� ��Ͽ��� �����ϼ���! -1:����";
		cin >> nInput;
		if (nInput != -1)
		{
			m_pPlayer->Sell(nInput);
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
		m_pMonster->Set("Slime", 100, 100, 20, 10, 10, 100);
		break;
	case E_MONSTER::SKELETON:
		m_pMonster->Set("Skeleton", 200, 200, 30, 10, 10, 100);
		break;
	case E_MONSTER::BOSS:
		m_pMonster->Set("Boss", 300, 100, 50, 10, 10, 100);
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
		m_pMonster->Set("Slime", 100, 100, 20, 10, 10, 100);
		break;
	case E_MONSTER::SKELETON:
		m_pMonster->Set("Skeleton", 200, 200, 30, 10, 10, 100);
		break;
	case E_MONSTER::BOSS:
		m_pMonster->Set("Boss", 300, 100, 50, 10, 10, 100);
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
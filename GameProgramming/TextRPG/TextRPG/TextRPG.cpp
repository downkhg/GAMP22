#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Status {
	int nHP;
	int nMP;
	int nStr;
	int nInt;
	int nDef;

	Status(int _hp = 0, int _mp = 0, int _str = 0, int _int = 0, int _def = 0)
	{
		nHP = _hp;
		nMP = _mp;
		nStr = _str;
		nInt = _int;
		nDef = _def;
	}
	void operator+=(const int value)
	{
		this->nHP += value;
		this->nMP += value;
		this->nStr += value;
		this->nDef += value;
		this->nInt += value;
	}
	Status operator+(const Status& status)
	{
		Status sResult;
		sResult.nHP = nHP + status.nHP;
		sResult.nMP = nMP + status.nMP;
		sResult.nStr = nStr + status.nStr;
		sResult.nDef = nDef + status.nDef;
		sResult.nInt = nInt + status.nInt;
		return sResult;
	}
	Status operator-(const Status& status)
	{
		Status sResult;
		sResult.nHP = nHP - status.nHP;
		sResult.nMP = nMP - status.nMP;
		sResult.nStr = nStr - status.nStr;
		sResult.nDef = nDef - status.nDef;
		sResult.nInt = nInt - status.nInt;
		return sResult;
	}
	void Show()
	{
		cout << "HP:" << nHP << endl;
		cout << "MP:" << nMP << endl;
		cout << "STR:" << nStr << endl;
		cout << "INT:" << nInt << endl;
		cout << "DEF:" << nDef << endl;
	}
};

class Item {
public:
	enum E_ITEM_KIND { WEAPON, ARMOR, ACC, POTION, THROW };
	E_ITEM_KIND eItemKind;
	string strName;
	string strComment;
	Status sFuction;
	int nGold;
	Item(E_ITEM_KIND kind = WEAPON, string name = "test", string comment = "test", Status status = Status(), int gold = 0)
	{
		Set(kind, name, comment, status, gold);
	}
	void Set(E_ITEM_KIND kind, string name, string comment, Status status, int gold)
	{
		eItemKind = kind;
		strName = name;
		strComment = comment;
		sFuction = status;
		nGold = gold;
	}
};

class Player {
	string m_strName;
	Status m_sStatus;
	int m_nLv = 1;
	int m_nExp = 0;
	int m_nGold;

	vector<Item*> m_listIventory;
	vector<Item*> m_listEqument;
public:
	void SetIventory(Item* item)
	{
		m_listIventory.push_back(item);
	}
	Item* GetIventoryIdx(int idx)
	{
		return m_listIventory[idx];
	}
	void DeleteIventory(int idx)
	{
		m_listIventory.erase(m_listIventory.begin() + idx);
	}

	bool UseItem(int idx)
	{
		Item* pItem = GetIventoryIdx(idx);

		if (pItem->eItemKind == Item::E_ITEM_KIND::THROW)
			return false;

		int nIdx = pItem->eItemKind;
		m_listEqument[nIdx] = pItem;
		m_sStatus = m_sStatus + pItem->sFuction;
		DeleteIventory(idx);

		return true;
	}

	void ReleaseEqument(int idx)
	{
		Item* pItem = m_listEqument[idx];
		m_sStatus = m_sStatus - pItem->sFuction;
		SetIventory(pItem);
	}

	bool Buy(Player& target, int idx)
	{
		Item* pItem = target.GetIventoryIdx(idx);
		if (pItem->nGold <= m_nGold)
		{
			SetIventory(pItem);
			m_nGold -= pItem->nGold;
			return true;
		}
		return false;
	}

	void Sell(int idx)
	{
		Item* pItem = GetIventoryIdx(idx);
		DeleteIventory(idx);
		m_nGold += pItem->nGold;
	}

	Player(const char* strName = "NONE", int _gold = 0, int _hp = 100, int _mp = 100, int _str = 20, int  _int = 10, int _def = 10, int _exp = 0, int equmentCount = 3)
	{
		Set(strName, _hp, _mp, _str, _int, _def, _exp);
		m_listEqument.resize(equmentCount);
		m_nGold = _gold;
	}

	void Set(string strName, int _hp, int _mp, int _str, int _int, int _def, int _exp)
	{
		m_strName = strName;
		m_sStatus.nHP = _hp;
		m_sStatus.nMP = _mp;
		m_sStatus.nStr = _str;
		m_sStatus.nInt = _int;
		m_sStatus.nDef = _def;
		m_nExp = _exp;
		m_nLv = 1;
	}

	void Attack(Player& taget)
	{
		taget.m_sStatus.nHP -= m_sStatus.nStr - m_sStatus.nDef;
	}

	void StillExp(Player& taget)
	{
		//Ÿ���� ����ġ�� �����ͼ� �� ����ġ�� �ø���.
		this->m_nExp = taget.m_nLv * 100 + taget.m_nExp;
	}

	void StillItem(Player& target, int idx = 0)
	{
		SetIventory(target.m_listIventory[idx]);
	}

	bool LvUp()
	{
		//���� ����ġ�� 100 �̻�Ǹ�, ����+1, ��� �ɷ�ġ 10����, ����ġ �ʱ�ȭ.
		if (m_nExp >= 100)
		{
			m_sStatus += 10;
			m_nLv++;
			m_nExp -= 100;
			return true;
		}
		return false;
	}

	bool Dead()
	{
		if (m_sStatus.nHP <= 0)
			return true;
		return false;
	}

	void Show()
	{
		cout << "######### " << m_strName << "######### " << endl;
		m_sStatus.Show();
		cout << "######### Inventory ######### " << endl;
		for (int i = 0; i < m_listIventory.size(); i++)
			if(m_listIventory[i] != nullptr)
				cout << i << ":" << m_listIventory[i]->strName << endl;
		cout << "######### Equment ######### " << endl;
		for (int i = 0; i < m_listEqument.size(); i++)
			if (m_listEqument[i] != nullptr)
				cout << i << ":" << m_listEqument[i]->strName << endl;
			else
				cout << i << ":" << "null" << endl;
		cout << "######### Gold:" << m_nGold << " ######### " << endl;
	}
};

class ItemManager {
	vector<Item> m_listItems;
public:
	enum E_ITEM_LIST { WOOD_SOWRD, BONE_SOWRD, WOOD_ARMOR, BONE_AMROR, WOOD_RING, BONE_RING, HP_POTION, MP_POTION, STONE, BOOM };
	ItemManager()
	{
		
	}

	void Init()
	{
		m_listItems.resize(10);
		m_listItems[0] = Item(Item::E_ITEM_KIND::WEAPON, "���", "������_����", Status(0, 0, 10), 100);
		m_listItems[1] = Item(Item::E_ITEM_KIND::WEAPON, "���ҵ�", "������_����", Status(0, 0, 20), 100);
		m_listItems[2] = Item(Item::E_ITEM_KIND::ARMOR, "��������", "����_����", Status(0, 0, 0, 10), 100);
		m_listItems[3] = Item(Item::E_ITEM_KIND::ARMOR, "���Ƹ�", "����_����", Status(0, 0, 20), 100);
		m_listItems[4] = Item(Item::E_ITEM_KIND::ACC, "��������", "ü��_����", Status(10), 100);
		m_listItems[5] = Item(Item::E_ITEM_KIND::ACC, "�ذ����", "ü��_����", Status(20), 100);
		m_listItems[6] = Item(Item::E_ITEM_KIND::POTION, "��������", "HPȸ��", Status(100), 100);
		m_listItems[7] = Item(Item::E_ITEM_KIND::POTION, "��������", "MPȸ��", Status(0, 100), 100);
		m_listItems[8] = Item(Item::E_ITEM_KIND::THROW, "¯��", "����_��_�����", Status(0, 0, 50), 100);
		m_listItems[9] = Item(Item::E_ITEM_KIND::THROW, "���", "�ټ�_��_�����", Status(0, 0, 50), 100);
		cout << "Init("<< m_listItems.size() <<")" << endl;
	}

	void SaveFile()
	{
		if (m_listItems.empty())
		{
			cout << "Save Data is Empty!!!" << endl;
			return;
		}
		else 
			cout << "Save Data" << endl;

		FILE* pFile = fopen("itemdatabase.csv", "wt");
		if (pFile)
		{
			fprintf(pFile, "%d\n", m_listItems.size());
			vector<Item>::iterator it = m_listItems.begin();
			for (; it != m_listItems.end(); it++)
			{
				Item sItem = *(it);
				fprintf(pFile, "%d,%s,%s,%d,%d,%d,%d,%d,%d\n", sItem.eItemKind, sItem.strName.c_str(), sItem.strComment.c_str(), sItem.nGold,
					sItem.sFuction.nHP, sItem.sFuction.nMP, sItem.sFuction.nStr, sItem.sFuction.nInt, sItem.sFuction.nDef);
			}
			fclose(pFile);
		}
		else
			cout << " Save Failed!" << endl;
	}

	void LoadFile()
	{
		FILE* pFile = fopen("itemdatabase.csv", "rt");
		if (pFile)
		{
			int nSize;
			fscanf(pFile, "%d", &nSize);

			for (int i = 0; i < nSize; i++)
			{
				char strTemp[1024];
				fscanf(pFile, "%s\n", strTemp);
				cout << strTemp << endl;
				char  arrStrs[10][128];
				char* strTemps = strtok(strTemp, ",");
				int idx = 0;
				while (strTemps != NULL)
				{
					//memcpy(arrStrs[idx], strTemps, 128);
					strcpy(arrStrs[idx], strTemps);
					cout << arrStrs[idx] << ",";
					//cout << strTemps << ",";
					strTemps = strtok(NULL, ",");
					idx++;
				}
				cout << endl;
				string name = arrStrs[1];
				string info = arrStrs[2];
				Item sItem((Item::E_ITEM_KIND)atoi(arrStrs[0]), name, info,
					Status(atoi(arrStrs[4]), atoi(arrStrs[5]), atoi(arrStrs[6]), atoi(arrStrs[7])),
					atoi(arrStrs[3]));
				m_listItems.push_back(sItem);
			}
			fclose(pFile);
		}
		else
			cout << "Load Failed!" << endl;
	}

	Item* GetItem(int idx)
	{
		return &m_listItems[idx];
	}
};

class GameManager
{
public:
	enum E_PLACE { EXIT = -1, CRATE, IVNETORY, SHOP, TOWN, FILED, BATTLE, GAME_OVER, THE_END, MAX };
	enum E_MONSTER { SILME, SKELETON, BOSS, MON_MAX };

	E_PLACE GetPlace()
	{
		return ePlace;
	}

	void Init()
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
	void EventCreate()
	{
		string name;
		cout << "�ɸ��� �̸��� �Է��ϼ���!:";
		cin >> name;
		cPlayer.Set(name, 100, 100, 20, 10, 10, 0);
		ePlace = E_PLACE::TOWN;
	}
	void EventInventory()
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
	void EventShop()
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
	void EventTown()
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
	void EvnetFiled()
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
	void EventBattle()
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
	
	void EventGameOver()
	{
		cout << "GAME OVER" << endl;
		ePlace = E_PLACE::EXIT;
	}
	void EventTheEnd()
	{
		cout << "The End" << endl;
		ePlace = E_PLACE::TOWN;
	}

	void Updata()
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
			EventInventory();
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
private:
	Player cPlayer = Player("Player", 100000);
	Player cMonster = Player("Monster");
	Player cShop;
	ItemManager cItemManager;

	E_PLACE ePlace = E_PLACE::CRATE;
};


void main()
{
	GameManager cGameManager;
	cGameManager.Init();

	while (cGameManager.GetPlace() != GameManager::E_PLACE::EXIT)
	{
		cGameManager.Updata();
	}
}

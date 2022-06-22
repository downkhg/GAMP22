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

	vector<Item> m_listIventory;
	vector<Item> m_listEqument;
public:
	void SetIventory(Item item)
	{
		m_listIventory.push_back(item);
	}
	Item GetIventoryIdx(int idx)
	{
		return m_listIventory[idx];
	}
	void DeleteIventory(int idx)
	{
		m_listIventory.erase(m_listIventory.begin() + idx);
	}

	bool UseItem(int idx)
	{
		Item cItem = GetIventoryIdx(idx);

		if (cItem.eItemKind == Item::E_ITEM_KIND::THROW)
			return false;

		int nIdx = cItem.eItemKind;
		m_listEqument[nIdx] = cItem;
		m_sStatus = m_sStatus + cItem.sFuction;
		DeleteIventory(idx);

		return true;
	}

	void ReleaseEqument(int idx)
	{
		Item cItem = m_listEqument[idx];
		m_sStatus = m_sStatus - cItem.sFuction;
		SetIventory(cItem);
	}

	Player(const char* strName = "NONE", int _hp = 100, int _mp = 100, int _str = 20, int  _int = 10, int _def = 10, int _exp = 0, int equmentCount = 3)
	{
		Set(strName, _hp, _mp, _str, _int, _def, _exp);
		m_listEqument.resize(equmentCount);
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
		//타겟의 경험치를 가져와서 내 경험치에 올린다.
		this->m_nExp = taget.m_nLv * 100 + taget.m_nExp;
	}

	void StillItem(Player& target, int idx = 0)
	{
		SetIventory(target.m_listIventory[idx]);
	}

	bool LvUp()
	{
		//만약 경험치가 100 이상되면, 레벨+1, 모든 능력치 10증가, 경험치 초기화.
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
			cout << i << ":" << m_listIventory[i].strName << endl;
		cout << "######### Equment ######### " << endl;
		for (int i = 0; i < m_listEqument.size(); i++)
			cout << i << ":" << m_listEqument[i].strName << endl;
	}
};

class ItemManager {
	vector<Item> m_listItems;
public:
	enum E_ITEM_LIST { WOOD_SOWRD, BONE_SOWRD, WOOD_ARMOR, BONE_AMROR, WOOD_RING, BONE_RING, HP_POTION, MP_POTION, STONE, BOOM };
	ItemManager()
	{
		m_listItems.resize(10);
		m_listItems[0] = Item(Item::E_ITEM_KIND::WEAPON, "목검", "데미지 증가", Status(0, 0, 10), 100);
		m_listItems[1] = Item(Item::E_ITEM_KIND::WEAPON, "본소드", "데미지 증가", Status(0, 0, 20), 100);
		m_listItems[2] = Item(Item::E_ITEM_KIND::ARMOR, "나무갑옷", "방어력 증가", Status(0, 0, 0, 10), 100);
		m_listItems[3] = Item(Item::E_ITEM_KIND::ARMOR, "본아머", "방어력 증가", Status(0, 0, 20), 100);
		m_listItems[4] = Item(Item::E_ITEM_KIND::ACC, "나무반지", "체력 증가", Status(10), 100);
		m_listItems[5] = Item(Item::E_ITEM_KIND::ACC, "해골반지", "체력 증가", Status(20), 100);
		m_listItems[6] = Item(Item::E_ITEM_KIND::POTION, "힐링포션", "HP회복", Status(100), 100);
		m_listItems[7] = Item(Item::E_ITEM_KIND::POTION, "마나포션", "MP회복", Status(0, 100), 100);
		m_listItems[8] = Item(Item::E_ITEM_KIND::THROW, "짱돌", "단일 적 대미지", Status(0, 0, 50), 100);
		m_listItems[9] = Item(Item::E_ITEM_KIND::THROW, "목검", "다수 적 대미지", Status(0, 0, 50), 100);
	}
	Item GetItem(int idx)
	{
		return m_listItems[idx];
	}
};


void main()
{
	//공격? 주인공이 게임에서 상대를 쓰러뜨리려고하는 행위
	Player cPlayer("Player");
	Player cMonster("Monster");
	ItemManager cItemManager;

	//cMonster.SetIventory(Item(Item::ETC, "HPPotion", "Hp Recover", Status(100, 0, 0, 0, 0), 100));
	Item cHPPotion = cItemManager.GetItem(ItemManager::E_ITEM_LIST::HP_POTION);
	cMonster.SetIventory(cHPPotion);

	cPlayer.SetIventory(cItemManager.GetItem(ItemManager::E_ITEM_LIST::BONE_AMROR));

	enum E_PLACE { EXIT = -1, CRATE, IVNETORY, TOWN, FILED, BATTLE, GAME_OVER, THE_END, MAX };
	E_PLACE ePlace = E_PLACE::CRATE;
	const char* strStageName[] = { "CRATE", "INVENTORY","TOWN", "FILED", "BATTLE", "GAME_OVER", "THE_END" };

	enum E_MONSTER { SILME, SKELETON, BOSS, MON_MAX };
	const char* strMonsterName[] = { "SILME", "SKELETON", "BOSS" };
	int nInput;


	while (ePlace != EXIT)
	{
		switch (ePlace)
		{
		case CRATE: //이름을 입력받는다.
		{
			string name;
			cout << "케릭터 이름을 입력하세요!:";
			cin >> name;
			cPlayer.Set(name, 100, 100, 20, 10, 10, 0);
			ePlace = E_PLACE::TOWN;
		}
		break;
		case IVNETORY://인벤토리의 목록을 보여주고, 사용할 아이템을 번호를 선택하면 사용 할 수있다. //장비를 선택하면 장비를 보여주고 해제할아이템 선택
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
		break;
		case TOWN: //인벤토리와 상점이 이용이 가능하다.
		{

			cout << "마을 입니다." << endl;
			cout << "어디로 가시겠습니까?" << endl;
			for (int i = E_PLACE::CRATE + 1; i < E_PLACE::BATTLE; i++)
				cout << i << ":" << strStageName[i] << ",";
			cin >> nInput;
			ePlace = (E_PLACE)nInput;
		}
		break;
		case FILED:
		{
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
		break;
		case BATTLE:
		{
			if (!cPlayer.Dead())
			{
				cPlayer.Attack(cMonster);
				cMonster.Show();
			}
			else
			{
				cout << "Monster Win!" << endl;
				cMonster.StillExp(cMonster);
				if (cMonster.LvUp())
					cout << "LvUp!!!" << endl;
				cMonster.Show();
				ePlace = GAME_OVER;
			}

			if (!cMonster.Dead())
			{
				cMonster.Attack(cPlayer);
				cPlayer.Show();
			}
			else
			{
				cout << "Player Win!" << endl;
				cPlayer.StillExp(cMonster);
				cPlayer.StillItem(cMonster);
				if (cPlayer.LvUp())
					cout << "LvUp!!!" << endl;
				cPlayer.StillItem(cMonster);
				cPlayer.Show();
				ePlace = TOWN;
			}
		}
		break;
		case GAME_OVER:
		{
			cout << "GAME OVER" << endl;
			ePlace = E_PLACE::EXIT;
		}
		break;
		case THE_END:
		{
			cout << "THE END" << endl;
			ePlace = E_PLACE::TOWN;
		}
		break;
		}
	}



}

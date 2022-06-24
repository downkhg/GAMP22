#include "Item.h"


Status::Status(int _hp, int _mp, int _str, int _int, int _def)
{
	nHP = _hp;
	nMP = _mp;
	nStr = _str;
	nInt = _int;
	nDef = _def;
}
void Status::operator+=(const int value)
{
	this->nHP += value;
	this->nMP += value;
	this->nStr += value;
	this->nDef += value;
	this->nInt += value;
}
Status Status::operator+(const Status& status)
{
	Status sResult;
	sResult.nHP = nHP + status.nHP;
	sResult.nMP = nMP + status.nMP;
	sResult.nStr = nStr + status.nStr;
	sResult.nDef = nDef + status.nDef;
	sResult.nInt = nInt + status.nInt;
	return sResult;
}
Status Status::operator-(const Status& status)
{
	Status sResult;
	sResult.nHP = nHP - status.nHP;
	sResult.nMP = nMP - status.nMP;
	sResult.nStr = nStr - status.nStr;
	sResult.nDef = nDef - status.nDef;
	sResult.nInt = nInt - status.nInt;
	return sResult;
}
void Status::Show()
{
	cout << "HP:" << nHP << endl;
	cout << "MP:" << nMP << endl;
	cout << "STR:" << nStr << endl;
	cout << "INT:" << nInt << endl;
	cout << "DEF:" << nDef << endl;
}

Item::Item(E_ITEM_KIND kind, string name, string comment, Status status, int gold)
{
	Set(kind, name, comment, status, gold);
}
void Item::Set(E_ITEM_KIND kind, string name, string comment, Status status, int gold)
{
	eItemKind = kind;
	strName = name;
	strComment = comment;
	sFuction = status;
	nGold = gold;
}
ItemManager::ItemManager()
{

}
void ItemManager::Init()
{
	m_listItems.resize(10);
	m_listItems[0] = Item(Item::E_ITEM_KIND::WEAPON, "목검", "데미지_증가", Status(0, 0, 10), 100);
	m_listItems[1] = Item(Item::E_ITEM_KIND::WEAPON, "본소드", "데미지_증가", Status(0, 0, 20), 100);
	m_listItems[2] = Item(Item::E_ITEM_KIND::ARMOR, "나무갑옷", "방어력_증가", Status(0, 0, 0, 10), 100);
	m_listItems[3] = Item(Item::E_ITEM_KIND::ARMOR, "본아머", "방어력_증가", Status(0, 0, 20), 100);
	m_listItems[4] = Item(Item::E_ITEM_KIND::ACC, "나무반지", "체력_증가", Status(10), 100);
	m_listItems[5] = Item(Item::E_ITEM_KIND::ACC, "해골반지", "체력_증가", Status(20), 100);
	m_listItems[6] = Item(Item::E_ITEM_KIND::POTION, "힐링포션", "HP회복", Status(100), 100);
	m_listItems[7] = Item(Item::E_ITEM_KIND::POTION, "마나포션", "MP회복", Status(0, 100), 100);
	m_listItems[8] = Item(Item::E_ITEM_KIND::THROW, "짱돌", "단일_적_대미지", Status(0, 0, 50), 100);
	m_listItems[9] = Item(Item::E_ITEM_KIND::THROW, "목검", "다수_적_대미지", Status(0, 0, 50), 100);
	cout << "Init(" << m_listItems.size() << ")" << endl;
}

void ItemManager::SaveFile()
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

void ItemManager::LoadFile()
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

Item* ItemManager::GetItem(int idx)
{
	return &m_listItems[idx];
}
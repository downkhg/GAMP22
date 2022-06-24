#include "Player.h"

void Player::SetIventory(Item* item)
{
	m_listIventory.push_back(item);
}
Item* Player::GetIventoryIdx(int idx)
{
	return m_listIventory[idx];
}
void Player::DeleteIventory(int idx)
{
	m_listIventory.erase(m_listIventory.begin() + idx);
}

bool Player::UseItem(int idx)
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

void Player::ReleaseEqument(int idx)
{
	Item* pItem = m_listEqument[idx];
	m_sStatus = m_sStatus - pItem->sFuction;
	SetIventory(pItem);
}

bool Player::Buy(Player& target, int idx)
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

void Player::Sell(int idx)
{
	Item* pItem = GetIventoryIdx(idx);
	DeleteIventory(idx);
	m_nGold += pItem->nGold;
}

Player::Player(const char* strName, int _gold, int _hp , int _mp, int _str, int  _int, int _def, int _exp, int equmentCount)
{
	Set(strName, _hp, _mp, _str, _int, _def, _exp);
	m_listEqument.resize(equmentCount);
	m_nGold = _gold;
}

void Player::Set(string strName, int _hp, int _mp, int _str, int _int, int _def, int _exp)
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

void Player::Attack(Player& taget)
{
	taget.m_sStatus.nHP -= m_sStatus.nStr - m_sStatus.nDef;
}

void Player::StillExp(Player& taget)
{
	//타겟의 경험치를 가져와서 내 경험치에 올린다.
	this->m_nExp = taget.m_nLv * 100 + taget.m_nExp;
}

void Player::StillItem(Player& target, int idx)
{
	SetIventory(target.m_listIventory[idx]);
}

bool Player::LvUp()
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

bool Player::Dead()
{
	if (m_sStatus.nHP <= 0)
		return true;
	return false;
}

void Player::Show()
{
	cout << "######### " << m_strName << "######### " << endl;
	m_sStatus.Show();
	cout << "######### Inventory ######### " << endl;
	for (int i = 0; i < m_listIventory.size(); i++)
		if (m_listIventory[i] != nullptr)
			cout << i << ":" << m_listIventory[i]->strName << endl;
	cout << "######### Equment ######### " << endl;
	for (int i = 0; i < m_listEqument.size(); i++)
		if (m_listEqument[i] != nullptr)
			cout << i << ":" << m_listEqument[i]->strName << endl;
		else
			cout << i << ":" << "null" << endl;
	cout << "######### Gold:" << m_nGold << " ######### " << endl;
}
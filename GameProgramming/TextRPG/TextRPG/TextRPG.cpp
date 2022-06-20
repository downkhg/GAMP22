#include <iostream>
#include <string>
using namespace std;

class Player {
	string m_strName;

	int m_nHP;
	int m_nMP;
	int m_nStr;
	int m_nInt;
	int m_nDef;
public:
	Player(string strName = "NONE", int _hp = 100, int _mp = 100, int _str = 20, int  _int = 10 , int _def = 10)
	{
		Set(strName, _hp, _mp, _str, _int, _def);;
	}

	void Set(string strName, int _hp, int _mp, int _str, int _int, int _def)
	{
		m_strName = strName;
		m_nHP = _hp;
		m_nMP = _mp;
		m_nStr = _str;
		m_nInt = _int;
		m_nDef = _def;
	}

	void Attack(Player& target)
	{
		target.Demaged(m_nStr);
	}
	void Demaged(int dem)
	{
		m_nHP -= dem - m_nDef;
	}
	bool Dead()
	{
		if (m_nHP <= 0)
			return true;
		return false;
	}

	void Show()
	{
		cout << "######### " << m_strName << "######### " << endl;
		cout << "HP:" << m_nHP << endl;
		cout << "MP:" << m_nMP << endl;
		cout << "STR:" << m_nStr << endl;
		cout << "INT:" << m_nInt << endl;
		cout << "DEF:" << m_nDef << endl;
	}
};

void main()
{
	//공격? 주인공이 게임에서 상대를 쓰러뜨리려고하는 행위
	Player cPlayer("Player");
	Player cMonster("Monster");

	while (!cPlayer.Dead() && !cMonster.Dead())//누군가가 죽으면 끝난다. -> 둘중하나라도 살아있으면 
	{
		if (!cPlayer.Dead())
		{
			cPlayer.Attack(cMonster);
			cMonster.Show();
		}
		if (!cMonster.Dead())
		{
			cMonster.Attack(cPlayer);
			cPlayer.Show();
		}
	}
}
#include <iostream>
#include <string>
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

class Player {
	string m_strName;
	Status m_sStatus;
	int m_nLv;
	int m_nExp;
public:
	Player(const char* strName = "NONE", int _hp = 100, int _mp = 100, int _str = 20, int  _int = 10, int _def = 10, int _exp = 0)
	{
		Set(strName, _hp, _mp, _str, _int, _def, _exp);
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
		else
		{
			cout << "Monster Win!" << endl;
			cMonster.StillExp(cMonster);
			if (cMonster.LvUp())
				cout << "LvUp!!!" << endl;
			cMonster.Show();
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
			if (cPlayer.LvUp())
				cout << "LvUp!!!" << endl;
			cPlayer.Show();
		}
	}
}

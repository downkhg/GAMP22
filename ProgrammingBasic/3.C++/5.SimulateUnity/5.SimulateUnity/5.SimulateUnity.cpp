#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Component
{
	virtual void Start() = 0; //순수가상함수.
	virtual void Update() = 0;
public:
	Component() { cout << typeid(*this).name() << "[" << this << "]" << endl; }
	virtual ~Component() { cout << "~" << typeid(*this).name() << "[" << this << "]" << endl; }

	bool operator==(const char* typeidname)
	{
		return !strcmp(typeid(*this).name(), typeidname);
	}
};

class GameObject
{
	string m_strName;
	list<Component*> m_listScrits;//has-a:
public:
	GameObject(string name)
	{
		m_strName = name;
		cout << typeid(*this).name() << "[" << this << "]:"<< m_strName << endl;
	}
	~GameObject()
	{ 
		for (list<Component*>::iterator it = m_listScrits.begin(); it != m_listScrits.end(); it++)
			delete *it;
		m_listScrits.clear();
		cout << "~" <<typeid(*this).name() << "[" << this << "]" << endl;
	}
	void AddComponent(Component* script) { m_listScrits.push_back(script); }
	Component* GetComponent(const char* typeidname) 
	{ 
		for (list<Component*>::iterator it = m_listScrits.begin(); it != m_listScrits.end(); it++)
		{
			Component* pComponset = *it;
			if (*pComponset == typeidname)
			{
				cout << typeid(*this).name()<< ".GetComponent("<< typeidname <<")[" << pComponset << "]" << endl;
				return pComponset;
			}
		}
		return NULL; 
	} 
	//Component* GetComponent(const char* typeidname){ return *find(m_listScrits.begin(), m_listScrits.end(), typeidname); }
	string GetName(){ return m_strName; }
};
//다형성을 이용하여 TargetTracker과 Player클래스를 같은 자료구조에서 관리함. 부모클래스(Component)를 상속받아야함.
class TargetTracker : public Component//상속
{
	GameObject* m_pTarget = NULL;
public:
	TargetTracker() { cout << typeid(*this).name() << "[" << this << "]" << endl; }
	~TargetTracker() { cout << "~" << typeid(*this).name() << "[" << this << "]" << endl; }

	GameObject* GetTarget() { return m_pTarget; };
	void SetTarget(GameObject* obj) 
	{ 
		m_pTarget = obj;
		cout << typeid(*this).name() << ".SetTarget("<< m_pTarget << ")" << endl;
	};

	void Start() override
	{
		cout << typeid(*this).name() << "["<< this <<"]:Start()" << endl;
	}
	void Update() override
	{
		cout << typeid(*this).name() << "[" << this << "]:Update()" << endl;
	}
};

class Player : public Component
{
	int m_nHp;
	int m_nStr;
public:
	Player() { cout << typeid(*this).name() << "[" << this << "]" << endl; }
	~Player() { cout << "~" << typeid(*this).name() << "[" << this << "]" << endl; }

	void InitStatus(int hp, int str)
	{
		m_nHp = hp;
		m_nStr = str;
	}

	void Start() override
	{
		InitStatus(100, 10);
		cout << typeid(*this).name() << "[" << this << "]:Start()" << endl;
	}
	void Update() override
	{
		cout << "~" << typeid(*this).name() << "[" << this << "]:Update()" << endl;
	}
};


void SimulateUnityTestMain()
{
	cout << "###### SimulateUnityTestMain() Start ######" << endl;

	cout << "###### Create GameObjects ######" << endl;
	GameObject objPlayer("Player");
	GameObject objEagle("Eagle");

	vector<GameObject*> listGameObjects(2);

	listGameObjects[0] = &objPlayer;
	listGameObjects[1] = &objEagle;
	//java나 c#에서는 클래스는 반드시 동적할당된다.
	//할당된 메모리는 가비지컬렉션이 자동으로 수집 관리한다.(c++ 스마트포인터)
	//객체: 참조자, 인스턴스: 동적할당 된 메모리
	//listGameObjects[2] = new GameObject("Opossum");
	//delete listGameObjects[2];

	cout << "###### " << objPlayer.GetName() <<".Add Componet ######"<< endl;
	objPlayer.AddComponent(new Player());

	cout << "###### " << objEagle.GetName() << ".Add Componet ######" << endl;
	objEagle.AddComponent(new Player());
	objEagle.AddComponent(new TargetTracker());

	cout << "GameLoop" << endl;

	cout << "###### "<< objEagle.GetName() <<".Target(" << objPlayer.GetName() <<") ######" << endl;
	TargetTracker* pTargetTarcker = dynamic_cast<TargetTracker*> (objEagle.GetComponent(typeid(TargetTracker).name()));
	if (pTargetTarcker)
		pTargetTarcker->SetTarget(&objPlayer);
	else
		cout <<"!"<< typeid(objEagle).name() << endl;
	cout << "###### SimulateUnityTestMain() End ######" << endl;
}

void main()
{
	SimulateUnityTestMain();
}
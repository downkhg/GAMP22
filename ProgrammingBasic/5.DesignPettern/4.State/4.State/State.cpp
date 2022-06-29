#include <iostream>
#include <stdlib.h> //메모리 동적할당 헤더
#include <crtdbg.h> //메모리 누수 탐지 헤더

class Context;
class StateOne;
class StateTow;
class StateThree;



class Context
{
	State* m_pState = NULL;
	///※그러나 friend는 사용하지않도록 권장함.
	//다음과 같이 friend클래스를 활용하여
	//SetState를 외부에서는 사용하지 못하지만,
	//각 State객체에서는 접근가능하도록 할수도 있다.
	friend class StateOne;
	friend class StateTow;
	friend class StateThree;

	void SetState(State* newState)
	{
		m_pState = newState;
	}

public:
	Context()
	{
		m_pState = new StateOne();
	}

	Context(State* curState)
	{
		m_pState = curState;
	}

	~Context()
	{
		delete m_pState;
	}
	void GoNext()
	{
		m_pState->GoNext(this);
	}
};

class State
{
	friend class Context;
public:
	virtual void GoNext(Context* context) = 0;
};


class StateThree : public State
{
public:
	void GoNext(Context* context) override
	{
		context->SetState(new StateOne);
	}
};

class StateTow : public State
{
public:
	void GoNext(Context* context) override
	{
		context->SetState(new StateTow);
	}
};


class StateOne : public State
{
public:
	void GoNext(Context* context) override
	{
		context->SetState(new StateThree);
	}
};

using namespace std;

void main()
{
	//_CrtSetBreakAlloc(165); //메모리 누수시 번호를 넣으면 할당하는 위치에 브레이크 포인트를 건다.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //메모리 누수 검사 

	Context cContext;
	//성성자에서 기본 StateOne을 할당하거나,
	//성성시 State를 설정할수있도록 생성자를 정의함.
	//소멸자에는 생성된 객체를 소멸시키도록 만듦.

	///※그러나 friend는 사용하지않도록 권장함.
	//friend키워드를 이용하여 Context만 사용가능하게 만들 수도 있다.
	//다음인터페이스는 사용하기 불편함
	//cContext.SetState(new StateOne());
	//Context::GoNext()시 다른 생성된 객체가 삭제되도록,
	//Contest::SetState()에서 기존에 할당된 객체를 삭제하게 만듦.
	cContext.GoNext();
	cContext.GoNext();
	cContext.GoNext();
}
#include <iostream>
#include <stdlib.h> //�޸� �����Ҵ� ���
#include <crtdbg.h> //�޸� ���� Ž�� ���

class Context;
class StateOne;
class StateTow;
class StateThree;



class Context
{
	State* m_pState = NULL;
	///�ر׷��� friend�� ��������ʵ��� ������.
	//������ ���� friendŬ������ Ȱ���Ͽ�
	//SetState�� �ܺο����� ������� ��������,
	//�� State��ü������ ���ٰ����ϵ��� �Ҽ��� �ִ�.
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
	//_CrtSetBreakAlloc(165); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻� 

	Context cContext;
	//�����ڿ��� �⺻ StateOne�� �Ҵ��ϰų�,
	//������ State�� �����Ҽ��ֵ��� �����ڸ� ������.
	//�Ҹ��ڿ��� ������ ��ü�� �Ҹ��Ű���� ����.

	///�ر׷��� friend�� ��������ʵ��� ������.
	//friendŰ���带 �̿��Ͽ� Context�� ��밡���ϰ� ���� ���� �ִ�.
	//�����������̽��� ����ϱ� ������
	//cContext.SetState(new StateOne());
	//Context::GoNext()�� �ٸ� ������ ��ü�� �����ǵ���,
	//Contest::SetState()���� ������ �Ҵ�� ��ü�� �����ϰ� ����.
	cContext.GoNext();
	cContext.GoNext();
	cContext.GoNext();
}
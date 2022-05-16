#include <iostream>

using namespace std; //ǥ�ض��̺귯���� ����Ѵ�.

namespace A
{
	int g_nData;
	void PrintData() { cout << "A::Data:"<<g_nData << endl; };
}
namespace B
{
	int g_nData;
	void PrintData() { cout << "B::Data:" << g_nData << endl; };
}

//using namespace A; //A��� �̸������� �⺻���� ����Ѵ�.
using namespace B; //B��� �̸������� �⺻���� ����Ѵ�.

void NamespaceTestMain()
{
	A::g_nData = 10;
	B::g_nData = 20;
	g_nData = 30; //�� ������ �̸������� ���� 1���� �־�� �۵��Ѵ�. 
	//A�� ����� ��� A::g_nData�� 30�� �ȴ�.
	//B�� ����� ��� B::g_nData�� 30�� �ȴ�.

	A::PrintData();// A::Data:10
	B::PrintData();// B::Data:20
}

namespace Overloading {
	//�����ε�: �Լ��� �̸��� ������, �Ű������� ������ Ÿ���� �ٸ� �Լ�.
	int Sum(int a, int b, int c) { return a + b + c; };
	int Sum(int a, int b) { return a + b; };
	int Sum(int a) { return a; };
	int Sum() { return 0; }

	void FunctionTestMain()
	{
		cout << "1.Sum(3):" << Sum(10, 20, 30) << endl;
		cout << "2.Sum(2):" << Sum(10, 20) << endl;
		cout << "3.Sum(1):" << Sum(10) << endl;
		cout << "4.Sum(0):" << Sum() << endl;
	}
}

namespace DefaultParameter
{
	//����Ʈ�Ű�����: �Լ��� �Ű������� ���� ����������, �⺻���� ������.
	//inline: �����Ϸ����� �Լ��� ȣ���ſ� �Լ��� ���� �ٿ��ִ´�. 
	//�Լ��� ȣ���� �����Ͽ� �ӵ��� ���� �ɼ�����. (�����Ϸ� ����ȭ: �����Ϸ� �ܿ��� �ڵ带 �������� �������)
	//(��, �����Ϸ��� inline�� �ٿ��� ���ٷ� ������ �ȵ� �Լ��� �ζ����Լ��� ����� ����.)
	inline int Sum(int a = 0, int b = 0, int c = 0) { return a + b + c; };

	void FunctionTestMain()
	{
		cout << "1.Sum(3):" << Sum(10, 20, 30) << endl;
		//cout << "1.Sum(3):" << 10+20+30 << endl; //����, �ζ��� �Լ�ȭ �ȴٸ� ������ ���� �۵��Ѵ�.
		cout << "2.Sum(2):" << Sum(10, 20) << endl;
		cout << "3.Sum(1):" << Sum(10) << endl;
		cout << "4.Sum(0):" << Sum() << endl;
	}
}

void HelloWorldMain()
{
	std::cout << "Hello World!!!\n" << std::endl;//\n
}

void main()
{
	//HelloWorldMain();
	//NamespaceTestMain();
	Overloading::FunctionTestMain();
	DefaultParameter::FunctionTestMain();
}
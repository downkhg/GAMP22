#include <iostream>

using namespace std; //표준라이브러리를 사용한다.

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

//using namespace A; //A라는 이름공간을 기본으로 사용한다.
using namespace B; //B라는 이름공간을 기본으로 사용한다.

void NamespaceTestMain()
{
	A::g_nData = 10;
	B::g_nData = 20;
	g_nData = 30; //위 가져올 이름공간은 둘중 1개만 있어야 작동한다. 
	//A를 사용할 경우 A::g_nData가 30이 된다.
	//B를 사용할 경우 B::g_nData가 30이 된다.

	A::PrintData();// A::Data:10
	B::PrintData();// B::Data:20
}

namespace Overloading {
	//오버로딩: 함수의 이름은 같으나, 매개변수의 갯수나 타입이 다른 함수.
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
	//디폴트매개변수: 함수의 매개변수에 값을 넣지않으면, 기본값을 지정함.
	//inline: 컴파일러에서 함수의 호출대신에 함수의 식을 붙여넣는다. 
	//함수를 호출을 제거하여 속도가 증가 될수있음. (컴파일러 최적화: 컴파일러 단에서 코드를 성능좋게 만들어줌)
	//(단, 컴파일러가 inline을 붙여도 한줄로 구성이 안된 함수는 인라인함수로 만들수 없다.)
	inline int Sum(int a = 0, int b = 0, int c = 0) { return a + b + c; };

	void FunctionTestMain()
	{
		cout << "1.Sum(3):" << Sum(10, 20, 30) << endl;
		//cout << "1.Sum(3):" << 10+20+30 << endl; //만약, 인라인 함수화 된다면 다음과 같이 작동한다.
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
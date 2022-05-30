#include <iostream>

using namespace std;

//자동차 추상화하기
//상태(데이터 - 변수): 색상,속도,기어
//동작(알고리즘 - 함수): 액셀:속도가 증가한다.,브레이크: 속도가 감소한다, 기어변경: 기어를 바꾼다.

struct SCar
{
	string strColor;
	int nSpeed = 0;
	enum E_GEAR
	{
		P, R, N, D
	};
	E_GEAR eGear;
};

void CarIinit(SCar& car, string color)
{
	car.eGear = SCar::E_GEAR::N;
	car.nSpeed = 0;
	car.strColor = color;
}

void CarAccel(SCar& car)
{
	car.nSpeed++;
}

void CarBreak(SCar& car)
{
	car.nSpeed--;
}

void CarSetGear(SCar& car, SCar::E_GEAR gear)
{
	car.eGear = gear;
}

void CarDeshBoard(SCar& car)
{
	cout << "Color:" << car.strColor << endl;
	cout << "Gear:"<< car.eGear << endl;
	cout << "Speed:" << car.nSpeed << endl;
}
//클래스: 구조체에 정보와 함수의 정보를 묶어서 나타내어 사용하기가 편리하다.(캡슐화)
class CCar
{	
public:
	//멤버함수는 모두 접근가능하게만든다.
	enum E_GEAR
	{
		P, R, N, D
	};
	////생성자: 객체(변수)가 생성될때 호출 되는 함수. 
	////생성자도 함수이므로 매개변수의 갯수나 타입이 다르면 오버로딩 가능하다.
	//CCar()//기본생성자: 기본멤버들을 기본값으로 초기화하는 생성자.
	//{
	//	eGear = E_GEAR::N;
	//	nSpeed = 0;
	//	strColor = "none";
	//	cout << "DefaultCar(" << eGear << "," << nSpeed << "," << strColor <<")" << endl;
	//}
	//CCar(string color)//매개변수를 통해 객체 내부의 값을 생성시 변경 가능한 생성자.
	//{
	//	eGear = E_GEAR::N;
	//	nSpeed = 0;
	//	strColor = color;
	//	cout << "PrameterCar(" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	//}
	CCar(string color = "gray")//디폴트매개변수를 활용하여 생성자 1개로 기본생성자도 대처함.
	{
		eGear = E_GEAR::N;
		nSpeed = 0;
		strColor = color;
		nCount++;
		cout << "DefaultPrameterCar["<<this<<"](" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	}
	//소멸자: 객체(변수)가 소멸될때 호출되는 함수.
	~CCar()
	{
		nCount--;
		cout << "~Car[" << this << "](" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	}
	//복사생성자: 객체에서 복사가 될때 호출되는 함수 -> 매개변수와 객체: 객체 생성자가 불리지않았는데 소멸자가 호출됨.
	CCar(CCar& car)
	{
		*this = car;
		nCount++;
		cout << "CopyCar[" << this << "](" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	}
	//멤버함수
	void Init(string color)
	{
		eGear = E_GEAR::N;
		nSpeed = 0;
		strColor = color;
	}
	void Accel()
	{
		if(eGear == D)
			nSpeed++;
	}
	void Break()
	{
		if (eGear == D)
			nSpeed--;
	}
	void SetGear(E_GEAR gear)
	{
		eGear = gear;
	}
	void SetColor(string color)
	{
		strColor = color;
	}
	void DeshBoard()
	{
		cout << "Color:" << strColor << endl;
		cout << "Gear:" << eGear << endl;
		cout << "Speed:" << nSpeed << endl;
	}
private:
	//멤버변수: 접근불가능하도록 만든다.
	string strColor;
	int nSpeed;
	E_GEAR eGear;//정의가 없으면 활용할수없으므로 멤버를 정의보다 아래로 내린다.
	
	static int nCount; //정적멤버변수: 모든 객체가 공유하는 멤버 - 자동차의 생산 대 수
public:
	static int GetCount()  //정적멤버함수: 객체 생성전에 접근 가능한 함수.
	{ 
		//nSpeed = 0; //일반멤버변수는 객체가 생성되지않았을수있으므로, 정적멤버함수에서는 호출이 불가능하다.
		return nCount; 
	}
};

void SwapCarVar(CCar a, CCar b)
{
	cout << "SwapCarVar("<<&a<<","<< &b <<")" << endl;
	CCar temp = b;
	b = a;
	a = temp;
}

void SwapCarRef(CCar& a, CCar& b)
{
	cout << "SwapCarRef(" << &a << "," << &b << ")" << endl;
	CCar temp = b;
	b = a;
	a = temp;
}

void SwapCarPtr(CCar* a, CCar* b)
{
	cout << "SwapCarPtr(" << a << "," << b << ")" << endl;
	CCar temp = *b;
	*b = *a;
	*a = temp;
}

void CarSwapTestMain()
{
	cout << "CarSwapTestMain Start()" << endl;
	CCar cCarA("red");
	CCar cCarB("blue");
	cCarA.DeshBoard();
	cCarB.DeshBoard();
	cout << "SwapCarVar" << endl;
	SwapCarVar(cCarA, cCarB);
	cCarA.DeshBoard();
	cCarB.DeshBoard();
	cout << "SwapCarRef" << endl;
	SwapCarRef(cCarA, cCarB);
	cCarA.DeshBoard();
	cCarB.DeshBoard();
	cout << "SwapCarPtr" << endl;
	SwapCarPtr(&cCarA, &cCarB);
	cCarA.DeshBoard();
	cCarB.DeshBoard();
	cout << "CarSwapTestMain End()" << endl;
}

void StaticLocalCar()
{
	cout << "StaticLocalCar Start()" << endl;
	static CCar cStaticCar("green");
	cout << "StaticLocalCar End()" << endl;
}

void StaticCarTestMain()
{
	for (int i = 0; i < 3; i++)
		StaticLocalCar();
}

void DynamicAllocateMain()
{
	cout << "DynamicAllocateMain 1()" << endl;
	CCar* pCar = NULL;
	//c++에서는 객체와 인스턴스를 구별 할 수 없음.(참고: 다른객체지향언어에서는 클래스는 반드시 참조된다. 참조하는 대상을 객체, 참조되는 메모리를 인스턴스라 부름.)
	//cout << "DynamicAllocateMain 2("<< pCar->GetCount() <<")" << endl; //다음과 같은 문법은 사용은 가능하나 위험성이 있다. (객체가 생성 전에 호출됨)
	cout << "DynamicAllocateMain 2(" << CCar::GetCount() << ")" << endl; //객체가 생성전에는 클래스밖에 알수없으므로, 클래스를 통해 접근해야한다.
	//다른객체지향언어의 개념에서 보면 포인터는 객체 (추적하는 독수리의 타겟팅 대상), 동적할당된 메모리는 인스턴스(독수리가 추적하는 플레이어).
	pCar = new CCar();
	delete pCar;
	cout << "DynamicAllocateMain 3(" << CCar::GetCount() << ")" << endl;
	pCar = new CCar[3];
	delete[] pCar;
	cout << "DynamicAllocateMain 4(" << CCar::GetCount() << ")" << endl;
}

CCar g_cCar;
int CCar::nCount = 0; //정적지역변수는 전역변수의 특성을 응용하여, 객체가 모두 같은 변수를 가지도록한다.

void ClassCarMain()
{
	cout << "ClassCarMain Start()" << endl;
	//디폴트매개변수의 경우 시나리오
	CCar cCar; //자동차의 칠없이 생산후
	cCar.Init("red"); //색상을 지정된 색상으로 변경한다.
	//자동차의 기어를 바꿔서 자동차에 기어를 조절함.
	cCar.SetGear(CCar::E_GEAR::D);//스틱을 조절하여 기어를 변경함.
	//cCar.strColor = "pink";//누군가 내차에와서 페인트칠을 했다 -> 위법(은닉: 의도치않은 동작을 막겠다)
	cCar.SetColor("blue"); //내 허락을 받아 자동차의 색상을 바꿈. -> 합법
	cCar.DeshBoard();
	cCar.Accel();
	cCar.DeshBoard();
	cCar.Break();
	cCar.DeshBoard();

	//생성자 호출시 매개변수를 설정하여 값을 변하는 시니리오.
	CCar cCarA("blue");//자동차를 주문할때 색상을 지정함.
	cCarA.SetGear(CCar::E_GEAR::D);
	cCarA.SetColor("blue"); 
	cCarA.DeshBoard();
	cCarA.Accel();
	cCarA.DeshBoard();
	cCarA.Break();
	cCarA.DeshBoard();
	cout << "ClassCarMain End()" << endl;
}
//※자동차가 생성되는 시나리오로 글로 정리한것이다.
//  클래스를 활용가능하면 해보고, 안되면 기초문법 멤버함수/변수, private/public의 문법적인 내용만 이해한다.
//1.구매한 자동차의 색상을 지정하고 공장에서 주문한다. -> 입력 변수(텍스트) -> 문자열 -> 문자열에 색상을 입력받는다.
//2.1에서 정한 색상으로 공장에서 자동차를 제조한다. -> 색상 문자열을 자동차 객체를 생성할때 설정한다. (생성자)
//3.3에서 생산된 자동차를 인수 받는다. -> ? 이 시나리오를 코드로 작성하려면 운전자가 필요하다.
//4.자동차는 기어를 D에 넣어야 엑셀을 밟으면 속도가 증가한다. -> 기어설정을 N으로 변경한다 . 엑셀을 함수를 호출한다.
//5.자동차는 엑셀을 밟으면 속도가 증가한다. -> 엑셀을 함수를 호출한다. (속도가 증가한다)
//6.자동차의 브레이크를 밟으면 속도가 감소한다. -> 브레이크 함수를 호출한다. (속도가 감소한다)
//7.속도가 0이 되면 자동차는 멈춘다. -> 차가 멈출때까지 브레이크를 밟는다. -> 속도가 0이될때까지 브레이크 함수를 출력한다.
//8.자동차의 조작을 입력을 받아 선택하도록 한다. -> 컴퓨터에게 어떤 명령을 할지 지정할수있도록한다  -> 방탈출게임 참조
//9.자동차의 기어를 P에 위치에 넣고 주행을 마친다. -> 기어를 p에 넣으면 운전이 종료된다.
void ClassCarScenarioTestMain()
{
	
}

void StructCarMain()
{
	SCar cCar;
	//기어의 스틱을 이용하지않고, 자동차 내부에 기어를 뜯어서 변경함.
	CarIinit(cCar, "red");
	cCar.strColor = "pink";//누군가 내차에와서 페인트칠을 했다 -> 위법이나 가능함.
	CarDeshBoard(cCar);
	CarAccel(cCar);
	CarDeshBoard(cCar);
	CarBreak(cCar);
	CarDeshBoard(cCar);
}

void main()
{
	cout << "main Start()" << endl;
	//StructCarMain(); //구조체 자동차 구현
	//ClassCarMain(); //클래스 자동차 구현
	//CarSwapTestMain(); //자동차클래스 스왑하기
	//StaticCarTestMain(); //정적지역변수 객체의 생성 및 소멸
	DynamicAllocateMain(); //동적할당한 객체의 생성 및 소멸
	cout << "main End()" << endl;
}
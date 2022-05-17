#include <iostream>

using namespace std;

//자동차 추상화하기
//상태(데이터 - 변수): 색상,속도,기어
//동작(알고리즘 - 함수): 액셀:속도가 증가한다.,브레이크: 속도가 감소한다, 기어변경: 기어를 바꾼다.

struct SCar
{
	string strColor;
	int nSpeed;
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
	enum E_GEAR
	{
		P, R, N, D
	};
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
	//멤버변수
	string strColor;
	int nSpeed;
	E_GEAR eGear;//정의가 없으면 활용할수없으므로 멤버를 정의보다 아래로 내린다.
};

void ClassCarMain()
{
	CCar cCar;
	cCar.Init("red");
	//자동차의 기어를 바꿔서 자동차에 기어를 조절함.
	cCar.SetGear(CCar::E_GEAR::D);//스틱을 조절하여 기어를 변경함.
	//cCar.strColor = "pink";//누군가 내차에와서 페인트칠을 했다 -> 위법(은닉: 의도치않은 동작을 막겠다)
	cCar.SetColor("blue"); //내 허락을 받아 자동차의 색상을 바꿈. -> 합법
	cCar.DeshBoard();
	cCar.Accel();
	cCar.DeshBoard();
	cCar.Break();
	cCar.DeshBoard();
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
	StructCarMain();
}
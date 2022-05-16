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

void CarIinit(SCar car, string color)
{
	car.eGear = SCar::E_GEAR::N;
	car.nSpeed++;
	car.strColor = color;
}

void CarAccel(SCar car)
{
	car.nSpeed++;
}

void CarBreak(SCar car)
{
	car.nSpeed--;
}

void CarSetGear(SCar car, SCar::E_GEAR gear)
{
	car.eGear = gear;
}

void CarDeshBoard(SCar car)
{
	cout << "Color:" << car.strColor << endl;
	cout << "Gear:"<< car.eGear << endl;
	cout << "Speed:" << car.nSpeed << endl;
}

void StructCarMain()
{
	SCar cCar;

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
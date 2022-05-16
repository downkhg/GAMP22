#include <iostream>

using namespace std;

//�ڵ��� �߻�ȭ�ϱ�
//����(������ - ����): ����,�ӵ�,���
//����(�˰��� - �Լ�): �׼�:�ӵ��� �����Ѵ�.,�극��ũ: �ӵ��� �����Ѵ�, ����: �� �ٲ۴�.

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
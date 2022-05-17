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
//Ŭ����: ����ü�� ������ �Լ��� ������ ��� ��Ÿ���� ����ϱⰡ ���ϴ�.(ĸ��ȭ)
class CCar
{	
public:
	//����Լ��� ��� ���ٰ����ϰԸ����.
	enum E_GEAR
	{
		P, R, N, D
	};
	//������: ��ü(����)�� �����ɶ� ȣ�� �Ǵ� �Լ�. 
	//�����ڵ� �Լ��̹Ƿ� �Ű������� ������ Ÿ���� �ٸ��� �����ε� �����ϴ�.
	CCar()//�⺻������: �⺻������� �⺻������ �ʱ�ȭ�ϴ� ������.
	{
		eGear = E_GEAR::N;
		nSpeed = 0;
		strColor = "none";
		cout << "DefaultCar(" << eGear << "," << nSpeed << "," << strColor <<")" << endl;
	}
	CCar(string color)//�Ű������� ���� ��ü ������ ���� ������ ���� ������ ������.
	{
		eGear = E_GEAR::N;
		nSpeed = 0;
		strColor = color;
		cout << "PrameterCar(" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	}
	//CCar(string color = "gray")//����Ʈ�Ű������� Ȱ���Ͽ� ������ 1���� �⺻�����ڵ� ��ó��.
	//{
	//	eGear = E_GEAR::N;
	//	nSpeed = 0;
	//	strColor = color;
	//	cout << "DefaultPrameterCar(" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	//}
	//����Լ�
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
	//�������: ���ٺҰ����ϵ��� �����.
	string strColor;
	int nSpeed;
	E_GEAR eGear;//���ǰ� ������ Ȱ���Ҽ������Ƿ� ����� ���Ǻ��� �Ʒ��� ������.
};

void ClassCarMain()
{
	//����Ʈ�Ű������� ��� �ó�����
	CCar cCar; //�ڵ����� ĥ���� ������
	cCar.Init("red"); //������ ������ �������� �����Ѵ�.
	//�ڵ����� �� �ٲ㼭 �ڵ����� �� ������.
	cCar.SetGear(CCar::E_GEAR::D);//��ƽ�� �����Ͽ� �� ������.
	//cCar.strColor = "pink";//������ �������ͼ� ����Ʈĥ�� �ߴ� -> ����(����: �ǵ�ġ���� ������ ���ڴ�)
	cCar.SetColor("blue"); //�� ����� �޾� �ڵ����� ������ �ٲ�. -> �չ�
	cCar.DeshBoard();
	cCar.Accel();
	cCar.DeshBoard();
	cCar.Break();
	cCar.DeshBoard();

	//������ ȣ��� �Ű������� �����Ͽ� ���� ���ϴ� �ôϸ���.
	CCar cCarA("blue");//�ڵ����� �ֹ��Ҷ� ������ ������.
	cCarA.SetGear(CCar::E_GEAR::D);
	cCarA.SetColor("blue"); 
	cCarA.DeshBoard();
	cCarA.Accel();
	cCarA.DeshBoard();
	cCarA.Break();
	cCarA.DeshBoard();
}

void StructCarMain()
{
	SCar cCar;
	//����� ��ƽ�� �̿������ʰ�, �ڵ��� ���ο� �� �� ������.
	CarIinit(cCar, "red");
	cCar.strColor = "pink";//������ �������ͼ� ����Ʈĥ�� �ߴ� -> �����̳� ������.
	CarDeshBoard(cCar);
	CarAccel(cCar);
	CarDeshBoard(cCar);
	CarBreak(cCar);
	CarDeshBoard(cCar);
}

void main()
{
	//StructCarMain();
	ClassCarMain();
}
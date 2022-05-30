#include <iostream>

using namespace std;

//�ڵ��� �߻�ȭ�ϱ�
//����(������ - ����): ����,�ӵ�,���
//����(�˰��� - �Լ�): �׼�:�ӵ��� �����Ѵ�.,�극��ũ: �ӵ��� �����Ѵ�, ����: �� �ٲ۴�.

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
//Ŭ����: ����ü�� ������ �Լ��� ������ ��� ��Ÿ���� ����ϱⰡ ���ϴ�.(ĸ��ȭ)
class CCar
{	
public:
	//����Լ��� ��� ���ٰ����ϰԸ����.
	enum E_GEAR
	{
		P, R, N, D
	};
	////������: ��ü(����)�� �����ɶ� ȣ�� �Ǵ� �Լ�. 
	////�����ڵ� �Լ��̹Ƿ� �Ű������� ������ Ÿ���� �ٸ��� �����ε� �����ϴ�.
	//CCar()//�⺻������: �⺻������� �⺻������ �ʱ�ȭ�ϴ� ������.
	//{
	//	eGear = E_GEAR::N;
	//	nSpeed = 0;
	//	strColor = "none";
	//	cout << "DefaultCar(" << eGear << "," << nSpeed << "," << strColor <<")" << endl;
	//}
	//CCar(string color)//�Ű������� ���� ��ü ������ ���� ������ ���� ������ ������.
	//{
	//	eGear = E_GEAR::N;
	//	nSpeed = 0;
	//	strColor = color;
	//	cout << "PrameterCar(" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	//}
	CCar(string color = "gray")//����Ʈ�Ű������� Ȱ���Ͽ� ������ 1���� �⺻�����ڵ� ��ó��.
	{
		eGear = E_GEAR::N;
		nSpeed = 0;
		strColor = color;
		nCount++;
		cout << "DefaultPrameterCar["<<this<<"](" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	}
	//�Ҹ���: ��ü(����)�� �Ҹ�ɶ� ȣ��Ǵ� �Լ�.
	~CCar()
	{
		nCount--;
		cout << "~Car[" << this << "](" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	}
	//���������: ��ü���� ���簡 �ɶ� ȣ��Ǵ� �Լ� -> �Ű������� ��ü: ��ü �����ڰ� �Ҹ����ʾҴµ� �Ҹ��ڰ� ȣ���.
	CCar(CCar& car)
	{
		*this = car;
		nCount++;
		cout << "CopyCar[" << this << "](" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	}
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
	
	static int nCount; //�����������: ��� ��ü�� �����ϴ� ��� - �ڵ����� ���� �� ��
public:
	static int GetCount()  //��������Լ�: ��ü �������� ���� ������ �Լ�.
	{ 
		//nSpeed = 0; //�Ϲݸ�������� ��ü�� ���������ʾ����������Ƿ�, ��������Լ������� ȣ���� �Ұ����ϴ�.
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
	//c++������ ��ü�� �ν��Ͻ��� ���� �� �� ����.(����: �ٸ���ü��������� Ŭ������ �ݵ�� �����ȴ�. �����ϴ� ����� ��ü, �����Ǵ� �޸𸮸� �ν��Ͻ��� �θ�.)
	//cout << "DynamicAllocateMain 2("<< pCar->GetCount() <<")" << endl; //������ ���� ������ ����� �����ϳ� ���輺�� �ִ�. (��ü�� ���� ���� ȣ���)
	cout << "DynamicAllocateMain 2(" << CCar::GetCount() << ")" << endl; //��ü�� ���������� Ŭ�����ۿ� �˼������Ƿ�, Ŭ������ ���� �����ؾ��Ѵ�.
	//�ٸ���ü�������� ���信�� ���� �����ʹ� ��ü (�����ϴ� �������� Ÿ���� ���), �����Ҵ�� �޸𸮴� �ν��Ͻ�(�������� �����ϴ� �÷��̾�).
	pCar = new CCar();
	delete pCar;
	cout << "DynamicAllocateMain 3(" << CCar::GetCount() << ")" << endl;
	pCar = new CCar[3];
	delete[] pCar;
	cout << "DynamicAllocateMain 4(" << CCar::GetCount() << ")" << endl;
}

CCar g_cCar;
int CCar::nCount = 0; //�������������� ���������� Ư���� �����Ͽ�, ��ü�� ��� ���� ������ ���������Ѵ�.

void ClassCarMain()
{
	cout << "ClassCarMain Start()" << endl;
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
	cout << "ClassCarMain End()" << endl;
}
//���ڵ����� �����Ǵ� �ó������� �۷� �����Ѱ��̴�.
//  Ŭ������ Ȱ�밡���ϸ� �غ���, �ȵǸ� ���ʹ��� ����Լ�/����, private/public�� �������� ���븸 �����Ѵ�.
//1.������ �ڵ����� ������ �����ϰ� ���忡�� �ֹ��Ѵ�. -> �Է� ����(�ؽ�Ʈ) -> ���ڿ� -> ���ڿ��� ������ �Է¹޴´�.
//2.1���� ���� �������� ���忡�� �ڵ����� �����Ѵ�. -> ���� ���ڿ��� �ڵ��� ��ü�� �����Ҷ� �����Ѵ�. (������)
//3.3���� ����� �ڵ����� �μ� �޴´�. -> ? �� �ó������� �ڵ�� �ۼ��Ϸ��� �����ڰ� �ʿ��ϴ�.
//4.�ڵ����� �� D�� �־�� ������ ������ �ӵ��� �����Ѵ�. -> ������ N���� �����Ѵ� . ������ �Լ��� ȣ���Ѵ�.
//5.�ڵ����� ������ ������ �ӵ��� �����Ѵ�. -> ������ �Լ��� ȣ���Ѵ�. (�ӵ��� �����Ѵ�)
//6.�ڵ����� �극��ũ�� ������ �ӵ��� �����Ѵ�. -> �극��ũ �Լ��� ȣ���Ѵ�. (�ӵ��� �����Ѵ�)
//7.�ӵ��� 0�� �Ǹ� �ڵ����� �����. -> ���� ���⶧���� �극��ũ�� ��´�. -> �ӵ��� 0�̵ɶ����� �극��ũ �Լ��� ����Ѵ�.
//8.�ڵ����� ������ �Է��� �޾� �����ϵ��� �Ѵ�. -> ��ǻ�Ϳ��� � ����� ���� �����Ҽ��ֵ����Ѵ�  -> ��Ż����� ����
//9.�ڵ����� �� P�� ��ġ�� �ְ� ������ ��ģ��. -> �� p�� ������ ������ ����ȴ�.
void ClassCarScenarioTestMain()
{
	
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
	cout << "main Start()" << endl;
	//StructCarMain(); //����ü �ڵ��� ����
	//ClassCarMain(); //Ŭ���� �ڵ��� ����
	//CarSwapTestMain(); //�ڵ���Ŭ���� �����ϱ�
	//StaticCarTestMain(); //������������ ��ü�� ���� �� �Ҹ�
	DynamicAllocateMain(); //�����Ҵ��� ��ü�� ���� �� �Ҹ�
	cout << "main End()" << endl;
}
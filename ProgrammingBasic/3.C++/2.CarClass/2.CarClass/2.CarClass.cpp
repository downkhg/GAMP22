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
	//멤버함수는 모두 접근가능하게만든다.
	enum E_GEAR
	{
		P, R, N, D
	};
	//생성자: 객체(변수)가 생성될때 호출 되는 함수. 
	//생성자도 함수이므로 매개변수의 갯수나 타입이 다르면 오버로딩 가능하다.
	CCar()//기본생성자: 기본멤버들을 기본값으로 초기화하는 생성자.
	{
		eGear = E_GEAR::N;
		nSpeed = 0;
		strColor = "none";
		cout << "DefaultCar(" << eGear << "," << nSpeed << "," << strColor <<")" << endl;
	}
	CCar(string color)//매개변수를 통해 객체 내부의 값을 생성시 변경 가능한 생성자.
	{
		eGear = E_GEAR::N;
		nSpeed = 0;
		strColor = color;
		cout << "PrameterCar(" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	}
	//CCar(string color = "gray")//디폴트매개변수를 활용하여 생성자 1개로 기본생성자도 대처함.
	//{
	//	eGear = E_GEAR::N;
	//	nSpeed = 0;
	//	strColor = color;
	//	cout << "DefaultPrameterCar(" << eGear << "," << nSpeed << "," << strColor << ")" << endl;
	//}
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
};

void ClassCarMain()
{
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
	//StructCarMain();
	ClassCarMain();
}
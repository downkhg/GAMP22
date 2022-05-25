#include <iostream>

using namespace std;

class Vector
{
	float x;
	float y;
public:
	Vector(float x = 0, float y = 0)
	{
		this->x = x;
		this->y = y;
	}
	//연산자오버로딩: 멤버함수의 일종. 특정 연산자가 호출될때 호출되는 함수.
	//연산의 결과가 될 타입(리턴값) 오퍼레이터연산자(함수명) 매개변수(오른쪽계산하는 타입)
	Vector operator+(Vector v)
	{
		return Vector(x + v.x, y + v.y);
	}
	Vector operator-(Vector v)
	{
		return Vector(x - v.x, y-v.y);
	}
	Vector operator*(float d)
	{
		return Vector(x*d,y*d);
	}
	//friend: 외부에 함수나 클래스가 자신의 priavte멤버를 사용하도록 하는 문법
	//외부연산자(정식명침아님): 기본타입과같이 클래스내부에서 연산할수없는 연산자를 오버로딩할때 사용함.
	friend Vector operator*(float d, Vector v)//기본타입과 결합법칙성립시 - 사용하지않아도됨.(실제 유니티라이브러리도 결합법칙이 성립하지않음)
	{
		return Vector(d * v.x, d * v.y);
	}
	friend ostream& operator<<(ostream& os, Vector v)//입력받은 값을 리턴값으로 계속전달해야하므로 외부연산자를 이용해야함.
	{
		return os << "(" << v.x << "," << v.y << ")";
	}
	bool operator==(Vector v)
	{
		return (v.x == this->x && v.y == this->y);
	}
	float operator[](int idx)
	{
		if (idx == 0)
			return x;
		else
			return y;
	}
	float Distance()
	{
		return sqrt(x * x + y * y);
	}
	Vector Normalize()
	{
		float fDist = Distance();
		return Vector(x / fDist, y / fDist);
	}
	void Display(const char* msg = "")
	{
		cout << msg << "(" << x << "," << y << ")" << endl;
	}
	
};

void main()
{
	Vector vPos;
	Vector vEndPos(100,0);

	//cout <<"vPos("<< vPos[0] << "," << vPos[1]  <<")"<< endl;
	//cout << "vEndPos(" << vEndPos[0] << "," << vEndPos[1] << ")" << endl;
	vPos.Display("vPos");
	vPos.Display("vEndPos");

	Vector vDist = vEndPos - vPos;
	Vector vMovePos = vPos + vDist;
	float fDist = vDist.Distance();
	Vector vDistDir = vDist.Normalize();
	Vector vDistAndDir = fDist * vDistDir; //기본타입*클래스
	//Vector vDistAndDir = vDistDir * fDist; //클래스*기본타입

	vMovePos.Display("vMovePos");
	vDist.Display("vDist");
	vDistDir.Display("vDistDir");
	vDistAndDir.Display("vDistAndDir");

	if (vEndPos == vMovePos)
	{
		cout << vEndPos << "==" << vMovePos << endl;
	}
	else
		cout << vEndPos << "!=" << vMovePos << endl;

	if (vDist == vDistAndDir)
	{
		cout << vEndPos << "==" << vMovePos << endl;
	}
	else
		cout << vEndPos << "!=" << vMovePos << endl;
}
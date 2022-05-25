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
	//�����ڿ����ε�: ����Լ��� ����. Ư�� �����ڰ� ȣ��ɶ� ȣ��Ǵ� �Լ�.
	//������ ����� �� Ÿ��(���ϰ�) ���۷����Ϳ�����(�Լ���) �Ű�����(�����ʰ���ϴ� Ÿ��)
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
	//friend: �ܺο� �Լ��� Ŭ������ �ڽ��� priavte����� ����ϵ��� �ϴ� ����
	//�ܺο�����(���ĸ�ħ�ƴ�): �⺻Ÿ�԰����� Ŭ�������ο��� �����Ҽ����� �����ڸ� �����ε��Ҷ� �����.
	friend Vector operator*(float d, Vector v)//�⺻Ÿ�԰� ���չ�Ģ������ - ��������ʾƵ���.(���� ����Ƽ���̺귯���� ���չ�Ģ�� ������������)
	{
		return Vector(d * v.x, d * v.y);
	}
	friend ostream& operator<<(ostream& os, Vector v)//�Է¹��� ���� ���ϰ����� ��������ؾ��ϹǷ� �ܺο����ڸ� �̿��ؾ���.
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
	Vector vDistAndDir = fDist * vDistDir; //�⺻Ÿ��*Ŭ����
	//Vector vDistAndDir = vDistDir * fDist; //Ŭ����*�⺻Ÿ��

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
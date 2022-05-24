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
	bool operator==(Vector v)
	{
		return (v.x == this->x && v.y == this->y);
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

	Vector vDist = vEndPos - vPos;
	Vector vMovePos = vPos + vDist;
	float fDist = vDist.Distance();
	Vector vDistDir = vDist.Normalize();
	Vector vDistAndDir = vDistDir * fDist;

	if (vEndPos == vMovePos)
	{
		cout << "vEndPos == vMovePos" << endl;
	}
	else
		cout << "vEndPos != vMovePos" << endl;

	if (vDist == vDistAndDir)
	{
		cout << "vDist == vDistAndDir" << endl;
	}
	else
		cout << "vDist != vDistAndDir" << endl;
}
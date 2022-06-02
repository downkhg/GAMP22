#include <iostream>
#include <list>

using namespace std;
//도형과 같이 공통적인 특징이 속성이 없고 동작만 존재하는 클래스를 굳이 상속관계로 만들필요가 없다.
namespace Inheritance
{
	//1차원이라면 객체로 볼수없다.
	struct Vector//객체: 벡터(2차원 위치)
	{
		//public:
		float x;
		float y;
		Vector(int x = 0, int y = 0) { this->x = x; this->y = y; }
		void Print(const char* msg)
		{
			cout << msg << "(" << x << "," << y << ")" << endl;
		}
	};

	class Shape //도형:
	{
	public:
		Shape()
		{
			cout << "Shape[" << this << "]" << endl;
		}
		~Shape()
		{
			cout << "~Shape[" << this << "]" << endl;
		}
		void Draw()
		{
			cout << "Shape[" << this << "]::Draw()" << endl;
		};
	};
	//원과 같이 삼각형,사각형을 클래스로 만들기
	class Circle : public Shape
	{
		Vector vPos;
		float fRadius;
	public:
		Circle(Vector pos, float rad)
		{
			cout << "Circle[" << this << "]" << endl;
			vPos = pos;
			fRadius = rad;

			cout << "Rad:" << fRadius << endl;
		}
		~Circle()
		{
			cout << "~Circle[" << this << "]()" << endl;
		}
		void Draw()
		{
			cout << "Circle[" << this << "]::Draw()" << endl;
			vPos.Print("Pos");
			cout << "Rad:" << fRadius << endl;
		}
	};
	class TriAngle : public Shape
	{
		Vector vA;
		Vector vB;
		Vector vC;
	public:
		TriAngle(Vector a, Vector b, Vector c) { cout << "TriAngle[" << this << "]" << endl; };
		~TriAngle() { cout << "TriAngle[" << this << "]" << endl; };
		void Draw()
		{
			cout << "RectAangle[" << this << "]::Draw()" << endl;
			vA.Print("A:");
			vB.Print("B:");
			vC.Print("C:");
		}
	};
	class RectAangle : public Shape
	{
		Vector vTL;
		Vector vBR;
	public:
		RectAangle(Vector tl, Vector br)
		{
			cout << "RectAangle[" << this << "]" << endl;
			vTL = tl;
			vBR = br;
		}
		~RectAangle()
		{
			cout << "~RectAangle[" << this << "]()" << endl;
		}
		void Draw()
		{
			cout << "RectAangle[" << this << "]::Draw()" << endl;
			vTL.Print("TopLeft:");
			vBR.Print("BottomRight:");
		}
	};

	//부모의 부분과 자식의 부분은 메모리가 다르다. 
	//결국 상속을 통해서 두개의 같은이름의 함수를 가진다.
	void ShapeMain()
	{
		Shape cShape;
		Circle cCrilce({ 1,1 }, 1);
		cShape.Draw();
		cShape.Shape::Draw();
		cCrilce.Draw();
		cCrilce.Shape::Draw();
	}
	//프로그램 실행중에 선택하여 모양을 여러개를 그리려면 어떻게해야하는가?//동적으로 메모리를 할당받아야한다.
	void PowerPointMain()
	{
		list<Shape*> listShapes;

		listShapes.push_back(new Circle(Vector(1,1), 1));
		listShapes.push_back(new RectAangle(Vector(1, 1), Vector(2,2)));
		listShapes.push_back(new TriAngle(Vector(0, 0), Vector(0, 1), Vector(1, 1)));

		list<Shape*>::iterator it;
		for (it = listShapes.begin(); it != listShapes.end(); it++)
		{
			Shape* pShape = *it;
			pShape->Draw();
		}

		it = listShapes.begin();
		//자식부분에 맴버에 접근하러면 캐스팅을 해야한다. 
		//이럴거라면 한꺼번에 관리하기위해 리스트가 사용될 이유가 없다.
		((Circle*)*it)->Draw(); it++;
		((RectAangle*)*it)->Draw(); it++;
		((TriAngle*)*it)->Draw(); it++;

		//while (it != listShapes.end())
		//{
		//	(*it)->Draw();
		//	it++;
		//}

		for (it = listShapes.begin(); it != listShapes.end(); it++)
			delete* it;
	}
}

namespace Virtual
{
	//1차원이라면 객체로 볼수없다.
	struct Vector//객체: 벡터(2차원 위치)
	{
		//public:
		float x;
		float y;
		Vector(int x = 0, int y = 0) { this->x = x; this->y = y; }
		void Print(const char* msg)
		{
			cout << msg << "(" << x << "," << y << ")" << endl;
		}
	};

	class Shape //도형:
	{
	public:
		Shape()
		{
			cout << "Shape[" << this << "]:" << sizeof(*this) << endl;
		}
		~Shape()
		{
			cout << "~Shape[" << this << "]" << endl;
		}
		void Draw()
		{
			cout << "Shape[" << this << "]::Draw()" << endl;
		};
	};
	//원과 같이 삼각형,사각형을 클래스로 만들기
	class Circle : public Shape
	{
		Vector vPos;
		float fRadius;
	public:
		Circle(Vector pos, float rad)
		{
			cout << "Circle[" << this << "]:" << sizeof(*this) << endl;
			vPos = pos;
			fRadius = rad;

			cout << "Rad:" << fRadius << endl;
		}
		~Circle()
		{
			cout << "~Circle[" << this << "]()" << endl;
		}
		void Draw()
		{
			cout << "Circle[" << this << "]::Draw()" << endl;
			vPos.Print("Pos");
			cout << "Rad:" << fRadius << endl;
		}
	};
	class TriAngle : public Shape
	{
		Vector vA;
		Vector vB;
		Vector vC;
	public:
		TriAngle(Vector a, Vector b, Vector c) { cout << "TriAngle[" << this << "]" << endl; };
		~TriAngle() { cout << "TriAngle[" << this << "]:" << sizeof(*this) << endl; };
		void Draw()
		{
			cout << "RectAangle[" << this << "]::Draw()" << endl;
			vA.Print("A:");
			vB.Print("B:");
			vC.Print("C:");
		}
	};
	class RectAangle : public Shape
	{
		Vector vTL;
		Vector vBR;
	public:
		RectAangle(Vector tl, Vector br)
		{
			cout << "RectAangle[" << this << "]:" << sizeof(*this) << endl;
			vTL = tl;
			vBR = br;
		}
		~RectAangle()
		{
			cout << "~RectAangle[" << this << "]()" << endl;
		}
		void Draw()
		{
			cout << "RectAangle[" << this << "]::Draw()" << endl;
			vTL.Print("TopLeft:");
			vBR.Print("BottomRight:");
		}
	};

	//부모의 부분과 자식의 부분은 메모리가 다르다. 
	//결국 상속을 통해서 두개의 같은이름의 함수를 가진다.
	void ShapeMain()
	{
		Shape cShape;
		Circle cCrilce({ 1,1 }, 1);
		cShape.Draw();
		cShape.Shape::Draw();
		cCrilce.Draw();
		cCrilce.Shape::Draw();
	}
	//프로그램 실행중에 선택하여 모양을 여러개를 그리려면 어떻게해야하는가?//동적으로 메모리를 할당받아야한다.
	void PowerPointMain()
	{
		list<Shape*> listShapes;

		listShapes.push_back(new Circle(Vector(1, 1), 1));
		listShapes.push_back(new RectAangle(Vector(1, 1), Vector(2, 2)));
		listShapes.push_back(new TriAngle(Vector(0, 0), Vector(0, 1), Vector(1, 1)));

		list<Shape*>::iterator it;
		for (it = listShapes.begin(); it != listShapes.end(); it++)
		{
			Shape* pShape = *it;
			pShape->Draw();
		}

		it = listShapes.begin();
		//자식부분에 맴버에 접근하러면 캐스팅을 해야한다. 
		//이럴거라면 한꺼번에 관리하기위해 리스트가 사용될 이유가 없다.
		((Circle*)*it)->Draw(); it++;
		((RectAangle*)*it)->Draw(); it++;
		((TriAngle*)*it)->Draw(); it++;

		//while (it != listShapes.end())
		//{
		//	(*it)->Draw();
		//	it++;
		//}

		for (it = listShapes.begin(); it != listShapes.end(); it++)
			delete* it;
	}
}

void main()
{
	//Inheritance::ShapeMain();
	//Inheritance::PowerPointMain();
	Virtual::PowerPointMain();
}
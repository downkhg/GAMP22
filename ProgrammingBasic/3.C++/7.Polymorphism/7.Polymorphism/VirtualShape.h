#pragma once

#include <iostream>
#include <list>

using namespace std;
//도형과 같이 공통적인 특징이 속성이 없고 동작만 존재하는 클래스를 굳이 상속관계로 만들필요가 없다.

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
		//가상함수테이블(v-ptr): 가상함수의 경우는 객체에 함수의 포인터가 포함된다. 그러므로 이부분에 자식객체의 함수주소가 들어가므로, 자식의 함수를 호출할수있다.
		virtual void Draw()//가상함수: 자식객체서 동일한 이름으로 함수를 오버라이딩가능하다.
		{
			cout << "Shape[" << this << "]::Draw()" << endl;
		};
	};
	//원과 같이 삼각형,사각형을 클래스로 만들기
	class Circle : public Shape
	{
		Vector vPos;//8
		float fRadius;//4
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
		void Draw() override //오버라이딩함수: 부모객체의 가상함수를 구현한 것. //키워드를 반드시 붙여야하는 것은 아니다.
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
		TriAngle(Vector a, Vector b, Vector c) { cout << "TriAngle[" << this << "]:" << sizeof(*this) << endl; };
		~TriAngle() { cout << "~TriAngle[" << this << "]" << endl; };
		void Draw()
		{
			cout << "TriAngle[" << this << "]::Draw()" << endl;
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
		cout << "####### Virtual::PowerPointMain() Start #####" << endl;
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
		cout << "####### Virtual::PowerPointMain() End #####" << endl;
	}
}

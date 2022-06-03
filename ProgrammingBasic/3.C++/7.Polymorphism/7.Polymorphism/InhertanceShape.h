#pragma once
#include <iostream>
#include <list>

using namespace std;

namespace Inheritance
{
	//1�����̶�� ��ü�� ��������.
	struct Vector//��ü: ����(2���� ��ġ)
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

	class Shape //����:
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
	//���� ���� �ﰢ��,�簢���� Ŭ������ �����
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
			cout << "Circle[" << this << "]::Draw(" << &Shape::Draw <<")" << endl;
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
			cout << "RectAangle[" << this << "]::Draw("<< &TriAngle::Draw <<")" << endl;
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
			cout << "RectAangle[" << this << "]::Draw(" << &RectAangle::Draw << ")" << endl;
			vTL.Print("TopLeft:");
			vBR.Print("BottomRight:");
		}
	};

	//�θ��� �κа� �ڽ��� �κ��� �޸𸮰� �ٸ���. 
	//�ᱹ ����� ���ؼ� �ΰ��� �����̸��� �Լ��� ������.
	void ShapeMain()
	{
		Shape cShape;
		Circle cCrilce({ 1,1 }, 1);
		cShape.Draw();
		cShape.Shape::Draw();
		cCrilce.Draw();
		cCrilce.Shape::Draw();
	}
	//���α׷� �����߿� �����Ͽ� ����� �������� �׸����� ����ؾ��ϴ°�?//�������� �޸𸮸� �Ҵ�޾ƾ��Ѵ�.
	void PowerPointMain()
	{
		cout << "####### Inheritance::PowerPointMain() Start #####" << endl;
		list<Shape*> listShapes;

		listShapes.push_back(new Circle(Vector(1, 1), 1));
		listShapes.push_back(new RectAangle(Vector(1, 1), Vector(2, 2)));
		listShapes.push_back(new TriAngle(Vector(0, 0), Vector(0, 1), Vector(1, 1)));

		list<Shape*>::iterator it;
		for (it = listShapes.begin(); it != listShapes.end(); it++)
		{
			Shape* pShape = *it;
			pShape->Draw();//�ش���ġ�� �극��ŷ ����Ʈ�� �ɰ� pShape�� Ȯ���ص� v-ptr�� �������ʴ´�.
		}

		it = listShapes.begin();
		//�ڽĺκп� �ɹ��� �����Ϸ��� ĳ������ �ؾ��Ѵ�. 
		//�̷��Ŷ�� �Ѳ����� �����ϱ����� ����Ʈ�� ���� ������ ����.
		//�θ������Ϳ��� �ڽ��� ��ü�� ������ �Ϸ���, �ڽİ�ü�� ĳ�����ؾ��Ѵ�.
		//�̷��� �ؾߵȴٸ� ���� ����� �޴� ������ ������?
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
		cout << "####### Inheritance::PowerPointMain() End #####" << endl;
	}

	//���α׷� �����߿� �����Ͽ� ����� �������� �׸����� ����ؾ��ϴ°�?//�������� �޸𸮸� �Ҵ�޾ƾ��Ѵ�.
	void PowerPointVoidMain()
	{
		list<void*> listShapes;

		listShapes.push_back(new Circle(Vector(1, 1), 1));
		listShapes.push_back(new RectAangle(Vector(1, 1), Vector(2, 2)));
		listShapes.push_back(new TriAngle(Vector(0, 0), Vector(0, 1), Vector(1, 1)));

		list<void*>::iterator it;
		for (it = listShapes.begin(); it != listShapes.end(); it++)
		{
			Shape* pShape = (Shape*)*it;
			pShape->Draw();
		}

		it = listShapes.begin();
		//�ڽĺκп� �ɹ��� �����Ϸ��� ĳ������ �ؾ��Ѵ�. 
		//�̷��Ŷ�� �Ѳ����� �����ϱ����� ����Ʈ�� ���� ������ ����.
		//�θ������Ϳ��� �ڽ��� ��ü�� ������ �Ϸ���, �ڽİ�ü�� ĳ�����ؾ��Ѵ�.
		//�̷��� �ؾߵȴٸ� ���� ����� �޴� ������ ������?
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

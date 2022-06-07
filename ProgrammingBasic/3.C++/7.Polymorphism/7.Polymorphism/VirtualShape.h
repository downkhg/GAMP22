#pragma once

#include <iostream>
#include <list>

using namespace std;
//������ ���� �������� Ư¡�� �Ӽ��� ���� ���۸� �����ϴ� Ŭ������ ���� ��Ӱ���� �����ʿ䰡 ����.

namespace Virtual
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
	//�������̽�: ��������� ����������, ��� ����� ���������Լ���. �̷��� Ư���� �����Ƿ�, java�� c#������ ���߻���� �Ϸ��� �������̽��� �̿��Ѵ�.
	//�߻�Ŭ����: ���������Լ��� 1���̻� ���� Ŭ����. ��üȭ�� �Ҽ�����.
	//��üȭ: �߻�Ŭ������ ��ӹ޾Ƽ� Ŭ������ ����� ��.
	class Shape //����:
	{
	public:
		Shape()
		{
			cout << "Shape[" << this << "]:" << sizeof(*this) << endl;
		}
		//�Ҹ��ڸ� �θ������ͷ� ȣ���Ϸ��� �����Լ��� �����.
		//�Ҹ���,���������,���Կ����ڴ� �����Ϸ����� �ڵ����� �����ǹǷ�,
		//��������Ҹ��ڶ�� ������ ���������ʴ´�.
		virtual ~Shape()
		{
			cout << "~Shape[" << this << "]" << endl;
		}
		//�����Լ����̺�(v-ptr): �����Լ��� ���� ��ü�� �Լ��� �����Ͱ� ���Եȴ�. �׷��Ƿ� �̺κп� �ڽİ�ü�� �Լ��ּҰ� ���Ƿ�, �ڽ��� �Լ��� ȣ���Ҽ��ִ�.
		//virtual void Draw()//�����Լ�: �ڽİ�ü�� ������ �̸����� �Լ��� �������̵������ϴ�.
		virtual void Draw() = 0//���������Լ�: �ڽİ�ü�� ��ӹ޾Ƽ� ��������� �ݵ�� �������̵��� �Լ��� �־�߸� �ǵ��� �����Ѵ�.
		{
			cout << "Shape[" << this << "]::Draw()" << endl;
		};
	};
	//���� ���� �ﰢ��,�簢���� Ŭ������ �����
	//�߻�Ŭ������ ��ӹ޾Ƽ� �ڽ�Ŭ������ �����߸� ��ä(����)�� ������ִ�.
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
		void Draw() override //�������̵��Լ�: �θ�ü�� �����Լ��� ������ ��. //Ű���带 �ݵ�� �ٿ����ϴ� ���� �ƴϴ�.
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

	//�θ��� �κа� �ڽ��� �κ��� �޸𸮰� �ٸ���. 
	//�ᱹ ����� ���ؼ� �ΰ��� �����̸��� �Լ��� ������.
	void ShapeMain()
	{
		//Shape cShape; //�߻�Ŭ������ ��üȭ �� �� ����.
		Circle cCrilce({ 1,1 }, 1);
		//cShape.Draw();
		//cShape.Shape::Draw();
		cCrilce.Draw();
		cCrilce.Shape::Draw();
	}
	//���α׷� �����߿� �����Ͽ� ����� �������� �׸����� ����ؾ��ϴ°�?//�������� �޸𸮸� �Ҵ�޾ƾ��Ѵ�.
	void PowerPointMain()
	{
		cout << "####### Virtual::PowerPointMain() Start #####" << endl;
		list<Shape*> listShapes;
		cout << "####### Virtual::PowerPointMain() Create Shapes #####" << endl;
		listShapes.push_back(new Circle(Vector(1, 1), 1));
		listShapes.push_back(new RectAangle(Vector(1, 1), Vector(2, 2)));
		listShapes.push_back(new TriAngle(Vector(0, 0), Vector(0, 1), Vector(1, 1)));
		cout << "####### Virtual::PowerPointMain() Draw Shapes List #####" << endl;
		list<Shape*>::iterator it;
		for (it = listShapes.begin(); it != listShapes.end(); it++)
		{
			Shape* pShape = *it;
			pShape->Draw();//�ش���ġ�� �극��ŷ ����Ʈ�� �ɰ� pShape�� Ȯ���ϸ�, v-ptr�� ����� �Լ��� ������ �����ִ�.
		}
		cout << "####### Virtual::PowerPointMain() Draw Shapes  #####" << endl;
		it = listShapes.begin();
		//�ڽĺκп� �ɹ��� �����Ϸ��� ĳ������ �ؾ��Ѵ�. 
		//�̷��Ŷ�� �Ѳ����� �����ϱ����� ����Ʈ�� ���� ������ ����.
		((Circle*)*it)->Draw(); it++;
		((RectAangle*)*it)->Draw(); it++;
		((TriAngle*)*it)->Draw(); it++;

		//while (it != listShapes.end())
		//{
		//	(*it)->Draw();
		//	it++;
		//}
		cout << "####### Virtual::PowerPointMain() Draw Delete  #####" << endl;
		for (it = listShapes.begin(); it != listShapes.end(); it++)
			delete* it;
		cout << "####### Virtual::PowerPointMain() End #####" << endl;
	}
}

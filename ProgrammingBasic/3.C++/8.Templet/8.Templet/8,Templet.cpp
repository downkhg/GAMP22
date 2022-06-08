/*##################################
C++ 템플릿(C++ 수업용)
파일명: 1.4.Templet
작성자 : 김홍규(downkhg@gmail.com)
마지막수정날짜 : 2022.03.29
버전 : 1.5
###################################*/
#include <iostream>
#include <iostream>
#include <stack>

using namespace std;
//일반 클래스
class CData
{
	int nData;
public:
	void SetData(int data) { nData = data; }
	int GetData() { return nData; }
};
//동적할당 포함 클래스
//템플릿으로 정의할때 필요한 호출함수들을 모두다 오버로딩해야한다.
class CBox
{
	int* pData;
	void _initData(int data) { this->pData = new int(); *this->pData = data; }
public:
	CBox(int data = 0) { _initData(data); }
	~CBox() { delete pData; }
	CBox(const CBox& box) { _initData(*box.pData); }
	CBox& operator= (const CBox& box) //대입연산자
	{
		_initData(*box.pData);
		return *this;
	}
	void SetData(int data) { *pData = data; }
	int GetData() { return *pData; }
};
//템플릿으로 저장타입을 변경가능한 클래스
template<typename Type>
class CBoxTemplete
{
	Type* pData;
	void _initData(Type data) { this->pData = new Type(); *this->pData = data; }
public:
	CBoxTemplete(Type data = Type()) { _initData(data); }
	~CBoxTemplete() { delete pData; }
	CBoxTemplete(const CBoxTemplete& box) { _initData(*box.pData); }
	CBoxTemplete& operator= (const CBoxTemplete& box) //대입연산자
	{
		_initData(*box.pData);
		return *this;
	}
	void SetData(Type data) { *pData = data; }
	Type GetData() { return *pData; }
};


template<typename Type>
void Swap(Type& a, Type& b)
{
	Type temp = a;
	a = b;
	b = temp;
}
//템플릿: 데이터형이 어떤것이 들어든 처리할수있도록 일반화 하는것.
void FunctionTempletMain()
{
	int nDataA = 10;
	int nDataB = 20;
	float fDataA = 3.14f;
	float fDataB = 0.1f;
	CData cDataA;
	CData cDataB;
	cDataA.SetData(10);
	cDataB.SetData(20);
	CBox cBoxDataA;
	CBox cBoxDataB;
	cBoxDataA.SetData(10);
	cBoxDataB.SetData(20);

	CBoxTemplete<float> cBoxanitypeA(3.14f);
	CBoxTemplete<float> cBoxanitypeB(1.25f);

	printf("Origin(int):%d/%d\n", nDataA, nDataB);
	Swap(nDataA, nDataB);
	printf("Swap(int):%d/%d\n", nDataA, nDataB);
	printf("Origin(float):%f/%f\n", fDataA, fDataB);
	Swap(fDataA, fDataB);
	printf("Swap(float):%f/%f\n", fDataA, fDataB);
	Swap(cDataA, cDataB);
	printf("Swap(Class):%d/%d\n", cDataA.GetData(), cDataB.GetData());
	//다음과 같이 연산자나 기본호출 함수를 오버로딩해야하는 경우가 필요하다.
	Swap(cBoxDataA, cBoxDataB);
	printf("Swap(Boxsing):%d/%d\n", cBoxDataA.GetData(), cBoxDataB.GetData());
	//템플릿을 이용하면 타입을 변경할수있게 만들수있다.
	Swap(cBoxanitypeA, cBoxanitypeB);
	printf("Swap(Templet):%f/%f\n", cBoxanitypeA.GetData(), cBoxanitypeB.GetData());
}
template<typename Type>
class Box
{
	Type data;
public:
	void SetData(Type data) { this->data = data; }
	Type GetData() { return data; }
	void Display()
	{
		cout << typeid(*this).name() << "(" << typeid(data).name() << "):" << data << endl;
	}
};
//템플렛의 타입은 서로 다른타입을 여러개 정의할수있다.
template <typename TypeKey, typename TypeData>
class MapData
{
	TypeKey key;
	TypeData data;
public:
	MapData(TypeKey key, TypeData data)
	{
		this->key = key;
		this->data = data;
	}
	TypeData operator[](TypeKey) { return data; }
};
void TempletClassMain()
{
	//클래스 내부의 변수의 타입을 외부에서 정의할수있도록 만드는것.
	Box<int> box;
	box.SetData(10);
	box.Display();

	MapData<std::string, float> data("Pi", 3.14f);
	cout << data["Pi"] << endl;
}

void main()
{
	FunctionTempletMain();
	//TempletClassMain();
	//Mokeup::StackMain();
}
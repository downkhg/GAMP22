#include <stdio.h>

//전위연산자:++data,후위연산자:data++ 
//데이터의 값이 전위연산자와 후위 연산자의 차이점을 확인하는 프로그램
//데이터: 데이터2개가 필요하다 -> nDataA,nDataB -> 정수
//알고리즘: nDataB = ++nDataA, nDataB = nDataA++, ?
void IncDecTestMain()
{
	int nDataA = 10, nDataB; //10, ?
	nDataB = nDataA; //10
	printf("1.nDataA/B:%d/%d\n", nDataA, nDataB);
	nDataB = ++nDataA; //11/11 ->  전위연산자: 대입연산자보다 우선순위가 높으므로, 증감하고, 값이 변수에 대입된다.
	printf("2.nDataA/B:%d/%d\n", nDataA, nDataB);
	nDataB = nDataA++; //12/12 -> 12/11 -> 후위연산자는 대입연산자보다 우선순위가 낮으므로, 증감전 값이 변수에 대입된다.
	printf("3.nDataA/B:%d/%d\n", nDataA, nDataB);
}

//포인터, 포인터와 함수, 배열, 2차원배열
//문제: 정수와 실수의 데이터를 선언하고, 
//선언된 데이터를 각 실수와 정수의 포인터에 저장하여,       
//모든 변수들 에서 연산 할 수 있는 모든 결과를 출력하라.
void PointerTestMain()
{

}

void SwapVal(int a, int b)
{
	printf("SwapVal[%d/%d]:%d,%d\n", &a, &b, a, b);
	int temp = a;
	b = a;
	temp = b;
}
void SwapPtr(int* a, int* b)
{
	printf("SwapPtr[%d/%d]:%d,%d\n", &a, &b, a, b);
	int temp = *a;
	*b = *a;
	temp = *b;
}
void SwapRef(int& a, int& b)
{
	printf("SwapRef[%d/%d]:%d,%d\n", &a, &b, a, b);
	int temp = a;
	b = a;
	temp = b;
}

void FunctionAndPointerMain()
{
	int nDataA = 10;
	int nDataB = 20;
	printf("Val DataA/B[%d/%d]:%d,%d\n",&nDataA,&nDataB,nDataA,nDataB);
	SwapVal(nDataA, nDataB);
	printf("SwapVal: DataA/B[%d/%d]:%d,%d\n", &nDataA, &nDataB, nDataA, nDataB);
	SwapPtr(&nDataA, &nDataB);
	printf("Ptrl: DataA/B[%d/%d]:%d,%d\n", &nDataA, &nDataB, nDataA, nDataB);
	SwapRef(nDataA, nDataB);
}

void ArrayMain()
{

}

void Array2DTestMain()
{

}

void main()
{
	//PointerTestMain();
	FunctionAndPointerMain();
	//ArrayMain();
	//Array2DTestMain();
}
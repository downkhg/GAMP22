#include <stdio.h>
#include <string.h>
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
// 
//포인터: 주소값을 저장하는 변수.
void PointerTestMain()
{
	int nData = 10;
	float fData = 3.14f;
	int* pIntData = &nData;
	float* pFloatData = &fData;

	printf("nData[%d]:%d\n",&nData,nData);
	printf("pIntData[%d]:%d\n", *pIntData, pIntData);

	printf("fData[%d]:%f\n", &fData, fData);
	printf("pFloatData[%f]:%d\n", *pFloatData, pFloatData);
}
//값에의한호출: 매개변수에 값을 복사해서 넘겼을때
void SwapVal(int a, int b)
{
	printf("SwapVal[%d/%d]:%d,%d\n", &a, &b, a, b);
	int temp = a;
	b = a;
	temp = b;
}

//참조(포인터)에의한 호출: 매개변수에 주소값을 전달하였기 때문에 
///(포인터가 가진 주소값이 가진 변수)의 값을 변경한다.
void SwapPtr(int* pA, int* pB)
{
	printf("SwapPtr[%d/%d]:%d,%d\n", &pA, &pB, pA, pB);
	int temp = *pA;
	*pB = *pA;
	temp = *pB;
}
//참조자를 이용하여 매개변수로 전달받은 값을 변경.
//기본적인 원리는 포인터로 이해하더라도 실제 코드를 사용할때는 
//참조자를 활용하는것이 활용하기 쉽다.
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
	SwapVal(nDataA, nDataB);//매개변수가 변경되고 전달된 변수의 값이 변경되지는 않는다.
	printf("SwapVal: DataA/B[%d/%d]:%d,%d\n", &nDataA, &nDataB, nDataA, nDataB);
	SwapPtr(&nDataA, &nDataB);//매개변수가 가진 주소값을 가진 변수의 값이 변경된다.
	printf("Ptrl: DataA/B[%d/%d]:%d,%d\n", &nDataA, &nDataB, nDataA, nDataB);
	SwapRef(nDataA, nDataB); //매개변수에 전달된 변수의 값이 변경된다.
}

void ArrayMain()
{
	const int nSize = 3;
	int arrScore[nSize];
	int arrSize = sizeof(arrScore) / sizeof(int);
	for (int i = 0; i < nSize; i++)
		arrScore[i] = 100 - i * 10;
	printf("arrScore:%d\n",arrScore);
	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]%d,", &arrScore[i], i, arrScore[i]);
	printf("\n");
	int* pScore = arrScore;
	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]%d,", pScore + i, i, *(pScore + i));
	printf("\n");
	for (int i = 0; i < nSize; i++)
	{
		printf("[%d/%d]%d,", pScore, i, *pScore);
		pScore++;
	}
	printf("\n");
	int arrCopyScore[nSize];
	for (int i = 0; i < nSize; i++)
		arrCopyScore[i] = arrScore[i];
	memcpy(arrCopyScore, arrScore, sizeof(arrCopyScore));
}

void Array2DTestMain()
{

}

void main()
{
	//PointerTestMain();
	//FunctionAndPointerMain();
	ArrayMain();
	//Array2DTestMain();
}
#include <stdio.h>

//����������:++data,����������:data++ 
//�������� ���� ���������ڿ� ���� �������� �������� Ȯ���ϴ� ���α׷�
//������: ������2���� �ʿ��ϴ� -> nDataA,nDataB -> ����
//�˰���: nDataB = ++nDataA, nDataB = nDataA++, ?
void IncDecTestMain()
{
	int nDataA = 10, nDataB; //10, ?
	nDataB = nDataA; //10
	printf("1.nDataA/B:%d/%d\n", nDataA, nDataB);
	nDataB = ++nDataA; //11/11 ->  ����������: ���Կ����ں��� �켱������ �����Ƿ�, �����ϰ�, ���� ������ ���Եȴ�.
	printf("2.nDataA/B:%d/%d\n", nDataA, nDataB);
	nDataB = nDataA++; //12/12 -> 12/11 -> ���������ڴ� ���Կ����ں��� �켱������ �����Ƿ�, ������ ���� ������ ���Եȴ�.
	printf("3.nDataA/B:%d/%d\n", nDataA, nDataB);
}

//������, �����Ϳ� �Լ�, �迭, 2�����迭
//����: ������ �Ǽ��� �����͸� �����ϰ�, 
//����� �����͸� �� �Ǽ��� ������ �����Ϳ� �����Ͽ�,       
//��� ������ ���� ���� �� �� �ִ� ��� ����� ����϶�.
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
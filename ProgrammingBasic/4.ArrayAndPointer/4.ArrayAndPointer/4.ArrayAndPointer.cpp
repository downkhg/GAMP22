#include <stdio.h>
#include <string.h>
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
// 
//������: �ּҰ��� �����ϴ� ����.
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
//��������ȣ��: �Ű������� ���� �����ؼ� �Ѱ�����
void SwapVal(int a, int b)
{
	printf("SwapVal[%d/%d]:%d,%d\n", &a, &b, a, b);
	int temp = a;
	b = a;
	temp = b;
}

//����(������)������ ȣ��: �Ű������� �ּҰ��� �����Ͽ��� ������ 
///(�����Ͱ� ���� �ּҰ��� ���� ����)�� ���� �����Ѵ�.
void SwapPtr(int* pA, int* pB)
{
	printf("SwapPtr[%d/%d]:%d,%d\n", &pA, &pB, pA, pB);
	int temp = *pA;
	*pB = *pA;
	temp = *pB;
}
//�����ڸ� �̿��Ͽ� �Ű������� ���޹��� ���� ����.
//�⺻���� ������ �����ͷ� �����ϴ��� ���� �ڵ带 ����Ҷ��� 
//�����ڸ� Ȱ���ϴ°��� Ȱ���ϱ� ����.
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
	SwapVal(nDataA, nDataB);//�Ű������� ����ǰ� ���޵� ������ ���� ��������� �ʴ´�.
	printf("SwapVal: DataA/B[%d/%d]:%d,%d\n", &nDataA, &nDataB, nDataA, nDataB);
	SwapPtr(&nDataA, &nDataB);//�Ű������� ���� �ּҰ��� ���� ������ ���� ����ȴ�.
	printf("Ptrl: DataA/B[%d/%d]:%d,%d\n", &nDataA, &nDataB, nDataA, nDataB);
	SwapRef(nDataA, nDataB); //�Ű������� ���޵� ������ ���� ����ȴ�.
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
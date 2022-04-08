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
//�迭: ������ �޸𸮿� ������� ���� �ε����� �̿��Ͽ� ���� �����ϰ� �Ѵ�.
//�迭���̸��� �ּҰ��� ������ �����Ƿ�, �ε����� 0�� ������ �ּҰ��� +0�ؾ� ���� �ּҰ��� �����⶧���̴�.
//�����Ϳ���: �������� �ּҰ��� �ش������Ͱ� �����Ҽ��ִ� ������Ÿ���� ũ�⸸ŭ �����Ѵ�. ��) char +1, int +4, double +8
//�迭�� �����͸� Ȱ���Ͽ� �����Ǿ��ִ�. �׷��Ƿ� ũ�⸦ �Ҵ��Ҷ� �߰��� �����Ҽ������Ƿ�. 
//������ �̿��Ͽ� �迭�� ũ�⸦ ��������� ����� �̿��ؾ߸� �Ѵ�.
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
	for (int i = 0; i < nSize; i++)//0,1,2
		printf("[%d/%d]%d,", arrScore + i, i, *(arrScore + i));//�迭�̸�+�ε���
	printf("\n");
	for (int i = 0; i < nSize; i++)
	{
		printf("[%d/%d]%d,", pScore, i, *pScore); //������ �������Ҷ����� ����Ű�� �ּҰ��� �ٸ���.
		pScore++;//�����Ϳ���
	}
	printf("\n");
	int arrCopyScore[nSize];
	//�迭�� �ε����� ���縦 �ϸ� 3�� �ݺ��ؾ��Ѵ�.
	for (int i = 0; i < nSize; i++)
		arrCopyScore[i] = arrScore[i];
	//�޸� ���縦 �̿��ϸ� �޸𸮸� ����ũ�⸸ŭ �����ϹǷ� ������.
	memcpy_s(arrCopyScore, sizeof(arrCopyScore), arrScore, sizeof(arrCopyScore));
}

void Array2DTestMain()
{
	i
}

void main()
{
	//PointerTestMain();
	//FunctionAndPointerMain();
	ArrayMain();
	//Array2DTestMain();
}
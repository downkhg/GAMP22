#include <stdio.h>
#include <stdlib.h>
//�迭�� �Է¹��� ���� �̿��Ͽ� �޸�ũ�⸦ �����ϵ��� ����� ���α׷�.
//�����Ҵ�(����): ���������ܰ迡 �޸��� ��� �� ũ�Ⱑ �����Ǵ� ��. -> �����̸��� �ο������ϴ�. ������ ���ܰ迡�� �޸��� �����ֱⰡ �����ȴ�.
//�����Ҵ�(��): ���α׷� �����߿� �޸𸮰� �Ҵ�Ǵ� ��.  -> �ּҰ��� ���� ���������ϴ�, �����͸� �̿��Ͽ� �����ҵ� �޸��� �ּҰ��� �����Ѵ�. �޸��� �����Ҵ��� ���������ؾ��Ѵ�.
//�������÷���: ���α׷��� �����Ҵ�� �޸𸮸� �������ִ� ��. (C#,Java..)
//�����Ҵ�� �޸𸮰� �����Ǵ� ���. 
//C/C++: ���� �޸𸮸� ���� �����ؾ��ϴ� ���. ����Ʈ������(C++): �����Ҵ�� �޸𸮸� �ڵ����� �������ִ� ������.
void DaynamicAllocateTestMain()
{
	int nSize;
	int* pArray = NULL;//������:

	printf("ArraySize:");
	scanf_s("%d", &nSize);
	//�����Ҵ�� �迭�� ũ�⸦ ����Ͽ� �Ҵ��ϰ� ����� Ÿ�Կ� �°� ĳ�����Ѵ�.
	//�迭�� �����Ϳ����� �̿��Ϸ���, ������ Ÿ���� �˾ƾ��Ѵ�.
	pArray = (int*)malloc(nSize * sizeof(int));

	if (pArray != NULL)
	{
		for (int i = 0; i < nSize; i++)
		{
			pArray[i] = i * 10;
			printf("[%d]%d,",i,pArray[i]);
		}
	}
	//�����Ҵ�����: �����Ҵ��� �����Ϸ����� �����층�� �Ұ����ϹǷ�, 
	//���α׷��Ӱ� �޸𸮸� �Ҵ������Ѵ�.
	free(pArray);
}

void RellocateTestMain()
{
	int nSize;
	int* pArray = NULL;//������:

	printf("ArraySize:");
	scanf_s("%d", &nSize);
	//�����Ҵ�� �迭�� ũ�⸦ ����Ͽ� �Ҵ��ϰ� ����� Ÿ�Կ� �°� ĳ�����Ѵ�.
	//�迭�� �����Ϳ����� �̿��Ϸ���, ������ Ÿ���� �˾ƾ��Ѵ�.
	pArray = (int*)malloc(nSize * sizeof(int));
	printf("pArray:%d\n", pArray);
	if (pArray != NULL)
	{
		for (int i = 0; i < nSize; i++)
		{
			pArray[i] = i * 10;
			printf("[%d]%d,", i, pArray[i]);
		}
	}
	printf("\n");
	int nResize;
	printf("Resize:");
	scanf_s("%d", &nResize);
	nSize += nResize;
	//�����Ҵ�� �޸��� ũ�⸦ �����ϴ� �Լ�
	//�����Ҵ�� �޸��� �⺻ũ�⿡�� �ø������ٸ�, ���ο� �޸𸮸� �����ϰ� �����Ѵ�.
	pArray = (int*)realloc(pArray, nSize * sizeof(int));
	printf("pArray:%d\n", pArray);
	//pArray[nSize] = nSize * 10;
	if (pArray != NULL)
	{
		for (int i = 0; i < nSize+1; i++)
		{
			//pArray[i] = i * 10;
			printf("[%d]%d,", i, pArray[i]);
		}
	}
	printf("\n");
	//�����Ҵ�����: �����Ҵ��� �����Ϸ����� �����층�� �Ұ����ϹǷ�, 
	//���α׷��Ӱ� �޸𸮸� �Ҵ������Ѵ�.
	free(pArray);
}
//�޸��� ������ ���� �����Ҽ����� ������ ǥ���� ����.
void NewDeleteMain()
{
	int nSize = 10;
	int* pArray = new int[nSize];
	int* pIntData = new int;
	printf("pArray:%d\n", pArray);
	if (pArray != NULL)
	{
		for (int i = 0; i < nSize + 1; i++)
		{
			//pArray[i] = i * 10;
			printf("[%d]%d,", i, pArray[i]);
		}
	}
	printf("pIntData:%d\n",pIntData);
	delete[] pArray;
	delete pIntData;
}

void main()
{
	//DaynamicAllocateTestMain();
	RellocateTestMain();
}
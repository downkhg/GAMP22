#include <stdio.h>
#include <string.h>
//����������:++data,����������:data++ 
//�������� ���� ���������ڿ� ���� �������� �������� Ȯ���ϴ� ���α׷�
//������: ������2���� �ʿ��ϴ� -> nDataA,nDataB -> ����
//�˰�����: nDataB = ++nDataA, nDataB = nDataA++, ?
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
//4x3ũ���� �迭�� �����,
//ũ�Ⱑ 12�� 1�����迭�� ����� ���� ����for���� �̿��Ͽ� ���� �����ϰ�, 
//�ּҰ�,�ε���,������ ������ϱ�
void Array2DTestMain()
{
	const int nSizeX = 4;
	const int nSizeY = 3;
	const int nSize = nSizeY * nSizeX;
	int arr2DArray[nSizeY][nSizeX];
	int arrFake2DArray[nSize];
	for (int y = 0; y < nSizeY; y++)//0,1,2,3
	{
		for (int x = 0; x < nSizeX; x++)//0,1,2
		{
			arr2DArray[y][x] = y * nSizeY + x;//[0][0]:0 //[0][1]:1 //[0][2]:2 //[0][3]:3 ////[1][0]:0 //[1][1]:4 //[1][2]:5 //[1][3]:6 .....
			printf("%d[%d,%d]:%d,", &arr2DArray[y][x], y, x, arr2DArray[y][x], arr2DArray[y][x]);
		}
		printf("\n");
	}

	for (int y = 0; y < nSizeY; y++)//0,1,2,3
	{
		for (int x = 0; x < nSizeX; x++)//0,1,2
		{
			int idx = y * nSizeY + x;
			arrFake2DArray[idx] = idx;
			printf("%d[%d,%d]:%d,", &arrFake2DArray[idx], y, x, arrFake2DArray[idx], arrFake2DArray[idx]);
		}
		printf("\n");
	}
}
//PrintString(����ҳ����� ����,����� ���ڿ�,�ε�����¿���)
void PrintString(const char* msg, const char* str, bool isIdx)
{
	int idx = 0;
	printf("%s", msg);
	while (str[idx] != '\0')//%s�� ���ڿ��� �������� ����ϵ��� �۵��Ѵ�.
	{
		if(isIdx) printf("[%d]%c,", idx, str[idx]);
		else printf("%c,", idx, str[idx]);
		idx++;
	}
	printf("\n");
}

//���ڿ��� �̿��Ҷ� ���� �迭�� ũ��� ��Եɱ�?
//���ڿ��� ������ ũ��ȿ� �����ؼ� �����ؾ��ϹǷ�, ���ڿ����� �˾ƾ� ����� �׸� �Ҽ��ִ�.
//%s�� �̿��ϸ� �ι����������� ����� �ϹǷ� ��½ÿ� ���ڿ��� �ʿ��Ѻκи� �����ִ�.
//"���ڿ�"�� �̿��Ͽ� �����ϸ�, ���� ���� ���� �ڵ����� �ι��ڰ� �Ҵ�ȴ�.
void StringTestMain()
{
	const int nSize = 16;
	char strWord[nSize] = "gameprograming";//24 - 14 = 10 //���� 10ĭ�� ��� �ɱ�?
	//���ڿ����̾��� ���ڴ� ��� ��µɱ�?
	strWord[0] = 't';
	strWord[1] = 'e';
	strWord[2] = 's';
	strWord[3] = 't';
	strWord[4] = 0;// '\0';//�ι���: ���ڿ��� ���� �˸��� ����: '\0'(== 0)
	printf("for:");
	for (int i = 0; i < nSize; i++)
		printf("%c",strWord[i]);
	printf("\n");
	printf("string: %s\n", strWord);
	PrintString("while:", strWord, false);
	printf("\n");
}

void FullNameMakerMain()
{
	char strLastName[8] = "k";
	char strFirstName[8] = "hg";
	char strFullNameKr[16];
	char strFullNameEn[16];

	strcpy(strFullNameKr, strLastName);
	strcat(strFullNameKr, strFirstName);
	printf("Kr(%s, %s)[%d]: %s\n",strFirstName, strLastName, strlen(strFullNameKr), strFullNameKr);
	PrintString("krWihle", strFullNameKr,true);
	sprintf(strFullNameEn,"%s %s",strFirstName,strLastName);
	printf("En(%s, %s)[%d]: %s\n", strFirstName, strLastName, strlen(strFullNameEn), strFullNameEn);

	int nResult = strcmp(strLastName, strFirstName); //���ڿ��� �������̸� ��ȯ�Ѵ�. ������ 0�� ��ȯ��.
	if(!strcmp(strLastName, strFirstName)) //�Ϲ������� ���ڿ��񱳽� ������ ���� Ȱ���Ѵ�.
	//if (!nResult)
	{
		printf("%d: %s == %s\n", nResult,strLastName,strFirstName);
	}
	else
	{
		printf("%d: %s != %s\n", nResult, strLastName, strFirstName);
	}
}
/*
����:GAME
Q: _ _ _ _
A : G
Q : G _ _ _
......(�߷�)
A : GA_E
Q : M
A : GAME
*/
void HangManGameMain()
{

}

void main()
{
	//PointerTestMain();
	//FunctionAndPointerMain();
	//ArrayMain();
	//Array2DTestMain();
	FullNameMakerMain();
	//StringTestMain();
}
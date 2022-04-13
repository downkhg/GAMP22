#include <stdio.h>

int g_nDataC;
static int g_nDataD;

void PrintDataC()
{
	printf("PrintDataC[%d]:%d\n",&g_nDataC,g_nDataC);
}

static void PrintDataD()
{
	printf("PrintDataD[%d]:%d\n", &g_nDataD, g_nDataD);
}

void StaticGrobalVarTestMain()
{
	printf("g_nDataD[%d]:%d\n", &g_nDataD, g_nDataD);
	g_nDataD = 200;
	PrintDataD();
}

void StaticVarCount() 
{
	static int nStaticLocalVar = 0; //�������������� �Լ��� ������ �����ȴ�.
	int nLocalVar = 0; //���������� �Լ��� ������ �������.

	nStaticLocalVar++;
	nLocalVar++;

	printf("StaticLocalVar:%d\n",nStaticLocalVar);
	printf("LocalVar:%d\n",nLocalVar);
}

void StaticLocalVarTestMain()
{
	//�Ʒ� ����� �������������� ��� ���� ��������ǰ�,
	//�Ʒ��� ���������� ȣ��ø��� ���� ���� �������� �˼��ִ�.
	for (int i = 0; i < 3; i++)
		StaticVarCount();
}

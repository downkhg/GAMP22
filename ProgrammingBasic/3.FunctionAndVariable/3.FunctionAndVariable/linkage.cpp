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
	static int nStaticLocalVar = 0; //정적지역변수는 함수가 끝나도 유지된다.
	int nLocalVar = 0; //지역변수는 함수가 끝나면 사라진다.

	nStaticLocalVar++;
	nLocalVar++;

	printf("StaticLocalVar:%d\n",nStaticLocalVar);
	printf("LocalVar:%d\n",nLocalVar);
}

void StaticLocalVarTestMain()
{
	//아래 출력은 정적지역변수의 경우 값이 계속증가되고,
	//아랫쪽 지역변수는 호출시마다 같은 값이 유지됨을 알수있다.
	for (int i = 0; i < 3; i++)
		StaticVarCount();
}

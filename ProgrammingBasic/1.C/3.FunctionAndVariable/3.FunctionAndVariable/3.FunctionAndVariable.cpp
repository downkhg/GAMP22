#include <stdio.h>
//���������� ��������
//(�Լ�)�� (��������)�� �Լ� ���ο����� ��밡�������� (��������)�� (� �Լ�)������ ��밡���ϴ�.
//(��)�� (����)�� �������� ���� �� ������ (�������)�� (��� ��)������ ���Ѹ������ִ�.

//��������: ����Լ����� ������ ������ ����. ���α׷��� ����ɶ� ����.
int g_nDataA = 10;
int g_nDataB = 20;

//�Ű������� Ȱ���Ͽ� �Լ� �ȿ� ���� �����ϰ�, 
//�� ������ ���� ����� ������ �̿��Ͽ� �Լ� ������ ��������.
//���ϵǸ� �Լ��� ����ǹǷ� 1���̻��� ���� �Լ��ܺη� ������ �� ����.
//������ �޸𸮿� �����ȴ�.
//�Ű������� ������ ����������.

//����
//1. ���������� ���������� �������� �����ΰ�?
//2. ���������� ���������� ���� �����ǰ� ���� �Ҹ�Ǵ°�?
//3. ���������� ���������� ����ϴ� ������ �����ΰ�?
//��ȭ
//4. ���������� ��� ��� �Լ����� ������ �����Ѱ�?
//5. ���������� �� �Լ��� �Ҹ��ϸ� �������Ǵ°�?

int Sum(int a, int b)//�Ű�����: �Լ����ο� �����͸� �����ϴ� ���� //�Ű����� a,b�� �����ȴ�. //������ a,b�� �μ��� ���޵� ���� ����ȴ�.
{
	printf("Sum - g_nDataA/B[%d/%d]%d/%d\n", &g_nDataA, &g_nDataB, g_nDataA, g_nDataB); //9

	printf("Sum-a:%d,b:%d\n", &a, &b); //10
	int c = a + b; //11 //����c�� �����ϰ�, a�� b�� ��� ����� �����Ѵ�.
	return c; //12 //����c�� �������� �Լ� ������ ��������. //�Լ��� ����Ǿ� �Ű�����(a,b)�� ��������(c)�� �Ҹ��Ѵ�.
}

void SumParametarTestMain()
{
	printf("SumParametarTestMain - g_nDataA/B[%d/%d]%d/%d\n", &g_nDataA, &g_nDataB, g_nDataA, g_nDataB); //4

	//��������: �Լ����ο����� �����ϴ� �Լ�. �Լ��� ����ɶ�({}�� ������) �����ȴ�.
	int nDataA = 10; //5 //nDataA��� ������ �����ȴ�.
	int nDataB = 20; //6 //nDataB��� ������ �����ȴ�.
	printf("nDataA:%d, nDataB:%d\n", &nDataA, &nDataB); //7
	//nDataA�� a, nDataB �� b�� ���� �����ΰ�? X
	//nDataA�� a, nDataB �� b�� ���� ���ΰ�? O
	//����Ʈ1���� 2���� ���� ���(������)����. O
	//����Ʈ1���� 2���� �ּ�(����)�� ������? X
	int nResult = Sum(nDataA, nDataB); //8 //�Լ� c�� �������� nResult������ ����� ���� �����Ѵ�.

	printf("%d + %d = %d\n", nDataA, nDataB, nResult);//13
}//�Լ��� ����Ǹ� nDataA, nDataB, nResult�� �Ҹ��Ѵ�.

//extern �ش纯���� �Լ��� �� ���Ͽ��� ������ �ٸ����Ͽ� �����Ѵ�.
extern int g_nDataC;
extern void PrintDataC();
//extern int g_nDataD; //extern�ϴ��� ���������������� ������ �Ұ����ϴ�.
//extern void PrintDataD();//extern�ϴ��� �����Լ����� ������ �Ұ����ϴ�.
extern void StaticGrobalVarTestMain();

void LinkageTestMain()
{
	//linkage.cpp���Ͽ� �ִ� ������ �ּҰ��� �����Ƿ� ���� ������.
	printf("g_nDataC[%d]:%d\n", &g_nDataC, g_nDataC);
	g_nDataC = 100;
	PrintDataC();

	////�ٸ����Ͽ� �ִ� �������������� �ٸ����Ͽ� ������ �Ұ����ϴ�.
	//printf("g_nDataD[%d]:%d\n", &g_nDataD, g_nDataD);
	//g_nDataD = 200;
	//PrintDataD();

	//�ٸ����Ͽ� �������������� ���������� �����ϰ� �ʹٸ�,
	//������ ���� ��ũ������ �Լ��� ���� ȣ���ؾ��Ѵ�.
	StaticGrobalVarTestMain();
}

extern void StaticLocalVarTestMain();

void main()//1
{
	printf("main - g_nDataA/B[%d/%d]%d/%d\n", &g_nDataA, &g_nDataB, g_nDataA, g_nDataB); //2
	SumParametarTestMain(); //3
	////�����Ͽ��� - SumParametarTestMain�� ������. main������ ������ �Ұ����ϴ�.
	//nDataA = 10; 
	LinkageTestMain();
	StaticLocalVarTestMain();
}//14 main�Լ��� ����Ǹ� ���α׷��� ����ǹǷ� ���������� g_nDataA, g_nDataB�� �Ҹ��Ѵ�.
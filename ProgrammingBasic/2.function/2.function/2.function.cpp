#include <stdio.h>
#define PI 3.141592 //��ȣ���: ������ �ÿ� ��ȣ���ִ°��� �ش� ���� �־���.

//�Լ�(Function): ��� ����̳� ������ �ϳ��� ������ ���� ���� ����ϵ��� �����ϴ� ��.
//�Լ��� ����: �̷��� �Լ��� �ִٴ� ���� �����Ϸ����� �̸� �˸�. �Լ��� ������ �̿��ϸ� �Լ��� �ٽɳ��븸 �����ϰ� ��� �� �� �ִ�.
//��������� �Լ�: ����ڰ� ����� ���� ���� �����ϴ� �Լ�.
int Sum(int a, int b); //�μ��� ������ ���ϴ� �Լ�.
float CircleArea(float rad); //���� �������� �Է��ϸ� ���� ���̸� ���ϴ� �Լ�.
void ASCIICodeCheck(); //�ƽ�Ű�ڵ��� �� 128���� Ȯ���Ͽ� ����ϴ� �Լ�.
float ArrivalTimeSec(float dist, float speed); //�Ÿ��� �ӵ��� ������ �ɸ��ð��� ���ϴ� �Լ�.
char GradeCheck(int nScore); //������ ������ ������ �˷��ִ� �Լ�.
float Caculator(float fDataA, float fDataB, char cOp); //�μ��� �����ڸ� ������ ������ִ� �Լ�(��Ģ���길 ����)
void CaculatorLoofMain(); //�μ��� ����ϴ� ����
void FunctionTestMain();  //�� �Լ����� ������� �׽�Ʈ�ϴ� �Լ�.

//F12: �Լ��� ���Ƿ� �̵�
void main()
{
	//CaculatorLoofMain();
	FunctionTestMain();
}

//�Լ��� ����: ������ ����� �Լ��� ��ü���� ������ ������ִ� ��.
//�μ��� ������ ���ϴ� �Լ�. //<-�ڵ��ϼ��ÿ� �Լ��� ����� �ּ����� ��������.
int Sum(int a, int b)
{
	int c = a + b;
	return c;
}

//���� �������� �Է��ϸ� ���� ���̸� ���ϴ� �Լ�.
float CircleArea(float rad)
{
	float area;
	area = rad * rad * PI; //area = rad * rad * 3.141592; //�����ϵɶ� �̷������� ġȯ�ȴ�.
	return area;
}

//�ƽ�Ű�ڵ��� �� 0~128�� Ȯ���Ͽ� ����ϴ� �Լ�.
void ASCIICodeCheck()
{
	for (int i = 0; i < 128; i++)
	{
		printf("%d:%c,", i, i);
		if (i % 12 == 0) printf("\n");
	}
}

//�Ÿ��� �ӵ��� �Է��ϸ� �����ϴ� �ð��� ����ϴ� �Լ�.
float ArrivalTimeSec(float dist, float speed)
{
	float time = dist / speed;
	return time;
}

//������ ������ ������ �˷��ִ� �Լ�.
char GradeCheck(int nScore)
{
	char cGrade;

	if (nScore >= 90)
	{
		cGrade = 'A';
	}
	else if (nScore >= 80)
	{
		cGrade = 'B';
	}
	else if (nScore >= 70)
	{
		cGrade = 'C';
	}
	else if (nScore >= 60)
	{
		cGrade = 'D';
	}
	else
	{
		cGrade = 'F';
	}

	return cGrade;
}

//�μ��� �����ڸ� ������ ������ִ� �Լ�(��Ģ���길 ����)
float Caculator(float fDataA, float fDataB, char cOp) //���ϰ� �Լ����̸�(�Ű�����....)
{
	float fResult = -1;

	if (cOp == '+')
		fResult = fDataA + fDataB;
	else if (cOp == '-')
		fResult = fDataA - fDataB;
	else if (cOp == '*')
		fResult = fDataA * fDataB;
	else if (cOp == '/')
		fResult = fDataA / fDataB;
	else
	{
		printf("%c is not Support!\n", cOp);
		return -1.0f; //������ ������ �Լ��� ����ȴ�.
	}

	return fResult; //�Լ��� ����ɶ� �Լ������� ������ ��.
}

//���� �����
//1. ���� -> (����:����:����?�Ǽ�!)�� (������:����:����)�� (�Է�:scanf)�ϸ� ��(���:����:�Ǽ�)�� ����ϴ� ���.
//2. �����ڴ� ��Ģ���길 �����ϴ�(+,-,*,/)
//3. ������ �ϱ����ؼ� �ּ� 2���� ������ �ʿ��ϹǷ� 2���� ����Ѵ�.
//4. ����� �����Ҷ����� (�ݺ�)�ؼ� ����� �Է��ϰ�, Ȯ���Ҽ��ִ�.
//������: ����A, ����B, ������, ���
//�˰���: ���ڿ� �����ڸ� �Է¹ް�, 
//		    ��Ģ������ ������ ����Լ��� ȣ���ϰ�, �ʿ��� ���� �־ ���ϴ� ���Ϲ��� ���� �ԷµȰ����� ����Ѵ�.
//			ex) 1+1 1+1=2
void CaculatorLoofMain()
{
	float fDataA, fDataB, fResult; 
	char cOp = 0; 

	while (cOp != 'x')
	{
		printf("ex) 1+1 exit)?x?>> "); //
		scanf("%f%c%f", &fDataA, &cOp, &fDataB); //

		fResult = Caculator(fDataA, fDataB, cOp);

		printf("%f%c%f=%f\n", fDataA, cOp, fDataB, fResult);
	}
}

void FunctionTestMain()
{
	//�Լ��� �Է°��� ������ �ش��ϴ� ����� ��ȯ�ϴ� �Լ�
	printf("10+20 = %d\n", Sum(10, 20));
	printf("radius:5 area:%f\n", CircleArea(5.0f));
	printf("ArrivalTime:%fs\n", ArrivalTimeSec(100, 10));
	//ȣ���ϸ� Ư������� �����ϴ� �Լ�
	ASCIICodeCheck();
}
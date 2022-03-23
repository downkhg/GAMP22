#include <stdio.h>//ǥ������� ���̺귯��
#define PI 3.141592//�����Ϸ��� PI��� �ԷµȰ��� ������ ���� �־���.(�޸𸮰�������x)

//�μ��� ���ؼ� ������� ���ϴ� ���α׷�.
void SumMain()//��������� �Լ�: ������ ����ڰ� ���� �Լ�.
{
	//����: �����͸� ��� ����.
	//Ÿ��: float,double(�Ǽ�), int(����),  char(����)
	int a = 10;
	int b = 20;
	int c = a + b;
	printf("%d + %d = %d\n", a, b, c);//���̺귯�� �Լ�
}

//���� �������ϱ�(��, ���Ǹ����� ���Ϸ��� ������x������x3.141592�� �Ѵ�.)
//������ = pi * r*r
//������(����): ������(�Ǽ�),  ������(pi): 3.141592, ������(�Ǽ�) 
//�˰���: ������ = ������*������*������
void CircleAreaMain()
{
	float rad = 0;
	float area = 0;
	const float pi = 3.141592;//�������
	//pi = 2;//�������: ������ �ʱ�ȭ�� ���� �����Ҽ�����.
	printf("rad?");
	scanf("%f", &rad); //
	area = rad * rad * PI;//
	//area = rad * rad * pi;
	printf("%f * %f *%f = %f\n", rad, rad, pi, area);
}
//���� ������ Ÿ���� ũ�⸦ Ȯ���غ���
//(int x, char,int,short,long,float,duble, �� ũ�⸦ �궧�� sizeof()�� �̿��Ѵ�.)
void ValSizeMain()
{
	int x;
	printf("x:%d\n",sizeof(x));
	printf("char:%d\n", sizeof(char));
	printf("int:%d\n", sizeof(int));
	printf("short:%d\n", sizeof(short));
	printf("long:%d\n", sizeof(long));
	printf("float:%d\n", sizeof(float));
	printf("double:%d\n", sizeof(double));
}

//0~128
void ASCIITestMain()
{
	for (int i = 0; i < 128; i++)
	{
		printf("%d:%c, ",i,i);
		if (i % 11 == 0) printf("\n");
	}
}
//�¾�� ���������� �Ÿ��� d�̰�, 
//�¾��� �ӵ��� s�϶�,
//�¾翡�� ������ ��� �ð� t�� ���Ͽ���.
//s: 30�� km/s
//d: 14960��km
//t: �ʴ���
//��ȭ: t�� �� �ʷ� ��Ÿ������
//������: dist, speed, second -> ����, �Ǽ� -> ?
//�˰���: t = d/s ���
//--------- d //- s
void LightSpeedMain()
{
	//�����⸦ �Ҷ��� �Ǽ����� ����(=������ ���� ���� ����.)�ϴ�.
	float dist = 14960;
	float speed = 30;
	float sec = dist/speed;
	//printf("time:%d\n",sec);
	//printf("%d/%d=%d\n", dist, speed , sec);
	printf("%f/%f=%f\n", dist, speed, sec);
}

void LightSpeedMain2()
{
	float dist = 14960;
	float speed = 30;
	float time = dist / speed;
	//printf("time:%d\n",sec);
	//printf("%d/%d=%d\n", dist, speed , sec);
	printf("%f/%f=%f\n", dist, speed, time);
	int min, sec;
	min = time / 60;
	//sec = (int)time % 60;
	sec = time - min * 60;
	printf("%02d:%02d",min,sec);
}
//++ --
//�������� ���� ���������ڿ� ���� �������� �������� Ȯ���ϴ� ���α׷�
//������: ������ 2����(nDataA, nDataB) �ʿ��ϴ�. --,++�������� ���̵� �˼��ֵ��� ���α׷��� �ۼ��ϱ�
//�˰���: nDataA�� nDataB�� �ʱⰪ�˾ƾ� �ڿ� ������� ����� �˼��ִ�. nDataB = nDataA++, nDataB = ++nData
void IncDecTestMain()
{
	int nDataA = 10; //10
	int nDataB = nDataA; //10
	printf("1.DataA/B: %d/%d\n",nDataA,nDataB);
	nDataB = nDataA++; //11/11 -> �������: 10/11 -> ����: ���� -> ����: �˻� -> ���������ڴ� ���Կ����ں��� �켱������ �����Ƿ� �������� ���� ���޵ȴ�.
	printf("2.DataA/B: %d/%d\n", nDataA, nDataB);
	nDataB = ++nDataA; //12/12 -> ���������ڴ� ���Կ����ں��� �켱������ �����Ƿ�, ������ ���� ������ ���޵ȴ�.
	printf("3.DataA/B: %d/%d\n", nDataA, nDataB);
}

void OpTestMain()
{
	int x = 10, y = 10, z = 33;
	x += 1; //11
	y *= 2; //20
	z %= (x + y); //33 % 31 = 2 

	printf("x/y/z:%d,%d,%d\n",x,y,z);
}

void main()//���α׷����� ����Ǿ����� os���� �ҷ��ִ� �Լ�
{
	//Ctrl+F5
	printf("Hello World!!!\n");//\n: �ٹٲ޹���.
	//�Լ��� ȣ��: �Լ��� ����Ѵ�.
	//SumMain();//�����ݷ�: ���帶������ ��Ÿ���� ��ȣ
	//CircleAreaMain();
	//ValSizeMain();
	//ASCIITestMain();
	//LightSpeedMain();
	//LightSpeedMain2();
	//IncDecTestMain();
	OpTestMain();
}
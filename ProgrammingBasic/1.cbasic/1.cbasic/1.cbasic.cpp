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
void LightSpeedMain()
{

}

void main()//���α׷����� ����Ǿ����� os���� �ҷ��ִ� �Լ�
{
	//Ctrl+F5
	printf("Hello World!!!\n");//\n: �ٹٲ޹���.
	//�Լ��� ȣ��: �Լ��� ����Ѵ�.
	//SumMain();//�����ݷ�: ���帶������ ��Ÿ���� ��ȣ
	//CircleAreaMain();
	//ValSizeMain();
	ASCIITestMain();
}
#include <stdio.h>//ǥ������� ���̺귯��

//�μ��� ���ؼ� ������� ���ϴ� ���α׷�.
void SumMain()//��������� �Լ�: ������ ����ڰ� ���� �Լ�.
{
	//����: �����͸� ��� ����.
	int a = 10;
	int b = 20;
	int c = a + b;
	printf("%d + %d = %d", a, b, c);//���̺귯�� �Լ�
}
//���� �������ϱ�
void CircleAreaMain()
{

}

void main()//���α׷����� ����Ǿ����� os���� �ҷ��ִ� �Լ�
{
	//Ctrl+F5
	printf("Hello World!!!\n");//\n: �ٹٲ޹���.
	//�Լ��� ȣ��: �Լ��� ����Ѵ�.
	SumMain();//�����ݷ�: ���帶������ ��Ÿ���� ��ȣ
	CircleAreaMain();
}
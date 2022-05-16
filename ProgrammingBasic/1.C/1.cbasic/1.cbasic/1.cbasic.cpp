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
//�˰�����: ������ = ������*������*������
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
//�˰�����: t = d/s ���
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
//�˰�����: nDataA�� nDataB�� �ʱⰪ�˾ƾ� �ڿ� ������� ����� �˼��ִ�. nDataB = nDataA++, nDataB = ++nData
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
//������ �Է��ϸ�, ������ ����ϴ� ���α׷������.
//(A: 90���̻� B: 80���̻� C: 70�� �̻� D: 60���̻� 60�� �̸�: F)
//������: ���� -> ����, ���� -> ����
//�˰�����: �������� ���ǿ� ���� (A: 90���̻� B: 80���̻� C: 70�� �̻� D: 60���̻� 60�� �̸�: F) ������ ���
void GradeTestMain()
{
	int nScore;
	char cGrade;
	printf("Score: ");
	scanf("%d",&nScore);

	if (nScore >= 90)
		cGrade = 'A';
	else if (nScore >= 80)
		cGrade = 'B';
	else if (nScore >= 70)
		cGrade = 'C';
	else if (nScore >= 60)
	{
		cGrade = 'D';
		printf("Dead");
	}
	else
	{
		cGrade = 'F';
		printf("Fail!!!");
	}
	
	printf("Score:%d Grade:%c\n",nScore,cGrade);
}
//��Ģ������ ������ ���⸦ ������.
//1. ���� (�Է�:scanf)�ϸ� ����ϴ� (����:����,����)�� (��:����,����?�Ǽ�!)�� (����)�Ҽ��ִ�.
//2. ��Ģ������ +,-,*,/ -> ����, �Է��� 2���� �Է¹޾ƾ� ������ �����ϹǷ� �ּ� 2���� �Է¹޴´�.
//������: ����, ����
//�˰�����: �μ��� �����ڸ� �Է¹޴´�. 
//			������ ���� +��� �μ��� ���Ѵ�. 
//			������ ���� -��� �μ��� ����. 
//			������ ���� /��� �μ��� ������. 
//			������ ���� *��� �μ��� ���Ѵ�.   
void CalcultorMain()
{
	float fDataA, fDataB, fResult; //������ �μ�
	char cOp; //������
	//������ ���� �Է¹޴��� ������ �ذ��ϸ�ȴ�. //�׷��� ���� �޴°�� ���͸� ���ؼ� �߸��� �Է��� �������ִ�.
	/*printf("DataA:");
	scanf("%f", &fDataA);
	printf("DataB:");
	scanf("%f", &fDataB);
	printf("Opreator:");
	scanf("%c", &cOp);*/
	printf("ex) 1+1\n");
	scanf("%f%c%f", &fDataA, &cOp, &fDataB);//������ �����Ҷ� ���⳪ �߰����ڵ� ������ �ش�.

	if (cOp == '+')
		fResult = fDataA + fDataB;
	else if (cOp == '-')
		fResult = fDataA - fDataB;
	else if (cOp == '/')
		fResult = fDataA / fDataB;
	else if (cOp == '*')
		fResult = fDataA * fDataB;
	else
	{
		printf("%c is not support!!!\n", cOp);
		return;//������ ������ �Լ��� ����ȴ�.
	}

	printf("%f%c%f=%f",fDataA,cOp,fDataB, fResult);
}
//��Ģ������ ������ ���⸦ ������.
//1. ���� (�Է�:scanf)�ϸ� ����ϴ� (����:����,����)�� (��:����,����?�Ǽ�!)�� (����)�Ҽ��ִ�.
//2. ��Ģ������ +,-,*,/ -> ����, �Է��� 2���� �Է¹޾ƾ� ������ �����ϹǷ� �ּ� 2���� �Է¹޴´�.
//������: ����, ����
//�˰�����: �����ڿ� x�� �Է¹��������� �ݺ��ϸ� 
//			x�� ������ ����ȴ�.
//			�μ��� �����ڸ� �Է¹޴´�. 
//			������ ���� +��� �μ��� ���Ѵ�. 
//			������ ���� -��� �μ��� ����. 
//			������ ���� /��� �μ��� ������. 
//			������ ���� *��� �μ��� ���Ѵ�.   
void CalcultorSwichMain()
{
	float fDataA, fDataB, fResult; //������ �μ�
	char cOp; //������
	//������ ���� �Է¹޴��� ������ �ذ��ϸ�ȴ�. //�׷��� ���� �޴°�� ���͸� ���ؼ� �߸��� �Է��� �������ִ�.
	/*printf("DataA:");
	scanf("%f", &fDataA);
	printf("DataB:");
	scanf("%f", &fDataB);
	printf("Opreator:");
	scanf("%c", &cOp);*/
	printf("ex) 1+1\n");
	scanf("%f%c%f", &fDataA, &cOp, &fDataB);//������ �����Ҷ� ���⳪ �߰����ڵ� ������ �ش�.

	switch (cOp)//����� ��������̳Ŀ����� �б⸦ ������.
	{
	case '+': //case~break�� ¦�� �̷�� ����ϴ� ���� �����̴�.
		fResult = fDataA + fDataB;
		//break;//�����Ǹ� �Ʒ� ���忡�� break�� ���������� �ݺ��ȴ�.
	case '-':
		fResult = fDataA - fDataB;
		break;
	case '*':
		fResult = fDataA * fDataB;
		break;
	case '/':
		fResult = fDataA / fDataB;
		break;
	default:
		printf("%c is not support!!!\n",cOp);
		return;//������ ������ �Լ��� ����ȴ�.
		break;
	}

	printf("%f%c%f=%f\n", fDataA, cOp, fDataB, fResult);
}

void CalcultorWhileMain()
{
	float fDataA, fDataB, fResult; //������ �μ� 
	char cOp = 0; //������ //?

	//while (false)//()�ȿ� ������ �����ϸ� �ݺ��ϰ�, �������������� ����ȴ�. // 
	//while(!(cOp == 'x'))// 0 == 'x' -> F -> T
	while (cOp != 'x')//if���� ������ �ݴ�� ���ǹ��� ������ȴ�. //��ǻ�ʹ� �ݺ��Ǵ� ������ �ſ� �߿��ϹǷ�, ������ ������ �����ϴ� �ΰ��� ����� �ٸ���.
	{
		printf("ex) 1+1, exit:?x?\n");
		scanf("%f%c%f", &fDataA, &cOp, &fDataB);//������ �����Ҷ� ���⳪ �߰����ڵ� ������ �ش�.
		//if (cOp == 'x') break; //������ ������ ����ã�´�.
		if (cOp == '+')
			fResult = fDataA + fDataB;
		else if (cOp == '-')
			fResult = fDataA - fDataB;
		else if (cOp == '/')
			fResult = fDataA / fDataB;
		else if (cOp == '*')
			fResult = fDataA * fDataB;
		else
		{
			printf("%c is not support!!!\n", cOp);
			return;//������ ������ �Լ��� ����ȴ�.
		}

		printf("%f%c%f=%f\n", fDataA, cOp, fDataB, fResult);
	}
}
//������ 10������ ����ϰ� 4�ð� ���Ŀ� ������ ����?
//������ 1�ð����� 2�辿 �����Ѵ�.
//������: ���ռ�,�ð�
//�˰�����: ���ռ�*2, 1�ð�����, 100���� �̻��̵ɶ�����
//1.�����Ϳ� �˰������� �и��Ѵ�.
//2.�����ʹ� ���� �˰������� ����,�ݺ�,���� ���� ���յȴ�.
//3.�ݺ��Ǵ� ���� ���� �ݺ��ϰ� ������ ����Ѵ�.
//void BateriaMain()
//{
//	int nBateria = 10;//10
//	int nTime = 0;//0
//
//	nBateria = nBateria * 2;//10*2 = 20
//	nTime = 1;
//
//	nBateria = nBateria * 2;//20*2 = 40
//	nTime = 2;
//
//	nBateria = nBateria * 2;//40*2 = 80
//	nTime = 3;
//
//	nBateria = nBateria * 2;//80 * 2 = 160
//	nTime = 4;
//
//	printf("Time:%d\n", nTime);
//}

//4.�ݺ��Ǵ� ��Ģ���� ã�Ƽ� ���ѹݺ��� ������ �ݺ��� ������ ��� Ȯ���Ѵ�.
//(���α׷��Ӱ� �ƴ϶�� ���⼭ ���ĵ� ������. �׷��� ��ġ��(������� �þ�����)�� ������� �ɼ�����)

void BateriaMain()
{
	int nBateria = 10;
	int nTime = 0;

	//while (true)
	while(nBateria < 100)//�������ǿ� �ݴ�Ǵ� ������ �ݺ����� ������������ �����Ѵ�.
	{
		nBateria = nBateria * 2;//20
		nTime = nTime + 1;
		printf("Bateria:%d Time:%d\n", nBateria, nTime);
		//if (nBateria >= 100) break;
	}
}

//(����:����) 10������ ����Ͽ� (10�ð���:����)�� ���ռ��� ���Ͽ���.
//�̶�, ������ (1�ð� ���� 4��)�� �����Ѵ� 
//���ռ�:10 //�ð�:0  //���ռ�*=4
void BateriaCountMain()
{

	int nBateria = 10;//10
	int nTime = 0;//0

	////�ڵ�� ���� ���������� �����ϱ������� �ڵ��ۼ���ü�� ����������.
	//for (nTime = 0; nTime < 10; nTime++)
	//{
	//	nBateria = nBateria * 4;
	//	printf("Time:%d\n", nTime);
	//	printf("Bateria:%d\n", nBateria);
	//}

	//while (true)
	while (nTime < 10)
	{
		nBateria = nBateria * 4;
		nTime++;
		printf("Time:%d\n", nTime);
		printf("Bateria:%d\n", nBateria);
		//if (nTime == 10)  break;
	}

	/*printf("Time:%d\n", nTime);
	printf("Bateria:%d\n", nBateria);*/
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
	//OpTestMain();
	//CalcultorMain();
	//CalcultorWhileMain();
	BateriaCountMain();
}
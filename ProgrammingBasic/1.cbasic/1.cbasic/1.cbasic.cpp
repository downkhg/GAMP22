#include <stdio.h>//표준입출력 라이브러리
#define PI 3.141592//컴파일러가 PI라고 입력된곳에 지정된 값을 넣어줌.(메모리공간차지x)

//두수를 더해서 결과값을 구하는 프로그램.
void SumMain()//사용자정의 함수: 어떤기능을 사용자가 만든 함수.
{
	//변수: 데이터를 담는 상자.
	//타입: float,double(실수), int(정수),  char(문자)
	int a = 10;
	int b = 20;
	int c = a + b;
	printf("%d + %d = %d\n", a, b, c);//라이브러리 함수
}

//원의 면적구하기(단, 원의면적을 구하려면 반지름x반지름x3.141592를 한다.)
//원면적 = pi * r*r
//데이터(변수): 반지름(실수),  원주율(pi): 3.141592, 원면적(실수) 
//알고리즘: 원면적 = 반지름*반지름*원주율
void CircleAreaMain()
{
	float rad = 0;
	float area = 0;
	const float pi = 3.141592;//상수변수
	//pi = 2;//상수변수: 변수에 초기화된 값을 변경할수없다.
	printf("rad?");
	scanf("%f", &rad); //
	area = rad * rad * PI;//
	//area = rad * rad * pi;
	printf("%f * %f *%f = %f\n", rad, rad, pi, area);
}
//각각 변수의 타입의 크기를 확인해보기
//(int x, char,int,short,long,float,duble, 단 크기를 잴때는 sizeof()를 이용한다.)
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
//태양과 지구사이의 거리가 d이고, 
//태양의 속도가 s일때,
//태양에서 지구에 닿는 시간 t를 구하여라.
//s: 30만 km/s
//d: 14960만km
//t: 초단위
//심화: t를 분 초로 나타내보기
void LightSpeedMain()
{

}

void main()//프로그램에서 실행되었을때 os에서 불러주는 함수
{
	//Ctrl+F5
	printf("Hello World!!!\n");//\n: 줄바꿈문자.
	//함수의 호출: 함수를 사용한다.
	//SumMain();//세미콜론: 문장마지막을 나타내는 기호
	//CircleAreaMain();
	//ValSizeMain();
	ASCIITestMain();
}
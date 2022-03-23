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
//데이터: dist, speed, second -> 정수, 실수 -> ?
//알고리즘: t = d/s 출력
//--------- d //- s
void LightSpeedMain()
{
	//나누기를 할때는 실수형이 안전(=오차가 없는 것이 좋다.)하다.
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
//데이터의 값이 전위연산자와 후위 연산자의 차이점을 확인하는 프로그램
//데이터: 변수가 2개가(nDataA, nDataB) 필요하다. --,++연산자의 차이도 알수있도록 프로그램을 작성하기
//알고리즘: nDataA와 nDataB의 초기값알아야 뒤에 연산들의 결과를 알수있다. nDataB = nDataA++, nDataB = ++nData
void IncDecTestMain()
{
	int nDataA = 10; //10
	int nDataB = nDataA; //10
	printf("1.DataA/B: %d/%d\n",nDataA,nDataB);
	nDataB = nDataA++; //11/11 -> 실제결과: 10/11 -> 수업: 질문 -> 공부: 검색 -> 후위연산자는 대입연산자보다 우선순위가 낮으므로 연산전에 값이 전달된다.
	printf("2.DataA/B: %d/%d\n", nDataA, nDataB);
	nDataB = ++nDataA; //12/12 -> 전위연산자는 대입연산자보다 우선순위가 높으므로, 증감후 값이 변수에 전달된다.
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

void main()//프로그램에서 실행되었을때 os에서 불러주는 함수
{
	//Ctrl+F5
	printf("Hello World!!!\n");//\n: 줄바꿈문자.
	//함수의 호출: 함수를 사용한다.
	//SumMain();//세미콜론: 문장마지막을 나타내는 기호
	//CircleAreaMain();
	//ValSizeMain();
	//ASCIITestMain();
	//LightSpeedMain();
	//LightSpeedMain2();
	//IncDecTestMain();
	OpTestMain();
}
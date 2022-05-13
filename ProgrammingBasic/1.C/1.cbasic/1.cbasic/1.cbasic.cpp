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
//점수를 입력하면, 학점을 출력하는 프로그램만들기.
//(A: 90점이상 B: 80점이상 C: 70점 이상 D: 60점이상 60점 미만: F)
//데이터: 점수 -> 정수, 학점 -> 문자
//알고리즘: 각점수의 조건에 따라 (A: 90점이상 B: 80점이상 C: 70점 이상 D: 60점이상 60점 미만: F) 학점을 출력
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
//사칙연산이 가능한 계산기를 만들어라.
//1. 값을 (입력:scanf)하면 계산하는 (연산:변수,문자)과 (수:변수,정수?실수!)를 (변경)할수있다.
//2. 사칙연산은 +,-,*,/ -> 문자, 입력은 2개는 입력받아야 연산이 가능하므로 최소 2개만 입력받는다.
//데이터: 연산, 변수
//알고리즘: 두수와 연산자를 입력받는다. 
//			연산이 만약 +라면 두수를 더한다. 
//			연산이 만약 -라면 두수를 뺀다. 
//			연산이 만약 /라면 두수를 나눈다. 
//			연산이 만약 *라면 두수를 곱한다.   
void CalcultorMain()
{
	float fDataA, fDataB, fResult; //연산할 두수
	char cOp; //연산자
	//다음과 같이 입력받더라도 문제를 해결하면된다. //그러나 각각 받는경우 엔터를 통해서 잘못된 입력이 들어갈수도있다.
	/*printf("DataA:");
	scanf("%f", &fDataA);
	printf("DataB:");
	scanf("%f", &fDataB);
	printf("Opreator:");
	scanf("%c", &cOp);*/
	printf("ex) 1+1\n");
	scanf("%f%c%f", &fDataA, &cOp, &fDataB);//형식을 지정할때 띄어쓰기나 중간문자도 영향을 준다.

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
		return;//리턴을 만나면 함수가 종료된다.
	}

	printf("%f%c%f=%f",fDataA,cOp,fDataB, fResult);
}
//사칙연산이 가능한 계산기를 만들어라.
//1. 값을 (입력:scanf)하면 계산하는 (연산:변수,문자)과 (수:변수,정수?실수!)를 (변경)할수있다.
//2. 사칙연산은 +,-,*,/ -> 문자, 입력은 2개는 입력받아야 연산이 가능하므로 최소 2개만 입력받는다.
//데이터: 연산, 변수
//알고리즘: 연산자에 x를 입력받을때까지 반복하며 
//			x가 들어오면 종료된다.
//			두수와 연산자를 입력받는다. 
//			연산이 만약 +라면 두수를 더한다. 
//			연산이 만약 -라면 두수를 뺀다. 
//			연산이 만약 /라면 두수를 나눈다. 
//			연산이 만약 *라면 두수를 곱한다.   
void CalcultorSwichMain()
{
	float fDataA, fDataB, fResult; //연산할 두수
	char cOp; //연산자
	//다음과 같이 입력받더라도 문제를 해결하면된다. //그러나 각각 받는경우 엔터를 통해서 잘못된 입력이 들어갈수도있다.
	/*printf("DataA:");
	scanf("%f", &fDataA);
	printf("DataB:");
	scanf("%f", &fDataB);
	printf("Opreator:");
	scanf("%c", &cOp);*/
	printf("ex) 1+1\n");
	scanf("%f%c%f", &fDataA, &cOp, &fDataB);//형식을 지정할때 띄어쓰기나 중간문자도 영향을 준다.

	switch (cOp)//어떤값이 어느조건이냐에따라 분기를 나눈다.
	{
	case '+': //case~break는 짝을 이루어 사용하는 것이 보통이다.
		fResult = fDataA + fDataB;
		//break;//생략되면 아래 문장에서 break를 만날때까지 반복된다.
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
		return;//리턴을 만나면 함수가 종료된다.
		break;
	}

	printf("%f%c%f=%f\n", fDataA, cOp, fDataB, fResult);
}

void CalcultorWhileMain()
{
	float fDataA, fDataB, fResult; //연산할 두수 
	char cOp = 0; //연산자 //?

	//while (false)//()안에 조건이 만족하면 반복하고, 만족하지않으면 종료된다. // 
	//while(!(cOp == 'x'))// 0 == 'x' -> F -> T
	while (cOp != 'x')//if문의 조건의 반대로 조건문에 넣으면된다. //컴퓨터는 반복되는 조건이 매우 중요하므로, 끝나는 조건을 생각하는 인간의 사고와 다르다.
	{
		printf("ex) 1+1, exit:?x?\n");
		scanf("%f%c%f", &fDataA, &cOp, &fDataB);//형식을 지정할때 띄어쓰기나 중간문자도 영향을 준다.
		//if (cOp == 'x') break; //끝나는 조건을 먼저찾는다.
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
			return;//리턴을 만나면 함수가 종료된다.
		}

		printf("%f%c%f=%f\n", fDataA, cOp, fDataB, fResult);
	}
}
//세균은 10마리를 배양하고 4시간 이후에 세균의 수는?
//세균은 1시간마다 2배씩 증가한다.
//데이터: 세균수,시간
//알고리즘: 세균수*2, 1시간마다, 100마리 이상이될때까지
//1.데이터와 알고리즘을 분리한다.
//2.데이터는 변수 알고리즘은 연산,반복,조건 등이 조합된다.
//3.반복되는 경우는 먼저 반복하고 정답을 출력한다.
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

//4.반복되는 규칙성을 찾아서 무한반복을 돌린후 반복된 과정을 모두 확인한다.
//(프로그래머가 아니라면 여기서 마쳐도 무방함. 그러나 정치질(약점잡아 늘어지기)에 희생량이 될수있음)

void BateriaMain()
{
	int nBateria = 10;
	int nTime = 0;

	//while (true)
	while(nBateria < 100)//종료조건에 반대되는 조건을 반복문의 종료조건으로 설정한다.
	{
		nBateria = nBateria * 2;//20
		nTime = nTime + 1;
		printf("Bateria:%d Time:%d\n", nBateria, nTime);
		//if (nBateria >= 100) break;
	}
}

//(세균:변수) 10마리를 배양하여 (10시간후:조건)의 세균수를 구하여라.
//이때, 세균이 (1시간 마다 4배)찍 증가한다 
//세균수:10 //시간:0  //세균수*=4
void BateriaCountMain()
{

	int nBateria = 10;//10
	int nTime = 0;//0

	////코드는 비교적 간단하지만 숙달하기전에는 코드작성자체가 어려울수있음.
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
	//OpTestMain();
	//CalcultorMain();
	//CalcultorWhileMain();
	BateriaCountMain();
}
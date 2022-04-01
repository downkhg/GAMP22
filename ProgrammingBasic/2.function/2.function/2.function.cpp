#include <stdio.h>
#define PI 3.141592 //기호상수: 컴파일 시에 기호가있는곳에 해당 값을 넣어줌.

//함수(Function): 어떠한 기능이나 연산을 하나의 단위로 묶어 쉽게 사용하도록 제공하는 것.
//함수의 선언: 이러한 함수가 있다는 것을 컴파일러에게 미리 알림. 함수의 선언을 이용하면 함수의 핵심내용만 이해하고 사용 할 수 있다.
//사용자정의 함수: 사용자가 기능을 직접 만들어서 제공하는 함수.
int Sum(int a, int b); //두수의 덧셈을 구하는 함수.
float CircleArea(float rad); //원의 반지름을 입력하면 원의 넓이를 구하는 함수.
void ASCIICodeCheck(); //아스키코드의 값 128개를 확인하여 출력하는 함수.
float ArrivalTimeSec(float dist, float speed); //거리와 속도를 넣으면 걸린시간을 구하는 함수.
char GradeCheck(int nScore); //점수를 넣으면 학점을 알려주는 함수.
float Caculator(float fDataA, float fDataB, char cOp); //두수와 연산자를 넣으면 계산해주는 함수(사칙연산만 가능)
void CaculatorLoofMain(); //두수를 계산하는 계산기
void FunctionTestMain();  //위 함수들의 사용방법을 테스트하는 함수.

//F12: 함수의 정의로 이동
void main()
{
	//CaculatorLoofMain();
	FunctionTestMain();
}

//함수의 정의: 위에서 선언된 함수의 구체적인 내용을 만들어주는 것.
//두수의 덧셈을 구하는 함수. //<-자동완성시에 함수의 기능을 주석으로 설명가능함.
int Sum(int a, int b)
{
	int c = a + b;
	return c;
}

//원의 반지름을 입력하면 원의 넓이를 구하는 함수.
float CircleArea(float rad)
{
	float area;
	area = rad * rad * PI; //area = rad * rad * 3.141592; //컴파일될때 이런식으로 치환된다.
	return area;
}

//아스키코드의 값 0~128을 확인하여 출력하는 함수.
void ASCIICodeCheck()
{
	for (int i = 0; i < 128; i++)
	{
		printf("%d:%c,", i, i);
		if (i % 12 == 0) printf("\n");
	}
}

//거리와 속도를 입력하면 도착하는 시간을 계산하는 함수.
float ArrivalTimeSec(float dist, float speed)
{
	float time = dist / speed;
	return time;
}

//점수를 넣으면 학점을 알려주는 함수.
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

//두수와 연산자를 넣으면 계산해주는 함수(사칙연산만 가능)
float Caculator(float fDataA, float fDataB, char cOp) //리턴값 함수의이름(매개변수....)
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
		return -1.0f; //리턴을 만나면 함수는 종료된다.
	}

	return fResult; //함수가 종료될때 함수밖으로 내보낼 값.
}

//계산기 만들기
//1. 계산기 -> (숫자:변수:정수?실수!)와 (연산자:변수:문자)를 (입력:scanf)하면 그(결과:변수:실수)를 출력하는 기계.
//2. 연산자는 사칙연산만 가능하다(+,-,*,/)
//3. 연산을 하기위해서 최소 2개의 변수가 필요하므로 2개만 사용한다.
//4. 계산을 종료할때까지 (반복)해서 결과를 입력하고, 확인할수있다.
//데이터: 숫자A, 숫자B, 연산자, 결과
//알고리즘: 숫자와 연산자를 입력받고, 
//		    사칙연산이 가능한 계산함수를 호출하고, 필요한 값을 넣어서 원하는 리턴받은 값과 입력된값들을 출력한다.
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
	//함수에 입력값을 넣으면 해당하는 결과를 반환하는 함수
	printf("10+20 = %d\n", Sum(10, 20));
	printf("radius:5 area:%f\n", CircleArea(5.0f));
	printf("ArrivalTime:%fs\n", ArrivalTimeSec(100, 10));
	//호출하면 특정기능을 수행하는 함수
	ASCIICodeCheck();
}
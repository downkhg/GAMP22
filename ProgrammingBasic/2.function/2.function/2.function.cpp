#include <stdio.h> //라이브러리: 필요한 기능(함수)을 제공하는 것. 
//1.함수는 무엇일까? 왜 필요할까? 
//1)계산식을 만들어 재활용한다. 
//2)반복적인 코드를 나타면서 직관적으로 이해 할 수 있다.
//3)매개변수를 활용하여 함수 안에 값을 전달하고, 
//4)그 값으로 계산된 결과를 리턴을 이용하여 함수 밖으로 내보낸다.
//2.함수의 선언은 왜 필요한가?
//보기편함. 컴파일러가 위에서 부터 실행되기때문에 그함수의 기본적인 정보는 알아야만 아래 함수에서 호출가능하기때문입니다.

//라이브러리함수: 사용자가 정의하지않고 기본으로 제공되는 함수 
// ex) stdio.h -> scanf,printf stdlib.h -> srand, rand
//사용자 정의함수: 사용자가 함수의 내용을 만들어서 제공하는 함수.
//함수의 선언: 컴파일러에게 이러한 함수가 있다는 것을 알림.
void FunctionTestMain();
void CaculatorLoofMain();

//리턴타입 함수명(매개변수...)
int Sum(int a, int b);
float CircleArea(int rad);
void ASCIICodeCheck(); //정의로 이동:F12
float ArrivalTimeSec(float dist, float speed);
char GradeCheck(int nScore);
float Caculator(float fDataA, float fDataB, char cOp);

void main() //1
{
	//F9: 브레이킹 포인트 //F5: 디버거모드로 실행
	//F11: 함수안으로 이동 //F10: 함수단위에서 1줄 씩 이동
	FunctionTestMain();//함수의 호출 //2
	CaculatorLoofMain();//101
}//109

//함수의 정의: 선언된함수의 내용을 만드는 것.
//두수를 더하는 함수
int Sum(int a, int b)
{
	int c = a + b;//4
	return c;//5
}
//원의 면적구하기.(단, 면적은 반지름제곱*원주율(3.141592)이다.)
float CircleArea(int rad)
{
	const float pi = 3.141592;//상수변수: 초기화된 값을 변경할 수 없는 변수. //7
	float area; //8
	area = rad * rad * pi; //area = rad * rad * 3.141592; //9 //컴파일될때 이런식으로 치환된다.
	return area; //10
}
//0~128
void ASCIICodeCheck()
{
	for (int i = 0; i <= 128; i++) //19 //23
	{
		printf("%d:%c,", i, i); //20 //24
		if (i % 12 == 0) //21 //25 
			printf("\n"); //22
	} //100
}

//거리와 속도를 입력하면 도착시간을 계산하는 함수.
float ArrivalTimeSec(float dist, float speed)
{
	float time = dist / speed; //12
	return time; //13
}

//점수를 입력받아서 학점을 돌려주는 함수
char GradeCheck(int nScore)
{
	char cGrade;//15

	if (nScore >= 90)//16
	{
		cGrade = 'A';//17
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

	return cGrade;//18
}

//계산기 만들기
float Caculator(float fDataA, float fDataB, char cOp)
{
	float fResult; //108

	if (cOp == '+')//+ //109 //x
		fResult = fDataA + fDataB;// 1+1 = 2 //110
	else if (cOp == '-') //110
		fResult = fDataA - fDataB;
	else if (cOp == '*') //111
		fResult = fDataA * fDataB;
	else if (cOp == '/') //112
		fResult = fDataA / fDataB;
	else //113
	{
		printf("%c is not Support!\n", cOp); //x is not support!
		return -1.0f; //리턴을 만나면 함수는 종료된다.
	}

	return fResult; //111
}

//계산기 만들기
//1. 계산기 -> (숫자:변수:정수?실수!)와 (연산자:변수:문자)를 (입력:scanf)하면 그(결과:변수:실수)를 출력하는 기계.
//2. 연산자는 사칙연산만 가능하다(+,-,*,/)
//3. 연산을 하기위해서 최소 2개의 변수가 필요하므로 2개만 사용한다.
//4. 계산을 종료할때까지 (반복)해서 결과를 입력하고, 확인할수있다.
//데이터: 숫자A, 숫자B, 연산자, 결과
//알고리즘: 숫자와 연산자를 입력받고, 
//		    두수를 사칙연산하는 함수를 호출하고 그결과를 출력한다.
void CaculatorLoofMain()
{
	float fDataA, fDataB, fResult; //두값을 입력하는 실수형변수와 정답을 입력하는 변수를 만들었다. 초기화 되지않았으므로 모든 변수의 값은 알수없다. //102
	char cOp = 0; //연산자를 입력받기위해서 정수형변수를 선언하고 초기화지 않았다. //103

	while (cOp != 'x') //104
	{
		printf("ex) 1+1 exit)?x?>> "); //105
		scanf("%f%c%f", &fDataA, &cOp, &fDataB); //106 //1+1

		fResult = Caculator(fDataA, fDataB, cOp); //107 

		printf("%f%c%f=%f\n", fDataA, cOp, fDataB, fResult); //108 
	}
}

void FunctionTestMain()
{
	//특정연산을 하고 결과값을 반환하는 함수.
	printf("10+20 = %d\n", Sum(10, 20));//3
	printf("radius:5 Area:%f\n", CircleArea(5));//6
	printf("Distacne:100 Speed:10 Sec:%f\n", ArrivalTimeSec(100, 10));//11
	printf("Score:100 Gread:%c\n", GradeCheck(100));//14
	//특정 내용을 출력해주고 끝나는 함수.
	ASCIICodeCheck(); //17
}
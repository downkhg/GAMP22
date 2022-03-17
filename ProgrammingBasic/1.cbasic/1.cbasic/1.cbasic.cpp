#include <stdio.h>//표준입출력 라이브러리

//두수를 더해서 결과값을 구하는 프로그램.
void SumMain()//사용자정의 함수: 어떤기능을 사용자가 만든 함수.
{
	//변수: 데이터를 담는 상자.
	int a = 10;
	int b = 20;
	int c = a + b;
	printf("%d + %d = %d", a, b, c);//라이브러리 함수
}
//원의 면적구하기
void CircleAreaMain()
{

}

void main()//프로그램에서 실행되었을때 os에서 불러주는 함수
{
	//Ctrl+F5
	printf("Hello World!!!\n");//\n: 줄바꿈문자.
	//함수의 호출: 함수를 사용한다.
	SumMain();//세미콜론: 문장마지막을 나타내는 기호
	CircleAreaMain();
}
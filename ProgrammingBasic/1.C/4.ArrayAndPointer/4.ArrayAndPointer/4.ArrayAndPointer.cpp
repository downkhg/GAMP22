#include <stdio.h>
#include <string.h>
//전위연산자:++data,후위연산자:data++ 
//데이터의 값이 전위연산자와 후위 연산자의 차이점을 확인하는 프로그램
//데이터: 데이터2개가 필요하다 -> nDataA,nDataB -> 정수
//알고리즘: nDataB = ++nDataA, nDataB = nDataA++, ?
void IncDecTestMain()
{
	int nDataA = 10, nDataB; //10, ?
	nDataB = nDataA; //10
	printf("1.nDataA/B:%d/%d\n", nDataA, nDataB);
	nDataB = ++nDataA; //11/11 ->  전위연산자: 대입연산자보다 우선순위가 높으므로, 증감하고, 값이 변수에 대입된다.
	printf("2.nDataA/B:%d/%d\n", nDataA, nDataB);
	nDataB = nDataA++; //12/12 -> 12/11 -> 후위연산자는 대입연산자보다 우선순위가 낮으므로, 증감전 값이 변수에 대입된다.
	printf("3.nDataA/B:%d/%d\n", nDataA, nDataB);
}

//포인터, 포인터와 함수, 배열, 2차원배열
//문제: 정수와 실수의 데이터를 선언하고, 
//선언된 데이터를 각 실수와 정수의 포인터에 저장하여,       
//모든 변수들 에서 연산 할 수 있는 모든 결과를 출력하라.
// 
//포인터: 주소값을 저장하는 변수.
void PointerTestMain()
{
	int nData = 10;
	float fData = 3.14f;
	int* pIntData = &nData;
	float* pFloatData = &fData;

	printf("nData[%d]:%d\n",&nData,nData);
	printf("pIntData[%d]:%d\n", *pIntData, pIntData);

	printf("fData[%d]:%f\n", &fData, fData);
	printf("pFloatData[%f]:%d\n", *pFloatData, pFloatData);
}
//값에의한호출: 매개변수에 값을 복사해서 넘겼을때
void SwapVal(int a, int b)
{
	printf("SwapVal[%d/%d]:%d,%d\n", &a, &b, a, b);
	int temp = a;
	b = a;
	temp = b;
}

//참조(포인터)에의한 호출: 매개변수에 주소값을 전달하였기 때문에 
///(포인터가 가진 주소값이 가진 변수)의 값을 변경한다.
void SwapPtr(int* pA, int* pB)
{
	printf("SwapPtr[%d/%d]:%d,%d\n", &pA, &pB, pA, pB);
	int temp = *pA;
	*pB = *pA;
	temp = *pB;
}
//참조자를 이용하여 매개변수로 전달받은 값을 변경.
//기본적인 원리는 포인터로 이해하더라도 실제 코드를 사용할때는 
//참조자를 활용하는것이 활용하기 쉽다.
void SwapRef(int& a, int& b)
{
	printf("SwapRef[%d/%d]:%d,%d\n", &a, &b, a, b);
	int temp = a;
	b = a;
	temp = b;
}

void FunctionAndPointerMain()
{
	int nDataA = 10;
	int nDataB = 20;
	printf("Val DataA/B[%d/%d]:%d,%d\n",&nDataA,&nDataB,nDataA,nDataB);
	SwapVal(nDataA, nDataB);//매개변수가 변경되고 전달된 변수의 값이 변경되지는 않는다.
	printf("SwapVal: DataA/B[%d/%d]:%d,%d\n", &nDataA, &nDataB, nDataA, nDataB);
	SwapPtr(&nDataA, &nDataB);//매개변수가 가진 주소값을 가진 변수의 값이 변경된다.
	printf("Ptrl: DataA/B[%d/%d]:%d,%d\n", &nDataA, &nDataB, nDataA, nDataB);
	SwapRef(nDataA, nDataB); //매개변수에 전달된 변수의 값이 변경된다.
}
//배열: 변수를 메모리에 순서대로 만들어서 인덱스를 이용하여 접근 가능하게 한다.
//배열의이름은 주소값을 가지고 있으므로, 인덱스가 0인 이유가 주소값에 +0해야 원래 주소값이 나오기때문이다.
//포인터연산: 포인터의 주소값을 해당포인터가 저장할수있는 데이터타입의 크기만큼 증가한다. 예) char +1, int +4, double +8
//배열은 포인터를 활용하여 구현되어있다. 그러므로 크기를 할당할때 중간에 변경할수없으므로. 
//변수를 이용하여 배열의 크기를 만들수없고 상수를 이용해야만 한다.
void ArrayMain()
{
	const int nSize = 3;
	int arrScore[nSize];
	int arrSize = sizeof(arrScore) / sizeof(int);
	for (int i = 0; i < nSize; i++)
		arrScore[i] = 100 - i * 10;
	printf("arrScore:%d\n",arrScore);
	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]%d,", &arrScore[i], i, arrScore[i]);
	printf("\n");
	int* pScore = arrScore;
	for (int i = 0; i < nSize; i++)//0,1,2
		printf("[%d/%d]%d,", arrScore + i, i, *(arrScore + i));//배열이름+인덱스
	printf("\n");
	for (int i = 0; i < nSize; i++)
	{
		printf("[%d/%d]%d,", pScore, i, *pScore); //포인터 연산을할때마다 가르키는 주소값이 다르다.
		pScore++;//포인터연산
	}
	printf("\n");
	int arrCopyScore[nSize];
	//배열의 인덱스로 복사를 하면 3번 반복해야한다.
	for (int i = 0; i < nSize; i++)
		arrCopyScore[i] = arrScore[i];
	//메모리 복사를 이용하면 메모리를 일정크기만큼 복사하므로 빠르다.
	memcpy_s(arrCopyScore, sizeof(arrCopyScore), arrScore, sizeof(arrCopyScore));
}
//4x3크기의 배열을 만들고,
//크기가 12인 1차원배열을 만들어 각각 이중for문을 이용하여 값을 저장하고, 
//주소값,인덱스,원소의 값출력하기
void Array2DTestMain()
{
	const int nSizeX = 4;
	const int nSizeY = 3;
	const int nSize = nSizeY * nSizeX;
	int arr2DArray[nSizeY][nSizeX];
	int arrFake2DArray[nSize];
	for (int y = 0; y < nSizeY; y++)//0,1,2,3
	{
		for (int x = 0; x < nSizeX; x++)//0,1,2
		{
			arr2DArray[y][x] = y * nSizeY + x;//[0][0]:0 //[0][1]:1 //[0][2]:2 //[0][3]:3 ////[1][0]:0 //[1][1]:4 //[1][2]:5 //[1][3]:6 .....
			printf("%d[%d,%d]:%d,", &arr2DArray[y][x], y, x, arr2DArray[y][x], arr2DArray[y][x]);
		}
		printf("\n");
	}

	for (int y = 0; y < nSizeY; y++)//0,1,2,3
	{
		for (int x = 0; x < nSizeX; x++)//0,1,2
		{
			int idx = y * nSizeY + x;
			arrFake2DArray[idx] = idx;
			printf("%d[%d,%d]:%d,", &arrFake2DArray[idx], y, x, arrFake2DArray[idx], arrFake2DArray[idx]);
		}
		printf("\n");
	}
}
//PrintString(출력할내용의 제목,출력할 문자열,인덱스출력여부)
void PrintString(const char* msg, const char* str, bool isIdx)
{
	int idx = 0;
	printf("%s", msg);
	while (str[idx] != '\0')//%s는 문자열끝 전까지만 출력하도록 작동한다.
	{
		if(isIdx) printf("[%d]%c,", idx, str[idx]);
		else printf("%c,", idx, str[idx]);
		idx++;
	}
	printf("\n");
}

//문자열을 이용할때 남는 배열의 크기는 어떻게될까?
//문자열은 적당한 크기안에 저장해서 변경해야하므로, 문자열끝을 알아야 출력을 그만 할수있다.
//%s를 이용하면 널문자전까지만 출력을 하므로 출력시에 문자열에 필요한부분만 볼수있다.
//"문자열"를 이용하여 저장하면, 문장 제일 끝에 자동으로 널문자가 할당된다.
void StringTestMain()
{
	const int nSize = 16;
	char strWord[nSize] = "gameprograming";//24 - 14 = 10 //남은 10칸은 어떻게 될까?
	//문자열끝이없는 문자는 어떻게 출력될까?
	strWord[0] = 't';
	strWord[1] = 'e';
	strWord[2] = 's';
	strWord[3] = 't';
	strWord[4] = 0;// '\0';//널문자: 문자열의 끝을 알리는 문자: '\0'(== 0)
	printf("for:");
	for (int i = 0; i < nSize; i++)
		printf("%c",strWord[i]);
	printf("\n");
	printf("string: %s\n", strWord);
	PrintString("while:", strWord, false);
	printf("\n");
}

void FullNameMakerMain()
{
	char strLastName[8] = "k";
	char strFirstName[8] = "hg";
	char strFullNameKr[16];
	char strFullNameEn[16];

	strcpy(strFullNameKr, strLastName);
	strcat(strFullNameKr, strFirstName);
	printf("Kr(%s, %s)[%d]: %s\n",strFirstName, strLastName, strlen(strFullNameKr), strFullNameKr);
	PrintString("krWihle", strFullNameKr,true);
	sprintf(strFullNameEn,"%s %s",strFirstName,strLastName);
	printf("En(%s, %s)[%d]: %s\n", strFirstName, strLastName, strlen(strFullNameEn), strFullNameEn);

	int nResult = strcmp(strLastName, strFirstName); //문자열의 길이차이를 반환한다. 같으면 0을 반환함.
	if(!strcmp(strLastName, strFirstName)) //일반적으로 문자열비교시 다음과 같이 활용한다.
	//if (!nResult)
	{
		printf("%d: %s == %s\n", nResult,strLastName,strFirstName);
	}
	else
	{
		printf("%d: %s != %s\n", nResult, strLastName, strFirstName);
	}
}
/*
정답:GAME
Q: _ _ _ _
A : G
Q : G _ _ _
......(중략)
A : GA_E
Q : M
A : GAME
*/
void HangManGameMain()
{

}

void main()
{
	//PointerTestMain();
	//FunctionAndPointerMain();
	//ArrayMain();
	//Array2DTestMain();
	FullNameMakerMain();
	//StringTestMain();
}
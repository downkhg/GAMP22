#include <stdio.h>
#include <stdlib.h>
//배열을 입력받은 값을 이용하여 메모리크기를 변경하도록 만드는 프로그램.
//정적할당(스택): 컴파일전단계에 메모리의 사용 및 크기가 결정되는 것. -> 변수이름을 부여가능하다. 컴파일 전단계에서 메모리의 생성주기가 결정된다.
//동적할당(힙): 프로그램 실행중에 메모리가 할당되는 것.  -> 주소값만 으로 구별가능하다, 포인터를 이용하여 동적할된 메모리의 주소값을 저장한다. 메모리의 동적할당을 직접해제해야한다.
//가비지컬렉션: 프로그램에 동적할당된 메모리를 관리해주는 것. (C#,Java..)
//동적할당된 메모리가 관리되는 언어. 
//C/C++: 동적 메모리를 직접 관리해야하는 언어. 스마트포인터(C++): 동적할당된 메모리를 자동으로 해제해주는 포인터.
void DaynamicAllocateTestMain()
{
	int nSize;
	int* pArray = NULL;//포인터:

	printf("ArraySize:");
	scanf_s("%d", &nSize);
	//동적할당될 배열의 크기를 계산하여 할당하고 사용할 타입에 맞게 캐스팅한다.
	//배열의 포인터연산을 이용하려면, 변수의 타입을 알아야한다.
	pArray = (int*)malloc(nSize * sizeof(int));

	if (pArray != NULL)
	{
		for (int i = 0; i < nSize; i++)
		{
			pArray[i] = i * 10;
			printf("[%d]%d,",i,pArray[i]);
		}
	}
	//동적할당해제: 동적할당은 컴파일러에서 스케쥴링이 불가능하므로, 
	//프로그래머가 메모리를 할당해제한다.
	free(pArray);
}

void RellocateTestMain()
{
	int nSize;
	int* pArray = NULL;//포인터:

	printf("ArraySize:");
	scanf_s("%d", &nSize);
	//동적할당될 배열의 크기를 계산하여 할당하고 사용할 타입에 맞게 캐스팅한다.
	//배열의 포인터연산을 이용하려면, 변수의 타입을 알아야한다.
	pArray = (int*)malloc(nSize * sizeof(int));
	printf("pArray:%d\n", pArray);
	if (pArray != NULL)
	{
		for (int i = 0; i < nSize; i++)
		{
			pArray[i] = i * 10;
			printf("[%d]%d,", i, pArray[i]);
		}
	}
	printf("\n");
	int nResize;
	printf("Resize:");
	scanf_s("%d", &nResize);
	nSize += nResize;
	//동적할당된 메모리의 크기를 변경하는 함수
	//동적할당된 메모리의 기본크기에서 늘릴수없다면, 새로운 메모리를 생성하고 복제한다.
	pArray = (int*)realloc(pArray, nSize * sizeof(int));
	printf("pArray:%d\n", pArray);
	//pArray[nSize] = nSize * 10;
	if (pArray != NULL)
	{
		for (int i = 0; i < nSize+1; i++)
		{
			//pArray[i] = i * 10;
			printf("[%d]%d,", i, pArray[i]);
		}
	}
	printf("\n");
	//동적할당해제: 동적할당은 컴파일러에서 스케쥴링이 불가능하므로, 
	//프로그래머가 메모리를 할당해제한다.
	free(pArray);
}
//메모리의 개념을 몰라도 이해할수있을 정도로 표현이 쉽다.
void NewDeleteMain()
{
	int nSize = 10;
	int* pArray = new int[nSize];
	int* pIntData = new int;
	printf("pArray:%d\n", pArray);
	if (pArray != NULL)
	{
		for (int i = 0; i < nSize + 1; i++)
		{
			//pArray[i] = i * 10;
			printf("[%d]%d,", i, pArray[i]);
		}
	}
	printf("pIntData:%d\n",pIntData);
	delete[] pArray;
	delete pIntData;
}

void main()
{
	//DaynamicAllocateTestMain();
	RellocateTestMain();
}
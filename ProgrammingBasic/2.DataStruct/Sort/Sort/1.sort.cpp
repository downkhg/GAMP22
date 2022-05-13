#include <stdio.h>

void Swap(int& a, int& b)
{
	printf("Swap(%d,%d)\n",a,b);
	int temp = a;
	a = b;
	b = temp;
}

int FindMinIdx(int startIdx, int arrData[], int size)
{
	int nMinIdx = startIdx;
	for (int i = startIdx; i < size; i++)
	{
		if (arrData[nMinIdx] > arrData[i])
		{
			nMinIdx = i;
			printf("MinIdx[%d]%d<->[%d]%d\n", nMinIdx, arrData[nMinIdx], i, arrData[i]);
		}
	}
	return nMinIdx;
}

void InsertSortMain()
{
	//                0,1,2,3,4,5,6,7,8
	int arrData[] = { 8,1,7,4,2,3,9,5,6 };
	int nSize = sizeof(arrData) / sizeof(int);
	
	int nSelIdx = 0;
	
	for (nSelIdx = 0; nSelIdx < nSize-1; nSelIdx++)
	{
		int nStartIdx = nSelIdx;
		int nMinIdx = FindMinIdx(nStartIdx, arrData, nSize);
		/*int nMinIdx = nStartIdx;
		for (int i = nSelIdx; i < nSize; i++)
		{
			if (arrData[nMinIdx] > arrData[i])
			{
				nMinIdx = i;
				printf("MinIdx[%d]%d<->[%d]%d", nMinIdx,arrData[nMinIdx], i, arrData[i]);
			}
		}*/
		
		if (nSelIdx != nMinIdx)//최소값과 선택값이 같다면 변경할 필요가없다.
		{
			printf("SwapIdx[%d]:%d<->[%d]%d\n", nSelIdx, arrData[nSelIdx], nMinIdx, arrData[nMinIdx]);
			Swap(arrData[nSelIdx], arrData[nMinIdx]);
			printf("SwapIdx[%d]:%d<->[%d]%d\n", nSelIdx, arrData[nSelIdx], nMinIdx, arrData[nMinIdx]);
		}
		else
			printf("Min == Sel\n");
	}
	
	for (int i = 0; i < nSize; i++)
	{
		printf("%d,",arrData[i]);
	}
	printf("\n");
}

void main()
{
	InsertSortMain();
}
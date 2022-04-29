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
	int arrData[] = { 8,1,7,4,2,3,9,5,6 };
	int nSize = sizeof(arrData) / sizeof(int);
	
	int nSelIdx = 0;
	
	for (nSelIdx = 0; nSelIdx < nSize-1; nSelIdx++)
	{
		int nStartIdx = nSelIdx + 1;
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
		printf("SwapIdx[%d]<->[%d]\n",nSelIdx, nMinIdx);
		Swap(arrData[nSelIdx], arrData[nMinIdx]);
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
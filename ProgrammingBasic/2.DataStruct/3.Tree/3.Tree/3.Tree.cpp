/*##################################
이진트리(C언어 수업용)
파일명: BinaryTree.cpp
작성자 : 김홍규(downkhg@gmail.com)
마지막수정날짜 : 2022.03.04
버전 : 1.01
###################################*/
#include <stdio.h>

using namespace std;

struct SNode {
	int nData;
	SNode* pLeft;
	SNode* pRight;
};

SNode* CreateNode(int data)
{
	SNode* pTemp = new SNode;
	pTemp->nData = data;
	pTemp->pLeft = NULL;
	pTemp->pRight = NULL;
	return pTemp;
};
bool MakeLeft(SNode* pParent, SNode* pChilde)
{
	if (pParent == NULL)//0x01 == NULL -> F
		return false;
	pParent->pLeft = pChilde;
	return true;
};
bool MakeRight(SNode* pParent, SNode* pChilde)
{
	if (pParent == NULL)
		return false;
	pParent->pRight = pChilde;
	return true;
};

void Traverse(SNode* pNode)
{
	if (pNode == NULL) return; //N == N -> T
	//printf("%d\n", pNode->nData); //전위
	Traverse(pNode->pLeft);
	//printf("%d\n", pNode->nData); //중위
	Traverse(pNode->pRight);
	printf("%d\n", pNode->nData); //후위
}

void Print(SNode* pSeed)
{
	Traverse(pSeed);
}

void MakeMinHeapTree(SNode* pParent, SNode* pNode)
{
	static int nLv = 0;
	nLv++;
	printf("MakeMinHeap[%d]:%d/%d\n", nLv, pParent->nData, pNode->nData);
	if (pParent->pLeft == NULL)
	{
		pParent->pLeft = pNode;
		printf("%d MakeLeft!\n",pNode->nData);
		return;
	}
	else if (pParent->pRight == NULL)
	{
		pParent->pRight = pNode;
		printf("%d MakeRiht!\n", pNode->nData);
		return;
	}
	else
	{
		MakeMinHeapTree(pParent->pLeft, pNode);
	}
}

void main()
{
	SNode* pSeed = NULL;

	SNode* pNodes[5];
	for (int i = 0; i < 5; i++)
	{
		pNodes[i] = CreateNode((i + 1) * 10);
		if (pSeed == NULL)
			pSeed = pNodes[i];
		else
			MakeMinHeapTree(pSeed, pNodes[i]);
	}
	/*
	SNode* pParent = CreateNode(10);
	SNode* pLeft = CreateNode(20);
	SNode* pRight = CreateNode(30);
	SNode* pD = CreateNode(40);
	SNode* pE = CreateNode(50);//

	MakeLeft(pParent, pLeft);
	MakeRight(pParent, pRight);

	MakeLeft(pLeft, pD);
	MakeRight(pLeft, pE);

	pSeed = pParent;
	*/
	Print(pSeed);
	printf("##### End Main ####");
}
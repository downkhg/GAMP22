/*##################################
이진트리(C언어 수업용)
파일명: Graph.cpp
작성자 : 김홍규(downkhg@gmail.com)
마지막수정날짜 : 2022.05.11
버전 : 1.01
###################################*/
#include <stdio.h>
#include <list>

using namespace std;
//노드에 멤버는 필요에 따라 추가 할수있다.
struct SNode {
	char cData;
	list<SNode*> listAdj;
	bool bVisit;
};

SNode* CreateNode(char data)
{
	SNode* pTemp = new SNode;
	pTemp->cData = data;
	pTemp->bVisit = false;
	return pTemp;
};

bool MakeAdjcency(SNode* pParent, SNode* pChilde)
{
	if (pParent == NULL)//0x01 == NULL -> F
		return false;
	pParent->listAdj.push_back(pChilde);
	return true;
};
//이 방문방법은 BFS에 가깝지만 문제가있음.
void Traverse(SNode* pNode)
{
	if (pNode == NULL) return; //N == N -> T
	//Traverse(pNode);
	if (pNode->bVisit == false)
	{
		printf("%c\n", pNode->cData);
		list<SNode*>::iterator  it;
		for (it = pNode->listAdj.begin(); it != pNode->listAdj.end(); it++)
		{
			SNode* pAdj = *it;
			Traverse(pAdj);
		}
		pNode->bVisit = true;
	}
}

void TraverseDFS(SNode* pNode, bool bPrint = true)
{
	if (pNode->bVisit == false)
	{
		if (bPrint) printf("%c,", pNode->cData);//A//B
		if (pNode->bVisit == false)
		{
			pNode->bVisit = true;

			if (!pNode->listAdj.empty())
			{
				list<SNode*>::iterator  it;
				for (it = pNode->listAdj.begin(); it != pNode->listAdj.end(); it++)
				{
					TraverseDFS(*it);//F
				}
			}
		}
	}
}

void DFS(SNode* pNode, bool bPrint = true)
{
	TraverseDFS(pNode, bPrint);
	printf("\n");
}

void Print(SNode* pSeed)
{
	Traverse(pSeed);
}

enum E_NODE { A, B, C, D, E, F, G,H,MAX };

void main()
{
	SNode* pNodes[MAX];
	char cNodeData = 'A';
	for (int i = 0; i < MAX; i++)
	{
		pNodes[i] = CreateNode(cNodeData);
		cNodeData++;
	}
	
	MakeAdjcency(pNodes[A], pNodes[B]);
	MakeAdjcency(pNodes[A], pNodes[C]);
	MakeAdjcency(pNodes[B], pNodes[D]);
	MakeAdjcency(pNodes[B], pNodes[F]);
	MakeAdjcency(pNodes[C], pNodes[B]);
	MakeAdjcency(pNodes[D], pNodes[H]);
	MakeAdjcency(pNodes[E], pNodes[C]);
	MakeAdjcency(pNodes[E], pNodes[H]);
	MakeAdjcency(pNodes[F], pNodes[D]);
	MakeAdjcency(pNodes[F], pNodes[G]);
	MakeAdjcency(pNodes[F], pNodes[H]);
	MakeAdjcency(pNodes[G], pNodes[E]);
	MakeAdjcency(pNodes[G], pNodes[F]);
	MakeAdjcency(pNodes[G], pNodes[H]);

	//Print(pNodes[A]);
	DFS(pNodes[A]);
	printf("##### End Main ####");
}
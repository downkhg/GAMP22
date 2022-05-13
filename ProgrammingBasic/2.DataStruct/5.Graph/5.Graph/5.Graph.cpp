/*##################################
이진트리(C언어 수업용)
파일명: Graph.cpp
작성자 : 김홍규(downkhg@gmail.com)
마지막수정날짜 : 2022.05.11
버전 : 1.01
###################################*/
#include <stdio.h>
#include <list>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
//노드에 멤버는 필요에 따라 추가 할수있다.
struct SNode {
	char cData;
	list<SNode*> listAdj;
	bool bVisit;
	list<SNode*>::iterator itAdj;
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
	if(pParent->listAdj.size() == 1)
		pParent->itAdj = pParent->listAdj.begin();
	return true;
};

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

SNode* VisitStackDFS(SNode* pNode, stack<SNode*>& visit)
{
	SNode* pNext = NULL;
	if (pNode)
	{
		if (pNode->bVisit == false)
		{
			//cout << "Visit:" << pNode->cData << endl;
			printf("%c,",pNode->cData);
			visit.push(pNode);
			pNode->bVisit = true;
		}
		else
		{
			//cout << "Revisit:" << pNode->cData << endl;
		}
		//list<SNode*>::iterator it = pNode->itChild;
		if (pNode->listAdj.size() > 0)//0
		{
			if (pNode->itAdj != pNode->listAdj.end())
			{
				pNext = *pNode->itAdj;
				while (pNext != NULL && pNext->bVisit == true)
				{
					if (pNode->itAdj != pNode->listAdj.end())
					{
						//cout << "Revisit!" << (*pNode->itChild)->cData << endl;
						pNext = *pNode->itAdj;
						pNode->itAdj++;
					}
					else
					{
						//cout << "Visit Complete!" << pNode->cData << endl;
						pNext = NULL;
					}
				}
			}
		}
	}
	else
	{
		//cout << "Visit Complete! " << visit.top()->cData << endl;
		visit.pop();
		if (!visit.empty())
			pNext = visit.top();
	}
	return pNext;
}

void TraverDFSStack(SNode* pNode)
{
	printf("DFS(Stack):");
	stack<SNode*> visit;
	do
	{
		if (!pNode)//A //N
		{
			//cout << "Visit Complete! " << visit.top()->cData << endl;
			visit.pop();
			if (!visit.empty())
				pNode = visit.top();
		}
		pNode = VisitStackDFS(pNode, visit);
	} while (!visit.empty());
	printf("\n");
}

bool VisitBFS(SNode* pNode, queue<SNode*>& visit)
{
	if (pNode)
	{
		if (pNode->bVisit == false)
		{
			printf("%c.",pNode->cData);
			//cout << "Visit:" << pNode->cData << endl;
			pNode->bVisit = true;
			visit.push(pNode);
			return true;
		}
		else
		{
			//cout << "Revisit! " << visit.front()->cData << endl;
		}
	}
	return false;
}

void TraverBFS(SNode* pNode)
{
	printf("BFS:");
	queue<SNode*> visit;
	do
	{
		if (!visit.empty())//A
			pNode = visit.front();
		VisitBFS(pNode, visit);//A

		list<SNode*>::iterator it = pNode->listAdj.begin();
		for (; it != pNode->listAdj.end(); it++)
		{
			SNode* pNode = *it;
			VisitBFS(pNode, visit);//D,F
		}
		visit.pop();//B

	} while (!visit.empty());
	printf("\n");
}

void TraverDFS(SNode* pNode, bool bPrint = true)
{
	printf("DFS:");
	TraverseDFS(pNode, bPrint);
	printf("\n");
}

void TraverReset(SNode* pNodes[], int size)
{
	for (int i = 0; i < size; i++)
	{
		pNodes[i]->bVisit = false;
		pNodes[i]->itAdj = pNodes[i]->listAdj.begin();
	}
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

	TraverDFS(pNodes[A],true);
	TraverReset(pNodes, MAX);
	TraverBFS(pNodes[A]);
	TraverReset(pNodes, MAX);
	TraverDFSStack(pNodes[A]);
	TraverReset(pNodes, MAX);
	printf("##### End Main ####");
}
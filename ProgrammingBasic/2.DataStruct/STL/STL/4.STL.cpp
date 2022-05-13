/*##################################
STL(�ڷᱸ�� ������)
���ϸ�: STL_empty.cpp
�ۼ��� : ��ȫ��(downkhg@gmail.com)
������������¥ : 2022.03.09
���� : 1.05
###################################*/
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>//hash_map -> unordered_map: vs2019���� ����
using namespace std;
//����: �����迭
//0.�迭�� �����Ͱ� ����ɰ����� �̸� Ȯ���Ǿ��ִ�.
//1.�ε����� ���������� �����ϴ�.
//2.�� �ڷ�� �����Ϳ���(�ε���)�� ���� ����/���������� �����ϴ�.
//3.�迭�� ũ�⸦ ��Ÿ���߿� ���氡���ϴ�.
void VectorMain()
{
	vector<int> container(1);
	container[0] = 10;
	for (int i = 0; i < container.size(); i++)
		printf("%d:%d,", i, container[i]);//cout << i <<":"<<container[i] << ",";//i: 0 //10 //0:10,\n
	printf("\n");//cout << endl;
	container.resize(3);
	for (int i = 0; i < container.size(); i++)
		container[i] = 100 - i * 10;
	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << i << ":" << container[i] << ",";
	cout << endl;
	//1.�߰� 2.���� 3.���� 4.��λ���
	vector<int>::iterator it;//������
	for (it = container.begin(); it != container.end(); it++)
		cout << &*it << ":"<< *it << ",";
	cout << endl;
	container.push_back(100);//�迭�߰��� �迭��ü�� �����Ҽ����ִ�.
	for (it = container.begin(); it != container.end(); it++)
		cout << &*it << ":" << *it << ",";
	cout << endl;
	it = container.begin() + 2;
	cout << "find:";	
	it = find(container.begin(), container.end(), 70);
	if(it != container.end())
		cout << &*it<<":"<< *it << endl;
	cout << endl;
	container.insert(it, -20);//�迭 �߰�����
	for (it = container.begin(); it != container.end(); it++)
		cout << &*it << ":" << *it << ",";
	cout << endl;
}
//1.ũ�� 10���� ����. 100���� 10�� �����Ͽ� �� ������ ���� �����Ѵ�.
//2.ũ������ 5��
//3.�ǳ��� �߰� 0,-10
//4.ã�� 70
//5.����: 70�� -20
//5.1.80�̶�� ã�� ���� 70�̾ƴϹǷ� find�� ������ �ִ�?
//6.-20 �����, ��������
//7.������, ��λ���
void VectorTestMain()
{
	
	vector<int> container(10);
	for (int i = 0; i < container.size(); i++)
		container[i] = 100 - (10 * i);

	cout << "1.init(" << container.size() << "):";
	for (int i = 0; i < container.size(); i++)
		cout << i << ":" << container[i] << ",";
	cout << endl;

	container.resize(5);
	cout << "2.resize("<<container.size()<<"):";
	for (int i = 0; i < container.size(); i++)
		cout << i << ":" << container[i] << ",";
	cout << endl;

	container.push_back(0);
	cout << "3-1.push_back(0):";
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "["<< i << "]:" << container[i] << ",";
	cout << endl;

	container.push_back(-10);
	cout << "3-2.push_back(-10):";
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]:" << container[i] << ",";
	cout << endl;

	vector<int>::iterator itFind = find(container.begin(), container.end(), 70);
	if (itFind != container.end())
		cout <<"4.itFind["<<&(*itFind)<<"]:"<<*itFind << endl;

	vector<int>::iterator itInsert = container.insert(itFind, -20);
	cout << "5.insert:";
	vector<int>::iterator it;
	for (it = container.begin(); it != container.end(); it++)
		cout << &(*it) << ":" << *it << ",";
	cout << endl;

	//if (itFind != container.end()) //itFind�� ���������ʴ´�.
	//	cout << "itFind[" << &(*itFind) << "]:" << *itFind << endl;
	container.erase(itInsert);
	cout << "6-1.erase:";
	for (it = container.begin(); it != container.end(); it++)
		cout << &(*it) << ":" << *it << ",";
	cout << endl;
	cout << "6-2.ramdom iterator"<<endl;
	it = container.begin() + 3;
	if (it != container.end())
		cout <<"begin+3:"<< *it << endl;
	it = container.end() - 3;
	if (it != container.end())
		cout << "end+3:" << *it << endl;
	reverse(container.begin(), container.end());
	cout << "7-1.reverse:";
	for (it = container.begin(); it != container.end(); it++)
		cout << &(*it) << ":" << *it << ",";
	cout << endl;

	container.clear();
	cout << "7-2.clear:";
	for (it = container.begin(); it != container.end(); it++)
		cout << &(*it) << ":" << *it << ",";
	cout << endl;
}

//���Ḯ��Ʈ
//1.�����ʹ� �������ٸ� �����ϴ�.(����x)
//2.���Ḯ��Ʈ�� �߰�,����,������ O(1)�̴�.
//3.���Ḯ��Ʈ�� ����: ����, ȯ��, ���� stl�� ����Ʈ�� ��� �ش�Ǵ°�?
void ListMain()
{
	list<int> container(10);
	list<int>::iterator it;
	int i = 0;
	for (it = container.begin(); it != container.end(); it++)
	{
		*it = 100 - (10 * i);
		i++;
	}
	cout << "1.init(" << container.size() << "):";
	for (it = container.begin(); it != container.end(); it++)
		cout << &(*it) << ":" << *it << ",";
	cout << endl;

	container.resize(5);
	cout << "2.resize(" << container.size() << "):";
	for (it = container.begin(); it != container.end(); it++)
		cout << &(*it) << ":" << *it << ",";
	cout << endl;

	container.push_back(0);
	cout << "3-1.push_back(0):";
	for (it = container.begin(); it != container.end(); it++)
		cout << &(*it) << ":" << *it << ",";
	cout << endl;

	container.push_back(-10);
	cout << "3-2.push_back(-10):";
	for (it = container.begin(); it != container.end(); it++)
		cout << &(*it) << ":" << *it << ",";
	cout << endl;

	list<int>::iterator itFind = find(container.begin(), container.end(), 70);
	if (itFind != container.end())
		cout << "4.itFind[" << &(*itFind) << "]:" << *itFind << endl;

	list<int>::iterator itInsert = container.insert(itFind, -20);
	cout << "5.insert:";
	for (it = container.begin(); it != container.end(); it++)
		cout << &(*it) << ":" << *it << ",";
	cout << endl;

	//if (itFind != container.end()) //itFind�� ���������ʴ´�.
	//	cout << "itFind[" << &(*itFind) << "]:" << *itFind << endl;
	container.erase(itInsert);
	cout << "6.erase:";
	for (it = container.begin(); it != container.end(); it++)
		cout << &(*it) << ":" << *it << ",";
	cout << endl;
	cout << "6-2. dual iterator" << endl;
	it = ++container.begin();
	if (it != container.end())
		cout << "begin++:" << *it << endl;
	it = --container.end();
	if (it != container.end())
		cout << "end--:" << *it << endl;
	reverse(container.begin(), container.end());
	cout << "7-1.reverse:";
	for (it = container.begin(); it != container.end(); it++)
		cout << &(*it) << ":" << *it << ",";
	cout << endl;

	container.clear();
	cout << "7-2.clear:";
	for (it = container.begin(); it != container.end(); it++)
		cout << &(*it) << ":" << *it << ",";
	cout << endl;
}
//��ũ: �յڷ� �ڷḦ �߰�/��������, �������ٰ���.
void DequeMain()
{
	deque<int> container(10);
	for (int i = 0; i < container.size(); i++)
		container[i] = 100 - (10 * i);

	cout << "1.init(" << container.size() << "):";
	for (int i = 0; i < container.size(); i++)
		cout << i << ":" << container[i] << ",";
	cout << endl;

	container.resize(5);
	cout << "2.resize(" << container.size() << "):";
	for (int i = 0; i < container.size(); i++)
		cout << i << ":" << container[i] << ",";
	cout << endl;

	container.push_back(0);
	cout << "3-1.push_back(0):";
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]:" << container[i] << ",";
	cout << endl;

	container.push_back(-10);
	cout << "3-2.push_back(-10):";
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]:" << container[i] << ",";
	cout << endl;

	container.push_front(110);
	cout << "3-3.push_back(110):";
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]:" << container[i] << ",";
	cout << endl;

	container.push_back(-10);
	cout << "3-2.push_back(-10):";
	for (int i = 0; i < container.size(); i++)
		cout << &container[i] << "[" << i << "]:" << container[i] << ",";
	cout << endl;


	deque<int>::iterator itFind = find(container.begin(), container.end(), 70);
	if (itFind != container.end())
		cout << "4.itFind[" << &(*itFind) << "]:" << *itFind << endl;

	deque<int>::iterator itInsert = container.insert(itFind, -20);
	cout << "5.insert:";
	deque<int>::iterator it;
	for (it = container.begin(); it != container.end(); it++)
		cout << &(*it) << ":" << *it << ",";
	cout << endl;

	//if (itFind != container.end()) //itFind�� ���������ʴ´�.
	//	cout << "itFind[" << &(*itFind) << "]:" << *itFind << endl;
	container.erase(itInsert);
	cout << "6-1.erase:";
	for (it = container.begin(); it != container.end(); it++)
		cout << &(*it) << ":" << *it << ",";
	cout << endl;
	cout << "6-2.ramdom iterator" << endl;
	it = container.begin() + 3;
	if (it != container.end())
		cout << "begin+3:" << *it << endl;
	it = container.end() - 3;
	if (it != container.end())
		cout << "end+3:" << *it << endl;
	reverse(container.begin(), container.end());
	cout << "7-1.reverse:";
	for (it = container.begin(); it != container.end(); it++)
		cout << &(*it) << ":" << *it << ",";
	cout << endl;

	container.clear();
	cout << "7-2.clear:";
	for (it = container.begin(); it != container.end(); it++)
		cout << &(*it) << ":" << *it << ",";
	cout << endl;
}
//����: �ڿ��� �߰��ǰ� �ڿ��� ����.
//����Լ����� ���� �Լ��� ȣ���Ҷ����� ���ÿ� ����.
//���ڿ������� -> ���ڹ迭 -> apple -> elppa 
//������: ���ڿ� = "apple",����<����>
//�˰���: ���ڿ��� ������� -> ������ ����ϱ�
void StackMain()
{
	char strWord[] = "apple";
	stack<char> cStack;
	printf("Word:%s\n", strWord);
	int idx = 0;
	while (strWord[idx])
	{
		cStack.push(strWord[idx]);
		idx++;
	}
	idx = 0;
	while (cStack.empty() == false)
	{
		strWord[idx] = cStack.top();//��������.
		cStack.pop();//����
		idx++;
	}
	printf("Reverse:%s\n",strWord);
}
//ť: �ڿ��� �߰��ϰ� �տ��� ����.
//�޼���ť: �̺�Ʈ�� �߻��� ������� �����ϴ� ����.
//�Էµ� ������� ��ɾ� ó���ϱ�
//�Է�: A,B,C,D -> ���: A,B,C,D
//������: �޽���: A,B,C,D, ť<����>
//�˰���: �޼����� ť�� ����Ͽ� ����(�Է�)�ϰ�, ����(���)����
void QueueMain()
{
	queue<char> cQueue;
	char cInput = '\0';
	while (cInput != 'x')
	{
		cin >> cInput;
		cQueue.push(cInput);
	}
	while (cQueue.empty() == false)
	{
		cout << cQueue.front() << ",";
		cQueue.pop();
	}
	cout << endl;
}
//�켱����ť: �켱������ ���� ���Ұ� ��������(��)
//�������� �����͸� �־����� � ������� �����Ͱ� �����°�? ū������ ���´�.
//10,20,30 -> 30,20,10
//30,20,10 -> 30,20,10
//20,10,30 -> 30,20,10
void PriorytyQueueMain()
{
	priority_queue<char> cQueue;
	char cInput = '\0';
	while (cInput != 'x')
	{
		cin >> cInput;
		cQueue.push(cInput);
	}
	while (cQueue.empty() == false)
	{
		cout << cQueue.top() << ",";
		cQueue.pop();
	}
	cout << endl;
}
//��: ���������� �����͸� ã�����ִ�.
//�ش翵��ܾ ������ �ѱ��� ����� ���´�.
void MapMain()
{
	map<string, string> mapDic;

	mapDic["test"] = "����";
	mapDic["pratice"] = "����";
	mapDic["try"] = "����";
	mapDic["note"] = "���";

	cout << mapDic["try"] << endl;
	cout << mapDic["note"] << endl;
}
//��: �������� �����͸� �ִ´�. �����ʹ� ������ ������� �����͸� ã�´�.
void SetMain()
{
	set<int> setData;

	setData.insert(10);
	setData.insert(20);
	setData.insert(30);
	setData.insert(40);

	set<int>::iterator it = setData.find(10);

	if (it != setData.end()) it;
	for (it = setData.begin(); it != setData.end(); it++)
		cout << *it << ",";
	cout << endl;
}
//�ؽø�: �ؽ����̺�
void HashMapMain()
{
	unordered_map<string, string> mapDic;

	mapDic["test"] = "����";
	mapDic["pratice"] = "����";
	mapDic["try"] = "����";
	mapDic["note"] = "���";

	cout << mapDic["try"] << endl;
	cout << mapDic["note"] << endl;
}
void main()
{
	//VectorMain();
	//VectorTestMain();
	//ListMain();
	//DequeMain();
	//StackMain();
	//QueueMain();
	//PriorytyQueueMain();
	//MapMain();
	SetMain();
}
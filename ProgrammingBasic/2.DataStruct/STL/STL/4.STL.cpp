/*##################################
STL(자료구조 수업용)
파일명: STL_empty.cpp
작성자 : 김홍규(downkhg@gmail.com)
마지막수정날짜 : 2022.03.09
버전 : 1.05
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
#include <unordered_map>//hash_map -> unordered_map: vs2019부터 변경
using namespace std;
//벡터: 동적배열
//0.배열은 데이터가 저장될공간이 미리 확보되어있다.
//1.인덱스로 원소접근이 가능하다.
//2.각 자료는 포인터연산(인덱스)을 통한 순차/랜덤접근이 가능하다.
//3.배열의 크기를 런타임중에 변경가능하다.
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
	//1.추가 2.삽입 3.삭제 4.모두삭제
	vector<int>::iterator it;//접근자
	for (it = container.begin(); it != container.end(); it++)
		cout << &*it << ":"<< *it << ",";
	cout << endl;
	container.push_back(100);//배열추가시 배열전체를 변경할수도있다.
	for (it = container.begin(); it != container.end(); it++)
		cout << &*it << ":" << *it << ",";
	cout << endl;
	it = container.begin() + 2;
	cout << "find:";	
	it = find(container.begin(), container.end(), 70);
	if(it != container.end())
		cout << &*it<<":"<< *it << endl;
	cout << endl;
	container.insert(it, -20);//배열 중간삽입
	for (it = container.begin(); it != container.end(); it++)
		cout << &*it << ":" << *it << ",";
	cout << endl;
}
//1.크기 10으로 생성. 100에서 10씩 감소하여 각 원소의 값을 설정한다.
//2.크기조절 5개
//3.맨끝에 추가 0,-10
//4.찾기 70
//5.삽입: 70에 -20
//5.1.80이라면 찾은 값이 70이아니므로 find에 문제가 있다?
//6.-20 지우기, 랜덤접근
//7.뒤집기, 모두삭제
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

	//if (itFind != container.end()) //itFind는 존재하지않는다.
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

//연결리스트
//1.데이터는 순차접근만 가능하다.(랜덤x)
//2.연결리스트에 추가,삽입,삭제은 O(1)이다.
//3.연결리스트의 종류: 단일, 환형, 이중 stl의 리스트는 어디에 해당되는가?
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

	//if (itFind != container.end()) //itFind는 존재하지않는다.
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
//데크: 앞뒤로 자료를 추가/삭제가능, 랜덤접근가능.
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

	//if (itFind != container.end()) //itFind는 존재하지않는다.
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
//스택: 뒤에서 추가되고 뒤에서 꺼냄.
//재귀함수에서 이전 함수를 호출할때마다 스택에 쌓임.
//문자열뒤집기 -> 문자배열 -> apple -> elppa 
//데이터: 문자열 = "apple",스택<문자>
//알고리즘: 문자열을 뒤집어라 -> 스택을 사용하기
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
		strWord[idx] = cStack.top();//마지막값.
		cStack.pop();//삭제
		idx++;
	}
	printf("Reverse:%s\n",strWord);
}
//큐: 뒤에서 추가하고 앞에서 꺼냄.
//메세지큐: 이벤트가 발생한 순서대로 저장하는 공간.
//입력된 순서대로 명령어 처리하기
//입력: A,B,C,D -> 출력: A,B,C,D
//데이터: 메시지: A,B,C,D, 큐<문자>
//알고리즘: 메세지를 큐를 사용하여 저장(입력)하고, 꺼내(출력)보기
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
//우선순위큐: 우선순위가 높은 원소가 먼저나감(힙)
//무작위로 데이터를 넣었을때 어떤 순서대로 데이터가 나오는가? 큰값부터 나온다.
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
//맵: 사전식으로 데이터를 찾을수있다.
//해당영어단어를 넣으면 한국어 결과가 나온다.
void MapMain()
{
	map<string, string> mapDic;

	mapDic["test"] = "시험";
	mapDic["pratice"] = "연습";
	mapDic["try"] = "도전";
	mapDic["note"] = "기록";

	cout << mapDic["try"] << endl;
	cout << mapDic["note"] << endl;
}
//셋: 순서없이 데이터를 넣는다. 데이터는 순서와 상관없이 데이터를 찾는다.
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
//해시맵: 해시테이블
void HashMapMain()
{
	unordered_map<string, string> mapDic;

	mapDic["test"] = "시험";
	mapDic["pratice"] = "연습";
	mapDic["try"] = "도전";
	mapDic["note"] = "기록";

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
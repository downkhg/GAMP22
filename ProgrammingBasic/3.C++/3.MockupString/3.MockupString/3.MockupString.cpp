#include <iostream>
#include <string.h>

using namespace std;

void STDStringMain()
{
	string strMsg("test");
	string strMsg2("DataTest");
	string strCopyMsg = strMsg;

	cout << "Msg[" << &strMsg << "/" << (int)strMsg.c_str() << "]:" << strMsg.c_str() << endl;
	cout << "Msg2[" << &strMsg2 << "/" << (int)strMsg2.c_str() << "]:" << strMsg2.c_str() << endl;
	cout << "CopyMsg[" << &strCopyMsg << "/" << (int)strCopyMsg.c_str() << "]:" << strCopyMsg.c_str() << endl;
}

void STDHangManGameMain()
{
	string strQ = "____";
	string strA = "GAME";
	char cInput;

	do
	{
		cout << "Q:" << strQ << endl;
		cin >> cInput;

		int idx = strA.find(cInput);
		if (idx == -1)
		{
			cout << cInput << "is not found!" << endl;
		}
		else
		{
			strQ.replace(idx, 1, 1, cInput);
			//strQ[idx] = cInput;
		}
	} 	while (!strQ._Equal(strA));
	cout << "The End" << endl;
	//while (strQ != strA);
}
//1.문자열 더하기 
//2.문자열 비교(같다, 다르다)
//3.문자배열 테스트
//4.문자입력/출력
void STDStringOperatorTestMain()
{
	string strLastName = "k";
	string strFirstName = "hg";

	cout << "LastName:";
	for (int i = 0; i < strLastName.size(); i++)
		cout << strLastName[i];
	cout << endl;
	cout << "FirstName:";
	for (int i = 0; i < strFirstName.size(); i++)
		cout << strFirstName[i];
	cout << endl;

	string strKrFullName = strLastName + strFirstName;
	cout << "KrFullName:" << strKrFullName.c_str() << endl;

	string strEnFullName = strFirstName + strKrFullName;
	cout << "EnFullName:" << strEnFullName.c_str() << endl;
}

namespace Mockup
{
	class string
	{
		char* m_pStr;
	public:
		string(const char* text = nullptr)
		{
			if (text)
			{
				int nSize = strlen(text);
				nSize++;
				m_pStr = new char[nSize];
				strcpy_s(m_pStr, nSize, text);
			}
			cout << "string[" << this << "/" << (int)this->c_str() << "]:" << this->c_str() << endl;
		}
		~string()
		{
			cout << "~string[" << this << "/" << (int)this->c_str() << "]:" << this->c_str() << endl;
			delete[] m_pStr;
		}
		string(string& str)
		{
			//*this = str;
			int nSize = strlen(str.c_str());
			nSize++;
			m_pStr = new char[nSize];
			strcpy_s(m_pStr, nSize, str.c_str());
			cout << "copy string(&)[" << this << "/" << (int)this->c_str() << "]:" << this->c_str() << endl;
		}
		string(string&& str)
		{
			//*this = str;
			int nSize = strlen(str.c_str());
			nSize++;
			m_pStr = new char[nSize];
			strcpy_s(m_pStr, nSize, str.c_str());
			cout << "copy string(&&)[" << this << "/" << (int)this->c_str() << "]:" << this->c_str() << endl;
		}

		const char* c_str()
		{
			return m_pStr;
		}

		//행맨게임 추가내용
		int find(char c)
		{
			/*for (int i = 0; i < size(); i++)
			{
				if (m_pStr[i] == c)
					return i;
			}
			return -1;*/
			return  strchr(m_pStr, c) - m_pStr;
		}
		int replace(int idx, int size, int count, char c)
		{
			return *(m_pStr + idx + size * count - 1) = c;
		}
		bool _Equal(string& str)
		{
			return !strcmp(this->m_pStr, str.c_str());
		}

		//연산자오버로딩 추가사항.
		int size()
		{
			return strlen(m_pStr);
		}

		string operator+(string& str)
		{
			int nSize = str.size() + size() + 1;
			char* pTempStr = new char[nSize];
			sprintf_s(pTempStr, nSize, "%s%s", m_pStr, str.m_pStr);
			string strTemp(pTempStr);
			delete[] pTempStr;
			return strTemp;
		}

		bool operator==(string& str)
		{
			return _Equal(str);
		}

		bool operator!=(string& str)
		{
			return *this == str;
		}

		char operator[](int idx)
		{
			return m_pStr[idx];
		}

		friend ostream& operator<< (ostream& os, string& s)
		{
			return os << s.c_str();
		}

		friend istream& operator>> (istream& is, string& s)
		{
			return is >> s.m_pStr;
		}
	};
}

void MockupStringMain()
{
	//_CrtSetBreakAlloc(161); //메모리 누수시 번호를 넣으면 할당하는 위치에 브레이크 포인트를 건다.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //메모리 누수 검사 
	Mockup::string strMsg("test");
	Mockup::string strMsg2("DataTest");
	Mockup::string strCopyMsg = strMsg;

	cout << "Msg[" << &strMsg << "/" << (int)strMsg.c_str() << "]:" << strMsg.c_str() << endl;
	cout << "Msg2[" << &strMsg2 << "/" << (int)strMsg2.c_str() << "]:" << strMsg2.c_str() << endl;
	cout << "CopyMsg[" << &strCopyMsg << "/" << (int)strCopyMsg.c_str() << "]:" << strCopyMsg.c_str() << endl;
}

void MockupHangManGameMain()
{
	Mockup::string strQ = "____";
	Mockup::string strA = "GAME";
	char cInput;

	do
	{
		cout << "Q:" << strQ.c_str() << endl;
		cin >> cInput;

		int idx = strA.find(cInput);
		if (idx == -1)
		{
			cout << cInput << "is not found!" << endl;
		}
		else
		{
			strQ.replace(idx, 1, 1, cInput);
			//strQ[idx] = cInput;
		}
	} while (!strQ._Equal(strA));
	cout << "The End" << endl;
	//while (strQ != strA);
}
//1.문자열 더하기 
//2.문자열 비교(같다, 다르다)
//3.문자배열/길이 테스트
//4.문자입력/출력
void MockupStringOperatorTestMain()
{
	Mockup::string strLastName = "k";
	Mockup::string strFirstName = "hg";

	cout << "LastName:";
	cin >> strLastName;
	cout << "FristName:";
	cin >> strFirstName;

	cout << "LastName:";
	for (int i = 0; i < strLastName.size(); i++)
		cout << strLastName[i];
	cout << endl;
	cout << "FirstName:";
	for (int i = 0; i < strFirstName.size(); i++)
		cout << strFirstName[i];
	cout << endl;

	Mockup::string strKrFullName = strLastName + strFirstName;
	//cout << "KrFullName:" << strKrFullName.c_str() << endl;
	cout << "KrFullName:" << strKrFullName << endl;

	Mockup::string strEnFullName = strFirstName + strLastName;
	//cout << "EnFullName:" << strEnFullName.c_str() << endl;
	cout << "EnFullName:" << strKrFullName << endl;
}

void main()
{
	MockupHangManGameMain();
	//STDStringMain();
	//MockupStringMain();
	//STDHangManGameMain();
	//MockupStringMain();
	//STDStringOperatorTestMain();
	//MockupStringOperatorTestMain();
}
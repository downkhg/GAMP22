//복사생성자와 소멸자는 왜 필요한가?
//문자열 == 스트링클래스?

#include <iostream>
#include <string.h>
using namespace std;

void STDStringMain()
{
	string strMsg("Test");
	string strMsg2("DataTest");
	string strCopyMsg = strMsg;

	cout << "Msg[" << &strMsg << "/"<< (int)strMsg.c_str() <<"]:" << strMsg.c_str() << endl;
	cout << "Msg2[" << &strMsg2 << "/" << (int)strMsg2.c_str() << "]:" << strMsg2.c_str() << endl;
	cout << "CopyMsg[" << &strCopyMsg << "/" << (int)strCopyMsg.c_str() << "]:" << strCopyMsg.c_str() << endl;
}

namespace Mockup
{
	class string
	{
		char* m_pStr;
	public:
		string(const char* text)
		{
			int nSize = strlen(text);
			m_pStr = new char[nSize+1];
			strcpy_s(m_pStr, nSize + 1, text);
			cout << "string[" << this << "/" << (int)m_pStr << "]" << m_pStr << endl;
		}

		~string()
		{
			cout << "~string[" << this << "/" << (int)m_pStr << "]" << m_pStr << endl;
			delete m_pStr;
		}

		string(string& text)
		{
			*this = text;
			cout << "copystring[" << this << "/" << (int)m_pStr << "]" << m_pStr << endl;
		}

		const char* c_str() { return m_pStr; }
	};
}


void MockupStringMain()
{
	//_CrtSetBreakAlloc(163); 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Mockup::string strMsg("Test");
	Mockup::string strMsg2("DataTest");
	Mockup::string strCopyMsg = strMsg;

	cout << "Msg[" << &strMsg << "/" << (int)strMsg.c_str() << "]:" << strMsg.c_str() << endl;
	cout << "Msg2[" << &strMsg2 << "/" << (int)strMsg2.c_str() << "]:" << strMsg2.c_str() << endl;
	cout << "CopyMsg[" << &strCopyMsg << "/" << (int)strCopyMsg.c_str() << "]:" << strCopyMsg.c_str() << endl;
}


void main()
{
	//STDStringMain();
	MockupStringMain();
}
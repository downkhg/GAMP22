
// RPGStatusDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "RPGStatus.h"
#include "RPGStatusDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRPGStatusDlg 대화 상자



CRPGStatusDlg::CRPGStatusDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RPGSTATUS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRPGStatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_COMBO_CLASS, m_comboClass);
	DDX_Control(pDX, IDC_EDIT_HP, m_editHP);
	DDX_Control(pDX, IDC_STATIC_BONUS, m_staticBonus);
	DDX_Control(pDX, IDC_EDIT_MP, m_editMP);
}

BEGIN_MESSAGE_MAP(CRPGStatusDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_MP, &CRPGStatusDlg::OnDeltaposSpinMp)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_HP, &CRPGStatusDlg::OnDeltaposSpinHp)
END_MESSAGE_MAP()


// CRPGStatusDlg 메시지 처리기

BOOL CRPGStatusDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CRPGStatusDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CRPGStatusDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CRPGStatusDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void SyncBonusNState(int nBonus, int nState, CEdit& cEdit, CStatic& cStatc)
{
	CString strString;
	strString.Format(_T("%d"), nState);
	cEdit.SetWindowTextW(strString);
	strString.Format(_T("보너스포인트: %d"), nBonus);
	cStatc.SetWindowTextW(strString);
}

void CRPGStatusDlg::OnDeltaposSpinMp(NMHDR* pNMHDR, LRESULT* pResult)
{
	Player* pPlayer = m_cGameManager.GetPlayer();
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	//m_nMP = pPlayer->GetStatus().nMP;
	if (pNMUpDown->iDelta < 0)
	{
		m_nBonus--;
		pPlayer->GetStatus().nMP++;
		SyncBonusNState(m_nBonus, pPlayer->GetStatus().nMP, m_editMP, m_staticBonus);
		/*CString strString;
		strString.Format(_T("%d"), m_nMP);
		m_editMP.SetWindowTextW(strString);
		strString.Format(_T("보너스포인트: %d"), m_nBonus);
		m_staticBonus.SetWindowTextW(strString);*/
		TRACE("Click up\n");
	}
	else
	{
		pPlayer->GetStatus().nMP--;
		m_nBonus++;
		SyncBonusNState(m_nBonus, pPlayer->GetStatus().nMP, m_editMP, m_staticBonus);
		/*CString strString;
		strString.Format(_T("%d"), m_nMP);
		m_editMP.SetWindowTextW(strString);
		strString.Format(_T("보너스포인트: %d"), m_nBonus);
		m_staticBonus.SetWindowTextW(strString);*/
		TRACE("Click donw\n");
	}
	//pPlayer->GetStatus().nMP = m_nMP;
	//pPlayer->GetStatus().nMP = m_n
	//pPlayer->GetStatus().nMP = m_n;
	///pPlayer->GetStatus().nMP = m_nMP;

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}

void CRPGStatusDlg::OnDeltaposSpinHp(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.


	*pResult = 0;
}

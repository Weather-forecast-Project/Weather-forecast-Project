
// mxlDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "mxl.h"
#include "mxlDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
//	static UINT ThreadFirst(LPVOID _mothod);
	CFont font;

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmxlDlg 대화 상자


IMPLEMENT_DYNAMIC(CmxlDlg, CDialogEx);

CmxlDlg::CmxlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmxlDlg::IDD, pParent)
{
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CmxlDlg::~CmxlDlg()
{
	// 이 대화 상자에 대한 자동화 프록시가 있을 경우 이 대화 상자에 대한
	//  후방 포인터를 NULL로 설정하여
	//  대화 상자가 삭제되었음을 알 수 있게 합니다.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CmxlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICVIEW, maps);
	DDX_Control(pDX, IDC_EDIT1, medit);
	DDX_Control(pDX, IDC_LIST1, mlist);

	DDX_Control(pDX, IDC_LIST2, mlist2);
	DDX_Control(pDX, IDC_EDIT2, medit2);

	DDX_Control(pDX, IDC_BUTTON1, m_b1);
	DDX_Control(pDX, IDC_BUTTON2, m_b2);
	DDX_Control(pDX, IDC_BUTTON3, m_b3);
	DDX_Control(pDX, IDC_BUTTON21, m_b21);
	DDX_Control(pDX, IDC_BUTTON13, m_b13);
	//  DDX_Control(pDX, IDC_BUTTON10, m);
	DDX_Control(pDX, IDC_BUTTON12, m_b12);
	DDX_Control(pDX, IDC_BUTTON10, m_b10);
	DDX_Control(pDX, IDC_BUTTON11, m_b11);
	DDX_Control(pDX, IDC_BUTTON14, m_b14);
	DDX_Control(pDX, IDC_BUTTON15, m_b15);
	DDX_Control(pDX, IDC_BUTTON16, m_b16);
	DDX_Control(pDX, IDC_BUTTON17, m_b17);
	DDX_Control(pDX, IDC_BUTTON18, m_b18);
	DDX_Control(pDX, IDC_BUTTON4, m_b4);
	DDX_Control(pDX, IDC_BUTTON19, m_b19);
	DDX_Control(pDX, IDC_BUTTON20, m_b20);
	DDX_Control(pDX, IDC_BUTTON5, m_b5);
	DDX_Control(pDX, IDC_BUTTON6, m_b6);
	DDX_Control(pDX, IDC_BUTTON7, m_b7);
	DDX_Control(pDX, IDC_BUTTON8, m_b8);
	DDX_Control(pDX, IDC_BUTTON9, m_b9);
	DDX_Control(pDX, IDC_EDIT3, medit3);
}

BEGIN_MESSAGE_MAP(CmxlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_BUTTON1, &CmxlDlg::OnBnClickedButton1)

	ON_BN_CLICKED(IDC_BUTTON2, &CmxlDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CmxlDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON18, &CmxlDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON4, &CmxlDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CmxlDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CmxlDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CmxlDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CmxlDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CmxlDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CmxlDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON12, &CmxlDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON11, &CmxlDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON13, &CmxlDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CmxlDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CmxlDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CmxlDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CmxlDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON19, &CmxlDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON21, &CmxlDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON20, &CmxlDlg::OnBnClickedButton20)
END_MESSAGE_MAP()


// CmxlDlg 메시지 처리기

UINT ThreadFirst(LPVOID inval)
{
	CStringArray *array = (CStringArray*)inval;

	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	MSXML2::IXMLDOMDocument2Ptr pDoc;

	MSXML2::IXMLDOMNodeListPtr pNodeList;
	pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument));
	
	DWORD startTick = GetTickCount();
	pDoc->put_async(VARIANT_FALSE);

	
	CString outTotalString;

	CString rss[21] = { _T("http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=1114055000"), _T(" http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=2820051000"), _T("http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4111159800"), _T("http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4211058000"),
		_T("http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4215051000"), _T("http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4421051000"), _T(" http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4311374100"), _T(" http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=3017063000"), _T("http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4511171200")
		, _T("http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=2914074500"), _T(" http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4611051000"), _T(" http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4613078000"), _T(" http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4793025000"), _T("http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4717052000"), _T("http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4711152500"),
		_T(" http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=2711051700"), _T("http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=3114051000"), _T("http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4812356000"), _T("http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=2647069000"), _T("http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=4794025000"), _T(" http://www.kma.go.kr/wid/queryDFSRSS.jsp?zone=5011063000") };
	while (TRUE)
	{
	for (int k = 0; k < 21; k++)
	{
		
		pDoc->load((_variant_t)rss[k]);

		for (int i = 0; i < 3; i++)
		{
			CString outString;
			CString sky,wet;
			CString nextsky;
			if (i == 0){
				pNodeList = pDoc->selectNodes(L"//hour");
				outString.Format(_T("시각: %s시\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				array[k].Add(outString);
				pNodeList = pDoc->selectNodes(L"//temp");
				outString.Format(_T("기온: %sºC\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				array[k].Add(outString);

	 			pNodeList = pDoc->selectNodes(L"//sky");
				outString.Format(_T("하늘상태: %s\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				if (outString == "하늘상태: 1\n")
				{
					sky.Format(_T("하늘상태:  맑음\n"));
				}
				else if (outString == "하늘상태: 2\n")
				{
					sky.Format(_T("하늘상태:  구름조금\n"));
				}
				else if (outString == "하늘상태: 3\n")
				{
					sky.Format(_T("하늘상태:  구름많음\n"));
				}
				else 
				{
					sky.Format(_T("하늘상태:  흐림\n"));
				}				
				array[k].Add(sky);
				pNodeList = pDoc->selectNodes(L"//pty");
				outString.Format(_T("강수상태:%s\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				if (outString == "강수상태:1\n")
				{
					wet.Format(_T("하늘상태:  비내림\n"));
				}
				else if (outString == "강수상태:2\n")
				{
					wet.Format(_T("하늘상태: 비 또는 눈 \n"));
				}
				else if (outString == "강수상태:3\n")
				{
					wet.Format(_T("하늘상태: 눈 또는 비 \n"));
				}
				else if (outString == "강수상태:4\n")
				{
					wet.Format(_T("하늘상태:  눈내림\n"));
				}
				else
				{
					wet.Format(_T("하늘상태:  비 또는 눈 없음\n"));
				}
				array[k].Add(wet);
				pNodeList = pDoc->selectNodes(L"//pop");
				outString.Format(_T("강수확률: %s%%\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				array[k].Add(outString);
				pNodeList = pDoc->selectNodes(L"//r12");
				outString.Format(_T("예상강수량: %s[mm]\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				array[k].Add(outString);
				pNodeList = pDoc->selectNodes(L"//s12");
				outString.Format(_T("예상적설량: %s[mm]\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				array[k].Add(outString);
				pNodeList = pDoc->selectNodes(L"//reh");
				outString.Format(_T("습도: %s%%\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				array[k].Add(outString);
			}
			else if (i>0)
			{
				pNodeList = pDoc->selectNodes(L"//temp");
				outString.Format(_T("내일기온: %sºC\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				array[k].Add(outString);
				pNodeList = pDoc->selectNodes(L"//sky");
				outString.Format(_T("내일하늘상태:%s\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				if (outString == "내일하늘상태:1\n")
				{
					nextsky.Format(_T("내일하늘상태:  맑음\n"));
				}
				else if(outString == "내일하늘상태:2\n")
				{
					nextsky.Format(_T("내일하늘상태:  구름조금\n"));
				}
				else if (outString == "내일하늘상태:3\n")
				{
					nextsky.Format(_T("내일하늘상태:  구름많음\n"));
				}
				else 
				{
					nextsky.Format(_T("내일하늘상태:  흐림\n"));
				}
				//outString.Format(_T("내일하늘상태:%s\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				array[k].Add(nextsky);
			}
		}

	}
	::Sleep(60000);
}
}


BOOL CmxlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

			AfxBeginThread(ThreadFirst, (LPVOID)array);
	
	

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CmxlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmxlDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	//CClientDC dc(this);
	CImage Image;

	Image.Load(_T("지도1.jpg"));
	Image.BitBlt(dc.m_hDC, 0, 0);
	medit.SetWindowTextW(_T("오늘의날씨"));
	medit2.SetWindowTextW(_T("내일의날씨"));



	/*if (IsIconic())
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

		CDC memDC;
		memDC.CreateCompatibleDC(maps.GetDC());
		CBitmap	bitmap;
		bitmap.LoadBitmap(IDB_BITMAP1);
		memDC.SelectObject(&bitmap);

		CStatic *staticSize = (CStatic*)GetDlgItem(IDC_PICVIEW);
		CRect RECT;
		staticSize->GetClientRect(rect);
		int iwidth = rect.Width();
		int iheight = rect.Height();
		maps.GetDC()->StretchBlt(0, 0, iwidth, iheight, &memDC, 0, 0, 149, 220, SRCCOPY);
		// 아이콘을 그립니다.

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}*/
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CmxlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 컨트롤러에서 해당 개체 중 하나를 계속 사용하고 있을 경우
//  사용자가 UI를 닫을 때 자동화 서버를 종료하면 안 됩니다.  이들
//  메시지 처리기는 프록시가 아직 사용 중인 경우 UI는 숨기지만,
//  UI가 표시되지 않아도 대화 상자는
//  남겨 둡니다.

void CmxlDlg::OnClose()
{
	if (CanExit())
	
		//delete array;
		CDialogEx::OnClose();
	
}
void CmxlDlg::OnOK()
{ 
	w = 0;
	Invalidate();
	for (int i = 0; i < 8; i++)
	{
		
		mlist.DeleteString(0);
	}
	for (int i = 0; i < 2; i++)
	{
		
		mlist2.DeleteString(0);
	}

	m_b2.EnableWindow(TRUE); m_b1.EnableWindow(TRUE); m_b3.EnableWindow(TRUE); m_b4.EnableWindow(TRUE);
	m_b5.EnableWindow(TRUE); m_b6.EnableWindow(TRUE); m_b7.EnableWindow(TRUE); m_b8.EnableWindow(TRUE);
	m_b9.EnableWindow(TRUE); m_b10.EnableWindow(TRUE); m_b11.EnableWindow(TRUE); m_b12.EnableWindow(TRUE);
	m_b13.EnableWindow(TRUE); m_b14.EnableWindow(TRUE); m_b15.EnableWindow(TRUE); m_b16.EnableWindow(TRUE);
	m_b17.EnableWindow(TRUE); m_b18.EnableWindow(TRUE); m_b19.EnableWindow(TRUE); m_b20.EnableWindow(TRUE);
	m_b21.EnableWindow(TRUE);

	
}


void CmxlDlg::OnCancel()
{
	if (CanExit())
	
		//delete array;
		CDialogEx::OnCancel();
	
	}

BOOL CmxlDlg::CanExit()
{
	// 프록시 개체가 계속 남아 있으면 자동화 컨트롤러에서는
	//  이 응용 프로그램을 계속 사용합니다.  대화 상자는 남겨 두지만
	//  해당 UI는 숨깁니다.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}


void CmxlDlg::wether()
{

	for (int i = 0; i < 8; i++)
	{
		mlist.AddString(array[w].GetAt(i));
	}
	mlist2.AddString(array[w].GetAt(8));
	mlist2.AddString(array[w].GetAt(9));

	CClientDC dc(this);
	CImage Image;
	//내일이미지
	if (array[w].GetAt(9) == "내일하늘상태:  맑음\n")
	{
	  	Image.Load(_T("해1.jpg"));
		Image.BitBlt(dc.m_hDC, 930, 50);
	}
	else if (array[w].GetAt(9) == "내일하늘상태:  구름조금\n")
	{
		Image.Load(_T("구름조금.png"));
		Image.BitBlt(dc.m_hDC, 930, 50);
	}
	else
	{
		Image.Load(_T("구름.png"));
		Image.BitBlt(dc.m_hDC, 930, 50);
	}
	Image.Destroy();
	//오늘이미지
	/*if (array[w].GetAt(2) == "하늘상태:  맑음\n")
	{
		Image.Load(_T("해1.jpg"));
		Image.BitBlt(dc.m_hDC, 700, 50);
	}
	else if (array[w].GetAt(2) == "하늘상태:  구름조금\n")
	{
		Image.Load(_T("구름조금.png"));
		Image.BitBlt(dc.m_hDC, 700, 50);
	}*/

	//else //구름많거나 흐릴때 강수상태 변화에 따른 이미지
	//{
		if (array[w].GetAt(3) == "강수상태:0\n")
		{
			if (array[w].GetAt(2) == "하늘상태:  맑음\n")
			{
				Image.Load(_T("해1.jpg"));
				Image.BitBlt(dc.m_hDC, 700, 50);
			}
			else if (array[w].GetAt(2) == "하늘상태:  구름조금\n")
			{
				Image.Load(_T("구름조금.png"));
				Image.BitBlt(dc.m_hDC, 700, 50);
			}
			else
			{
				Image.Load(_T("구름.png"));
				Image.BitBlt(dc.m_hDC, 930, 50);
			}
		}
		else if (array[w].GetAt(3) == "강수상태:1\n")
		{
			Image.Load(_T("비.jpg"));
			Image.BitBlt(dc.m_hDC, 700, 50);
		}
		else if (array[w].GetAt(3) == "강수상태:4\n")
		{
			Image.Load(_T("눈.jpg"));
			Image.BitBlt(dc.m_hDC, 700, 50);
		}
		else
		{
			Image.Load(_T("구름.png"));
			Image.BitBlt(dc.m_hDC, 700, 50);
		}
	
	Image.Destroy();
	::ReleaseDC(m_hWnd, dc.m_hDC);
}

void CmxlDlg::OnBnClickedButton1() //서울
{
	
	m_b2.EnableWindow(FALSE);m_b1.EnableWindow(FALSE);m_b3.EnableWindow(FALSE);m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE);m_b6.EnableWindow(FALSE);m_b7.EnableWindow(FALSE);m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE);m_b10.EnableWindow(FALSE);m_b11.EnableWindow(FALSE);m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE);m_b14.EnableWindow(FALSE);m_b15.EnableWindow(FALSE);m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 0;
	CmxlDlg::wether();
}





void CmxlDlg::OnBnClickedButton2()//인천
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 1;
	medit3.SetWindowTextW(_T("인천"));
	CmxlDlg::wether();
}



void CmxlDlg::OnBnClickedButton3()//수원
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 2;
	CmxlDlg::wether();
}


void CmxlDlg::OnBnClickedButton4()//춘천
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 3;
	CmxlDlg::wether();
}


void CmxlDlg::OnBnClickedButton5()//강릉
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 4;
	CmxlDlg::wether();
}


void CmxlDlg::OnBnClickedButton6()//서산
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 5;
	CmxlDlg::wether();
}


void CmxlDlg::OnBnClickedButton7()//청주
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 6;
	CmxlDlg::wether();
}


void CmxlDlg::OnBnClickedButton8()//대전
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 7;
	CmxlDlg::wether();
}


void CmxlDlg::OnBnClickedButton9()//전주
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 8;
	CmxlDlg::wether();
}


void CmxlDlg::OnBnClickedButton10()//광주
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 9;
	CmxlDlg::wether();
}



void CmxlDlg::OnBnClickedButton11()//목포
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 10;
	CmxlDlg::wether();
}

void CmxlDlg::OnBnClickedButton12()
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 11;
	CmxlDlg::wether();
}


void CmxlDlg::OnBnClickedButton13()
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 12;
	CmxlDlg::wether();
}


void CmxlDlg::OnBnClickedButton14()
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 13;
	CmxlDlg::wether();
}


void CmxlDlg::OnBnClickedButton15()
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 14;
	CmxlDlg::wether();
}


void CmxlDlg::OnBnClickedButton16()
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 15;
	CmxlDlg::wether();
}


void CmxlDlg::OnBnClickedButton17()
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 16;
	CmxlDlg::wether();
}


void CmxlDlg::OnBnClickedButton18()
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 17;
	CmxlDlg::wether();
}



void CmxlDlg::OnBnClickedButton19()
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 18;
	CmxlDlg::wether();

}


void CmxlDlg::OnBnClickedButton21()
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 20;
	CmxlDlg::wether();
	}





void CmxlDlg::OnBnClickedButton20()
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 19;
	CmxlDlg::wether();
	}



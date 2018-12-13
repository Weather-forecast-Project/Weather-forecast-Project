
// mxlDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "mxl.h"
#include "mxlDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
//	static UINT ThreadFirst(LPVOID _mothod);
	CFont font;

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CmxlDlg ��ȭ ����


IMPLEMENT_DYNAMIC(CmxlDlg, CDialogEx);

CmxlDlg::CmxlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmxlDlg::IDD, pParent)
{
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CmxlDlg::~CmxlDlg()
{
	// �� ��ȭ ���ڿ� ���� �ڵ�ȭ ���Ͻð� ���� ��� �� ��ȭ ���ڿ� ����
	//  �Ĺ� �����͸� NULL�� �����Ͽ�
	//  ��ȭ ���ڰ� �����Ǿ����� �� �� �ְ� �մϴ�.
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


// CmxlDlg �޽��� ó����

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
				outString.Format(_T("�ð�: %s��\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				array[k].Add(outString);
				pNodeList = pDoc->selectNodes(L"//temp");
				outString.Format(_T("���: %s��C\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				array[k].Add(outString);

	 			pNodeList = pDoc->selectNodes(L"//sky");
				outString.Format(_T("�ϴû���: %s\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				if (outString == "�ϴû���: 1\n")
				{
					sky.Format(_T("�ϴû���:  ����\n"));
				}
				else if (outString == "�ϴû���: 2\n")
				{
					sky.Format(_T("�ϴû���:  ��������\n"));
				}
				else if (outString == "�ϴû���: 3\n")
				{
					sky.Format(_T("�ϴû���:  ��������\n"));
				}
				else 
				{
					sky.Format(_T("�ϴû���:  �帲\n"));
				}				
				array[k].Add(sky);
				pNodeList = pDoc->selectNodes(L"//pty");
				outString.Format(_T("��������:%s\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				if (outString == "��������:1\n")
				{
					wet.Format(_T("�ϴû���:  �񳻸�\n"));
				}
				else if (outString == "��������:2\n")
				{
					wet.Format(_T("�ϴû���: �� �Ǵ� �� \n"));
				}
				else if (outString == "��������:3\n")
				{
					wet.Format(_T("�ϴû���: �� �Ǵ� �� \n"));
				}
				else if (outString == "��������:4\n")
				{
					wet.Format(_T("�ϴû���:  ������\n"));
				}
				else
				{
					wet.Format(_T("�ϴû���:  �� �Ǵ� �� ����\n"));
				}
				array[k].Add(wet);
				pNodeList = pDoc->selectNodes(L"//pop");
				outString.Format(_T("����Ȯ��: %s%%\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				array[k].Add(outString);
				pNodeList = pDoc->selectNodes(L"//r12");
				outString.Format(_T("���󰭼���: %s[mm]\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				array[k].Add(outString);
				pNodeList = pDoc->selectNodes(L"//s12");
				outString.Format(_T("����������: %s[mm]\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				array[k].Add(outString);
				pNodeList = pDoc->selectNodes(L"//reh");
				outString.Format(_T("����: %s%%\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				array[k].Add(outString);
			}
			else if (i>0)
			{
				pNodeList = pDoc->selectNodes(L"//temp");
				outString.Format(_T("���ϱ��: %s��C\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				array[k].Add(outString);
				pNodeList = pDoc->selectNodes(L"//sky");
				outString.Format(_T("�����ϴû���:%s\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
				if (outString == "�����ϴû���:1\n")
				{
					nextsky.Format(_T("�����ϴû���:  ����\n"));
				}
				else if(outString == "�����ϴû���:2\n")
				{
					nextsky.Format(_T("�����ϴû���:  ��������\n"));
				}
				else if (outString == "�����ϴû���:3\n")
				{
					nextsky.Format(_T("�����ϴû���:  ��������\n"));
				}
				else 
				{
					nextsky.Format(_T("�����ϴû���:  �帲\n"));
				}
				//outString.Format(_T("�����ϴû���:%s\n"), (LPCTSTR)pNodeList->Getitem(i * 8)->Gettext());
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

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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
	
	

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CmxlDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	//CClientDC dc(this);
	CImage Image;

	Image.Load(_T("����1.jpg"));
	Image.BitBlt(dc.m_hDC, 0, 0);
	medit.SetWindowTextW(_T("�����ǳ���"));
	medit2.SetWindowTextW(_T("�����ǳ���"));



	/*if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
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
		// �������� �׸��ϴ�.

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}*/
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CmxlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ��Ʈ�ѷ����� �ش� ��ü �� �ϳ��� ��� ����ϰ� ���� ���
//  ����ڰ� UI�� ���� �� �ڵ�ȭ ������ �����ϸ� �� �˴ϴ�.  �̵�
//  �޽��� ó����� ���Ͻð� ���� ��� ���� ��� UI�� ��������,
//  UI�� ǥ�õ��� �ʾƵ� ��ȭ ���ڴ�
//  ���� �Ӵϴ�.

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
	// ���Ͻ� ��ü�� ��� ���� ������ �ڵ�ȭ ��Ʈ�ѷ�������
	//  �� ���� ���α׷��� ��� ����մϴ�.  ��ȭ ���ڴ� ���� ������
	//  �ش� UI�� ����ϴ�.
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
	//�����̹���
	if (array[w].GetAt(9) == "�����ϴû���:  ����\n")
	{
	  	Image.Load(_T("��1.jpg"));
		Image.BitBlt(dc.m_hDC, 930, 50);
	}
	else if (array[w].GetAt(9) == "�����ϴû���:  ��������\n")
	{
		Image.Load(_T("��������.png"));
		Image.BitBlt(dc.m_hDC, 930, 50);
	}
	else
	{
		Image.Load(_T("����.png"));
		Image.BitBlt(dc.m_hDC, 930, 50);
	}
	Image.Destroy();
	//�����̹���
	/*if (array[w].GetAt(2) == "�ϴû���:  ����\n")
	{
		Image.Load(_T("��1.jpg"));
		Image.BitBlt(dc.m_hDC, 700, 50);
	}
	else if (array[w].GetAt(2) == "�ϴû���:  ��������\n")
	{
		Image.Load(_T("��������.png"));
		Image.BitBlt(dc.m_hDC, 700, 50);
	}*/

	//else //�������ų� �帱�� �������� ��ȭ�� ���� �̹���
	//{
		if (array[w].GetAt(3) == "��������:0\n")
		{
			if (array[w].GetAt(2) == "�ϴû���:  ����\n")
			{
				Image.Load(_T("��1.jpg"));
				Image.BitBlt(dc.m_hDC, 700, 50);
			}
			else if (array[w].GetAt(2) == "�ϴû���:  ��������\n")
			{
				Image.Load(_T("��������.png"));
				Image.BitBlt(dc.m_hDC, 700, 50);
			}
			else
			{
				Image.Load(_T("����.png"));
				Image.BitBlt(dc.m_hDC, 930, 50);
			}
		}
		else if (array[w].GetAt(3) == "��������:1\n")
		{
			Image.Load(_T("��.jpg"));
			Image.BitBlt(dc.m_hDC, 700, 50);
		}
		else if (array[w].GetAt(3) == "��������:4\n")
		{
			Image.Load(_T("��.jpg"));
			Image.BitBlt(dc.m_hDC, 700, 50);
		}
		else
		{
			Image.Load(_T("����.png"));
			Image.BitBlt(dc.m_hDC, 700, 50);
		}
	
	Image.Destroy();
	::ReleaseDC(m_hWnd, dc.m_hDC);
}

void CmxlDlg::OnBnClickedButton1() //����
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





void CmxlDlg::OnBnClickedButton2()//��õ
{
	m_b2.EnableWindow(FALSE); m_b1.EnableWindow(FALSE); m_b3.EnableWindow(FALSE); m_b4.EnableWindow(FALSE);
	m_b5.EnableWindow(FALSE); m_b6.EnableWindow(FALSE); m_b7.EnableWindow(FALSE); m_b8.EnableWindow(FALSE);
	m_b9.EnableWindow(FALSE); m_b10.EnableWindow(FALSE); m_b11.EnableWindow(FALSE); m_b12.EnableWindow(FALSE);
	m_b13.EnableWindow(FALSE); m_b14.EnableWindow(FALSE); m_b15.EnableWindow(FALSE); m_b16.EnableWindow(FALSE);
	m_b17.EnableWindow(FALSE); m_b18.EnableWindow(FALSE); m_b19.EnableWindow(FALSE); m_b20.EnableWindow(FALSE);
	m_b21.EnableWindow(FALSE);
	w = 1;
	medit3.SetWindowTextW(_T("��õ"));
	CmxlDlg::wether();
}



void CmxlDlg::OnBnClickedButton3()//����
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


void CmxlDlg::OnBnClickedButton4()//��õ
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


void CmxlDlg::OnBnClickedButton5()//����
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


void CmxlDlg::OnBnClickedButton6()//����
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


void CmxlDlg::OnBnClickedButton7()//û��
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


void CmxlDlg::OnBnClickedButton8()//����
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


void CmxlDlg::OnBnClickedButton9()//����
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


void CmxlDlg::OnBnClickedButton10()//����
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



void CmxlDlg::OnBnClickedButton11()//����
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



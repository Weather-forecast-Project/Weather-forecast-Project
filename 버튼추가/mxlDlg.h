
// mxlDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"

class CmxlDlgAutoProxy;


// CmxlDlg 대화 상자
class CmxlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CmxlDlg);
	friend class CmxlDlgAutoProxy;

// 생성입니다.
public:
	CmxlDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	virtual ~CmxlDlg();
	int w=0;
	CStringArray *array = new CStringArray[21];
// 대화 상자 데이터입니다.
	enum { IDD = IDD_MXL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	CmxlDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();



	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();

	virtual void wether();
	DECLARE_MESSAGE_MAP()
public:
	CStatic maps;
	CEdit medit;
	CEdit medit2;
	CListBox mlist;
	CListBox mlist2;
	CButton m_b1;
	CButton m_b2;
	CFont font;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton20();
	CButton m_b3;
	CButton m_b21;
	CButton m_b13;
//	CButton m;
	CButton m_b12;
	CButton m_b10;
	CButton m_b11;
	CButton m_b14;
	CButton m_b15;
	CButton m_b16;
	CButton m_b17;
	CButton m_b18;
	CButton m_b4;
	CButton m_b19;
	CButton m_b20;
	CButton m_b5;
	CButton m_b6;
	CButton m_b7;
	CButton m_b8;
	CButton m_b9;
	CEdit medit3;
};

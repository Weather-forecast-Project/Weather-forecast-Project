
// DlgProxy.cpp : ���� ����
//

#include "stdafx.h"
#include "mxl.h"
#include "DlgProxy.h"
#include "mxlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmxlDlgAutoProxy

IMPLEMENT_DYNCREATE(CmxlDlgAutoProxy, CCmdTarget)

CmxlDlgAutoProxy::CmxlDlgAutoProxy()
{
	EnableAutomation();
	
	// �ڵ�ȭ ��ü�� Ȱ��ȭ�Ǿ� �ִ� ���� ��� ���� ���α׷��� �����ϱ� ���� 
	//	�����ڿ��� AfxOleLockApp�� ȣ���մϴ�.
	AfxOleLockApp();

	// ���� ���α׷��� �� â �����͸� ���� ��ȭ ���ڿ� ����
	//  �׼����� �����ɴϴ�.  ���Ͻ��� ���� �����͸� �����Ͽ�
	//  ��ȭ ���ڸ� ����Ű�� ��ȭ ������ �Ĺ� �����͸� �� ���Ͻ÷�
	//  �����մϴ�.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CmxlDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CmxlDlg)))
		{
			m_pDialog = reinterpret_cast<CmxlDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CmxlDlgAutoProxy::~CmxlDlgAutoProxy()
{
	// ��� ��ü�� OLE �ڵ�ȭ�� ��������� �� ���� ���α׷��� �����ϱ� ����
	// 	�Ҹ��ڰ� AfxOleUnlockApp�� ȣ���մϴ�.
	//  �̷��� ȣ��� �� ��ȭ ���ڰ� ������ �� �ֽ��ϴ�.
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CmxlDlgAutoProxy::OnFinalRelease()
{
	// �ڵ�ȭ ��ü�� ���� ������ ������ �����Ǹ�
	// OnFinalRelease�� ȣ��˴ϴ�.  �⺻ Ŭ�������� �ڵ����� ��ü�� �����մϴ�.
	// �⺻ Ŭ������ ȣ���ϱ� ���� ��ü�� �ʿ��� �߰� ���� �۾���
	// �߰��Ͻʽÿ�.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CmxlDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CmxlDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// ����: IID_Imxl�� ���� ������ �߰��Ͽ�
//  VBA���� ���� ���� ���ε��� �����մϴ�.
//  �� IID�� .IDL ���Ͽ� �ִ� dispinterface�� GUID�� ��ġ�ؾ� �մϴ�.

// {E48FA626-FCAD-4106-A7F3-AD79F860587E}
static const IID IID_Imxl =
{ 0xE48FA626, 0xFCAD, 0x4106, { 0xA7, 0xF3, 0xAD, 0x79, 0xF8, 0x60, 0x58, 0x7E } };

BEGIN_INTERFACE_MAP(CmxlDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CmxlDlgAutoProxy, IID_Imxl, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 ��ũ�ΰ� �� ������Ʈ�� StdAfx.h�� ���ǵ˴ϴ�.
// {499EAC6E-E52D-4750-99EC-DB0853D183EA}
IMPLEMENT_OLECREATE2(CmxlDlgAutoProxy, "mxl.Application", 0x499eac6e, 0xe52d, 0x4750, 0x99, 0xec, 0xdb, 0x8, 0x53, 0xd1, 0x83, 0xea)


// CmxlDlgAutoProxy �޽��� ó����

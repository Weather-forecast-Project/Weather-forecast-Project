
// DlgProxy.h: ��� ����
//

#pragma once

class CmxlDlg;


// CmxlDlgAutoProxy ��� ���

class CmxlDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CmxlDlgAutoProxy)

	CmxlDlgAutoProxy();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.

// Ư���Դϴ�.
public:
	CmxlDlg* m_pDialog;
// �۾��Դϴ�.
public:

// �������Դϴ�.
	public:
	virtual void OnFinalRelease();

// �����Դϴ�.
protected:
	virtual ~CmxlDlgAutoProxy();

	// ������ �޽��� �� �Լ�

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CmxlDlgAutoProxy)

	// ������ OLE ����ġ �� �Լ�

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};


#pragma once
#include "afxwin.h"


// CDlgLrc �Ի���

class CDlgLrc : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgLrc)

public:
	CDlgLrc(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgLrc();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_LRC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

	CListBox m_list_lrc;
	bool m_isOpen;
//	virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	virtual BOOL DestroyWindow();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual void OnCancel();
};

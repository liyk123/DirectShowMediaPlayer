#pragma once
#include "afxwin.h"


// CDlgPlaylist �Ի���

class CDlgPlaylist : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgPlaylist)

public:
	CDlgPlaylist(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgPlaylist();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_PLIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listbox;
	bool m_isOpen;
	virtual BOOL DestroyWindow();
//	virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual void OnCancel();
};

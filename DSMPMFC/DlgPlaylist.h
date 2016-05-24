#pragma once
#include "afxwin.h"


// CDlgPlaylist 对话框

class CDlgPlaylist : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgPlaylist)

public:
	CDlgPlaylist(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgPlaylist();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_PLIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listbox;
	bool m_isOpen;
	virtual BOOL DestroyWindow();
//	virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual void OnCancel();
};

#pragma once

#include "MediaInfoDLL.h"
#include "afxwin.h"
// CDlgFileInfo 对话框

class CDlgFileInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFileInfo)

public:
	CDlgFileInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgFileInfo();
	MediaInfoDLL::String m_Fileinfo;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_FILE_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_FileinfoCtl;
	virtual BOOL OnInitDialog();
};

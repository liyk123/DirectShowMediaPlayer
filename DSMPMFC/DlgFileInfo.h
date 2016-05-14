#pragma once

#include "MediaInfoDLL.h"
#include "afxwin.h"
// CDlgFileInfo �Ի���

class CDlgFileInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFileInfo)

public:
	CDlgFileInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgFileInfo();
	MediaInfoDLL::String m_Fileinfo;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_FILE_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_FileinfoCtl;
	virtual BOOL OnInitDialog();
};

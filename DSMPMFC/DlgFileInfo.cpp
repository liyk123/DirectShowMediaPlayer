// DlgFileInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "DSMPMFC.h"
#include "DlgFileInfo.h"
#include "afxdialogex.h"


// CDlgFileInfo 对话框

IMPLEMENT_DYNAMIC(CDlgFileInfo, CDialogEx)

CDlgFileInfo::CDlgFileInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_FILE_INFO, pParent)
{
	m_Fileinfo = L"";
}

CDlgFileInfo::~CDlgFileInfo()
{
}

void CDlgFileInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_FILE_INFO, m_FileinfoCtl);
}


BEGIN_MESSAGE_MAP(CDlgFileInfo, CDialogEx)
END_MESSAGE_MAP()


// CDlgFileInfo 消息处理程序


BOOL CDlgFileInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化
	m_FileinfoCtl.SetWindowTextW(m_Fileinfo.c_str());
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

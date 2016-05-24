// DlgLrc.cpp : 实现文件
//

#include "stdafx.h"
#include "DSMPMFC.h"
#include "DlgLrc.h"
#include "afxdialogex.h"


// CDlgLrc 对话框

IMPLEMENT_DYNAMIC(CDlgLrc, CDialogEx)

CDlgLrc::CDlgLrc(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_LRC, pParent)
{
	m_isOpen = false;
}

CDlgLrc::~CDlgLrc()
{
}

void CDlgLrc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_LRC, m_list_lrc);
}


BEGIN_MESSAGE_MAP(CDlgLrc, CDialogEx)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CDlgLrc 消息处理程序


//BOOL CDlgLrc::Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//
//	return CDialogEx::Create(lpszTemplateName, pParentWnd);
//}


BOOL CDlgLrc::DestroyWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	m_isOpen = false;
	return CDialogEx::DestroyWindow();
}


void CDlgLrc::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);
	
	// TODO: 在此处添加消息处理程序代码
	m_isOpen = bShow ? true : false;
}


void CDlgLrc::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	ShowWindow(SW_HIDE);
	//CDialogEx::OnCancel();
}

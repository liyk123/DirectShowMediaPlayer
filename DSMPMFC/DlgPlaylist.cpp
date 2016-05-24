// DlgPlaylist.cpp : 实现文件
//

#include "stdafx.h"
#include "DSMPMFC.h"
#include "DlgPlaylist.h"
#include "afxdialogex.h"


// CDlgPlaylist 对话框

IMPLEMENT_DYNAMIC(CDlgPlaylist, CDialogEx)

CDlgPlaylist::CDlgPlaylist(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_PLIST, pParent)
{
	m_isOpen = false;
}

CDlgPlaylist::~CDlgPlaylist()
{
}

void CDlgPlaylist::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PLAYLIST, m_listbox);
}


BEGIN_MESSAGE_MAP(CDlgPlaylist, CDialogEx)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CDlgPlaylist 消息处理程序


BOOL CDlgPlaylist::DestroyWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	m_isOpen = false;
	return CDialogEx::DestroyWindow();
}


//BOOL CDlgPlaylist::Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//	m_isOpen = true;
//	return CDialogEx::Create(lpszTemplateName, pParentWnd);
//}


void CDlgPlaylist::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);
	
	// TODO: 在此处添加消息处理程序代码
	m_isOpen = bShow?true:false;
}


void CDlgPlaylist::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	ShowWindow(SW_HIDE);
	//CDialogEx::OnCancel();
}

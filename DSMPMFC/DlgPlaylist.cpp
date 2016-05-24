// DlgPlaylist.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DSMPMFC.h"
#include "DlgPlaylist.h"
#include "afxdialogex.h"


// CDlgPlaylist �Ի���

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


// CDlgPlaylist ��Ϣ�������


BOOL CDlgPlaylist::DestroyWindow()
{
	// TODO: �ڴ����ר�ô����/����û���
	m_isOpen = false;
	return CDialogEx::DestroyWindow();
}


//BOOL CDlgPlaylist::Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
//{
//	// TODO: �ڴ����ר�ô����/����û���
//	m_isOpen = true;
//	return CDialogEx::Create(lpszTemplateName, pParentWnd);
//}


void CDlgPlaylist::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);
	
	// TODO: �ڴ˴������Ϣ����������
	m_isOpen = bShow?true:false;
}


void CDlgPlaylist::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���
	ShowWindow(SW_HIDE);
	//CDialogEx::OnCancel();
}

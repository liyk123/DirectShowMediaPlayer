// DlgLrc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DSMPMFC.h"
#include "DlgLrc.h"
#include "afxdialogex.h"


// CDlgLrc �Ի���

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


// CDlgLrc ��Ϣ�������


//BOOL CDlgLrc::Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
//{
//	// TODO: �ڴ����ר�ô����/����û���
//
//	return CDialogEx::Create(lpszTemplateName, pParentWnd);
//}


BOOL CDlgLrc::DestroyWindow()
{
	// TODO: �ڴ����ר�ô����/����û���
	m_isOpen = false;
	return CDialogEx::DestroyWindow();
}


void CDlgLrc::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);
	
	// TODO: �ڴ˴������Ϣ����������
	m_isOpen = bShow ? true : false;
}


void CDlgLrc::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���
	ShowWindow(SW_HIDE);
	//CDialogEx::OnCancel();
}

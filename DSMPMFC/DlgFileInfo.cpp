// DlgFileInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DSMPMFC.h"
#include "DlgFileInfo.h"
#include "afxdialogex.h"


// CDlgFileInfo �Ի���

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


// CDlgFileInfo ��Ϣ�������


BOOL CDlgFileInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_FileinfoCtl.SetWindowTextW(m_Fileinfo.c_str());
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

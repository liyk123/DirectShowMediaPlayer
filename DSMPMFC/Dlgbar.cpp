// Dlgbar.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DSMPMFC.h"
#include "Dlgbar.h"
#include "afxdialogex.h"


// CDlgbar �Ի���

IMPLEMENT_DYNAMIC(CDlgbar, CDialogBar)

CDlgbar::CDlgbar(CWnd* pParent /*=NULL*/)
    : CDialogBar()
{
}

CDlgbar::~CDlgbar()
{
}

void CDlgbar::DoDataExchange(CDataExchange* pDX)
{
}


BEGIN_MESSAGE_MAP(CDlgbar, CDialogBar)
    ON_MESSAGE(WM_INITDIALOG, &CDlgbar::OnInitdialog)
END_MESSAGE_MAP()


// CDlgbar ��Ϣ�������


afx_msg LRESULT CDlgbar::OnInitdialog(WPARAM wParam, LPARAM lParam)
{
    BOOL bRet = HandleInitDialog(wParam, lParam);

    if(!UpdateData(FALSE))
    {
        TRACE("InitCDataStatus Failed��");
    }

    return TRUE;
}

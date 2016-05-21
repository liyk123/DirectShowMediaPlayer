// Dlgbar.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DSMPMFC.h"
#include "Dlgbar.h"
#include "afxdialogex.h"
#include "MainFrm.h"

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
	DDX_Control(pDX, IDC_SLIDER_PRG, m_sctl);
}


BEGIN_MESSAGE_MAP(CDlgbar, CDialogBar)
    ON_MESSAGE(WM_INITDIALOG, OnInitdialog)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CDlgbar ��Ϣ�������


afx_msg LRESULT CDlgbar::OnInitdialog(WPARAM wParam, LPARAM lParam)
{
    BOOL bRet = HandleInitDialog(wParam, lParam);

    if(!UpdateData(FALSE))
    {
        TRACE("InitCDataStatus Failed��");
    }
	CRect rect;
	::GetClientRect(GetParent()->GetSafeHwnd(),&rect);
	//m_sctl.Create(0, rect, this, IDC_SLIDER_PRG);
	m_sctl.SetLineSize(20);
	//m_sctl.SetBuddy(GetParentFrame());
	m_sctl.SetPageSize(200);
	m_sctl.SetRange(0, 1000);
    return TRUE;
}


void CDlgbar::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	//CDSMPMFCView* pView = (CDSMPMFCView*)pFrame->GetActiveView();
	CMainFrame* pFrame = (CMainFrame*)GetParentFrame();
	CDSMPMFCDoc* pDoc = (CDSMPMFCDoc*)pFrame->GetActiveDocument();
	if (!pDoc->m_pmf->isPlaying)
		m_sctl.SetPos(0);
	else if(nSBCode== SB_THUMBPOSITION)
		pDoc->m_pmf->Seek(m_sctl.GetPos());
	CDialogBar::OnHScroll(nSBCode, nPos, pScrollBar);
}

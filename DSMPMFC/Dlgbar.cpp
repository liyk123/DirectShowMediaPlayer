// Dlgbar.cpp : 实现文件
//

#include "stdafx.h"
#include "DSMPMFC.h"
#include "Dlgbar.h"
#include "afxdialogex.h"
#include "MainFrm.h"

// CDlgbar 对话框

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
	DDX_Control(pDX, IDC_SLIDER_VOL, m_vctl);
}


BEGIN_MESSAGE_MAP(CDlgbar, CDialogBar)
    ON_MESSAGE(WM_INITDIALOG, OnInitdialog)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CDlgbar 消息处理程序


afx_msg LRESULT CDlgbar::OnInitdialog(WPARAM wParam, LPARAM lParam)
{
    BOOL bRet = HandleInitDialog(wParam, lParam);

    if(!UpdateData(FALSE))
    {
        TRACE("InitCDataStatus Failed！");
    }
	CRect rect;
	::GetClientRect(GetParent()->GetSafeHwnd(),&rect);
	m_sctl.SetLineSize(20);
	m_sctl.SetPageSize(200);
	m_sctl.SetRange(0, 1000);
	m_vctl.SetLineSize(2);
	m_vctl.SetPageSize(20);
	m_vctl.SetRange(0, 100);
	m_vctl.SetPos(100);
    return TRUE;
}


void CDlgbar::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	//CDSMPMFCView* pView = (CDSMPMFCView*)pFrame->GetActiveView();
	CMainFrame* pFrame = (CMainFrame*)GetParentFrame();
	CDSMPMFCDoc* pDoc = (CDSMPMFCDoc*)pFrame->GetActiveDocument();
	if (pScrollBar->GetSafeHwnd() == m_sctl.GetSafeHwnd())
	{
		if (!pDoc->m_pmf->isPlaying)
			m_sctl.SetPos(0);
		else if (nSBCode == SB_THUMBPOSITION)
			pDoc->m_pmf->Seek(m_sctl.GetPos());
	}
	else if (pScrollBar->GetSafeHwnd() == m_vctl.GetSafeHwnd())
	{
		if (pDoc->m_pmf->isPlaying/*&&nSBCode == SB_THUMBPOSITION*/)
			pDoc->m_pmf->pAudio->put_Volume(CDSMPMFCDoc::volumes[m_vctl.GetPos()]);
	}
	CDialogBar::OnHScroll(nSBCode, nPos, pScrollBar);
}

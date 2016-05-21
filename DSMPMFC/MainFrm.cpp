
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "DSMPMFC.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
    ON_WM_CREATE()
//  ON_COMMAND(ID_BTN_PLAY, &CMainFrame::OnBtnPlay)
//  ON_COMMAND(ID_BTN_PAUSE, &CMainFrame::OnBtnPause)
//  ON_COMMAND(ID_BTN_STOP, &CMainFrame::OnBtnStop)
    ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()

static UINT indicators[] =
{
    ID_SEPARATOR,           // ״̬��ָʾ��
    ID_INDICATOR_CAPS,
    ID_INDICATOR_NUM,
    ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
    // TODO: �ڴ���ӳ�Ա��ʼ������
	m_bFullScreenMode = FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if(CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;

    if(!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_BOTTOM | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
            !m_wndToolBar.LoadToolBar(IDR_TB_PLAY_CTL))
    {
        TRACE0("δ�ܴ���������\n");
        return -1;      // δ�ܴ���
    }

    if(!m_wndStatusBar.Create(this))
    {
        TRACE0("δ�ܴ���״̬��\n");
        return -1;      // δ�ܴ���
    }

    m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

    if(!m_wnddlgbar.Create(this, IDD_DIALOGBAR_CTL, WS_VISIBLE | WS_CHILD | CBRS_SIZE_DYNAMIC | CBRS_BOTTOM, IDD_DIALOGBAR_CTL))
    {
        TRACE0("Failed to create CDlgbar bar!");
        return -1;
    }

    // TODO: �������Ҫ��ͣ������������ɾ��������
    m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
    EnableDocking(CBRS_ALIGN_ANY);
    DockControlBar(&m_wndToolBar);
    //GetMenu()->GetSubMenu(0)->EnableMenuItem(3, MF_BYPOSITION | MF_DISABLED | MF_GRAYED);
    return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
    if(!CFrameWnd::PreCreateWindow(cs))
        return FALSE;

    // TODO: �ڴ˴�ͨ���޸�
    //  CREATESTRUCT cs ���޸Ĵ��������ʽ
    return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
    CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
    CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������



//void CMainFrame::OnBtnPlay()
//{
//  // TODO: �ڴ���������������
//  //HRESULT hr = this->GetActiveDocument()->m_pmf->pGraph->RenderFile(cstr_urlw, NULL);
//}


//void CMainFrame::OnBtnPause()
//{
//  // TODO: �ڴ���������������
//}


//void CMainFrame::OnBtnStop()
//{
//  // TODO: �ڴ���������������
//}


CStatusBar * CMainFrame::MainFrameGetStBar()
{
    return &m_wndStatusBar;
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
    // TODO: �ڴ����ר�ô����/����û���
    if(m_wnddlgbar.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
        return TRUE;

    return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}


void CMainFrame::FullScreenModeOn()
{
    GetWindowPlacement(&m_OldWndPlacement);
    CRect WindowRect;
    GetWindowRect(&WindowRect);
    CRect ClientRect;
    RepositionBars(0, 0xffff, AFX_IDW_PANE_FIRST, reposQuery, &ClientRect);
    ClientToScreen(&ClientRect);
    // ��ȡ��Ļ�ķֱ���
    int nFullWidth = GetSystemMetrics(SM_CXSCREEN);
    int nFullHeight = GetSystemMetrics(SM_CYSCREEN);
    //������������Ŀͻ���ȫ����ʾ����(0,0)��(nFullWidth, nFullHeight)����,
    //��(0,0)��(nFullWidth, nFullHeight)������������ԭ���ںͳ�������֮��� �ͻ���λ�ü�Ĳ�ֵ, �͵õ�ȫ����ʾ�Ĵ���λ��
    m_FullScreenRect.left = WindowRect.left - ClientRect.left;
    m_FullScreenRect.top = WindowRect.top - ClientRect.top;
    m_FullScreenRect.right = WindowRect.right - ClientRect.right + nFullWidth;
    m_FullScreenRect.bottom = WindowRect.bottom - ClientRect.bottom + nFullHeight;
    m_bFullScreenMode = TRUE;
    //����ȫ����ʾ��־Ϊ TRUE
    //����ȫ����ʾ״̬
    WINDOWPLACEMENT wndpl;
    wndpl.length = sizeof(WINDOWPLACEMENT);
    wndpl.flags = 0;
    wndpl.showCmd = SW_SHOWNORMAL;
    wndpl.rcNormalPosition = m_FullScreenRect;
    SetWindowPlacement(&wndpl);
    m_bFullScreenMode = TRUE;
}


void CMainFrame::FullScreenModeOff()
{
	ShowWindow(SW_HIDE);
	SetWindowPlacement(&m_OldWndPlacement);
	m_bFullScreenMode = FALSE;
}


void CMainFrame::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_bFullScreenMode)
	{
		lpMMI->ptMaxSize.x = m_FullScreenRect.Width();
		lpMMI->ptMaxSize.y = m_FullScreenRect.Height();
		lpMMI->ptMaxPosition.x = m_FullScreenRect.Width();
		lpMMI->ptMaxPosition.y = m_FullScreenRect.Height();
		// ����Track�ߴ�ҲҪ�ı� 
		lpMMI->ptMaxTrackSize.x = m_FullScreenRect.Width();
		lpMMI->ptMaxTrackSize.y = m_FullScreenRect.Height();
	}
	CFrameWnd::OnGetMinMaxInfo(lpMMI);
}

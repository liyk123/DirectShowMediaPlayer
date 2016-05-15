
// MainFrm.cpp : CMainFrame 类的实现
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
END_MESSAGE_MAP()

static UINT indicators[] =
{
    ID_SEPARATOR,           // 状态行指示器
    ID_INDICATOR_CAPS,
    ID_INDICATOR_NUM,
    ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
    // TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if(CFrameWnd::OnCreate(lpCreateStruct) == -1)
        return -1;

    if(!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
            !m_wndToolBar.LoadToolBar(IDR_TB_PLAY_CTL))
    {
        TRACE0("未能创建工具栏\n");
        return -1;      // 未能创建
    }

    if(!m_wndStatusBar.Create(this))
    {
        TRACE0("未能创建状态栏\n");
        return -1;      // 未能创建
    }

    m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

    if(!m_wnddlgbar.Create(this, IDD_DIALOGBAR_CTL, WS_VISIBLE | WS_CHILD | CBRS_SIZE_DYNAMIC | CBRS_BOTTOM, IDD_DIALOGBAR_CTL))
    {
        TRACE0("Failed to create CDlgbar bar!");
        return -1;
    }

    // TODO: 如果不需要可停靠工具栏，则删除这三行
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

    // TODO: 在此处通过修改
    //  CREATESTRUCT cs 来修改窗口类或样式
    return TRUE;
}

// CMainFrame 诊断

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


// CMainFrame 消息处理程序



//void CMainFrame::OnBtnPlay()
//{
//  // TODO: 在此添加命令处理程序代码
//  //HRESULT hr = this->GetActiveDocument()->m_pmf->pGraph->RenderFile(cstr_urlw, NULL);
//}


//void CMainFrame::OnBtnPause()
//{
//  // TODO: 在此添加命令处理程序代码
//}


//void CMainFrame::OnBtnStop()
//{
//  // TODO: 在此添加命令处理程序代码
//}


BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
    // TODO: 在此添加专用代码和/或调用基类
    if(m_wnddlgbar.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
        return TRUE;

    return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

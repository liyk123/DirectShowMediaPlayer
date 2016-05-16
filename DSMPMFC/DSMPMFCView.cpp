
// DSMPMFCView.cpp : CDSMPMFCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DSMPMFC.h"
#endif

#include "DSMPMFCDoc.h"
#include "DSMPMFCView.h"
#include "DlgFileInfo.h"
#include "MediaInfoDLL.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDSMPMFCView

IMPLEMENT_DYNCREATE(CDSMPMFCView, CView)

BEGIN_MESSAGE_MAP(CDSMPMFCView, CView)
    // 标准打印命令
    ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_UPDATE_COMMAND_UI(ID_BTN_PLAY, &CDSMPMFCView::OnUpdateBtnPlay)
//  ON_COMMAND(ID_BTN_PAUSE, &CDSMPMFCView::OnBtnPause)
    ON_UPDATE_COMMAND_UI(ID_BTN_STOP, &CDSMPMFCView::OnUpdateBtnStop)
    ON_UPDATE_COMMAND_UI(ID_BTN_PAUSE, &CDSMPMFCView::OnUpdateBtnPause)
    ON_COMMAND(ID_FILE_INFO, &CDSMPMFCView::OnFileInfo)
    ON_UPDATE_COMMAND_UI(ID_FILE_INFO, &CDSMPMFCView::OnUpdateFileInfo)
    ON_COMMAND(ID_BTN_PAUSE, &CDSMPMFCView::OnBtnPause)
    ON_COMMAND(ID_BTN_PLAY, &CDSMPMFCView::OnBtnPlay)
    ON_COMMAND(ID_BTN_STOP, &CDSMPMFCView::OnBtnStop)
    ON_WM_PAINT()
END_MESSAGE_MAP()

// CDSMPMFCView 构造/析构

CDSMPMFCView::CDSMPMFCView()
{
    // TODO: 在此处添加构造代码
}

CDSMPMFCView::~CDSMPMFCView()
{
}

BOOL CDSMPMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
    // TODO: 在此处通过修改
    //  CREATESTRUCT cs 来修改窗口类或样式
    return CView::PreCreateWindow(cs);
}

// CDSMPMFCView 绘制

void CDSMPMFCView::OnDraw(CDC* pDC)
{
    CDSMPMFCDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    if(!pDoc)
        return;

    // TODO: 在此处为本机数据添加绘制代码
//    CRect rect;
//    CDC memDC;
//    BITMAP bi;
//    pDoc->m_backgraph.GetObjectW(sizeof(bi), &bi);
//    memDC.CreateCompatibleDC(pDC);
//    memDC.SelectObject(&pDoc->m_backgraph);
//    GetClientRect(&rect);
//    int width = 0, height = 0;
//    int xPos = 0, yPos = 0;
//
//    if(rect.Width() * 10 / rect.Height() > bi.bmWidth * 10 / bi.bmHeight)
//    {
//        height = rect.Height();
//        width = height * (bi.bmWidth * 1000 / bi.bmHeight) / 1000;
//        xPos = rect.Width() - width;
//        xPos = xPos >> 1;
//    }
//    else
//    {
//        width = rect.Width();
//        height = width * (bi.bmHeight * 1000 / bi.bmWidth) / 1000;
//        yPos = rect.Height() - height;
//        yPos = yPos >> 1;
//    }
//
////  pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);
//    pDC->StretchBlt(xPos, yPos, width, height, &memDC, 0, 0, bi.bmWidth , bi.bmHeight, SRCCOPY);
//    CString txt;
//    txt.Format(L"%d:%d", width, height);
//    pDC->DrawTextW(txt, rect, 0);
}


// CDSMPMFCView 打印

BOOL CDSMPMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
    // 默认准备
    return DoPreparePrinting(pInfo);
}

void CDSMPMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: 添加额外的打印前进行的初始化过程
}

void CDSMPMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: 添加打印后进行的清理过程
}


// CDSMPMFCView 诊断

#ifdef _DEBUG
void CDSMPMFCView::AssertValid() const
{
    CView::AssertValid();
}

void CDSMPMFCView::Dump(CDumpContext& dc) const
{
    CView::Dump(dc);
}

CDSMPMFCDoc* CDSMPMFCView::GetDocument() const // 非调试版本是内联的
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDSMPMFCDoc)));
    return (CDSMPMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CDSMPMFCView 消息处理程序


void CDSMPMFCView::OnUpdateBtnPlay(CCmdUI *pCmdUI)
{
    // TODO: 在此添加命令更新用户界面处理程序代码
    if(GetDocument()->m_playlist.empty())
        pCmdUI->Enable(FALSE);
    else
        pCmdUI->Enable(TRUE);

    if(GetDocument()->m_pmf->isPlaying)
        pCmdUI->Enable(FALSE);

    if(GetDocument()->m_pmf->isPaused)
        pCmdUI->Enable(TRUE);
}


//void CDSMPMFCView::OnBtnPause()
//{
//  // TODO: 在此添加命令处理程序代码
//}


void CDSMPMFCView::OnUpdateBtnStop(CCmdUI *pCmdUI)
{
    // TODO: 在此添加命令更新用户界面处理程序代码
    if(GetDocument()->m_playlist.empty())
        pCmdUI->Enable(FALSE);
    else
        pCmdUI->Enable(TRUE);
	if (!GetDocument()->m_pmf->isPlaying)
		pCmdUI->Enable(FALSE);
}


void CDSMPMFCView::OnUpdateBtnPause(CCmdUI *pCmdUI)
{
    // TODO: 在此添加命令更新用户界面处理程序代码
    if(GetDocument()->m_playlist.empty())
        pCmdUI->Enable(FALSE);
    else
        pCmdUI->Enable(TRUE);

    if(!GetDocument()->m_pmf->isPlaying || GetDocument()->m_pmf->isPaused)
        pCmdUI->Enable(FALSE);
}


void CDSMPMFCView::OnFileInfo()
{
    // TODO: 在此添加命令处理程序代码
    CDlgFileInfo dlg;
    MediaInfoDLL::MediaInfo mi;
    MediaInfoDLL::String str = mi.Option(L"Info_Version");
    auto tstr = GetDocument()->m_playlist.front().GetString();
    mi.Open(tstr);
    mi.Option(L"Complete");
    str += L"\t\r\n";
    str += mi.Inform().c_str();
    mi.Close();
    dlg.m_Fileinfo = str;
    dlg.DoModal();
}


void CDSMPMFCView::OnUpdateFileInfo(CCmdUI *pCmdUI)
{
    // TODO: 在此添加命令更新用户界面处理程序代码
    if(GetDocument()->m_playlist.empty())
        pCmdUI->Enable(FALSE);
    else
        pCmdUI->Enable(TRUE);
}


void CDSMPMFCView::OnBtnPause()
{
    // TODO: 在此添加命令处理程序代码
    GetDocument()->m_pmf->pControl->Pause();
    GetDocument()->m_pmf->isPaused = true;
}


void CDSMPMFCView::OnBtnPlay()
{
    // TODO: 在此添加命令处理程序代码
	if(!GetDocument()->m_pmf->isPlaying)
		GetDocument()->m_pmf->name = GetDocument()->m_playlist.front();
    GetDocument()->m_pmf->Play(GetSafeHwnd());
}


void CDSMPMFCView::OnBtnStop()
{
    // TODO: 在此添加命令处理程序代码
    GetDocument()->m_pmf->Stop();
}


void CDSMPMFCView::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO: 在此处添加消息处理程序代码
    PAINTSTRUCT ps;
    RECT        rcClient, rc2, g_rcDest;
    HWND hwnd = GetSafeHwnd();
    ::GetClientRect(hwnd, &rcClient);
    GetClientRect(&rc2);
    ::BeginPaint(hwnd, &ps);
    auto pf = GetDocument()->m_pmf;
    auto g_pWc = pf->ppWc;
    SetRect(&g_rcDest, 0, 0, rcClient.bottom - pf->width, rcClient.top - pf->height);

    if(g_pWc != NULL&&pf->width+pf->height)
    {
        // 查找窗体需要重绘的客户区，该区域应该减去视频显示的区域
        // (这里假设g_rcDest 是已经计算好了的区域)
        HRGN rgnClient = CreateRectRgnIndirect(&rcClient);
        HRGN rgnVideo = CreateRectRgnIndirect(&g_rcDest);
        CombineRgn(rgnClient, rgnClient, rgnVideo, RGN_DIFF);
        // 重绘窗体
        HBRUSH hbr = GetSysColorBrush(COLOR_DESKTOP);
        FillRgn(dc, rgnClient, hbr);
        // 释放对象
        DeleteObject(hbr);
        DeleteObject(rgnClient);
        DeleteObject(rgnVideo);
        // 请求VMR to 重绘视频
        RECT rcSrc, rcDest;
        // 设置Source尺寸
        SetRect(&rcSrc, 0, 0, GetDocument()->m_pmf->width, GetDocument()->m_pmf->height);
        // 获得显示窗体的客户区尺寸
        ::GetClientRect(hwnd, &rcDest);
        //设置destination尺寸
        SetRect(&rcDest, 0, 0, rcDest.right, rcDest.bottom);
        // 视频定位
		//g_pWc->SetAspectRatioMode(VMR_ARMODE_LETTER_BOX);
        HRESULT hr = g_pWc->SetVideoPosition(&rcSrc, &rcDest);
        hr = g_pWc->RepaintVideo(hwnd, dc);
    }
    else  // 没有视频显示，重绘整个客户区
    {
        FillRect(dc, &rc2, (HBRUSH)(COLOR_DESKTOP));
    }

    ::EndPaint(hwnd, &ps);
    //CString str;
    //str.Format(L"%d,%d,%d,%d", rcClient.bottom, rcClient.top, rcClient.left, rcClient.right);
    //CRect rect;
    //GetClientRect(rect);
    //dc.DrawText(str, rect, 0);
    // 不为绘图消息调用 CView::OnPaint()
}


// DSMPMFCView.cpp : CDSMPMFCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
    // ��׼��ӡ����
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

// CDSMPMFCView ����/����

CDSMPMFCView::CDSMPMFCView()
{
    // TODO: �ڴ˴���ӹ������
}

CDSMPMFCView::~CDSMPMFCView()
{
}

BOOL CDSMPMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
    // TODO: �ڴ˴�ͨ���޸�
    //  CREATESTRUCT cs ���޸Ĵ��������ʽ
    return CView::PreCreateWindow(cs);
}

// CDSMPMFCView ����

void CDSMPMFCView::OnDraw(CDC* pDC)
{
    CDSMPMFCDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    if(!pDoc)
        return;

    // TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


// CDSMPMFCView ��ӡ

BOOL CDSMPMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
    // Ĭ��׼��
    return DoPreparePrinting(pInfo);
}

void CDSMPMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDSMPMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: ��Ӵ�ӡ����е��������
}


// CDSMPMFCView ���

#ifdef _DEBUG
void CDSMPMFCView::AssertValid() const
{
    CView::AssertValid();
}

void CDSMPMFCView::Dump(CDumpContext& dc) const
{
    CView::Dump(dc);
}

CDSMPMFCDoc* CDSMPMFCView::GetDocument() const // �ǵ��԰汾��������
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDSMPMFCDoc)));
    return (CDSMPMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CDSMPMFCView ��Ϣ�������


void CDSMPMFCView::OnUpdateBtnPlay(CCmdUI *pCmdUI)
{
    // TODO: �ڴ������������û����洦��������
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
//  // TODO: �ڴ���������������
//}


void CDSMPMFCView::OnUpdateBtnStop(CCmdUI *pCmdUI)
{
    // TODO: �ڴ������������û����洦��������
    if(GetDocument()->m_playlist.empty())
        pCmdUI->Enable(FALSE);
    else
        pCmdUI->Enable(TRUE);
	if (!GetDocument()->m_pmf->isPlaying)
		pCmdUI->Enable(FALSE);
}


void CDSMPMFCView::OnUpdateBtnPause(CCmdUI *pCmdUI)
{
    // TODO: �ڴ������������û����洦��������
    if(GetDocument()->m_playlist.empty())
        pCmdUI->Enable(FALSE);
    else
        pCmdUI->Enable(TRUE);

    if(!GetDocument()->m_pmf->isPlaying || GetDocument()->m_pmf->isPaused)
        pCmdUI->Enable(FALSE);
}


void CDSMPMFCView::OnFileInfo()
{
    // TODO: �ڴ���������������
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
    // TODO: �ڴ������������û����洦��������
    if(GetDocument()->m_playlist.empty())
        pCmdUI->Enable(FALSE);
    else
        pCmdUI->Enable(TRUE);
}


void CDSMPMFCView::OnBtnPause()
{
    // TODO: �ڴ���������������
    GetDocument()->m_pmf->pControl->Pause();
    GetDocument()->m_pmf->isPaused = true;
}


void CDSMPMFCView::OnBtnPlay()
{
    // TODO: �ڴ���������������
	if(!GetDocument()->m_pmf->isPlaying)
		GetDocument()->m_pmf->name = GetDocument()->m_playlist.front();
    GetDocument()->m_pmf->Play(GetSafeHwnd());
}


void CDSMPMFCView::OnBtnStop()
{
    // TODO: �ڴ���������������
    GetDocument()->m_pmf->Stop();
}


void CDSMPMFCView::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO: �ڴ˴������Ϣ����������
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
        // ���Ҵ�����Ҫ�ػ�Ŀͻ�����������Ӧ�ü�ȥ��Ƶ��ʾ������
        // (�������g_rcDest ���Ѿ�������˵�����)
        HRGN rgnClient = CreateRectRgnIndirect(&rcClient);
        HRGN rgnVideo = CreateRectRgnIndirect(&g_rcDest);
        CombineRgn(rgnClient, rgnClient, rgnVideo, RGN_DIFF);
        // �ػ洰��
        HBRUSH hbr = GetSysColorBrush(COLOR_DESKTOP);
        FillRgn(dc, rgnClient, hbr);
        // �ͷŶ���
        DeleteObject(hbr);
        DeleteObject(rgnClient);
        DeleteObject(rgnVideo);
        // ����VMR to �ػ���Ƶ
        RECT rcSrc, rcDest;
        // ����Source�ߴ�
        SetRect(&rcSrc, 0, 0, GetDocument()->m_pmf->width, GetDocument()->m_pmf->height);
        // �����ʾ����Ŀͻ����ߴ�
        ::GetClientRect(hwnd, &rcDest);
        //����destination�ߴ�
        SetRect(&rcDest, 0, 0, rcDest.right, rcDest.bottom);
        // ��Ƶ��λ
		//g_pWc->SetAspectRatioMode(VMR_ARMODE_LETTER_BOX);
        HRESULT hr = g_pWc->SetVideoPosition(&rcSrc, &rcDest);
        hr = g_pWc->RepaintVideo(hwnd, dc);
    }
    else  // û����Ƶ��ʾ���ػ������ͻ���
    {
        FillRect(dc, &rc2, (HBRUSH)(COLOR_DESKTOP));
    }

    ::EndPaint(hwnd, &ps);
    //CString str;
    //str.Format(L"%d,%d,%d,%d", rcClient.bottom, rcClient.top, rcClient.left, rcClient.right);
    //CRect rect;
    //GetClientRect(rect);
    //dc.DrawText(str, rect, 0);
    // ��Ϊ��ͼ��Ϣ���� CView::OnPaint()
}


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
#include "MainFrm.h"
//#include "Dlgbar.h"
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
    ON_WM_TIMER()
    ON_COMMAND(ID_BTN_NEXT, &CDSMPMFCView::OnBtnNext)
    ON_COMMAND(ID_BTN_BACK, &CDSMPMFCView::OnBtnBack)
    ON_UPDATE_COMMAND_UI(ID_BTN_BACK, &CDSMPMFCView::OnUpdateBtnBack)
    ON_UPDATE_COMMAND_UI(ID_BTN_NEXT, &CDSMPMFCView::OnUpdateBtnNext)
    ON_COMMAND(ID_BTN_FS, &CDSMPMFCView::OnBtnFs)
    ON_WM_KEYDOWN()
    ON_MESSAGE(WM_GRAPHNOTIFY, &CDSMPMFCView::OnGraphnotify)
    ON_COMMAND(ID_PLAYLIST, &CDSMPMFCView::OnPlaylist)
    ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, &CDSMPMFCView::OnUpdateFileSave)
    ON_COMMAND(ID_MOD_SEQ, &CDSMPMFCView::OnModSeq)
    ON_COMMAND(ID_MOD_LOOP, &CDSMPMFCView::OnModLoop)
    ON_UPDATE_COMMAND_UI(ID_MOD_SEQ, &CDSMPMFCView::OnUpdateModSeq)
    ON_UPDATE_COMMAND_UI(ID_MOD_LOOP, &CDSMPMFCView::OnUpdateModLoop)
    ON_COMMAND(ID_LRC, &CDSMPMFCView::OnLrc)
    ON_UPDATE_COMMAND_UI(ID_PLAYLIST, &CDSMPMFCView::OnUpdatePlaylist)
    ON_UPDATE_COMMAND_UI(ID_LRC, &CDSMPMFCView::OnUpdateLrc)
    ON_COMMAND(ID_MOD_SLOOP, &CDSMPMFCView::OnModSloop)
    ON_UPDATE_COMMAND_UI(ID_MOD_SLOOP, &CDSMPMFCView::OnUpdateModSloop)
END_MESSAGE_MAP()

// CDSMPMFCView ����/����

CDSMPMFCView::CDSMPMFCView()
{
    // TODO: �ڴ˴���ӹ������
    m_dlgplaylist = new CDlgPlaylist();
    m_dlgplaylist->Create(IDD_DLG_PLIST);
    m_dlglrc = new CDlgLrc();
    m_dlglrc->Create(IDD_DLG_LRC);
}

CDSMPMFCView::~CDSMPMFCView()
{
    if(m_dlgplaylist)
        delete m_dlgplaylist;

    if(m_dlglrc)
        delete m_dlglrc;
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



void CDSMPMFCView::OnUpdateBtnStop(CCmdUI *pCmdUI)
{
    // TODO: �ڴ������������û����洦��������
    if(GetDocument()->m_playlist.empty())
        pCmdUI->Enable(FALSE);
    else
        pCmdUI->Enable(TRUE);

    if(!GetDocument()->m_pmf->isPlaying)
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
	if (GetDocument()->m_playlist.empty())
		return;
    CDlgFileInfo dlg;
    MediaInfoDLL::MediaInfo mi;
    MediaInfoDLL::String str = mi.Option(L"Info_Version");
    auto tstr = GetDocument()->m_playlist.at(GetDocument()->m_plist_selector).GetString();
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
    GetDocument()->m_pmf->Pause();
}


void CDSMPMFCView::OnBtnPlay()
{
    // TODO: �ڴ���������������
    if(!GetDocument()->m_pmf->isPlaying)
    {
        CString name_t = GetDocument()->m_playlist.at(GetDocument()->m_plist_selector);
        GetDocument()->m_pmf->name = name_t;
    }

    GetDocument()->m_pmf->Play(GetSafeHwnd());
    m_dlgplaylist->m_listbox.SetCurSel(GetDocument()->m_plist_selector);
    SetTimer(1, 1000, NULL);

    if(m_dlglrc->m_list_lrc.GetCount())
        SetTimer(2, 10, NULL);
}


void CDSMPMFCView::OnBtnStop()
{
    // TODO: �ڴ���������������
    KillTimer(1);
	if (m_dlglrc->m_list_lrc.GetCount())
		KillTimer(2);
    m_pctrl->SetPos(0);
    CMainFrame* pFrame = (CMainFrame*)GetParent();
    CStatusBar* pSbar = pFrame->MainFrameGetStBar();
	pSbar->SetPaneText(0, L"��ֹͣ");
    pSbar->SetPaneText(1, L"00:00:00/00:00:00");
    GetDocument()->m_pmf->Stop();
    ClearScreen();
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

    if(g_pWc != NULL && pf->width + pf->height)
    {
        // ���Ҵ�����Ҫ�ػ�Ŀͻ�����������Ӧ�ü�ȥ��Ƶ��ʾ������
        // g_rcDest ���Ѿ�������˵�����
        HRGN rgnClient = CreateRectRgnIndirect(&rcClient);
        HRGN rgnVideo = CreateRectRgnIndirect(&g_rcDest);
        CombineRgn(rgnClient, rgnClient, rgnVideo, RGN_DIFF);
        // �ػ洰��
        HBRUSH hbr = (HBRUSH)GetStockObject(BLACK_BRUSH);
        FillRgn(dc, rgnClient, hbr);
        // �ͷŶ���
        DeleteObject(hbr);
        DeleteObject(rgnClient);
        DeleteObject(rgnVideo);
        // ����VMR to �ػ���Ƶ
        RECT rcSrc;
        // ����Source�ߴ�
        SetRect(&rcSrc, 0, 0, pf->width, pf->height);
        // ��Ƶ��λ
        HRESULT hr = g_pWc->SetVideoPosition(&rcSrc, &rcClient);
        hr = g_pWc->RepaintVideo(hwnd, dc);
    }
    else  // û����Ƶ��ʾ���ػ������ͻ���
    {
        FillRect(dc, &rc2, (HBRUSH)GetStockObject(BLACK_BRUSH));
    }

    ::EndPaint(hwnd, &ps);
}


void CDSMPMFCView::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    if(nIDEvent == 1)
    {
        CString curtimestr = L"00:00:00", durationstr = L"00:00:00";
        long long curtime = 0;
        long long duration = 0;
        int tns, thh, tmm, tss;
        int progress;
        CMainFrame* pFrame = (CMainFrame*)GetParent();
        CStatusBar* pSbar = pFrame->MainFrameGetStBar();
        auto pSeek = GetDocument()->m_pmf->pSeeking;
        //��ȡʱ��10^(-7)s
        pSeek->GetCurrentPosition(&curtime);

        if(curtime != 0)
        {
            //ת��Ϊ��
            tns = int(curtime / 10000000);
            thh = tns / 3600;
            tmm = (tns % 3600) / 60;
            tss = (tns % 60);
            curtimestr.Format(_T("%02d:%02d:%02d"), thh, tmm, tss);
        }

        pSeek->GetDuration(&duration);

        if(duration != 0)
        {
            tns = int(duration / 10000000);
            thh = tns / 3600;
            tmm = (tns % 3600) / 60;
            tss = (tns % 60);
            durationstr.Format(_T("%02d:%02d:%02d"), thh, tmm, tss);
            progress = int(curtime * 1000 / duration);
            m_pctrl->SetPos(progress);
        }

        CString text;
        text.Format(L"���ڲ���:%s", GetDocument()->m_pmf->name.c_str());
        pSbar->SetPaneText(0, text);
        pSbar->SetPaneText(1, curtimestr + L"/" + durationstr);
    }
    else if(nIDEvent == 2)
    {
        CString curtimestr;
        long long curtime = 0;
        long long duration = 0;
        int tns, tmm, tss, tms;
        CMainFrame* pFrame = (CMainFrame*)GetParent();
        CStatusBar* pSbar = pFrame->MainFrameGetStBar();
        auto pSeek = GetDocument()->m_pmf->pSeeking;
        //��ȡʱ��10^(-7)s
        pSeek->GetCurrentPosition(&curtime);

        if(curtime != 0)
        {
            //ת��Ϊ����
            tns = int(curtime / 10000);
            tmm = tns / 60000;
            tss = (tns % 60000) / 1000;
            tms = (tns % 1000) / 100;
            curtimestr.Format(L"%02d:%02d.%d",  tmm, tss, tms);
            std::wstring tstr(curtimestr.GetString());
            TRACE(L"%d\n", GetDocument()->m_lrc_selector.count(tstr));

            if(m_dlglrc->m_list_lrc.GetCount() && GetDocument()->m_lrc_selector.count(tstr))
                m_dlglrc->m_list_lrc.SetCurSel(GetDocument()->m_lrc_selector[tstr]);
        }
    }

    CView::OnTimer(nIDEvent);
}


void CDSMPMFCView::OnInitialUpdate()
{
    CView::OnInitialUpdate();

    // TODO: �ڴ����ר�ô����/����û���
    if(GetDocument()->m_pmf->isPlaying)
        OnBtnStop();

    m_pctrl = (CNiceSliderCtrl*)(GetParent()->GetDlgItem(IDD_DIALOGBAR_CTL)->GetDlgItem(IDC_SLIDER_PRG));
    m_vctrl = (CNiceSliderCtrl*)(GetParent()->GetDlgItem(IDD_DIALOGBAR_CTL)->GetDlgItem(IDC_SLIDER_VOL));
    m_dlgplaylist->SetWindowTextW(L"�����б�");
    CString text;

    while(m_dlgplaylist->m_listbox.GetCount())
        m_dlgplaylist->m_listbox.DeleteString(0);

    while(m_dlglrc->m_list_lrc.GetCount())
        m_dlglrc->m_list_lrc.DeleteString(0);

    if(GetDocument()->m_isPlaylist)
        m_dlgplaylist->SetWindowTextW(GetDocument()->GetPathName());

    for(auto x : GetDocument()->m_playlist)
    {
        m_dlgplaylist->m_listbox.AddString(x);
    }

    UpdateLrcIndex();
    //if(GetDocument()->m_playlist.size())
    //OnBtnPlay();
}


void CDSMPMFCView::OnBtnNext()
{
    if(GetDocument()->HasNextOrPri(true))
        ++GetDocument()->m_plist_selector %= GetDocument()->m_playlist.size();

    if(GetDocument()->m_pmf->isPlaying)
        OnBtnStop();

    OnBtnPlay();
}


void CDSMPMFCView::OnBtnBack()
{
    TRACE("OnBtnBack\t%d", GetDocument()->HasNextOrPri(false));

    if(GetDocument()->HasNextOrPri(false))
        if(GetDocument()->m_plist_selector == 0)
            GetDocument()->m_plist_selector = GetDocument()->m_playlist.size() - 1;
        else
            GetDocument()->m_plist_selector--;

    if(GetDocument()->m_pmf->isPlaying)
        OnBtnStop();

    OnBtnPlay();
}


void CDSMPMFCView::OnUpdateBtnBack(CCmdUI *pCmdUI)
{
    // TODO: �ڴ������������û����洦��������
    pCmdUI->Enable(GetDocument()->HasNextOrPri(false));
}

void CDSMPMFCView::OnUpdateBtnNext(CCmdUI * pCmdUI)
{
    // TODO: �ڴ������������û����洦��������
    pCmdUI->Enable(GetDocument()->HasNextOrPri(true));
}

void CDSMPMFCView::OnBtnFs()
{
    // TODO: �ڴ���������������
    CMainFrame* pFrame = (CMainFrame*)GetParent();

    if(pFrame->m_bFullScreenMode == FALSE)
        pFrame->FullScreenModeOn();
    else
        pFrame->FullScreenModeOff();
}

void CDSMPMFCView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    switch(nChar)
    {
        case VK_F11:
            {
                OnBtnFs();
                break;
            }

        case VK_F9:
            {
                OnFileInfo();
                break;
            }

        case VK_F8:
            {
                OnPlaylist();
                break;
            }

        case VK_SPACE:
            {
                if(!GetDocument()->m_playlist.empty())
                {
                    if(GetDocument()->m_pmf->isPlaying && !GetDocument()->m_pmf->isPaused)
                        OnBtnPause();
                    else
                        OnBtnPlay();
                }

                break;
            }

        case 'S':
            {
                if(GetDocument()->m_pmf->isPlaying)
                    OnBtnStop();

                break;
            }

        case VK_RIGHT:
            {
				if (!GetDocument()->m_pmf->isPlaying)
					break;
                int nPos = m_pctrl->GetPos() + 50;

                if(nPos > 1000)
                    nPos = 1000;

                m_pctrl->SetPos(nPos);
                GetDocument()->m_pmf->Seek(nPos);
                break;
            }

        case VK_LEFT:
            {
				if (!GetDocument()->m_pmf->isPlaying)
					break;
                int nPos = m_pctrl->GetPos() - 50;

                if(nPos < 0)
                    nPos = 0;

                m_pctrl->SetPos(nPos);
                GetDocument()->m_pmf->Seek(nPos);
                break;
            }

        case VK_PRIOR:
            {
                if(GetDocument()->HasNextOrPri(false))
                    OnBtnBack();

                break;
            }

        case VK_NEXT:
            {
                if(GetDocument()->HasNextOrPri(true))
                    OnBtnNext();

                break;
            }

        case VK_UP:
            {
                int nPos = m_vctrl->GetPos() + 2;

                if(nPos > 100)
                    nPos = 100;

                m_vctrl->SetPos(nPos);
                CMainFrame* pFrame = (CMainFrame*)GetParent();
                CStatusBar* pSbar = pFrame->MainFrameGetStBar();
                CString text;
                text.Format(L"%d%%", m_vctrl->GetPos());
                pSbar->SetPaneText(2, text);
                GetDocument()->m_pmf->m_volume = CDSMPMFCDoc::volumes[nPos];

                if(GetDocument()->m_pmf->isPlaying)
                {
                    GetDocument()->m_pmf->pAudio->put_Volume(GetDocument()->m_pmf->m_volume);
                }

                break;
            }

        case VK_DOWN:
            {
                int nPos = m_vctrl->GetPos() - 2;

                if(nPos < 0)
                    nPos = 0;

                m_vctrl->SetPos(nPos);
                CMainFrame* pFrame = (CMainFrame*)GetParent();
                CStatusBar* pSbar = pFrame->MainFrameGetStBar();
                CString text;
                text.Format(L"%d%%", m_vctrl->GetPos());
                pSbar->SetPaneText(2, text);
                GetDocument()->m_pmf->m_volume = CDSMPMFCDoc::volumes[nPos];

                if(GetDocument()->m_pmf->isPlaying)
                    GetDocument()->m_pmf->pAudio->put_Volume(GetDocument()->m_pmf->m_volume);

                break;
            }

        default:
            break;
    }

    CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

// ����
HRESULT CDSMPMFCView::ClearScreen()
{
    Invalidate(TRUE);
    return S_OK;
}
afx_msg LRESULT CDSMPMFCView::OnGraphnotify(WPARAM wParam, LPARAM lParam)
{
    LONG   eventCode = 0, eventParam1 = 0, eventParam2 = 0;
	CMainFrame* pFrame = (CMainFrame*)GetParent();
	CStatusBar* pSbar = pFrame->MainFrameGetStBar();
    while(SUCCEEDED(GetDocument()->m_pmf->pEvent->GetEvent(&eventCode, &eventParam1, &eventParam2, 0)))
    {
        // Spin through the events
        long long duration;
        GetDocument()->m_pmf->pEvent->FreeEventParams(eventCode, eventParam1, eventParam2);
        GetDocument()->m_pmf->pSeeking->GetDuration(&duration);

        if(duration == 0)
            continue;

        switch(eventCode)
        {
            case EC_COMPLETE:
                {
					pSbar->SetPaneText(0, L"��ֹͣ");
                    if(GetDocument()->m_isSingleloop)
                    {
                        OnBtnPlay();
                        break;
                    }

                    if(GetDocument()->HasNextOrPri(true))
                        OnBtnNext();
                    else
                        OnBtnStop();

                    break;
                }
            case EC_USERABORT:
            case EC_ERRORABORT:
                {
                    OnBtnStop();
                    break;
                }

            default:
                break;
        }
    }

    return 0;
}

void CDSMPMFCView::OnPlaylist()
{
    // TODO: �ڴ���������������
    if(!m_dlgplaylist->m_isOpen)
        m_dlgplaylist->ShowWindow(SW_SHOW);
    else
        m_dlgplaylist->ShowWindow(SW_HIDE);
}


void CDSMPMFCView::OnUpdateFileSave(CCmdUI *pCmdUI)
{
    // TODO: �ڴ������������û����洦��������
    pCmdUI->Enable(GetDocument()->m_isPlaylist);
}


void CDSMPMFCView::OnModSeq()
{
    // TODO: �ڴ���������������
    GetDocument()->m_playlistmode = Playlistmode::sequence;
}


void CDSMPMFCView::OnModLoop()
{
    // TODO: �ڴ���������������
    GetDocument()->m_playlistmode = Playlistmode::loop;
}


void CDSMPMFCView::OnUpdateModSeq(CCmdUI *pCmdUI)
{
    // TODO: �ڴ������������û����洦��������
    pCmdUI->SetCheck(GetDocument()->m_playlistmode == Playlistmode::sequence);
}


void CDSMPMFCView::OnUpdateModLoop(CCmdUI *pCmdUI)
{
    // TODO: �ڴ������������û����洦��������
    pCmdUI->SetCheck(GetDocument()->m_playlistmode == Playlistmode::loop);
}


void CDSMPMFCView::OnLrc()
{
    // TODO: �ڴ���������������
    if(!m_dlglrc->m_isOpen)
        m_dlglrc->ShowWindow(SW_SHOW);
    else
        m_dlglrc->ShowWindow(SW_HIDE);
}


void CDSMPMFCView::RstrToUnicode(CString& str, UINT CodePage)
{
    char *szBuf = new char[str.GetLength() + 1];//ע�⡰+1����char�ַ�Ҫ�����������CStringû��
    memset(szBuf, '\0', str.GetLength());
    int i;

    for(i = 0; i < str.GetLength(); i++)
    {
        szBuf[i] = (char)str.GetAt(i);
    }

    szBuf[i] = '\0';//���������������ĩβ�������롣
    int nLen;
    WCHAR *ptch;
    CString strOut;

    if(szBuf == NULL)
    {
        return;
    }

    nLen = MultiByteToWideChar(CodePage, 0, szBuf, -1, NULL, 0);//�����Ҫ�Ŀ��ַ��ֽ���
    ptch = new WCHAR[nLen];
    memset(ptch, '\0', nLen);
    MultiByteToWideChar(CodePage, 0, szBuf, -1, ptch, nLen);
    str.Format(_T("%s"), ptch);

    if(NULL != ptch)
        delete[] ptch;

    ptch = NULL;

    if(NULL != szBuf)
        delete[]szBuf;

    szBuf = NULL;
}


void CDSMPMFCView::UpdateLrcIndex()
{
    CStdioFile lrcfile;
    CString text, tindex;
    int index;
    CString lrcname = L"";

    if(GetDocument()->m_playlist.size())
        lrcname = GetDocument()->m_playlist.at(GetDocument()->m_plist_selector);

    lrcname = lrcname.Left(lrcname.ReverseFind('.'));
    lrcname.Append(L".lrc");
    TRACE(lrcname);

    if(lrcfile.Open(lrcname, CStdioFile::modeRead))
    {
        index = 0;

        while(lrcfile.ReadString(text))
        {
            RstrToUnicode(text, CP_UTF8);
            tindex = text.Left(text.Find(']'));
            text = text.Right(text.GetLength() - text.Find(']') - 1);
            tindex = tindex.Mid(1, tindex.GetLength() - 2);

            if(text != L"")
            {
                m_dlglrc->m_list_lrc.AddString(text);
                std::wstring tstr(tindex);
                tstr.append(1, 0);
                GetDocument()->m_lrc_selector[tstr.c_str()] = index++;
                TRACE(L"%d%s\n", GetDocument()->m_lrc_selector.count(tstr.c_str()), tstr.c_str());
            }
        }

        lrcfile.Close();
    }
}


void CDSMPMFCView::OnUpdatePlaylist(CCmdUI *pCmdUI)
{
    // TODO: �ڴ������������û����洦��������
    pCmdUI->SetCheck(m_dlgplaylist->m_isOpen);
}


void CDSMPMFCView::OnUpdateLrc(CCmdUI *pCmdUI)
{
    // TODO: �ڴ������������û����洦��������
    pCmdUI->SetCheck(m_dlglrc->m_isOpen);
}


void CDSMPMFCView::OnModSloop()
{
    // TODO: �ڴ���������������
    GetDocument()->m_isSingleloop = !GetDocument()->m_isSingleloop;
}


void CDSMPMFCView::OnUpdateModSloop(CCmdUI *pCmdUI)
{
    // TODO: �ڴ������������û����洦��������
    pCmdUI->SetCheck(GetDocument()->m_isSingleloop);
}

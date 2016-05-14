
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
//	ON_COMMAND(ID_BTN_PAUSE, &CDSMPMFCView::OnBtnPause)
	ON_UPDATE_COMMAND_UI(ID_BTN_STOP, &CDSMPMFCView::OnUpdateBtnStop)
	ON_UPDATE_COMMAND_UI(ID_BTN_PAUSE, &CDSMPMFCView::OnUpdateBtnPause)
	ON_COMMAND(ID_FILE_INFO, &CDSMPMFCView::OnFileInfo)
	ON_UPDATE_COMMAND_UI(ID_FILE_INFO, &CDSMPMFCView::OnUpdateFileInfo)
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

void CDSMPMFCView::OnDraw(CDC* /*pDC*/)
{
	CDSMPMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
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
	if (GetDocument()->m_playlist.empty())
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}


//void CDSMPMFCView::OnBtnPause()
//{
//	// TODO: �ڴ���������������
//}


void CDSMPMFCView::OnUpdateBtnStop(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if (GetDocument()->m_playlist.empty())
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
	
}


void CDSMPMFCView::OnUpdateBtnPause(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if (GetDocument()->m_playlist.empty())
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
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
	if (GetDocument()->m_playlist.empty())
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

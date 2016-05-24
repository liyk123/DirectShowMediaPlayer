
// DSMPMFCView.h : CDSMPMFCView ��Ľӿ�
//

#pragma once
#include "MediaFile.h"
#include "NiceSlider.h"
#include "DlgPlaylist.h"
#include "DlgLrc.h"

class CDSMPMFCView : public CView
{
protected: // �������л�����
	CDSMPMFCView();
	DECLARE_DYNCREATE(CDSMPMFCView)

// ����
public:
	CDSMPMFCDoc* GetDocument() const;
	CNiceSliderCtrl* m_pctrl;
	CNiceSliderCtrl* m_vctrl;
	CDlgPlaylist* m_dlgplaylist;
	CDlgLrc* m_dlglrc;
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDSMPMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnUpdateBtnPlay(CCmdUI *pCmdUI);
//	afx_msg void OnBtnPause();
	afx_msg void OnUpdateBtnStop(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBtnPause(CCmdUI *pCmdUI);
	afx_msg void OnFileInfo();
	afx_msg void OnUpdateFileInfo(CCmdUI *pCmdUI);
	afx_msg void OnBtnPause();
	afx_msg void OnBtnPlay();
	afx_msg void OnBtnStop();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
	afx_msg void OnBtnNext();
	afx_msg void OnBtnBack();
	afx_msg void OnUpdateBtnBack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBtnNext(CCmdUI *pCmdUI);
	afx_msg void OnBtnFs();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	// ����
	HRESULT ClearScreen();
protected:
	afx_msg LRESULT OnGraphnotify(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnPlaylist();
	afx_msg void OnUpdateFileSave(CCmdUI *pCmdUI);
	afx_msg void OnModSeq();
	afx_msg void OnModLoop();
	afx_msg void OnUpdateModSeq(CCmdUI *pCmdUI);
	afx_msg void OnUpdateModLoop(CCmdUI *pCmdUI);
	afx_msg void OnLrc();
	void RstrToUnicode(CString & str, UINT CodePage);
	void UpdateLrcIndex();
	afx_msg void OnUpdatePlaylist(CCmdUI *pCmdUI);
	afx_msg void OnUpdateLrc(CCmdUI *pCmdUI);
	afx_msg void OnModSloop();
};

#ifndef _DEBUG  // DSMPMFCView.cpp �еĵ��԰汾
inline CDSMPMFCDoc* CDSMPMFCView::GetDocument() const
   { return reinterpret_cast<CDSMPMFCDoc*>(m_pDocument); }
#endif


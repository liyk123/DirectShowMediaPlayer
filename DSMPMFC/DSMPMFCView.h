
// DSMPMFCView.h : CDSMPMFCView ��Ľӿ�
//

#pragma once


class CDSMPMFCView : public CView
{
protected: // �������л�����
	CDSMPMFCView();
	DECLARE_DYNCREATE(CDSMPMFCView)

// ����
public:
	CDSMPMFCDoc* GetDocument() const;
	CSliderCtrl* m_pctrl;
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
};

#ifndef _DEBUG  // DSMPMFCView.cpp �еĵ��԰汾
inline CDSMPMFCDoc* CDSMPMFCView::GetDocument() const
   { return reinterpret_cast<CDSMPMFCDoc*>(m_pDocument); }
#endif


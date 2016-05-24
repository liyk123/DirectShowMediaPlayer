
// DSMPMFCView.h : CDSMPMFCView 类的接口
//

#pragma once
#include "MediaFile.h"
#include "NiceSlider.h"
#include "DlgPlaylist.h"
#include "DlgLrc.h"

class CDSMPMFCView : public CView
{
protected: // 仅从序列化创建
	CDSMPMFCView();
	DECLARE_DYNCREATE(CDSMPMFCView)

// 特性
public:
	CDSMPMFCDoc* GetDocument() const;
	CNiceSliderCtrl* m_pctrl;
	CNiceSliderCtrl* m_vctrl;
	CDlgPlaylist* m_dlgplaylist;
	CDlgLrc* m_dlglrc;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDSMPMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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
	// 清屏
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

#ifndef _DEBUG  // DSMPMFCView.cpp 中的调试版本
inline CDSMPMFCDoc* CDSMPMFCView::GetDocument() const
   { return reinterpret_cast<CDSMPMFCDoc*>(m_pDocument); }
#endif


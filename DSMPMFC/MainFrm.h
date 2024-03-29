
// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include "Dlgbar.h"
class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
	CDlgbar           m_wnddlgbar;
// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
//	afx_msg void OnBtnPlay();
//	afx_msg void OnBtnPause();
//	afx_msg void OnBtnStop();
//	CDlgbar* pBar;
	CStatusBar *MainFrameGetStBar();
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	BOOL m_bFullScreenMode;
private:
	WINDOWPLACEMENT m_OldWndPlacement;
	CRect m_FullScreenRect;
public:
	void FullScreenModeOn();
	void FullScreenModeOff();
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
};



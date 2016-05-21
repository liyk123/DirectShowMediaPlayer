#pragma once
#include "NiceSlider.h"
#include "DSMPMFCDoc.h"
// CDlgbar �Ի���

class CDlgbar : public CDialogBar
{
	DECLARE_DYNAMIC(CDlgbar)

public:
	CDlgbar(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgbar();
	CNiceSliderCtrl m_sctl;
	CNiceSliderCtrl m_vctl;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGBAR_CTL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	afx_msg LRESULT OnInitdialog(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};


// DSMPMFC.h : DSMPMFC Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CDSMPMFCApp:
// �йش����ʵ�֣������ DSMPMFC.cpp
//

class CDSMPMFCApp : public CWinApp
{
public:
	CDSMPMFCApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	COleTemplateServer m_server;
		// �����ĵ������ķ���������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDSMPMFCApp theApp;


// DSMPMFC.h : DSMPMFC 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CDSMPMFCApp:
// 有关此类的实现，请参阅 DSMPMFC.cpp
//

class CDSMPMFCApp : public CWinApp
{
public:
	CDSMPMFCApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	COleTemplateServer m_server;
		// 用于文档创建的服务器对象
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDSMPMFCApp theApp;

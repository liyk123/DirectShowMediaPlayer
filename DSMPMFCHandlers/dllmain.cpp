// dllmain.cpp: DllMain 的实现。

#include "stdafx.h"
#include "resource.h"
#include "DSMPMFCHandlers_i.h"
#include "dllmain.h"
#include "xdlldata.h"

CDSMPMFCHandlersModule _AtlModule;

class CDSMPMFCHandlersApp : public CWinApp
{
public:

// 重写
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CDSMPMFCHandlersApp, CWinApp)
END_MESSAGE_MAP()

CDSMPMFCHandlersApp theApp;

BOOL CDSMPMFCHandlersApp::InitInstance()
{
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, NULL))
		return FALSE;
	return CWinApp::InitInstance();
}

int CDSMPMFCHandlersApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}

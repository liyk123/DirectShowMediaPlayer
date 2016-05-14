#pragma once
#include "afxwin.h"
class CMyDocManager :
    public CDocManager
{
public:
    CMyDocManager();
    virtual BOOL DoPromptFileName(CString& fileName, UINT nIDSTitle, DWORD lFlags, BOOL bOpenFileDialog, CDocTemplate* pTemplate);

    virtual ~CMyDocManager();
};


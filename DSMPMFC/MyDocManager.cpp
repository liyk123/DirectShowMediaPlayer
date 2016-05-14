#include "stdafx.h"
#include "MyDocManager.h"


CMyDocManager::CMyDocManager():CDocManager()
{
}

BOOL CMyDocManager::DoPromptFileName(CString & fileName, UINT nIDSTitle, DWORD lFlags, BOOL bOpenFileDialog, CDocTemplate * pTemplate)
{
	CString strFilter = L"�����б�|*.dsplist|֧�ֵ���Ƶ��ʽ|*.mp3; *.wav; *.aac; *.wma; *.flac|֧�ֵ���Ƶ��ʽ|*.mp4; *.wmv; *.avi; *.mkv|�����ļ�|*.*||";
	CFileDialog fdlg(bOpenFileDialog, NULL, NULL, lFlags, strFilter, NULL);
	if (fdlg.DoModal() == IDOK)
	{
		fileName = fdlg.GetPathName();
		return TRUE;
	}
	return FALSE;
}


CMyDocManager::~CMyDocManager()
{
}

#include "stdafx.h"
#include "MyDocManager.h"


CMyDocManager::CMyDocManager():CDocManager()
{
}

BOOL CMyDocManager::DoPromptFileName(CString & fileName, UINT nIDSTitle, DWORD lFlags, BOOL bOpenFileDialog, CDocTemplate * pTemplate)
{
	CString strFilter = L"播放列表|*.dsplist|支持的音频格式|*.mp3; *.wav; *.aac; *.wma; *.flac|支持的视频格式|*.mp4; *.wmv; *.avi; *.mkv|所有文件|*.*||";
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

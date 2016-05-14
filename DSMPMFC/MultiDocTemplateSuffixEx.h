#pragma once
#include "afxwin.h"
class CMultiDocTemplateSuffixEx :
	public CSingleDocTemplate
{
public:
	CString m_strSuffix;
public:
	CMultiDocTemplateSuffixEx(wchar_t *suffix, UINT nIDResource, CRuntimeClass* pDocClass,
		CRuntimeClass* pFrameClass, CRuntimeClass* pViewClass) :\
		CSingleDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
	{
		m_strSuffix.Format(L"%s", suffix);
	}
	virtual BOOL GetDocString(CString& rString, enum DocStringIndex index) const;

	virtual ~CMultiDocTemplateSuffixEx();
};


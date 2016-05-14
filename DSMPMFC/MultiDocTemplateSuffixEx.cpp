#include "stdafx.h"
#include "MultiDocTemplateSuffixEx.h"


BOOL CMultiDocTemplateSuffixEx::GetDocString(CString & rString, DocStringIndex index) const
{
	if (index == CDocTemplate::filterExt)
	{
		rString = L"." + m_strSuffix;
	}
	else if (index == CDocTemplate::fileNewName || index == CDocTemplate::filterName)
	{
		rString = m_strSuffix + L"(*." + m_strSuffix + L")";
		//rString = L"mp3(*.mp3)";
	}
	else
	{
		__super::GetDocString(rString, index);
	}
	return TRUE;
}


CMultiDocTemplateSuffixEx::~CMultiDocTemplateSuffixEx()
{
}

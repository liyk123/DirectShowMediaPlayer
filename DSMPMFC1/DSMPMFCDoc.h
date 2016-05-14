
// DSMPMFCDoc.h : CDSMPMFCDoc ��Ľӿ�
//


#pragma once
#include <queue>
#include <algorithm>
#include <iostream>
#ifdef _UNICODE
#include <locale>
#endif // _UNICODE
#define LC_INCLUDE
class CDSMPMFCDoc : public CDocument
{
protected: // �������л�����
    CDSMPMFCDoc();
    DECLARE_DYNCREATE(CDSMPMFCDoc)

// ����
public:

// ����
public:

// ��д
public:
    virtual BOOL OnNewDocument();
    virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
    virtual void InitializeSearchContent();
    virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
    virtual ~CDSMPMFCDoc();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
    DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
    // ����Ϊ����������������������ݵ� Helper ����
    void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
    // �����б�
    std::queue<CString> PlayList;
//  afx_msg void OnFileOpen();
    virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
    // ���������б��ļ�
    HRESULT AnalizePlaylist(LPCTSTR lpszPathName);
#ifndef LC_INCLUDE
    // ��Char���ַ�ת��ΪUnicode�ַ�
    int CharToUnicode(char* pchIn, CString* pstrOut);
    BOOL ReadStringToUnicode(CString& str);
#endif // LC_INCLUDE

};

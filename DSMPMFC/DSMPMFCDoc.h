
// DSMPMFCDoc.h : CDSMPMFCDoc ��Ľӿ�
//


#pragma once
#include "MediaFile.h"
#include <deque>
#include <map>
#include <string>

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

	// ���ɵ� OLE ����ӳ�亯��

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	// �����б�
	std::deque<CString> m_playlist;
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	bool m_isPlaylist;
	Playlistmode m_playlistmode;
	CMediaFile *m_pmf;
//	CBitmap m_backgraph;
	UINT32 m_plist_selector;
	static int *volumes;
	std::map<std::wstring, int> m_lrc_selector;
	bool HasNextOrPri(bool flag);
	bool m_isSingleloop;
};

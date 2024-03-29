
// DSMPMFCDoc.h : CDSMPMFCDoc 类的接口
//


#pragma once
#include "MediaFile.h"
#include <deque>
#include <map>
#include <string>

class CDSMPMFCDoc : public CDocument
{
protected: // 仅从序列化创建
	CDSMPMFCDoc();
	DECLARE_DYNCREATE(CDSMPMFCDoc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CDSMPMFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

	// 生成的 OLE 调度映射函数

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	// 播放列表
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

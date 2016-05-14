
// DSMPMFCDoc.cpp : CDSMPMFCDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DSMPMFC.h"
#endif

#include "DSMPMFCDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDSMPMFCDoc

IMPLEMENT_DYNCREATE(CDSMPMFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CDSMPMFCDoc, CDocument)
//	ON_COMMAND(ID_FILE_OPEN, &CDSMPMFCDoc::OnFileOpen)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CDSMPMFCDoc, CDocument)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_IDSMPMFC 的支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {25FA09EB-6767-47CC-85C0-F20C3A12DE67}
static const IID IID_IDSMPMFC =
{ 0x25FA09EB, 0x6767, 0x47CC, { 0x85, 0xC0, 0xF2, 0xC, 0x3A, 0x12, 0xDE, 0x67 } };

BEGIN_INTERFACE_MAP(CDSMPMFCDoc, CDocument)
INTERFACE_PART(CDSMPMFCDoc, IID_IDSMPMFC, Dispatch)
END_INTERFACE_MAP()


// CDSMPMFCDoc 构造/析构

CDSMPMFCDoc::CDSMPMFCDoc()
	: m_isPlaylist(false)
{
    // TODO: 在此添加一次性构造代码
    EnableAutomation();
    AfxOleLockApp();
	m_pmf = new CMediaFile;
}

CDSMPMFCDoc::~CDSMPMFCDoc()
{
    AfxOleUnlockApp();
	delete m_pmf;
}

BOOL CDSMPMFCDoc::OnNewDocument()
{
    if(!CDocument::OnNewDocument())
        return FALSE;
	while (!this->m_playlist.empty())
	{
		this->m_playlist.pop();
	}
    // TODO: 在此添加重新初始化代码
    // (SDI 文档将重用该文档)
    return TRUE;
}




// CDSMPMFCDoc 序列化

void CDSMPMFCDoc::Serialize(CArchive& ar)
{
    if(ar.IsStoring())
    {
        // TODO: 在此添加存储代码
		if (m_isPlaylist)
		{
			while (!this->m_playlist.empty())
			{
				//ar << m_playlist.front() << "\n";
				ar.WriteString(m_playlist.front());
				ar << "\r";
				m_playlist.pop();
			}
		}
    }
    else
    {
        // TODO: 在此添加加载代码
		CString str = L"";
		if (m_isPlaylist)
		{
			while (ar.ReadString(str))
			{
				TRACE(str+L"\n");
				m_playlist.push(str);
			}
		}
		else
		{
			str = ar.m_strFileName;
			m_playlist.push(str);
			m_pmf->name = str;
		}
    }
	
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CDSMPMFCDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
    // 修改此代码以绘制文档数据
    dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));
    CString strText = _T("TODO: implement thumbnail drawing here");
    LOGFONT lf;
    CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
    pDefaultGUIFont->GetLogFont(&lf);
    lf.lfHeight = 36;
    CFont fontDraw;
    fontDraw.CreateFontIndirect(&lf);
    CFont* pOldFont = dc.SelectObject(&fontDraw);
    dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
    dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CDSMPMFCDoc::InitializeSearchContent()
{
    CString strSearchContent;
    // 从文档数据设置搜索内容。
    // 内容部分应由“;”分隔
    // 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
    SetSearchContent(strSearchContent);
}

void CDSMPMFCDoc::SetSearchContent(const CString& value)
{
    if(value.IsEmpty())
    {
        RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
    }
    else
    {
        CMFCFilterChunkValueImpl *pChunk = NULL;
        ATLTRY(pChunk = new CMFCFilterChunkValueImpl);

        if(pChunk != NULL)
        {
            pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
            SetChunkValue(pChunk);
        }
    }
}

#endif // SHARED_HANDLERS

// CDSMPMFCDoc 诊断

#ifdef _DEBUG
void CDSMPMFCDoc::AssertValid() const
{
    CDocument::AssertValid();
}

void CDSMPMFCDoc::Dump(CDumpContext& dc) const
{
    CDocument::Dump(dc);
}
#endif //_DEBUG


// CDSMPMFCDoc 命令


BOOL CDSMPMFCDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	while (!m_playlist.empty())
		m_playlist.pop();
	CString tmpstr;
	tmpstr.Append(lpszPathName);
	tmpstr = tmpstr.Right(tmpstr.GetLength() - tmpstr.ReverseFind('.'));
	auto t = tmpstr.Compare(L".dsplist");
	m_isPlaylist = (t == 0) ? true : false;
    if(!CDocument::OnOpenDocument(lpszPathName))
        return FALSE;
	//if (t == 0)
	//{
	//	TRACE("The file is playlist!\n");
	//	m_isPlaylist = true;
	//	//if (this->AnalizePlaylist(lpszPathName) == S_OK)
	//		//TRACE("Analization is sucessfull!\n");
	//	// TODO:  在此添加您专用的创建代码
	//}
	//else
	//	m_isPlaylist = false;
    return TRUE;
}


// 分析播放列表文件
//HRESULT CDSMPMFCDoc::AnalizePlaylist(LPCTSTR lpszPathName)
//{
//	CStdioFile pf;
//	CString line = L"";
//	setlocale(LC_ALL, "chs");
//
//	try
//	{
//		pf.Open(lpszPathName, CFile::modeReadWrite, NULL);
//
//		while (pf.ReadString(line))
//		{
//			this->m_playlist.push(line);
//			TRACE(L"%s\n", this->m_playlist.front());
//		}
//	}
//	catch (CException* e)
//	{
//		e->ReportError();
//		return E_UNEXPECTED;
//	}
//
//	setlocale(LC_ALL, "C");
//	//TRACE(pf.GetFileName().GetString());
//	pf.Close();
//	return S_OK;
//}


//void CDSMPMFCDoc::OnFileOpen()
//{
//	// TODO: 在此添加命令处理程序代码auto pdoc = GetDocument();
//	auto pdoc = this;
//	CString strFilter = L"支持的音频格式|*.mp3; *.wav; *.aac; *.wma; *.flac|支持的视频格式|*.mp4; *.wmv; *.avi; *.mkv|播放列表|*.dsplist|所有文件|*.*||";
//	CFileDialog fdlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, strFilter, NULL);
//	if (fdlg.DoModal() == IDOK)
//	{
//		SetPathName(fdlg.GetPathName());
//	}
//
//}


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

int* CDSMPMFCDoc::volumes = new int[101] {-10000, -6418, -6147, -6000,-5892, -4826, -4647, -4540,- 4477, -4162, -3876, -3614, -3500,-3492, -3374, -3261, -3100, -3153, -3048, -2947, -2849, -2755, -2700,-2663, -2575, -2520, -2489, -2406, -2325, -2280, -2246, -2170, -2095, -2050,-2023, -1952, -1900, -1884, -1834, -1820, -1800, -1780, -1757, -1695, -1636, -1579,-1521, -1500, -1464, -1436, -1420, -1408, -1353, -1299, -1246, -1195, -1144,-1096, -1060, -1049, -1020, -1003, -957, -912, -868, -800, -774, -784, -760, -744,-705, -667, -630, -610, -594, -570, -558, -525, -493, -462, -432, -403,-375, -348, -322, -297, -285, -273, -250, -228, -207, -187, -176, -168,-150, -102, -75, -19, -10, 0, 0};

// CDSMPMFCDoc 构造/析构

CDSMPMFCDoc::CDSMPMFCDoc()
	: m_isPlaylist(false)
{
	// TODO: 在此添加一次性构造代码
	EnableAutomation();
	AfxOleLockApp();
	m_pmf = new CMediaFile;
//	m_backgraph.LoadBitmapW(IDB_BITMAP_BACK);
	m_plist_selector = 0;
	m_playlistmode = Playlistmode::sequence;
	m_playlist.clear();
	m_lrc_selector.clear();
	m_isSingleloop = false;
}

CDSMPMFCDoc::~CDSMPMFCDoc()
{
    AfxOleUnlockApp();
	delete m_pmf;
	m_playlist.clear();
	m_lrc_selector.clear();
	
}

BOOL CDSMPMFCDoc::OnNewDocument()
{
    if(!CDocument::OnNewDocument())
        return FALSE;
	if (m_pmf->isPlaying)
	{
		m_pmf->Stop();
	}
	m_playlist.clear();
    // TODO: 在此添加重新初始化代码
    // (SDI 文档将重用该文档)
    return TRUE;
}




// CDSMPMFCDoc 序列化

void CDSMPMFCDoc::Serialize(CArchive& ar)
{
	CString tmpstr;
	tmpstr.Append(ar.m_strFileName);
	tmpstr = tmpstr.Right(tmpstr.GetLength() - tmpstr.ReverseFind('.'));
	auto t = tmpstr.Compare(L".dsplist");
	m_isPlaylist = (t == 0) ? true : false;
    if(ar.IsStoring())
    {
        // TODO: 在此添加存储代码
		//if (m_isPlaylist)
		//{
			while (!this->m_playlist.empty())
			{
				//ar << m_playlist.front() << "\n";
				tmpstr.Format(L"\"%s\n", m_playlist.front());
				ar.WriteString(tmpstr);
				m_playlist.pop_front();
			}
		//}
		//else
		//{
		//	ar.Close();
		//}
		//
    }
    else
    {
        // TODO: 在此添加加载代码
		m_plist_selector = 0;
		CString str = L"";
		if (m_isPlaylist)
		{
			while (ar.ReadString(str))
			{
				TRACE(str+L"\n");
				str=str.Mid(str.Find(L"\"",0)+1);
				if (str=="")
					continue;

				m_playlist.push_back(str);
			}
			
		}
		else
		{
			str = ar.m_strFileName;
			m_playlist.push_back(str);
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
	m_playlist.clear();
	CString tmpstr;
	tmpstr.Append(lpszPathName);
	tmpstr = tmpstr.Right(tmpstr.GetLength() - tmpstr.ReverseFind('.'));
	auto t = tmpstr.Compare(L".dsplist");
	m_isPlaylist = (t == 0) ? true : false;
    if(!CDocument::OnOpenDocument(lpszPathName))
        return FALSE;
    return TRUE;
}


bool CDSMPMFCDoc::HasNextOrPri(bool flag)
{
	if (!m_isPlaylist || m_playlist.size() < 2)
		return false;
	else
	{
		switch (m_playlistmode)
		{
		case Playlistmode::loop:
			return true;
		case Playlistmode::sequence:
			return flag ? (m_plist_selector + 1) != m_playlist.size() : m_plist_selector > 0;
		default:
			return false;
		}
	}
}

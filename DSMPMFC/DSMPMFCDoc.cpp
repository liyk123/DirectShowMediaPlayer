
// DSMPMFCDoc.cpp : CDSMPMFCDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// ע��: ��������˶� IID_IDSMPMFC ��֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {25FA09EB-6767-47CC-85C0-F20C3A12DE67}
static const IID IID_IDSMPMFC =
{ 0x25FA09EB, 0x6767, 0x47CC, { 0x85, 0xC0, 0xF2, 0xC, 0x3A, 0x12, 0xDE, 0x67 } };

BEGIN_INTERFACE_MAP(CDSMPMFCDoc, CDocument)
INTERFACE_PART(CDSMPMFCDoc, IID_IDSMPMFC, Dispatch)
END_INTERFACE_MAP()


// CDSMPMFCDoc ����/����

CDSMPMFCDoc::CDSMPMFCDoc()
	: m_isPlaylist(false)
{
	// TODO: �ڴ����һ���Թ������
	EnableAutomation();
	AfxOleLockApp();
	m_pmf = new CMediaFile;
	m_backgraph.LoadBitmapW(IDB_BITMAP_BACK);
	m_selector = 0;
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
	if (m_pmf->isPlaying)
	{
		m_pmf->Stop();
	}
	m_playlist.clear();
    // TODO: �ڴ�������³�ʼ������
    // (SDI �ĵ������ø��ĵ�)
    return TRUE;
}




// CDSMPMFCDoc ���л�

void CDSMPMFCDoc::Serialize(CArchive& ar)
{
	CString tmpstr;
	tmpstr.Append(ar.m_strFileName);
	tmpstr = tmpstr.Right(tmpstr.GetLength() - tmpstr.ReverseFind('.'));
	auto t = tmpstr.Compare(L".dsplist");
	m_isPlaylist = (t == 0) ? true : false;
    if(ar.IsStoring())
    {
        // TODO: �ڴ���Ӵ洢����
		if (m_isPlaylist)
		{
			while (!this->m_playlist.empty())
			{
				//ar << m_playlist.front() << "\n";
				ar.WriteString(m_playlist.front());
				ar << "\r";
				m_playlist.pop_front();
				
			}
		}
		
    }
    else
    {
        // TODO: �ڴ���Ӽ��ش���
		m_selector = 0;
		CString str = L"";
		if (m_isPlaylist)
		{
			while (ar.ReadString(str))
			{
				TRACE(str+L"\n");
				str=str.Mid(str.Find(L"\"",0)+1);
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

// ����ͼ��֧��
void CDSMPMFCDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
    // �޸Ĵ˴����Ի����ĵ�����
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

// ������������֧��
void CDSMPMFCDoc::InitializeSearchContent()
{
    CString strSearchContent;
    // ���ĵ����������������ݡ�
    // ���ݲ���Ӧ�ɡ�;���ָ�
    // ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
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

// CDSMPMFCDoc ���

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


// CDSMPMFCDoc ����


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

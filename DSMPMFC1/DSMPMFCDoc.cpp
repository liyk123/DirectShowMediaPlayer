
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
//  ON_COMMAND(ID_FILE_OPEN, &CDSMPMFCDoc::OnFileOpen)
END_MESSAGE_MAP()


// CDSMPMFCDoc 构造/析构

CDSMPMFCDoc::CDSMPMFCDoc()
{
    // TODO: 在此添加一次性构造代码
}

CDSMPMFCDoc::~CDSMPMFCDoc()
{
}

BOOL CDSMPMFCDoc::OnNewDocument()
{
    if(!CDocument::OnNewDocument())
        return FALSE;

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
		
		while (!this->PlayList.empty())
		{
			ar << PlayList.front() << "\n";
			PlayList.pop();
		}
    }
    else
    {
        // TODO: 在此添加加载代码
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


//void CDSMPMFCDoc::OnFileOpen()
//{
//  // TODO: 在此添加命令处理程序代码
//  CFileDialog fdlg(true);
//  fdlg.DoModal();
//}


BOOL CDSMPMFCDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
    if(!CDocument::OnOpenDocument(lpszPathName))
        return FALSE;
	
    // TODO:  在此添加您专用的创建代码
    CString tmpstr;
    tmpstr.Append(lpszPathName);
    tmpstr = tmpstr.Right(tmpstr.GetLength() - tmpstr.ReverseFind('.'));

    if(tmpstr.Compare(L".dplist") == 0)
    {
        TRACE("The file is playlist!\n");
        if(this->AnalizePlaylist(lpszPathName) == S_OK)
            TRACE("Analization is sucessfull!\n");

#ifdef DEBUG
		//setlocale(LC_ALL, "chs");
        while(!this->PlayList.empty())
        {
            TRACE(L"%s\n",this->PlayList.front());
            this->PlayList.pop();
        }
		//setlocale(LC_ALL, "C");
#endif // DEBUG
    }
	
    return TRUE;
}


// 分析播放列表文件
HRESULT CDSMPMFCDoc::AnalizePlaylist(LPCTSTR lpszPathName)
{
    CStdioFile pf;
    CString line = L"";
    setlocale(LC_ALL, "chs");

    try
    {
        pf.Open(lpszPathName, CFile::modeReadWrite, NULL);

        while(pf.ReadString(line))
        {
#ifndef LC_INCLUDE
            this->ReadStringToUnicode(line);
#endif // LC_INCLUDE
            this->PlayList.push(line);
        }
    }
    catch(CException* e)
    {
        e->ReportError();
        return E_UNEXPECTED;
    }

    setlocale(LC_ALL, "C");
    //TRACE(pf.GetFileName().GetString());
    pf.Close();
    return S_OK;
}

#ifndef LC_INCLUDE

// 将Char型字符转换为Unicode字符
int CDSMPMFCDoc::CharToUnicode(char* pchIn, CString* pstrOut)
{
    int nLen;
    WCHAR *ptch;

    if(pchIn == NULL)
    {
        return 0;
    }

    nLen = MultiByteToWideChar(CP_ACP, 0, pchIn, -1, NULL, 0);//取得所需缓存的多少
    ptch = new WCHAR[nLen];//申请缓存空间
    MultiByteToWideChar(CP_ACP, 0, pchIn, -1, ptch, nLen);//转码
    pstrOut->Format(_T("%s"), ptch);
    delete[] ptch;
    return nLen;
}


BOOL CDSMPMFCDoc::ReadStringToUnicode(CString& str)
{
    char *szBuf = new char[str.GetLength() + 1]; //数量要加1

    for(int i = 0; i < str.GetLength(); i++)
    {
        szBuf[i] = (CHAR)str.GetAt(i);
    }

    szBuf[str.GetLength()] = '\0';   //这里，必须要加上，否则会在结尾片显示一个"铪"字。
    // USES_CONVERSION;
    //char * sz=W2A(str.GetBuffer());  //这些方法我都试过，不行的。
    BOOL bok = CharToUnicode(szBuf, &str);
    delete[]szBuf;
    return bok;
}


#endif // LC_INCLUDE

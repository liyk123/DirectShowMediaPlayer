
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
//  ON_COMMAND(ID_FILE_OPEN, &CDSMPMFCDoc::OnFileOpen)
END_MESSAGE_MAP()


// CDSMPMFCDoc ����/����

CDSMPMFCDoc::CDSMPMFCDoc()
{
    // TODO: �ڴ����һ���Թ������
}

CDSMPMFCDoc::~CDSMPMFCDoc()
{
}

BOOL CDSMPMFCDoc::OnNewDocument()
{
    if(!CDocument::OnNewDocument())
        return FALSE;

    // TODO: �ڴ�������³�ʼ������
    // (SDI �ĵ������ø��ĵ�)
    return TRUE;
}




// CDSMPMFCDoc ���л�

void CDSMPMFCDoc::Serialize(CArchive& ar)
{
    if(ar.IsStoring())
    {
        // TODO: �ڴ���Ӵ洢����
		
		while (!this->PlayList.empty())
		{
			ar << PlayList.front() << "\n";
			PlayList.pop();
		}
    }
    else
    {
        // TODO: �ڴ���Ӽ��ش���
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


//void CDSMPMFCDoc::OnFileOpen()
//{
//  // TODO: �ڴ���������������
//  CFileDialog fdlg(true);
//  fdlg.DoModal();
//}


BOOL CDSMPMFCDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
    if(!CDocument::OnOpenDocument(lpszPathName))
        return FALSE;
	
    // TODO:  �ڴ������ר�õĴ�������
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


// ���������б��ļ�
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

// ��Char���ַ�ת��ΪUnicode�ַ�
int CDSMPMFCDoc::CharToUnicode(char* pchIn, CString* pstrOut)
{
    int nLen;
    WCHAR *ptch;

    if(pchIn == NULL)
    {
        return 0;
    }

    nLen = MultiByteToWideChar(CP_ACP, 0, pchIn, -1, NULL, 0);//ȡ�����軺��Ķ���
    ptch = new WCHAR[nLen];//���뻺��ռ�
    MultiByteToWideChar(CP_ACP, 0, pchIn, -1, ptch, nLen);//ת��
    pstrOut->Format(_T("%s"), ptch);
    delete[] ptch;
    return nLen;
}


BOOL CDSMPMFCDoc::ReadStringToUnicode(CString& str)
{
    char *szBuf = new char[str.GetLength() + 1]; //����Ҫ��1

    for(int i = 0; i < str.GetLength(); i++)
    {
        szBuf[i] = (CHAR)str.GetAt(i);
    }

    szBuf[str.GetLength()] = '\0';   //�������Ҫ���ϣ�������ڽ�βƬ��ʾһ��"��"�֡�
    // USES_CONVERSION;
    //char * sz=W2A(str.GetBuffer());  //��Щ�����Ҷ��Թ������еġ�
    BOOL bok = CharToUnicode(szBuf, &str);
    delete[]szBuf;
    return bok;
}


#endif // LC_INCLUDE

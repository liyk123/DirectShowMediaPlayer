
// DSMPMFCView.cpp : CDSMPMFCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DSMPMFC.h"
#endif

#include "DSMPMFCDoc.h"
#include "DSMPMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDSMPMFCView

IMPLEMENT_DYNCREATE(CDSMPMFCView, CView)

BEGIN_MESSAGE_MAP(CDSMPMFCView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDSMPMFCView 构造/析构

CDSMPMFCView::CDSMPMFCView()
{
	// TODO: 在此处添加构造代码

}

CDSMPMFCView::~CDSMPMFCView()
{
}

BOOL CDSMPMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDSMPMFCView 绘制

void CDSMPMFCView::OnDraw(CDC* /*pDC*/)
{
	CDSMPMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDSMPMFCView 打印

BOOL CDSMPMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDSMPMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDSMPMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDSMPMFCView 诊断

#ifdef _DEBUG
void CDSMPMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CDSMPMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDSMPMFCDoc* CDSMPMFCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDSMPMFCDoc)));
	return (CDSMPMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CDSMPMFCView 消息处理程序

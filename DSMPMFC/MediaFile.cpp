// MediaFile.cpp : 实现文件
//

#include "stdafx.h"
#include "DSMPMFC.h"
#include "MediaFile.h"


// CMediaFile

CMediaFile::CMediaFile():CObject()
{
	name = L"";
	pSeeking = NULL;
	ppWc = NULL;
	pControl = NULL;
	pEvent = NULL;
	pGraph = NULL;
	pVmr = NULL;
	width = 0;
	height = 0;
	isPlaying = false;
	isPaused = false;
}

BOOL CMediaFile::Init(HWND hwndApp)
{
	HRESULT hr;
	hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void **)&pGraph);
	if (FAILED(hr)) {
		AfxMessageBox(_T("Error - Can't create Filter Graph."));
		return FALSE;
	}
	//  Query Interface
	hr |= pGraph->QueryInterface(IID_IMediaControl, (void **)&pControl);
	hr |= pGraph->QueryInterface(IID_IMediaEvent, (void **)&pEvent);
	//hr |= pGraph->QueryInterface(IID_IBasicVideo, (void **)&pVideo);
	hr |= pGraph->QueryInterface(IID_IBasicAudio, (void **)&pAudio);
	//hr |= pGraph->QueryInterface(IID_IVideoWindow, (void **)&pWindow);
	hr |= InitWindowlessVMR(hwndApp);
	hr |= pGraph->QueryInterface(IID_IMediaSeeking, (void **)&pSeeking);
	if (FAILED(hr)) {
		AfxMessageBox(_T("Error - Can't Query Interface."));
		return FALSE;
	}
	return TRUE;
}

BOOL CMediaFile::Releases()
{
	if (isPlaying)
		pControl->Stop();
	if (pVmr)
		pVmr->Release();
	if (ppWc)
		ppWc->Release();
	if (pSeeking)
		pSeeking->Release();
	if (pControl)
		pControl->Release();
	if (pEvent)
		pEvent->Release();
	if (pGraph)
		pGraph->Release();
	
	return TRUE;
}

HRESULT CMediaFile::InitWindowlessVMR(HWND hwndApp)
{
	if (!pGraph) return E_POINTER;
	pVmr = NULL;
	IVMRWindowlessControl* pWc = NULL;
	// 创建VMR
	HRESULT hr = CoCreateInstance(CLSID_VideoMixingRenderer, NULL,
		CLSCTX_INPROC, IID_IBaseFilter, (void**)&pVmr);
	if (FAILED(hr))
	{
		return hr;
	}
	// 把VMR添加到过滤器图表中
	hr = pGraph->AddFilter(pVmr, L"Video Mixing Render");
	if (FAILED(hr))
	{
		pVmr->Release();
		return hr;
	}
	// 设置显示模式
	IVMRFilterConfig* pConfig;
	hr = pVmr->QueryInterface(IID_IVMRFilterConfig, (void**)&pConfig);
	if (SUCCEEDED(hr))
	{
		hr = pConfig->SetRenderingMode(VMRMode::VMRMode_Windowless);
		
		pConfig->Release();
	}
	if (SUCCEEDED(hr))
	{
		// 设置窗体
		hr = pVmr->QueryInterface(IID_IVMRWindowlessControl, (void**)&pWc);
		if (SUCCEEDED(hr))
		{
			hr = pWc->SetVideoClippingWindow(hwndApp);
			if (SUCCEEDED(hr))
			{
				ppWc = pWc; //返回AddRef指针
			}
			else
			{
				pWc->Release();
			}
		}
	}
	pVmr->Release();
	return hr;
}

CMediaFile::~CMediaFile()
{
	if(isPlaying)
		Stop();
	//Releases();
	
}


// CMediaFile 成员函数


void CMediaFile::Play(HWND hwndView)
{
	if (isPaused&&isPlaying)
	{
		pControl->Run();
		isPaused = false;
		return;
	}
	Init(hwndView);
	int a=name.length();
	HRESULT hr = pGraph->RenderFile(name.c_str(), NULL);
	
	//this->GetDocument()->m_pmf->pVideo->
	if (FAILED(hr))
	{
		AfxMessageBox(_T("Can't open input file!"));
		return;
	}

	auto g_pWc = ppWc;
	hr = g_pWc->GetNativeVideoSize(&width, &height, NULL, NULL);

	if (SUCCEEDED(hr)&&width+height)
	{
		RECT rcSrc, rcDest;
		
		// 设置Source尺寸
		SetRect(&rcSrc, 0, 0, width, height);
		TRACE("%d\t%d\n", width, height);
		// 获得显示窗体的客户区尺寸
		::GetClientRect(hwndView, &rcDest);
		int lwidth=rcDest.right, lheight=rcDest.bottom;
		int xPos = 0, yPos = 0;
		//设置destination尺寸
		if (rcSrc.right * 10 / rcSrc.bottom > rcDest.right * 10 / rcDest.bottom)
		{
			lwidth = rcDest.right;
			lheight = int(lwidth*(rcSrc.bottom * 1.0/ rcSrc.right)) ;
			//lheight = lwidth*(9000 / 16)/1000;
			yPos = rcDest.bottom - lheight;
			yPos >>= 1;
		}
		else
		{
			lheight = rcDest.bottom;
			lwidth = int(lheight*(rcSrc.right * 1.0 / rcSrc.bottom));
			//lwidth = lheight*(16000 / 9)/1000;
			xPos = rcDest.right - lwidth;
			xPos >>= 1;
		}
		SetRect(&rcDest, xPos, yPos, lwidth, lheight);
		TRACE("%d\t%d\t%f\n", rcDest.right, rcDest.bottom, width*1.0 / height);
		// 视频定位
		g_pWc->SetAspectRatioMode(VMR_ARMODE_LETTER_BOX);
		hr = g_pWc->SetVideoPosition(&rcSrc, &rcDest);
		
	}

	//HWND screen_hwnd = NULL;
	//RECT windowRect;
	//screen_hwnd = GetSafeHwnd();
	//::GetClientRect(screen_hwnd, &windowRect);
	//GetDocument()->m_pmf->pWindow->put_Visible(OAFALSE);
	//GetDocument()->m_pmf->pWindow->put_Owner((OAHWND)screen_hwnd);
	//GetDocument()->m_pmf->pWindow->put_Left(0);
	//GetDocument()->m_pmf->pWindow->put_Top(0);
	//GetDocument()->m_pmf->pWindow->put_Width(windowRect.right - windowRect.left);
	//GetDocument()->m_pmf->pWindow->put_Height(windowRect.bottom - windowRect.top);
	//GetDocument()->m_pmf->pWindow->put_WindowStyle(WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_THICKFRAME);
	//GetDocument()->m_pmf->pWindow->put_MessageDrain((OAHWND)screen_hwnd);//Receive Message
	//GetDocument()->m_pmf->pWindow->put_Visible(OATRUE);
	HWND dlg_hwnd = NULL;
	dlg_hwnd = hwndView;
	pEvent->SetNotifyWindow((OAHWND)dlg_hwnd, WM_USER + 20, 0);
	// Run
	hr = pControl->Run();
	isPlaying = true;
}


void CMediaFile::Stop()
{
	long long position = 0;
	HRESULT hr;
	hr = pSeeking->SetPositions(&position, AM_SEEKING_AbsolutePositioning | AM_SEEKING_SeekToKeyFrame,
		0, AM_SEEKING_NoPositioning);
	hr = pControl->Stop();

	// Enumerate the filters And remove them
	IEnumFilters *pEnum = NULL;
	hr = pGraph->EnumFilters(&pEnum);
	if (SUCCEEDED(hr))
	{
		IBaseFilter *pFilter = NULL;
		while (S_OK == pEnum->Next(1, &pFilter, NULL))
		{
			// Remove the filter.
			pGraph->RemoveFilter(pFilter);
			// Reset the enumerator.
			pEnum->Reset();
			pFilter->Release();
		}
		pEnum->Release();
	}
	isPlaying = false;
	isPaused = false;
}

// MediaFile.cpp : ʵ���ļ�
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
	// ����VMR
	HRESULT hr = CoCreateInstance(CLSID_VideoMixingRenderer, NULL,
		CLSCTX_INPROC, IID_IBaseFilter, (void**)&pVmr);
	if (FAILED(hr))
	{
		return hr;
	}
	// ��VMR��ӵ�������ͼ����
	hr = pGraph->AddFilter(pVmr, L"Video Mixing Render");
	if (FAILED(hr))
	{
		pVmr->Release();
		return hr;
	}
	// ������ʾģʽ
	IVMRFilterConfig* pConfig;
	hr = pVmr->QueryInterface(IID_IVMRFilterConfig, (void**)&pConfig);
	if (SUCCEEDED(hr))
	{
		hr = pConfig->SetRenderingMode(VMRMode::VMRMode_Windowless);
		
		pConfig->Release();
	}
	if (SUCCEEDED(hr))
	{
		// ���ô���
		hr = pVmr->QueryInterface(IID_IVMRWindowlessControl, (void**)&pWc);
		if (SUCCEEDED(hr))
		{
			hr = pWc->SetVideoClippingWindow(hwndApp);
			if (SUCCEEDED(hr))
			{
				ppWc = pWc; //����AddRefָ��
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


// CMediaFile ��Ա����


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
		
		// ����Source�ߴ�
		SetRect(&rcSrc, 0, 0, width, height);
		TRACE("%d\t%d\n", width, height);
		// �����ʾ����Ŀͻ����ߴ�
		::GetClientRect(hwndView, &rcDest);
		//����destination�ߴ�
		SetRect(&rcDest, 0, 0, rcDest.right, rcDest.bottom);
		TRACE("%d\t%d\t%f\n", rcDest.right, rcDest.bottom, width*1.0 / height);
		// ��Ƶ��λ
		g_pWc->SetAspectRatioMode(VMR_ARMODE_LETTER_BOX);
		hr = g_pWc->SetVideoPosition(&rcSrc, &rcDest);
		
	}

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


HRESULT CMediaFile::Seek(int nPos)
{
	double pos_bar = 0.0;
	__int64 duration = 0;
	__int64 pos_time = 0;
	pos_bar = (double)nPos / 1000.0;
	pSeeking->GetDuration(&duration);
	pos_time = (__int64)(pos_bar*duration);
	__int64 position = pos_time;
	HRESULT hr = pSeeking->SetPositions(&position, AM_SEEKING_AbsolutePositioning | AM_SEEKING_SeekToKeyFrame,0, AM_SEEKING_NoPositioning);
	return S_OK;
}

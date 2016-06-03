#pragma once
#include "MediaInfoDLL.h"
// CMediaFile ÃüÁîÄ¿±ê
//#include <vmr9.h>
//#include <d3d9.h>

#define WM_GRAPHNOTIFY  (WM_USER+20)

typedef enum _playlistmode
{
	sequence,
	loop
}Playlistmode;

class CMediaFile : public CObject
{
public:
	CMediaFile();
	BOOL Init(HWND hwndApp);
	BOOL Releases();
	MediaInfoDLL::String name;
	IGraphBuilder *pGraph;
	IMediaControl *pControl;
	IMediaEventEx *pEvent;
	IBasicAudio *pAudio;
	IBaseFilter *pVmr;
	long m_volume;
	long width;
	long height;
	bool isPlaying;
	bool isPaused;
	//IBasicVideo *pVideo;
	//IBasicAudio *pAudio;
	//IVideoWindow *pWindow;
	IMediaSeeking *pSeeking;
	IVMRWindowlessControl* ppWc;
	HRESULT InitWindowlessVMR(HWND hwndApp);
	virtual ~CMediaFile();
	void Play(HWND hwndView);
	void Stop();
	HRESULT Seek(int nPos);
	void Pause();
};



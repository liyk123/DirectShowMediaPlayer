#pragma once
#include "MediaInfoDLL.h"

// CMediaFile ����Ŀ��

class CMediaFile : public CObject
{
public:
	CMediaFile();
	MediaInfoDLL::String name;
	virtual ~CMediaFile();
};



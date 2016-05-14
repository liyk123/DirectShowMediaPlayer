#pragma once
#include "MediaInfoDLL.h"

// CMediaFile ÃüÁîÄ¿±ê

class CMediaFile : public CObject
{
public:
	CMediaFile();
	MediaInfoDLL::String name;
	virtual ~CMediaFile();
};



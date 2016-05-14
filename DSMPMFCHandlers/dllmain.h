// dllmain.h: 模块类的声明。

class CDSMPMFCHandlersModule : public ATL::CAtlDllModuleT< CDSMPMFCHandlersModule >
{
public :
	DECLARE_LIBID(LIBID_DSMPMFCHandlersLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DSMPMFCHANDLERS, "{E0581B08-069E-45DD-A092-D8AE25BF560A}")
};

extern class CDSMPMFCHandlersModule _AtlModule;

#pragma once

#include "EasyWindow/base/base.h"
#include "Project/ProjectBase.h"

#if defined(__cplusplus)
extern "C" {
#endif

EASYWINDOW_STRUCT(WindowCfg);

typedef cstring(PROJ_APICALL *WCfgGetTitlefn)(WindowCfg*);
typedef float(PROJ_APICALL *WcfgGetWidthfn)(WindowCfg*);
typedef float(PROJ_APICALL *WcfgGetHeightfn)(WindowCfg*);
typedef uint8(PROJ_APICALL *WCfgGetFlagsfn)(WindowCfg*);

typedef void (PROJ_APICALL* WCfgSetTitlefn)(WindowCfg*, cstring);
typedef void (PROJ_APICALL* WCfgSetWidthfn)(WindowCfg*, float);
typedef void (PROJ_APICALL* WCfgSetHeightfn)(WindowCfg*, float);
typedef void (PROJ_APICALL* WCfgSetFlagsfn)(WindowCfg*, uint8);

typedef void (PROJ_APICALL* WCfgCreatefn)(WindowCfg*, cstring, float, float, uint8);
typedef void (PROJ_APICALL* WCfgDestroyfn)(WindowCfg*);

typedef struct _WindowCfgGet {
	WCfgGetTitlefn title;
	WcfgGetWidthfn width;
	WcfgGetHeightfn height;
	WCfgGetFlagsfn flags;
}WindowCfgGet;

typedef struct _WindowCfgSet {
	WCfgSetTitlefn title;
	WCfgSetWidthfn width;
	WCfgSetHeightfn height;
	WCfgSetFlagsfn flags;
}WindowCfgSet;

struct WindowCfg {
	WCfgCreatefn create;
	WCfgDestroyfn destroy;
	WindowCfgGet get;
	WindowCfgSet set;
};

WindowCfg* PROJ_STDCALL wcfg_construct(void);

#if defined(__cplusplus)
}
#endif

#pragma pop_macro("EASYWINDOW_ENABLE_CFG_MACROS")
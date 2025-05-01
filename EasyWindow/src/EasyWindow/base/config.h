#pragma once

#include "EasyWindow/base/base.h"
#include "EasyWindow/base/basetypes.h"

#if defined(__cplusplus)
extern "C" {
#endif

EASYWINDOW_STRUCT(WindowCfg);

typedef cstring(APICALL *WCfgGetTitlefn)(WindowCfg*);
typedef float(APICALL *WcfgGetWidthfn)(WindowCfg*);
typedef float(APICALL *WcfgGetHeightfn)(WindowCfg*);
typedef uint8(APICALL *WCfgGetFlagsfn)(WindowCfg*);

typedef void (APICALL* WCfgSetTitlefn)(WindowCfg*, cstring);
typedef void (APICALL* WCfgSetWidthfn)(WindowCfg*, float);
typedef void (APICALL* WCfgSetHeightfn)(WindowCfg*, float);
typedef void (APICALL* WCfgSetFlagsfn)(WindowCfg*, uint8);

typedef void (APICALL* WCfgCreatefn)(WindowCfg*, cstring, float, float, uint8);
typedef void (APICALL* WCfgDestroyfn)(WindowCfg*);

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

WindowCfg* APICALL wcfg_construct(void);

#if defined(__cplusplus)
}
#endif

#pragma pop_macro("EASYWINDOW_ENABLE_CFG_MACROS")
#include "config.h"
#include <stdlib.h>
#include <memory.h>

typedef struct _IWindowCfg {
	WCfgCreatefn create;
	WCfgDestroyfn destroy;
	WindowCfgGet get;
	WindowCfgSet set;
	cstring title;
	float width;
	float height;
	uint8 flags;
}IWindowCfg;


static void PROJ_STDCALL wcfg_create(WindowCfg*, cstring title, float width, float height, uint8 flags);
static void PROJ_STDCALL wcfg_destroy(WindowCfg* cfg);

static cstring PROJ_STDCALL wcfg_title(WindowCfg* cfg);
static float PROJ_STDCALL wcfg_width(WindowCfg* cfg);
static float PROJ_STDCALL wcfg_height(WindowCfg* cfg);
static uint8 PROJ_STDCALL wcfg_flags(WindowCfg* cfg);

static void PROJ_STDCALL wcfg_set_title(WindowCfg* cfg, cstring title);
static void PROJ_STDCALL wcfg_set_width(WindowCfg* cfg, float width);
static void PROJ_STDCALL wcfg_set_height(WindowCfg* cfg, float height);
static void PROJ_STDCALL wcfg_set_flags(WindowCfg* cfg, uint8 flags);

WindowCfg* PROJ_STDCALL wcfg_construct(void) {
	IWindowCfg* icfg = (IWindowCfg*)calloc(1, sizeof(IWindowCfg));
	if (!icfg) return nullptr;

	icfg->create = wcfg_create;
	icfg->destroy = wcfg_destroy;

	icfg->get.title = wcfg_title;
	icfg->get.width = wcfg_width;
	icfg->get.height = wcfg_height;
	icfg->get.flags = wcfg_flags;

	icfg->set.title = wcfg_set_title;
	icfg->set.width = wcfg_set_width;
	icfg->set.height = wcfg_set_height;
	icfg->set.flags = wcfg_set_flags;

	return (WindowCfg*)icfg;
}

static void PROJ_STDCALL wcfg_create(WindowCfg* cfg, cstring title, float width, float height, uint8 flags) {
	IWindowCfg* icfg = (IWindowCfg*)cfg;
	icfg->title = title;
	icfg->width = width;
	icfg->height = height;
	icfg->flags = flags;
	
}

static void PROJ_STDCALL wcfg_destroy(WindowCfg* cfg) {
	IWindowCfg* icfg = (IWindowCfg*)cfg;

	memset(&icfg->create, 0, sizeof(icfg->create));
	memset(&icfg->destroy, 0, sizeof(icfg->destroy));
	memset(&icfg->get, 0, sizeof(icfg->get));
	memset(&icfg->set, 0, sizeof(icfg->set));
	free(icfg);
}

static cstring PROJ_STDCALL wcfg_title(WindowCfg* cfg) {
	IWindowCfg* icfg = (IWindowCfg*) cfg;
	return icfg->title;
}

static float PROJ_STDCALL wcfg_width(WindowCfg* cfg) {
	IWindowCfg* icfg = (IWindowCfg*)cfg;
	return icfg->width;
}

static float PROJ_STDCALL wcfg_height(WindowCfg* cfg) {
	IWindowCfg* icfg = (IWindowCfg*)cfg;
	return icfg->height;
}

static uint8 PROJ_STDCALL wcfg_flags(WindowCfg* cfg) {
	IWindowCfg* icfg = (IWindowCfg*)cfg;
	return icfg->flags;
}

static void PROJ_STDCALL wcfg_set_title(WindowCfg* cfg, cstring title) {
	IWindowCfg* icfg = (IWindowCfg*)cfg;
	icfg->title = title;
}

static void PROJ_STDCALL wcfg_set_width(WindowCfg* cfg, float width) {
	IWindowCfg* icfg = (IWindowCfg*)cfg;
	icfg->width = width;
}

static void PROJ_STDCALL wcfg_set_height(WindowCfg* cfg, float height) {
	IWindowCfg* icfg = (IWindowCfg*)cfg;
	icfg->height = height;
}

static void PROJ_STDCALL wcfg_set_flags(WindowCfg* cfg, uint8 flags) {
	IWindowCfg* icfg = (IWindowCfg*)cfg;
	icfg->flags = flags;
}
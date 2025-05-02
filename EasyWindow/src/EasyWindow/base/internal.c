#include <stddef.h>
#include <assert.h>
#include "EasyWindow.h"
#include "config.h"
#include "internal.h"

void PROJ_STDCALL EasyWindowCreateCfg(_EasyWindow* window, cstring title, float width, float height, uint8 flags) {
	window->cfg = wcfg_construct();
	window->cfg->create(window->cfg, title, width, height, flags);
}

void PROJ_STDCALL EasyWindowDestroyCfg(_EasyWindow* window) {
	window->cfg->destroy(window->cfg);
}

PROJ_SYMBOL void* PROJ_STDCALL EasyWindowGetNativeWindow(EasyWindow* handle) {
	return _EasyWindowNativeWindow((_EasyWindow*)handle);
}
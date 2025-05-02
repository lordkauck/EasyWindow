#include "config.h"
#include "internal.h"
#include <assert.h>

PROJ_SYMBOL EasyWindow  PROJ_STDCALL EasyWindowCreateWindow(const char* title, float width, float height, unsigned char flags) {
	_EasyWindow* window = (_EasyWindow*)calloc(1, sizeof(_EasyWindow));
	assert(window != nullptr);
	if (window == nullptr) return nullptr;

	EasyWindowCreateCfg(window, title, width, height, flags);

#if defined(EASYWINDOW_PLATFORM_WIN)
	window->callback.imgui = nullptr;
#endif
	window->callback.minimize = nullptr;
	window->callback.resize = nullptr;
	window->callback.close = nullptr;
	window->callback.keyup = nullptr;
	window->callback.keydown = nullptr;
	window->callback.mouse_button = nullptr;
	window->callback.mouse_move = nullptr;
	window->callback.scroll = nullptr;

	_EasyWindowPlatformCreateWindow(window);
	g_EasyWindow.window = window;
	return (EasyWindow*)window;
}

PROJ_SYMBOL void  PROJ_STDCALL EasyWindowDestroyWindow(EasyWindow* handle) {
	_EasyWindow* window = (_EasyWindow*)handle;
	if (window == nullptr) return;
	
	EasyWindowDestroyCfg(window);

	// @TODO: Clear all callbacks to avoid exposing a half torn-down window object
	memset(&window->callback, 0, sizeof(window->callback));
	free(window);
}

void  PROJ_STDCALL EasyWindowMinimizeWindow(_EasyWindow* window) {
	if (window->callback.minimize)
		window->callback.minimize((EasyWindow)window);
}

void  PROJ_STDCALL EasyWindowResizeWindow(_EasyWindow* window, int16 width, int16 height) {
	window->cfg->set.width(window->cfg, (float)width);
	window->cfg->set.height(window->cfg, (float)height);

	// @TODO: Create a platform function that handles window resizing for
	//		  each platform since certain platforms handle window resizing
	//		  in different ways.
	_EasyWindowNativeResizeWindow(window, width, height);

	if (window->callback.resize)
		window->callback.resize((EasyWindow*)window, width, height);
}

void  PROJ_STDCALL EasyWindowCloseRequest(_EasyWindow* window) {
	window->closed = true;

	if (window->callback.close)
		window->callback.close((EasyWindow*)window);
}

PROJ_SYMBOL void PROJ_STDCALL EasyWindowPollEvents(void) {
	_EasyWindowNativePollEvents();
}

PROJ_SYMBOL float PROJ_STDCALL EasyWindowGetWindowWidth(EasyWindow handle) {
	if (!handle) return 0.0f;
	_EasyWindow* window = (_EasyWindow*)handle;
	return window->cfg->get.width(window->cfg);
}

PROJ_SYMBOL float PROJ_STDCALL EasyWindowGetWindowHeight(EasyWindow handle) {
	if (!handle) return 0.0f;
	_EasyWindow* window = (_EasyWindow*)handle;
	return window->cfg->get.height(window->cfg);
}
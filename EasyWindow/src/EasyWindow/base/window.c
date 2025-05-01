#include "config.h"
#include "internal.h"
#include <assert.h>

EASYWINDOW_API EasyWindow APICALL EasyWindowCreateWindow(const char* title, float width, float height, unsigned char flags) {
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

EASYWINDOW_API void APICALL EasyWindowDestroyWindow(EasyWindow* handle) {
	_EasyWindow* window = (_EasyWindow*)handle;
	if (window == nullptr) return;
	
	EasyWindowDestroyCfg(window);

	// @TODO: Clear all callbacks to avoid exposing a half torn-down window object
	memset(&window->callback, 0, sizeof(window->callback));
	free(window);
}

void APICALL EasyWindowMinimizeWindow(_EasyWindow* window) {
	if (window->callback.minimize)
		window->callback.minimize((EasyWindow)window);
}

void APICALL EasyWindowResizeWindow(_EasyWindow* window, int16 width, int16 height) {
	window->cfg->set.width(window->cfg, (float)width);
	window->cfg->set.height(window->cfg, (float)height);

	// @TODO: Create a platform function that handles window resizing for
	//		  each platform since certain platforms handle window resizing
	//		  in different ways.
	_EasyWindowNativeResizeWindow(window, width, height);

	if (window->callback.resize)
		window->callback.resize((EasyWindow*)window, width, height);
}

void APICALL EasyWindowCloseRequest(_EasyWindow* window) {
	window->closed = true;

	if (window->callback.close)
		window->callback.close((EasyWindow*)window);
}

EASYWINDOW_API void APICALL EasyWindowPollEvents(void) {
	_EasyWindowNativePollEvents();
}

EASYWINDOW_API float APICALL EasyWindowGetWindowWidth(EasyWindow handle) {
	if (!handle) return 0.0f;
	_EasyWindow* window = (_EasyWindow*)handle;
	return window->cfg->get.width(window->cfg);
}

EASYWINDOW_API float APICALL EasyWindowGetWindowHeight(EasyWindow handle) {
	if (!handle) return 0.0f;
	_EasyWindow* window = (_EasyWindow*)handle;
	return window->cfg->get.height(window->cfg);
}
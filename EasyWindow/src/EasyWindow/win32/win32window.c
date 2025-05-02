#include "EasyWindow/base/base.h"
#include "EasyWindow/base/internal.h"

#include <assert.h>
#include <Windows.h>
#include "win32window.h"


void PROJ_STDCALL _EasyWindowPlatformCreateWindow(_EasyWindow* window) {
	W32CreateNativeWindow(window); 
}

void* PROJ_STDCALL _EasyWindowNativeWindow(_EasyWindow* window) {
	return W32GetHandle(window); 
}

void PROJ_STDCALL _EasyWindowNativePollEvents(void) { W32PollEvents(); }

void PROJ_STDCALL _EasyWindowNativeResizeWindow(_EasyWindow* window, int16 width, int16 height) {
	W32ResizeWindow(window, width, height); 
}

HWND PROJ_STDCALL W32GetHandle(_EasyWindow* window) {
	return window->win32.handle; 
}

// @NOTE: This handles the window resize
void PROJ_STDCALL W32ResizeWindow(_EasyWindow* window, int16 width, int16 height) {
	 // @NOTE: In order to resize the window we need to call adjustwindowrect
	 // @NOTE: In order to do that, we need the window style & menu style
	 
	// @TODO: Implement on window size callback
}

void PROJ_STDCALL W32FocusWindow(_EasyWindow* window) {
	BringWindowToTop(window->win32.handle);
	SetForegroundWindow(window->win32.handle);
	SetFocus(window->win32.handle);
}

void PROJ_STDCALL W32PollEvents(void) {
	MSG msg = { 0 };
	_EasyWindow* window = g_EasyWindow.window;
	while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {
		if (msg.message == WM_QUIT) {
			EasyWindowCloseRequest(window);
		}
		
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
}

void PROJ_STDCALL W32UnregisterDestroyWnd(_EasyWindow* window) {
	// Destroy window & unregester the wndclass
	if (window->win32.handle) {
		DestroyWindow(window->win32.handle);
		UnregisterClass(window->win32.wndclass.lpszClassName, window->win32.instance);
	}
}
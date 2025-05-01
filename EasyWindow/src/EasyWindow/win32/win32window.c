#include "EasyWindow/base/base.h"
#include "EasyWindow/base/internal.h"

#include <assert.h>
#include <Windows.h>
#include "win32window.h"

<<<<<<< HEAD
void APICALL _EasyWindowPlatformCreateWindow(_EasyWindow* window) { 
	W32CreateNativeWindow(window); 
}

void* APICALL _EasyWindowNativeWindow(_EasyWindow* window) { 
	return W32GetHandle(window); 
}

void APICALL _EasyWindowNativePollEvents(void) { W32PollEvents(); }

void APICALL _EasyWindowNativeResizeWindow(_EasyWindow* window, int16 width, int16 height) { 
	W32ResizeWindow(window, width, height); 
}

HWND APICALL W32GetHandle(_EasyWindow* window) { 
=======
void PROJ_APICALL _EasyWindowPlatformCreateWindow(_EasyWindow* window) { 
	W32CreateNativeWindow(window); 
}

void* PROJ_APICALL _EasyWindowNativeWindow(_EasyWindow* window) { 
	return W32GetHandle(window); 
}

void PROJ_APICALL _EasyWindowNativePollEvents(void) { W32PollEvents(); }

void PROJ_APICALL _EasyWindowNativeResizeWindow(_EasyWindow* window, int16 width, int16 height) { 
	W32ResizeWindow(window, width, height); 
}

HWND PROJ_APICALL W32GetHandle(_EasyWindow* window) { 
>>>>>>> Initial Commit
	return window->win32.handle; 
}

// @NOTE: This handles the window resize
<<<<<<< HEAD
void APICALL W32ResizeWindow(_EasyWindow* window, int16 width, int16 height) {
=======
void PROJ_APICALL W32ResizeWindow(_EasyWindow* window, int16 width, int16 height) {
>>>>>>> Initial Commit
	 // @NOTE: In order to resize the window we need to call adjustwindowrect
	 // @NOTE: In order to do that, we need the window style & menu style
	 
	// @TODO: Implement on window size callback
}

<<<<<<< HEAD
void APICALL W32FocusWindow(_EasyWindow* window) {
=======
void PROJ_APICALL W32FocusWindow(_EasyWindow* window) {
>>>>>>> Initial Commit
	BringWindowToTop(window->win32.handle);
	SetForegroundWindow(window->win32.handle);
	SetFocus(window->win32.handle);
}

<<<<<<< HEAD
void APICALL W32PollEvents(void) {
=======
void PROJ_APICALL W32PollEvents(void) {
>>>>>>> Initial Commit
	MSG msg;
	_EasyWindow* window = g_EasyWindow.window;
	while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {
		if (msg.message == WM_QUIT) {
			EasyWindowCloseRequest(window);
		}
		
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
}

<<<<<<< HEAD
void APICALL W32UnregisterDestroyWnd(_EasyWindow* window) {
=======
void PROJ_APICALL W32UnregisterDestroyWnd(_EasyWindow* window) {
>>>>>>> Initial Commit
	// Destroy window & unregester the wndclass
	if (window->win32.handle) {
		DestroyWindow(window->win32.handle);
		UnregisterClass(window->win32.wndclass.lpszClassName, window->win32.instance);
	}
}
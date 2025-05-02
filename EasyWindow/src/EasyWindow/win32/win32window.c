#include "EasyWindow/base/base.h"
#include "EasyWindow/base/internal.h"

#include <assert.h>
#include <Windows.h>
#include "win32window.h"

<<<<<<< HEAD
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
=======
>>>>>>> Fixing broken stuff
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
<<<<<<< HEAD
>>>>>>> Initial Commit
=======
>>>>>>> Fixing broken stuff
	return window->win32.handle; 
}

// @NOTE: This handles the window resize
<<<<<<< HEAD
<<<<<<< HEAD
void APICALL W32ResizeWindow(_EasyWindow* window, int16 width, int16 height) {
=======
void PROJ_APICALL W32ResizeWindow(_EasyWindow* window, int16 width, int16 height) {
>>>>>>> Initial Commit
=======
void PROJ_APICALL W32ResizeWindow(_EasyWindow* window, int16 width, int16 height) {
>>>>>>> Fixing broken stuff
	 // @NOTE: In order to resize the window we need to call adjustwindowrect
	 // @NOTE: In order to do that, we need the window style & menu style
	 
	// @TODO: Implement on window size callback
}

<<<<<<< HEAD
<<<<<<< HEAD
void APICALL W32FocusWindow(_EasyWindow* window) {
=======
void PROJ_APICALL W32FocusWindow(_EasyWindow* window) {
>>>>>>> Initial Commit
=======
void PROJ_APICALL W32FocusWindow(_EasyWindow* window) {
>>>>>>> Fixing broken stuff
	BringWindowToTop(window->win32.handle);
	SetForegroundWindow(window->win32.handle);
	SetFocus(window->win32.handle);
}

<<<<<<< HEAD
<<<<<<< HEAD
void APICALL W32PollEvents(void) {
=======
void PROJ_APICALL W32PollEvents(void) {
>>>>>>> Initial Commit
=======
void PROJ_APICALL W32PollEvents(void) {
>>>>>>> Fixing broken stuff
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
<<<<<<< HEAD
void APICALL W32UnregisterDestroyWnd(_EasyWindow* window) {
=======
void PROJ_APICALL W32UnregisterDestroyWnd(_EasyWindow* window) {
>>>>>>> Initial Commit
=======
void PROJ_APICALL W32UnregisterDestroyWnd(_EasyWindow* window) {
>>>>>>> Fixing broken stuff
	// Destroy window & unregester the wndclass
	if (window->win32.handle) {
		DestroyWindow(window->win32.handle);
		UnregisterClass(window->win32.wndclass.lpszClassName, window->win32.instance);
	}
}
#ifndef EASYWINDOW_WIN32WINDOW_H
#define EASYWINDOW_WIN32WINDOW_H

#include "EasyWindow/base/base.h"
#include "EasyWindow/base/basetypes.h"
#include <Windows.h>

EASYWINDOW_STRUCT(_EasyWindow);
EASYWINDOW_STRUCT(_W32Window);

#define EASYWINDOW_WINDOW_STATE _W32Window win32

struct _W32Window {
	uint32 style;
	HINSTANCE instance; // HINSTANCE__
	WNDCLASSEX wndclass; // tagWNDCLASSEXA
	HWND handle; // HWND__
};

#ifdef __cplusplus
extern "C" {
#endif

b8 APICALL in_window(_EasyWindow*, int16, int16);
b8 APICALL mb_held(int32, uint8);

// @NOTE Win32 Platform function definitions
void APICALL W32CreateNativeWindow(_EasyWindow*);
void APICALL W32PollEvents(void);
void APICALL W32ResizeWindow(_EasyWindow*, int16, int16);
void APICALL W32UnregisterDestroyWnd(_EasyWindow*);
void APICALL W32FocusWindow(_EasyWindow*);
HWND APICALL W32GetHandle(_EasyWindow*);


LRESULT APICALL W32WndMsgProc(HWND, UINT, WPARAM, LPARAM);

#ifdef __cplusplus
}
#endif
#endif // EASYWINDOW_WIN32WINDOW_H
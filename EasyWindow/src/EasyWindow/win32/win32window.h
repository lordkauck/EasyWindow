#ifndef EASYWINDOW_WIN32WINDOW_H
#define EASYWINDOW_WIN32WINDOW_H

#include "EasyWindow/base/base.h"
#include "Project/ProjectBase.h"
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

b8 PROJ_STDCALL in_window(_EasyWindow*, int16, int16);
b8 PROJ_STDCALL mb_held(int32, uint8);

// @NOTE Win32 Platform function definitions
void PROJ_STDCALL W32CreateNativeWindow(_EasyWindow*);
void PROJ_STDCALL W32PollEvents(void);
void PROJ_STDCALL W32ResizeWindow(_EasyWindow*, int16, int16);
void PROJ_STDCALL W32UnregisterDestroyWnd(_EasyWindow*);
void PROJ_STDCALL W32FocusWindow(_EasyWindow*);
HWND PROJ_STDCALL W32GetHandle(_EasyWindow*);


LRESULT PROJ_STDCALL W32WndMsgProc(HWND, UINT, WPARAM, LPARAM);

#ifdef __cplusplus
}
#endif
#endif // EASYWINDOW_WIN32WINDOW_H
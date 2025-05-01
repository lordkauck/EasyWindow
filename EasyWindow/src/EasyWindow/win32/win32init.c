#include <Windows.h>
#include <winnt.h>

#include "EasyWindow/base/base.h"
#include "EasyWindow/base/config.h"
#include "EasyWindow/base/internal.h"
#include "win32window.h"

// This gets the handle to our own instance regardless of if we are a dll, static library or executable
// Useful for when you need the instance handle but can't be fucked to have it be passed thro functions
// as a parameter
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define SelfInstanceMacro ((HINSTANCE)&__ImageBase) 

<<<<<<< HEAD
void APICALL W32CreateNativeWindow(_EasyWindow* window) {
=======
void PROJ_APICALL W32CreateNativeWindow(_EasyWindow* window) {
>>>>>>> Initial Commit
	// @NOTE: Easy hack for getting instance handle, no need to pass as a parameter now! >:3
	window->win32.instance = SelfInstanceMacro;

	//  @NOTE: Now we create and register our WNDCLASSEX
	RtlZeroMemory(&window->win32.wndclass, sizeof(WNDCLASSEX));
	window->win32.wndclass.cbSize = sizeof(WNDCLASSEX);
	window->win32.wndclass.style = CS_OWNDC;
	window->win32.wndclass.lpfnWndProc = W32WndMsgProc;
	window->win32.wndclass.cbClsExtra = 0;
	window->win32.wndclass.cbWndExtra = 0;
	window->win32.wndclass.hInstance = window->win32.instance;
	window->win32.wndclass.hIcon = nullptr;
	window->win32.wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	window->win32.wndclass.hbrBackground = nullptr;
	window->win32.wndclass.lpszMenuName = nullptr;
	window->win32.wndclass.lpszClassName = "W32DefaultWndClass";
	window->win32.wndclass.hIconSm = nullptr;

	RegisterClassExA(&window->win32.wndclass);

	// @NOTE: Now we create, show & update our window
	RECT rc = { 0 };
	rc.left = 100;
	rc.right = window->cfg->get.width(window->cfg) + rc.left;
	rc.top = 100;
	rc.bottom = window->cfg->get.height(window->cfg) + rc.top;

	uint32 wflags = WS_CAPTION | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU | WS_MAXIMIZEBOX;
	AdjustWindowRect(&rc, wflags, FALSE);

	window->win32.style = wflags | WS_VISIBLE;

	// 6th argument is lparam, in this case ptr to window
	window->win32.handle = CreateWindowA(window->win32.wndclass.lpszClassName,
		window->cfg->get.title(window->cfg), window->win32.style, CW_USEDEFAULT, CW_USEDEFAULT,
		(rc.right - rc.left), (rc.bottom - rc.top),
		nullptr, nullptr, window->win32.instance, (EasyWindow*)window);

	ShowWindow(window->win32.handle, SW_SHOWDEFAULT);
	UpdateWindow(window->win32.handle);

	W32FocusWindow(window);

	SetPropA(window->win32.handle, "W32EmptyWindow", window);
}
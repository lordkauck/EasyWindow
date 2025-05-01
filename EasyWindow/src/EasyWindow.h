#ifndef EASYWINDOW_H
#define EASYWINDOW_H

#pragma push_macro("DLLEXPORT")
#if defined(EASYWND_LIB_DLL)
	#if defined(EASYWND_DLL)
		#define DLLEXPORT __declspec(dllexport)
	#else
		#define DLLEXPORT __declspec(dllimport)
	#endif // defined(EASYWND_DLL)
#else
#define DLLEXPORT
#endif // defined EASYWND_LIB_DLL

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef struct EasyWindow__* EasyWindow;

typedef void (*EasyWindowMinimizeCallbackfn)(EasyWindow);
typedef void (*EasyWindowResizeCallbackfn)(EasyWindow, short, short);
typedef void (*EasyWindowCloseCallbackfn)(EasyWindow);
typedef void (*EasyWindowKeyupCallbackfn)(EasyWindow, unsigned short int);
typedef void (*EasyWindowKeydownCallbackfn)(EasyWindow, unsigned short int, unsigned short int);
typedef void (*EasyWindowMouseButtonCallbackfn)(EasyWindow, char);
typedef void (*EasyWindowMouseMoveCallbackfn)(EasyWindow, float, float);
typedef void (*EasyWindowScrollCallbackfn)(EasyWindow, float, float);

//@HACK: This was the dumbest, easiest and simplest to implement way i could think of, for implementing ImGUI support
#if defined(_WIN64)
typedef __int64 (*EasyWindowImGuiMsgCallbackfn)(struct HWND__*, unsigned int, unsigned int, __int64);
#elif defined(_WIN32) && !defined(_WIN64)
typedef long (*EasyWindowImGuiMsgCallbackfn)(struct HWND__*, unsigned int, unsigned int, long);
#endif // defined(_WIN64)

DLLEXPORT void __cdecl EasyWindowInit(void);
DLLEXPORT EasyWindow __cdecl EasyWindowCreateWindow(const char*, float, float, unsigned char);
DLLEXPORT void __cdecl EasyWindowDestroyWindow(EasyWindow);
DLLEXPORT void __cdecl EasyWindowPollEvents(void);
DLLEXPORT void* __cdecl EasyWindowGetNativeWindow(EasyWindow);
DLLEXPORT float __cdecl EasyWindowGetWindowWidth(EasyWindow handle);
DLLEXPORT float __cdecl EasyWindowGetWindowHeight(EasyWindow handle);



DLLEXPORT EasyWindowImGuiMsgCallbackfn EasyWindowSetImGuiMsgCallback(EasyWindow, EasyWindowImGuiMsgCallbackfn);
DLLEXPORT EasyWindowMinimizeCallbackfn EasyWindowSetMinimizeCallback(EasyWindow, EasyWindowResizeCallbackfn);
DLLEXPORT EasyWindowResizeCallbackfn EasyWindowSetResizeCallback(EasyWindow, EasyWindowResizeCallbackfn);
DLLEXPORT EasyWindowCloseCallbackfn EasyWindowSetCloseCallback(EasyWindow, EasyWindowCloseCallbackfn);
DLLEXPORT EasyWindowKeyupCallbackfn EasyWindowSetKeyupCallback(EasyWindow, EasyWindowKeyupCallbackfn);
DLLEXPORT EasyWindowKeydownCallbackfn EasyWindowSetKeydownCallback(EasyWindow, EasyWindowKeydownCallbackfn);
DLLEXPORT EasyWindowMouseButtonCallbackfn EasyWindowSetMouseButtonCallback(EasyWindow, EasyWindowMouseButtonCallbackfn);
DLLEXPORT EasyWindowMouseMoveCallbackfn EasyWindowSetMouseMoveCallback(EasyWindow, EasyWindowMouseMoveCallbackfn);
DLLEXPORT EasyWindowScrollCallbackfn EasyWindowSetScrollCallback(EasyWindow, EasyWindowScrollCallbackfn);

#ifdef __cplusplus
}
#endif // __cplusplus

#pragma pop_macro("DLLEXPORT")
#endif // EASYWINDOW_H
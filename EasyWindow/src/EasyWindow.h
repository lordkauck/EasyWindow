#ifndef EASYWINDOW_H
#define EASYWINDOW_H

#include "EasyWindow/base/defines.h"

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


EASYWINDOW_API void APICALL EasyWindowInit(void);
EASYWINDOW_API EasyWindow APICALL EasyWindowCreateWindow(const char*, float, float, unsigned char);
EASYWINDOW_API void APICALL EasyWindowDestroyWindow(EasyWindow);
EASYWINDOW_API void APICALL EasyWindowPollEvents(void);
EASYWINDOW_API void* APICALL EasyWindowGetNativeWindow(EasyWindow);
EASYWINDOW_API float APICALL EasyWindowGetWindowWidth(EasyWindow handle);
EASYWINDOW_API float APICALL EasyWindowGetWindowHeight(EasyWindow handle);

#if EASYWINDOW_PLATFORM_WIN
//@HACK: This was the dumbest, easiest and simplest to implement way i could think of, for implementing ImGUI support
typedef long (*EasyWindowImGuiMsgCallbackfn)(struct HWND__*, unsigned int, unsigned int, long);

EASYWINDOW_API EasyWindowImGuiMsgCallbackfn EasyWindowSetImGuiMsgCallback(EasyWindow, EasyWindowImGuiMsgCallbackfn);
#endif

EASYWINDOW_API EasyWindowMinimizeCallbackfn EasyWindowSetMinimizeCallback(EasyWindow, EasyWindowResizeCallbackfn);
EASYWINDOW_API EasyWindowResizeCallbackfn EasyWindowSetResizeCallback(EasyWindow, EasyWindowResizeCallbackfn);
EASYWINDOW_API EasyWindowCloseCallbackfn EasyWindowSetCloseCallback(EasyWindow, EasyWindowCloseCallbackfn);
EASYWINDOW_API EasyWindowKeyupCallbackfn EasyWindowSetKeyupCallback(EasyWindow, EasyWindowKeyupCallbackfn);
EASYWINDOW_API EasyWindowKeydownCallbackfn EasyWindowSetKeydownCallback(EasyWindow, EasyWindowKeydownCallbackfn);
EASYWINDOW_API EasyWindowMouseButtonCallbackfn EasyWindowSetMouseButtonCallback(EasyWindow, EasyWindowMouseButtonCallbackfn);
EASYWINDOW_API EasyWindowMouseMoveCallbackfn EasyWindowSetMouseMoveCallback(EasyWindow, EasyWindowMouseMoveCallbackfn);
EASYWINDOW_API EasyWindowScrollCallbackfn EasyWindowSetScrollCallback(EasyWindow, EasyWindowScrollCallbackfn);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // EASYWINDOW_H
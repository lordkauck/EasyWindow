#ifndef EASYWINDOW_INTERNAL_H
#define EASYWINDOW_INTERNAL_H

#include "EasyWindow/base/base.h"
#include "EasyWindow/base/basetypes.h"
#include "EasyWindow.h"

#if defined(EASYWINDOW_PLATFORM_WIN)
#include "EasyWindow/win32/win32window.h"
#elif defined (EASYWINDOW_PLATFORM_UNIX)
// @TODO: Support other platforms
#endif


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	EASYWINDOW_HANDLE(EasyWindow);

	EASYWINDOW_STRUCT(WindowCfg);
	EASYWINDOW_STRUCT(_EasyWindowLib);
	EASYWINDOW_STRUCT(_EasyWindow);

	EASYWINDOW_STRUCT(_EasyWindowKey);

	// @NOTE: What i'm thinking is to add ImGui support 
	//		  based on the platform the programmer is
	//		  currently developing for.

	// @NOTE: Same with the window of course

	struct _EasyWindowKey {
		uint16 button;
		uint16 repeat;
	};

	struct _EasyWindow {
		bool closed;
		WindowCfg* cfg;
		

		struct {
			int8 buttons[8];
			int32 px;
			int32 py;
			float vx;
			float vy;
			b8 capture;
			b8 in_window;
		}mouse;

		_EasyWindowKey  keys[255];

		struct {
#if defined(EASYWINDOW_PLATFORM_WIN)
			EasyWindowImGuiMsgCallbackfn imgui;
#endif
			EasyWindowMinimizeCallbackfn minimize;
			EasyWindowResizeCallbackfn resize;
			EasyWindowCloseCallbackfn close;
			EasyWindowKeyupCallbackfn keyup;
			EasyWindowKeydownCallbackfn keydown;
			EasyWindowMouseButtonCallbackfn mouse_button;
			EasyWindowMouseMoveCallbackfn mouse_move;
			EasyWindowScrollCallbackfn scroll;
		}callback;

		EASYWINDOW_WINDOW_STATE;
	};

	struct _EasyWindowLib {
		_EasyWindow* window;
	};

	extern _EasyWindowLib g_EasyWindow;

	void APICALL EasyWindowAddWindow(_EasyWindow*);
	void APICALL EasyWindowRemoveWindow(_EasyWindow*);

	void APICALL EasyWindowCreateCfg(_EasyWindow*, cstring, float, float, uint8);
	void APICALL EasyWindowDestroyCfg(_EasyWindow* window);

	// @NOTE: All platform independent function definitions
	void APICALL EasyWindowMinimizeWindow(_EasyWindow* window);
	void APICALL EasyWindowResizeWindow(_EasyWindow*, int16, int16);
	void APICALL EasyWindowCloseRequest(_EasyWindow*);
	void* APICALL EasyWindowGetNativeWindow(_EasyWindow*);

	void APICALL EasyWindowInputMouseButton(_EasyWindow*, char);
	void APICALL EasyWindowInputKeyup(_EasyWindow*, uint16);
	void APICALL EasyWindowInputKeydown(_EasyWindow*, uint16, uint16);
	void APICALL EasyWindowMouseXY(_EasyWindow*, float, float);
	void APICALL EasyWindowInputScroll(_EasyWindow*, float, float);

	b8 APICALL EasyWindowMouseMoved(_EasyWindow* window, float x, float y);

	// @NOTE: All platform dependent function definitions
	// @TODO: Define these functions based on whatever platform is set
	void APICALL _EasyWindowPlatformCreateWindow(_EasyWindow*);
	void* APICALL _EasyWindowNativeWindow(_EasyWindow*);
	void APICALL _EasyWindowNativePollEvents(void);
	void APICALL _EasyWindowNativeResizeWindow(_EasyWindow*, int16, int16);
	void APICALL _EasyWindowNativeInputKeydown(_EasyWindow*, uint16, uint16);
	void APICALL _EasyWindowNativeInputKeyup(_EasyWindow*, uint16);
	
#ifdef __cplusplus
}
#endif // __cplusplus
#endif // EASYWINDOW_INTERNAL_H
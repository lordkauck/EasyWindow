#ifndef EASYWINDOW_INTERNAL_H
#define EASYWINDOW_INTERNAL_H

#include "EasyWindow/base/base.h"
#if defined(EASYWND_LIB_DLL)
	#define PROJECT_LIB_DLL 1
	#if defined(EASYWND_DLL)
		#define PROJECT_DLL 1
	#endif // defined(EASYWND_DLL)
#endif // defined(EASYWND_LIB_DLL) 
#include "Project/ProjectBase.h"
#include "EasyWindow.h"

#if defined(PLATFORM_WIN)
#include "EasyWindow/win32/win32window.h"
#elif defined (PLATFORM_LINUX)
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
			bool capture;
			bool in_window;
		}mouse;

		_EasyWindowKey  keys[255];

		struct {
#if defined(PLATFORM_WIN)
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

	void PROJ_APICALL EasyWindowAddWindow(_EasyWindow*);
	void PROJ_APICALL EasyWindowRemoveWindow(_EasyWindow*);

	void PROJ_APICALL EasyWindowCreateCfg(_EasyWindow*, cstring, float, float, uint8);
	void PROJ_APICALL EasyWindowDestroyCfg(_EasyWindow* window);

	// @NOTE: All platform independent function definitions
	void PROJ_APICALL EasyWindowMinimizeWindow(_EasyWindow* window);
	void PROJ_APICALL EasyWindowResizeWindow(_EasyWindow*, int16, int16);
	void PROJ_APICALL EasyWindowCloseRequest(_EasyWindow*);
	void* PROJ_APICALL EasyWindowGetNativeWindow(_EasyWindow*);

	void PROJ_APICALL EasyWindowInputMouseButton(_EasyWindow*, char);
	void PROJ_APICALL EasyWindowInputKeyup(_EasyWindow*, uint16);
	void PROJ_APICALL EasyWindowInputKeydown(_EasyWindow*, uint16, uint16);
	void PROJ_APICALL EasyWindowMouseXY(_EasyWindow*, float, float);
	void PROJ_APICALL EasyWindowInputScroll(_EasyWindow*, float, float);

	b8 PROJ_APICALL EasyWindowMouseMoved(_EasyWindow* window, float x, float y);

	// @NOTE: All platform dependent function definitions
	// @TODO: Define these functions based on whatever platform is set
	void PROJ_APICALL _EasyWindowPlatformCreateWindow(_EasyWindow*);
	void* PROJ_APICALL _EasyWindowNativeWindow(_EasyWindow*);
	void PROJ_APICALL _EasyWindowNativePollEvents(void);
	void PROJ_APICALL _EasyWindowNativeResizeWindow(_EasyWindow*, int16, int16);
	void PROJ_APICALL _EasyWindowNativeInputKeydown(_EasyWindow*, uint16, uint16);
	void PROJ_APICALL _EasyWindowNativeInputKeyup(_EasyWindow*, uint16);
	
#ifdef __cplusplus
}
#endif // __cplusplus
#endif // EASYWINDOW_INTERNAL_H
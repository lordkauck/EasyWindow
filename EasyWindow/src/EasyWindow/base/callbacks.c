#include "internal.h"
#include <assert.h>

#define SetCallbackMacro(handle, name, callback)     \
		_EasyWindow* window = (_EasyWindow*)handle;  \
		assert(window != nullptr);				     \
		PtrSwapMacro(window->callback.name, callback)\
		return callback

#if EASYWINDOW_PLATFORM_WIN
PROJ_SYMBOL EasyWindowImGuiMsgCallbackfn EasyWindowSetImGuiMsgCallback(EasyWindow handle, EasyWindowImGuiMsgCallbackfn callback) {
	SetCallbackMacro(handle, imgui, callback);
}
#endif 

PROJ_SYMBOL EasyWindowMinimizeCallbackfn EasyWindowSetMinimizeCallback(EasyWindow handle, EasyWindowResizeCallbackfn callback) {
	SetCallbackMacro(handle, minimize, callback);
}

PROJ_SYMBOL EasyWindowResizeCallbackfn EasyWindowSetResizeCallback(EasyWindow handle, EasyWindowResizeCallbackfn callback) {
	SetCallbackMacro(handle, resize, callback);
}

PROJ_SYMBOL EasyWindowCloseCallbackfn EasyWindowSetCloseCallback(EasyWindow handle, EasyWindowCloseCallbackfn callback) {
	SetCallbackMacro(handle, close, callback);
}

PROJ_SYMBOL EasyWindowKeyupCallbackfn EasyWindowSetKeyupCallback(EasyWindow handle, EasyWindowKeyupCallbackfn callback) {
	SetCallbackMacro(handle, keyup, callback);
}

PROJ_SYMBOL EasyWindowKeydownCallbackfn EasyWindowSetKeydownCallback(EasyWindow handle, EasyWindowKeydownCallbackfn callback) {
	SetCallbackMacro(handle, keydown, callback);
}

PROJ_SYMBOL EasyWindowMouseButtonCallbackfn EasyWindowSetMouseButtonCallback(EasyWindow handle, EasyWindowMouseButtonCallbackfn callback) {
	SetCallbackMacro(handle, mouse_button, callback);
}

PROJ_SYMBOL EasyWindowMouseMoveCallbackfn EasyWindowSetMouseMoveCallback(EasyWindow handle, EasyWindowMouseMoveCallbackfn callback) {
	SetCallbackMacro(handle, mouse_move, callback);
}

PROJ_SYMBOL EasyWindowScrollCallbackfn EasyWindowSetScrollCallback(EasyWindow handle, EasyWindowScrollCallbackfn callback) {
	SetCallbackMacro(handle, scroll, callback);
}
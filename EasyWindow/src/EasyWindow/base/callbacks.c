#include "internal.h"
#include <assert.h>

#define SetCallbackMacro(handle, name, callback)     \
		_EasyWindow* window = (_EasyWindow*)handle;  \
		assert(window != nullptr);				     \
		PtrSwapMacro(window->callback.name, callback)\
		return callback

#if EASYWINDOW_PLATFORM_WIN
EASYWINDOW_API EasyWindowImGuiMsgCallbackfn EasyWindowSetImGuiMsgCallback(EasyWindow handle, EasyWindowImGuiMsgCallbackfn callback) {
	SetCallbackMacro(handle, imgui, callback);
}
#endif 

EASYWINDOW_API EasyWindowMinimizeCallbackfn EasyWindowSetMinimizeCallback(EasyWindow handle, EasyWindowResizeCallbackfn callback) {
	SetCallbackMacro(handle, minimize, callback);
}

EASYWINDOW_API EasyWindowResizeCallbackfn EasyWindowSetResizeCallback(EasyWindow handle, EasyWindowResizeCallbackfn callback) {
	SetCallbackMacro(handle, resize, callback);
}

EASYWINDOW_API EasyWindowCloseCallbackfn EasyWindowSetCloseCallback(EasyWindow handle, EasyWindowCloseCallbackfn callback) {
	SetCallbackMacro(handle, close, callback);
}

EASYWINDOW_API EasyWindowKeyupCallbackfn EasyWindowSetKeyupCallback(EasyWindow handle, EasyWindowKeyupCallbackfn callback) {
	SetCallbackMacro(handle, keyup, callback);
}

EASYWINDOW_API EasyWindowKeydownCallbackfn EasyWindowSetKeydownCallback(EasyWindow handle, EasyWindowKeydownCallbackfn callback) {
	SetCallbackMacro(handle, keydown, callback);
}

EASYWINDOW_API EasyWindowMouseButtonCallbackfn EasyWindowSetMouseButtonCallback(EasyWindow handle, EasyWindowMouseButtonCallbackfn callback) {
	SetCallbackMacro(handle, mouse_button, callback);
}

EASYWINDOW_API EasyWindowMouseMoveCallbackfn EasyWindowSetMouseMoveCallback(EasyWindow handle, EasyWindowMouseMoveCallbackfn callback) {
	SetCallbackMacro(handle, mouse_move, callback);
}

EASYWINDOW_API EasyWindowScrollCallbackfn EasyWindowSetScrollCallback(EasyWindow handle, EasyWindowScrollCallbackfn callback) {
	SetCallbackMacro(handle, scroll, callback);
}
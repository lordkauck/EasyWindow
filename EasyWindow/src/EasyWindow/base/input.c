#include "internal.h"

void PROJ_APICALL _EasyWindowNativeInputKeydown(_EasyWindow* window, uint16 keycode, uint16 repeat) {
	window->keys[keycode].button = (repeat > 0) ? 2 : 1;

	window->keys[keycode].repeat += window->keys[keycode].button == 2 ? repeat : 0;

	if (window->callback.keydown)
		window->callback.keydown((EasyWindow*)window, keycode, window->keys[keycode].repeat);
}

void PROJ_APICALL _EasyWindowNativeInputKeyup(_EasyWindow* window, uint16 keycode) {
	window->keys[keycode].button = 0;
	window->keys[keycode].repeat = 0;

	if (window->callback.keyup)
		window->callback.keyup((EasyWindow*)window, keycode);
}

void PROJ_APICALL EasyWindowInputKeyup(_EasyWindow* window, uint16 keycode) { 
	_EasyWindowNativeInputKeyup(window, keycode); 
}

void PROJ_APICALL EasyWindowInputKeydown(_EasyWindow* window, uint16 keycode, uint16 repeat) { 
	_EasyWindowNativeInputKeydown(window, keycode, repeat); 
}

b8 PROJ_APICALL EasyWindowMouseMoved(_EasyWindow* window, float x, float y) {
	return ((x == window->mouse.vx) && (y == window->mouse.vy));
}

void PROJ_APICALL EasyWindowMouseXY(_EasyWindow* window, float vx, float vy) {
	window->mouse.vx = vx;
	window->mouse.vy = vy;

	if (window->callback.mouse_move) {
		window->callback.mouse_move((EasyWindow*)window, window->mouse.vx, window->mouse.vy);
	}

}

void PROJ_APICALL EasyWindowInputScroll(_EasyWindow* window, float x, float y) {
	if (window->callback.scroll) {
		window->callback.scroll((EasyWindow*)window, x, y);
	}
}

void PROJ_APICALL EasyWindowInputMouseButton(_EasyWindow* window, char button) {
	if (window->callback.mouse_button) {
		window->callback.mouse_button((EasyWindow*)window, button);
	}
}
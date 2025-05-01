#include "internal.h"

void APICALL _EasyWindowNativeInputKeydown(_EasyWindow* window, uint16 keycode, uint16 repeat) {
	window->keys[keycode].button = (repeat > 0) ? 2 : 1;

	window->keys[keycode].repeat += window->keys[keycode].button == 2 ? repeat : 0;

	if (window->callback.keydown)
		window->callback.keydown((EasyWindow*)window, keycode, window->keys[keycode].repeat);
}

void APICALL _EasyWindowNativeInputKeyup(_EasyWindow* window, uint16 keycode) {
	window->keys[keycode].button = 0;
	window->keys[keycode].repeat = 0;

	if (window->callback.keyup)
		window->callback.keyup((EasyWindow*)window, keycode);
}

void APICALL EasyWindowInputKeyup(_EasyWindow* window, uint16 keycode) { 
	_EasyWindowNativeInputKeyup(window, keycode); 
}

void APICALL EasyWindowInputKeydown(_EasyWindow* window, uint16 keycode, uint16 repeat) { 
	_EasyWindowNativeInputKeydown(window, keycode, repeat); 
}

b8 APICALL EasyWindowMouseMoved(_EasyWindow* window, float x, float y) {
	return ((x == window->mouse.vx) && (y == window->mouse.vy));
}

void APICALL EasyWindowMouseXY(_EasyWindow* window, float vx, float vy) {
	window->mouse.vx = vx;
	window->mouse.vy = vy;

	if (window->callback.mouse_move) {
		window->callback.mouse_move((EasyWindow*)window, window->mouse.vx, window->mouse.vy);
	}

}

void APICALL EasyWindowInputScroll(_EasyWindow* window, float x, float y) {
	if (window->callback.scroll) {
		window->callback.scroll((EasyWindow*)window, x, y);
	}
}

void APICALL EasyWindowInputMouseButton(_EasyWindow* window, char button) {
	if (window->callback.mouse_button) {
		window->callback.mouse_button((EasyWindow*)window, button);
	}
}
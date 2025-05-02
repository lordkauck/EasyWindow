#include "EasyWindow/base/base.h"
#include "EasyWindow/base/config.h"
#include "EasyWindow/base/internal.h"

#include <assert.h>
#include <Windows.h>
#include "win32window.h"

#define GET_X_LPARAM(lp)                        ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp)                        ((int)(short)HIWORD(lp))

<<<<<<< HEAD
<<<<<<< HEAD
b8 APICALL in_window(_EasyWindow* window, int16 x, int16 y) {
=======
b8 PROJ_APICALL in_window(_EasyWindow* window, int16 x, int16 y) {
>>>>>>> Initial Commit
=======
b8 PROJ_APICALL in_window(_EasyWindow* window, int16 x, int16 y) {
>>>>>>> Fixing broken stuff
	return !(
		(x >= 0 && x < (int16)window->cfg->get.width(window->cfg)) 
	 && (y >= 0 && y < (int16)window->cfg->get.height(window->cfg))
	);
}

<<<<<<< HEAD
<<<<<<< HEAD
b8 APICALL mb_held(int32 lparam, uint8 mask) { 
	return !(lparam & mask); 
}

LRESULT APICALL W32WndMsgProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
=======
=======
>>>>>>> Fixing broken stuff
b8 PROJ_APICALL mb_held(int32 lparam, uint8 mask) { 
	return !(lparam & mask); 
}

<<<<<<< HEAD
LRESULT __stdcall W32WndMsgProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
>>>>>>> Initial Commit
=======
LRESULT PROJ_APICALL W32WndMsgProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
>>>>>>> Fixing broken stuff
	_EasyWindow* window = (_EasyWindow*)GetPropA(hwnd, "W32EmptyWindow");
	if (!window) {
		switch (msg) {

		default: return DefWindowProcA(hwnd, msg, wparam, lparam);
		}
	}
	uint32 min_width = 880;
	uint32 min_height = 495;
	if (window) {
		if (window->callback.imgui) {
			if (window->callback.imgui(hwnd, msg, wparam, lparam))
				return 0;
		}

		switch (msg) {
		case WM_COMMAND: {

			break;
		}
		case WM_SIZE: {
			switch (wparam) {
			case SIZE_MINIMIZED: {
				
				break;
			}
			}
			break;
		}
		case WM_SIZING: {
			break;
		}
		case WM_CLOSE: {
			EasyWindowCloseRequest(window);
			W32UnregisterDestroyWnd(window);
			PostQuitMessage(0);
			return 0;
			break;
		}
		case WM_ERASEBKGND: {
			return 1;
			break;
		}

						  // Can't be fucked with to do this properly
		case WM_CHAR:
		case WM_SYSCHAR:
		case WM_UNICHAR:
			return 0;
			break;

		case WM_KEYDOWN:
		case WM_SYSKEYDOWN: {
			uint16 keyflags = HIWORD(wparam);
			uint16 vkcode = LOWORD(wparam);
			uint16 repeat = LOWORD(lparam);

			EasyWindowInputKeydown(window, vkcode, repeat);
			break;
		}
		case WM_KEYUP:
		case WM_SYSKEYUP: {
			short keyflags = HIWORD(wparam);
			short vkcode = LOWORD(wparam);
			EasyWindowInputKeyup(window, vkcode);
			break;
		}
		case WM_MOUSEMOVE: {
			// @NOTE: We get the raw position of the mouse 
			//		  this is needed to know where the mouse
			//		  is at all though it isn't what will be 
			//		  used for determining mouse position.
			POINTS pos = { GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam) };

			// @NOTE: To actually make sure the mouse is inside the window boundaries
			if ((!window->mouse.capture) && in_window(window, pos.x, pos.y)) {
				SetCapture(hwnd);
				window->mouse.capture = true;
			}

			// @NOTE: The mouse is using some wonky positioning,  tldr: 
			//		  it gets the position relative to the window's length 
			//		  & width. So we calculate the change in direction of 
			//		  the mouse on the x and y axis' and calculate the
			//		  position of the mouse inside the window from that
			int32 delta_x = pos.x - window->mouse.px;
			int32 delta_y = pos.y - window->mouse.py;

			// @NOTE: This is the "virtual" position of the mouse.
			//		  It's just the position of the mouse relative
			//		  to the center of the window.
			float delta_vx = window->mouse.vx + delta_x;
			float delta_vy = window->mouse.vy + delta_y;

			// @NOTE: We need to check if the mouse is outside the window boundaries
			//		  so that way we know if the user is trying to drag & drop a file
			//		  or if they are just not inside the window so we know if we should
			//		  capture mouse position or not.
			
			if (!in_window(window, pos.x, pos.y)) {
				// @NOTE: Just a bitmask for every mouse button that the Win32 API knows about
				unsigned char buttons = (MK_LBUTTON | MK_RBUTTON | MK_MBUTTON | MK_XBUTTON1 | MK_XBUTTON2);
				if ((!window->mouse.capture) && !(mb_held(lparam, buttons))) {
					// @NOTE: If the user isn't dragging and dropping something into the application
					//		  we do not want to capture the mouse position anymore since that could
					//		  cause some unwanted issues depending on the use case.
					// @NOTE: So we release capture and fire a mouse leave event (window lost focus).
					ReleaseCapture();
					window->mouse.capture = false;
					break;
				}

				// @NOTE: The user is dragging and droppping something into the application
				//		  so the mouse has *clearly* fucking moved, so we fire a mouse move
				//		  event.
				EasyWindowMouseXY(window, delta_vx, delta_vy);

				// @NOTE: We store the last "relative" position of the mouse
				//		  so we can use it for further calculations
				window->mouse.px = pos.x;
				window->mouse.py = pos.y;
				break;
			}

			// @NOTE: We only want to fire a mouse moved event if the 
			//		  user has *actually* moved the mouse.
			if (EasyWindowMouseMoved(window, delta_vx, delta_vy)) {
				// @NOTE: If the mouse has actually moved, then we can
				//		  call/create the mouse moved event
				EasyWindowMouseXY(window, delta_vx, delta_vy);
			}

			// @NOTE: We store the last "relative" position of the mouse
			//		  so we can use it for further calculations
			window->mouse.px = pos.x;
			window->mouse.py = pos.y;
			break;
		}
		case WM_MOUSEWHEEL: {
			EasyWindowInputScroll(window, 0.0, (SHORT)HIWORD(wparam) / (double)WHEEL_DELTA);
			return 0;
			break;
		}

		case WM_MOUSEHWHEEL: {
			// This message is only sent on Windows Vista and later
			// NOTE: The X-axis is inverted for consistency with macOS and X11
			EasyWindowInputScroll(window, -((SHORT)HIWORD(wparam) / (double)WHEEL_DELTA), 0.0);
		}
		default: return DefWindowProcA(hwnd, msg, wparam, lparam);
		}
	}
}
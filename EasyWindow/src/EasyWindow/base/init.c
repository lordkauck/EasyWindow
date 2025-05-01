#include "EasyWindow.h"
#include "internal.h"

_EasyWindowLib g_EasyWindow = { 0 };

#if defined(EASYWINDOW_DLL) 
static int __stdcall DllMain(HMODULE dll, DWORD fdwReason, LPVOID lpvReserved) {
	return 1;
}
#endif

EASYWINDOW_API void APICALL EasyWindowInit(void) {
	
}
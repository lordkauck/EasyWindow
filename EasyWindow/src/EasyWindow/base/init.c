#include "EasyWindow.h"
#include "internal.h"

_EasyWindowLib g_EasyWindow = { 0 };

#if defined(EASYWND_LIB_DLL) 
static int __stdcall DllMain(HMODULE dll, DWORD fdwReason, LPVOID lpvReserved) {
	return 1;
}
#endif

PROJ_SYMBOL void PROJ_APICALL EasyWindowInit(void) {
	
}
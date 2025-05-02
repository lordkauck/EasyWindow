#ifndef EASYWINDOW_BASE_H
#define EASYWINDOW_BASE_H

#include "Project/ProjectBase.h"
#pragma push_macro("EASYWND_ENABLE_MACROS")
#define EASYWND_ENABLE_MACROS 1

#if defined(EASYWND_ENABLE_MACROS)
#define EASYWINDOW_FORWARD_STRUCT(name) struct name
#define EASYWINDOW_FORWARD_HANDLE(name) typedef struct name##__ *name
#define EASYWINDOW_HANDLE(name) struct name##__ { char unused; }; typedef struct name##__ *name
#define EASYWINDOW_STRUCT(name) typedef struct name name

#define PtrSwapMacro(x, y)      \
		{						\
			auto t = x;			\
			x = y;				\
			y = t;				\
        }
#endif // defined(EASYWND_ENABLE_MACROS)
#pragma pop_macro("EASYWND_ENABLE_MACROS")
#endif // EASYWINDOW_BASE_H
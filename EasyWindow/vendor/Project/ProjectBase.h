#ifndef PROJECTBASE_H
#define PROJECTBASE_H

#pragma push_macro("PROJECT_CONFIG")
#define PROJECT_CONFIG 1
#if defined(PROJECT_CONFIG)
	#define PROJ_DEBUG_CONSOLE 1
	#if PROJ_DEBUG_CONSOLE
		#define PROJ_ENABLE_LOGGING 1
		#define PROJ_ENABLE_ASSERTS 1
	#endif // PROJ_DEBUG_CONSOLE

	#include "ProjectAPI.h"
	#include "Primatives.h"
#endif // defined(PROJECT_CONFIG)
#pragma pop_macro("PROJECT_CONFIG")

#endif // PROJECTBASE_H
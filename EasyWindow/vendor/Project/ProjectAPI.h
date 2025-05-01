#ifndef PROJECTAPI_H
#define PROJECTAPI_H

#if defined(PROJECT_CONFIG)
	#pragma push_macro("PROJECT_ENABLE_MACROS")
	#define PROJECT_ENABLE_MACROS 1
		
	#if defined(PROJECT_ENABLE_MACROS)
		#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)	|| defined(WIN64) || defined(_WIN64) || defined(__WIN64__)
			#define PLATFORM_WIN 1
		#elif defined(__linux__) || defined(__gnu_linux__)
			#define PLATFORM_LINUX 1
		#else
			#error Your platform is not supported yet!
		#endif

		#pragma push_macro("PROJECT_FIND_ARCH")
		#define PROJECT_FIND_ARCH 
		#if defined(PROJECT_FIND_ARCH)
			#if defined(PLATFORM_WIN)
				#if defined(_WIN64)
					#define ARCHX64
				#else
					#define ARCHX86
				#endif // defined (_WIN64)
			#elif defined(PLATFORM_LINUX)
			#else
			#endif // defined(PLATFORM_WIN)
		#endif // defined(PROJECT_FIND_ARCH)
		#pragma pop_macro("PROJECT_FIND_ARCH")

		#if defined(PLATFORM_WIN)
			#define PROJ_APICALL __stdcall
			#define PROJ_CDECL __cdecl 
			#define PROJ_THISCALL __thiscall
			#define PROJ_FASTCALL __fastcall  
			#define PROJ_VECCALL __vectorcall 
			#if defined(PROJECT_DLL) 
				#if defined(PROJECT_BUILD_DLL)
				#define PROJ_SYMBOL __declspec(dllexport)
			#else
				#define PROJ_SYMBOL __declspec(dllimport)
			#endif // defined(PROJECT_BUILD_DLL)
			#else
				#define PROJ_SYMBOL
			#endif // defined(PROJECT_DLL)
		#elif defined(PLATFORM_LINUX)
			#if defined(PROJECT_LIB)
				#define PROJ_SYMBOL __attribute__((visibility("default")))
			#else
				#define PROJ_SYMBOL 
			#endif
		#else
			#define PROJ_APICALL
			#define PROJ_CDECL
			#define PROJ_THISCALL 
			#define PROJ_FASTCALL 
			#define PROJ_VECCALL 
			#define PROJ_SYMBOL 
		#endif // defined(PLATFORM_WIN)
	#endif // PROJECT_ENABLE_MACROS 1
	#pragma pop_macro("PROJECT_ENABLE_MACROS")


#endif // defined(PROJECT_CONFIG)
#endif // PROJECTAPI_H
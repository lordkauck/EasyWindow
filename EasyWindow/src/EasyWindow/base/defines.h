#ifndef EASYWINDOW_DEFINES_H
#define EASYWINDOW_DEFINES_H

#pragma push_macro("EASYWND_ENABLE_MACROS")
#define EASYWND_ENABLE_MACROS 1

#if defined(EASYWND_ENABLE_MACROS)
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)	
	#define EASYWINDOW_PLATFORM_WIN 1
#elif defined(__linux__) || defined(__gnu_linux__)
	#define EASYWINDOW_PLATFORM_LINUX 1
#else
	#error Your platform is not supported yet!
#endif

#if defined(__clang__) || defined(__GNUC__)
	#define STATIC_ASSERT _Static_assert
#elif defined(_MSC_VER)
	#define STATIC_ASSERT static_assert
#endif

STATIC_ASSERT(sizeof(signed char)			 == 1, "Expected  int8 to be 1 byte in size.");
STATIC_ASSERT(sizeof(signed short int)		 == 2, "Expected int16 to be 2 byte in size.");
STATIC_ASSERT(sizeof(signed long int)		 == 4, "Expected int32 to be 4 byte in size.");
STATIC_ASSERT(sizeof(signed long long int)	 == 8, "Expected int64 to be 8 byte in size.");

STATIC_ASSERT(sizeof(unsigned char)			 == 1, "Expected  uint8 to be 1 byte in size.");
STATIC_ASSERT(sizeof(unsigned short int)	 == 2, "Expected uint16 to be 2 byte in size.");
STATIC_ASSERT(sizeof(unsigned long int)		 == 4, "Expected uint32 to be 4 byte in size.");
STATIC_ASSERT(sizeof(unsigned long long int) == 8, "Expected uint64 to be 8 byte in size.");


#if defined(EASYWINDOW_PLATFORM_WIN)
	#define APICALL __stdcall
	#define CDECL __cdecl 
	#if defined(EASYWINDOW_DLL) 
		#if defined(EASYWINDOW_BUILD_DLL)
			#define EASYWINDOW_API __declspec(dllexport)
		#else
			#define EASYWINDOW_API __declspec(dllimport)
		#endif // defined(EASYWINDOW_BUILD_DLL)
	#else
		#define EASYWINDOW_API
	#endif // defined(EASYWINDOW_DLL)
#elif defined(EASYWINDOW_PLATFORM_LINUX)
	#if defined(EASYWINDOW_LIB)
		#define EASYWINDOW_API __attribute__((visibility("default")))
	#else
		#define EASYWINDOW_API 
	#endif
#else
	#define APICALL
	#define CDECL
	#define EASYWINDOW_API 
#endif // defined(EASYWINDOW_PLATFORM_WIN) 

#endif // EASYWND_ENABLE_MACROS 1
#pragma pop_macro("EASYWND_ENABLE_MACROS")
#endif
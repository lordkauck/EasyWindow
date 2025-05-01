#ifndef PRIMATIVES_H
#define PRIMATIVES_H
typedef char					 int8;
typedef short					 int16;
typedef long					 int32;
typedef long long				 int64;

typedef unsigned char			 uint8;
typedef unsigned short			 uint16;
typedef unsigned long			 uint32;
typedef unsigned long long		 uint64;

typedef char*					 str;
typedef const char*				 cstring;

#ifndef __cplusplus
typedef char bool;
#define nullptr 0
#endif // __cplusplus

#if defined(ARCHX86) 
typedef unsigned int	 addr_t;
typedef uint32			 offset_t;
typedef uint32			 uint;
typedef unsigned int	 uptr_t;
typedef int				 ptr_t;
typedef uint32			 sizet;
#elif defined(ARCHX64) 
typedef unsigned __int64 addr_t;
typedef uint64			 offset_t;
typedef uint64			 uint;
typedef unsigned __int64 uptr_t;
typedef __int64			 ptr_t;
typedef uint64			 sizet;
#endif // defined(ARCHX86) 

#pragma push_macro("STATIC_ASSERT")
#if defined(__clang__) || defined(__GNUC__)
	#define STATIC_ASSERT _Static_assert
#elif defined(_MSC_VER)
	#define STATIC_ASSERT static_assert
#endif

STATIC_ASSERT(sizeof(int8) == 1, "Expected  int8 to be 1 byte in size.");
STATIC_ASSERT(sizeof(int16) == 2, "Expected int16 to be 2 byte in size.");
STATIC_ASSERT(sizeof(int32) == 4, "Expected int32 to be 4 byte in size.");
STATIC_ASSERT(sizeof(int64) == 8, "Expected int64 to be 8 byte in size.");

STATIC_ASSERT(sizeof(uint8) == 1, "Expected  uint8 to be 1 byte in size.");
STATIC_ASSERT(sizeof(uint16) == 2, "Expected uint16 to be 2 byte in size.");
STATIC_ASSERT(sizeof(uint32) == 4, "Expected uint32 to be 4 byte in size.");
STATIC_ASSERT(sizeof(uint64) == 8, "Expected uint64 to be 8 byte in size.");
#pragma pop_macro("STATIC_ASSERT")

#pragma push_macro("PROJ_DEFINE_LIMITS")
#define PROJ_DEFINE_LIMITS 1 
#if defined(PROJ_DEFINE_LIMITS)
	#define  int8_min         (-127i8 - 1)
	#define  int16_min        (-32767i16 - 1)
	#define  int32_min        (-2147483647i32 - 1)
	#define  int64_min        (-9223372036854775807i64 - 1)
	#define  int8_max         127i8
	#define  int16_max       32767i16
	#define  int32_max        2147483647i32
	#define  int64_max        9223372036854775807i64
	#define uint8_max        0xffui8
	#define uint16_max       0xffffui16
	#define uint32_max       0xffffffffui32
	#define uint64_max       0xffffffffffffffffui64
#endif // defined(PROJ_DEFINE_LIMITS)
#pragma pop_macro("PROJ_DEFINE_LIMITS")

#endif // ifndef PRIMATIVES_H
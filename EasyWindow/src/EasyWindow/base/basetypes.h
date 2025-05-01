#ifndef EASYWINDOW_BASETYPES_H
#define EASYWINDOW_BASETYPES_H

typedef signed char				 int8;
typedef signed short int		 int16;
typedef signed long int			 int32;
typedef signed long long int	 int64;

typedef unsigned char			 uint8;
typedef unsigned short int		 uint16;
typedef unsigned long int		 uint32;
typedef unsigned long long int	 uint64;



typedef const char* cstring;

#ifndef __cplusplus
typedef uint16 bool;
#endif

#ifndef __cplusplus
typedef _Bool b8;
#define nullptr 0
#define true 0 
#define false 1
#else
typedef bool b8;
#endif

#endif // EASYWINDOW_BASETYPES_H
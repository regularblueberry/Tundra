#pragma once
#include <stdint.h>
#include <stddef.h>
#include <wchar.h>
/*------------------------------|
	 <tun/types.h>		|
       Ring Level 0-3 API	|
-------------------------------*/

//Unsigned 64-bit Integer
typedef uint64_t u64;
//Unsigned 32-bit Integer
typedef uint32_t u32;
//Unsigned 16-bit Integer
typedef uint16_t u16;
//Unsigned 8-bit Integer
typedef uint8_t u8;
//Signed 64-bit Integer
typedef int64_t i64;
//Signed 32-bit Integer
typedef int32_t i32;
//Signed 16-bit Integer
typedef int16_t i16;
//Signed 8-bit Integer
typedef int8_t i8;

#ifndef __EXTRAC_RUNTIME__
	typedef i32 errvt;
#endif

typedef i32 __stream;
typedef i32 __device;

typedef u64 devID;
typedef char devName[255];

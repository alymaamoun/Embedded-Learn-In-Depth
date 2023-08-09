#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H


#include <stdint.h>

#define CPU_TYPE CPU_TYPE_16
#define CPU_BIT_ORDER LSB_FIRST
#define CPU_BYTE_ORDER HIGH_BYTE_FIRST

typedef unsigned char boolean;
typedef uint8_t  uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef int8_t   sint8;
typedef int16_t  sint16;
typedef int32_t  sint32;
typedef int64_t  sint64;

typedef uint8  uint8_least;
typedef uint16 uint16_least;
typedef uint32 uint32_least;
typedef uint64 uint64_least;
typedef sint8  sint8_least;
typedef sint16 sint16_least;
typedef sint32 sint32_least;
typedef sint64 sint64_least;


typedef volatile sint8  vint8_t;
typedef volatile uint8  vuint8_t;
typedef volatile sint16 vint16_t;
typedef volatile uint16 vuint16_t;
typedef volatile sint32 vint32_t;
typedef volatile uint32 vuint32_t;
typedef volatile sint64 vint64_t;
typedef volatile uint64 vuint64_t;

typedef double float32;
typedef long double float64;

typedef void* VoidPtr;
typedef const void* ConstVoidPtr;

//typedef enum {CPU_TYPE_8,CPU_TYPE_16,CPU_TYPE_32,CPU_TYPE_64}CPU_TYPE_;
//typedef enum {MSB_FIRST,LSB_FIRST}CPU_BIT_ORDER_;
//typedef enum {HIGH_BYTE_FIRST,LOW_BYTE_FIRST}CPU_BYTE_ORDER_;
typedef enum {FALSE,TRUE}TRUE_FALSE;



#endif

#ifndef FSTD_BASE_H
#define FSTD_BASE_H

/* Compiler Detection */
#include <cstdint>
#if defined(_MSC_VER)
    #define COMPILER_MSVC 1
#elif defined(__clang__)
    #define COMPILER_CLANG 1
#elif defined(__GNUC__)
    #define COMPILER_GCC 1
#else
    #error "Unsupported compiler"
#endif

/* Os Detection */
#if defined(_WIN32)
    #define OS_WINDOWS 1
#elif defined(__gnu_linux__)
    #define OS_LINUX 1
#elif defined(__APPLE__) && defined(__MACH__)
    #define OS_MAC 1
#else
    #error "Unsupported OS"
#endif

/* Architecture Detection */
#if defined(_M_AMD64) || defined(__amd64__) || defined(__x86_64__)
    #define ARCH_X64 1
#elif defined(_M_IX86) || defined(__i386__)
    #define ARCH_X86 1
#elif defined(_M_ARM) || defined(__arm__) || defined(__arm)
    #define ARCH_ARM 1
#elif defined(_M_ARM64) || defined(__aarch64__)
    #define ARCH_ARM64 1
#else
    #error "Unsupported architecture"
#endif

/* Define if not defined */
#if !defined(COMPILER_MSVC)
    #define COMPILER_MSVC 0
#endif
#if !defined(COMPILER_CLANG)
    #define COMPILER_CLANG 0
#endif
#if !defined(COMPILER_GCC)
    #define COMPILER_GCC 0
#endif
#if !defined(OS_WINDOWS)
    #define OS_WINDOWS 0
#endif
#if !defined(OS_LINUX)
    #define OS_LINUX 0
#endif
#if !defined(OS_MAC)
    #define OS_MAC 0
#endif
#if !defined(ARCH_X64)
    #define ARCH_X64 0
#endif
#if !defined(ARCH_X86)
    #define ARCH_X86 0
#endif
#if !defined(ARCH_ARM)
    #define ARCH_ARM 0
#endif
#if !defined(ARCH_ARM64)
    #define ARCH_ARM64 0
#endif


/* Asserts works the other way around than the <cassert>
 * in C asserts are enabled by default, and can be dissabled by declaring NDEBUG
 * here the assert have to be enabled explicitly */
#if ENABLE_ASSERT
    #define Assert(x) do { if(!(c)) { (*(int*)0) = 0 } } while(0);
#elif !defined(ENABLE_ASSERT)
    #define Assert(x)
#endif

/* Types */
#include <stdint.h>
typedef int8_t      i8;
typedef int16_t     i16;
typedef int32_t     i32;
typedef int64_t     i64;
typedef uint8_t     ui8;
typedef uint16_t    ui16;
typedef uint32_t    ui32;
typedef uint64_t    ui64;
typedef float       f32;
typedef double      f64;

static i8 min_i8 = (i8)0x80;
static i16 min_i16 = (i16)0x800;
static i32 min_i32 = (i32)0x80000000;
static i64 min_i64 = (i64)0x8000000000000000llu;

static i8 max_i8 = (i8)0x7f;
static i16 max_i16 = (i16)0x7fff;
static i32 max_i32 = (i32)0x7fffffff;
static i64 max_i64 = (i64)0x7fffffffffffffffllu;

static ui8 max_ui8 = (ui8)0xff;
static ui16 max_ui16 = (ui16)0xffff;
static ui32 max_ui32 = (ui32)0xffffffff;
static ui64 max_ui64 = (ui64)0xffffffffffffffffllu;

#endif // FSTD_BASE_H

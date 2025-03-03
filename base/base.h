#ifndef FSTD_BASE_H
#define FSTD_BASE_H

/* Compiler Detection */
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
#   define COMPILER_MSVC 0
#endif
#if !defined(COMPILER_CLANG)
#   define COMPILER_CLANG 0
#endif
#if !defined(COMPILER_GCC)
#   define COMPILER_GCC 0
#endif
#if !defined(OS_WINDOWS)
#   define OS_WINDOWS 0
#endif
#if !defined(OS_LINUX)
#   define OS_LINUX 0
#endif
#if !defined(OS_MAC)
#   define OS_MAC 0
#endif
#if !defined(ARCH_X64)
#   define ARCH_X64 0
#endif
#if !defined(ARCH_X86)
#   define ARCH_X86 0
#endif
#if !defined(ARCH_ARM)
#   define ARCH_ARM 0
#endif
#if !defined(ARCH_ARM64)
#   define ARCH_ARM64 0
#endif

#endif // FSTD_BASE_H

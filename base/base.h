#ifndef FSTD_BASE_H
#define FSTD_BASE_H

/* Compiler/OS/Architecture macros */
#if defined(_MSC_VER)
#   define COMPILER_MSVC 1
#   if defined(_WIN32)
#       define OS_WINDOWS 1
#   else
#       error OS not detected for COMPILER_MSVC
#   endif
#   if defined(_M_AMD64)
#       define ARCH_X64 1
#   elif defined(_M_IX86)
// Note(Zabsooon): This is the architecture only defined for 32-bits
#       define ARCH_X86 1
#   elif defined(_M_ARM)
#       define ARCH_ARM 1
#   else
#       error architecture not detected for COMPILER_MSVC
#   endif

#elif defined(__clang__)
#   define COMPILER_CLANG 1
#   if defined(_WIN32)
#       define OS_WINDOWS 1
#   elif defined(__gnu_linux__)
#       define OS_LINUX 1
#   elif defined(__APPLE__) && defined(__MACH__)
#       define OS_MAC 1
#   else
#       error OS not detected for COMPILER_CLANG
#   endif
#   if defined(__amd64__)
#       define ARCH_X64 1
#   elif defined(__i386__)
#       define ARCH_X86 1
#   elif defined(__arm__)
#       define ARCH_ARM 1
#   elif defined(__aarch64__)
#       define ARCH_ARM64 1
#   else
#       error architecture not detected for COMPILER_CLANG
#   endif

#elif defined(__GNUC__)
#   define COMPILER_GCC 1
#   if defined(_WIN32)
#       define OS_WINDOWS 1
#   elif defined(__gnu_linux__)
#       define OS_LINUX 1
#   elif defined(__APPLE__) && defined(__MACH__)
#       define OS_MAC 1
#   else
#       error OS not detected for COMPILER_GCC
#   endif
#   if defined(__amd64__)
#       define ARCH_X64 1
#   elif defined(__i386__)
#       define ARCH_X86 1
#   elif defined(__arm__)
#       define ARCH_ARM 1
#   elif defined(__aarch64__)
#       define ARCH_ARM64 1
#   else
#       error architecture not detected for COMPILER_GCC
#   endif


#else
#   error no macros support for this compiler
#endif



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

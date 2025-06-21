#include <gtest/gtest.h>
#include "fstd/base/base.h"

TEST(BaseTest, CompilerMacros) {
    int compiler_count = 0;
    if (COMPILER_MSVC) compiler_count++;
    if (COMPILER_CLANG) compiler_count++;
    if (COMPILER_GCC) compiler_count++;
    EXPECT_EQ(compiler_count, 1);
}

TEST(BaseTest, OsMacros) {
    int os_count = 0;
    if (OS_WINDOWS) os_count++;
    if (OS_LINUX) os_count++;
    if (OS_MAC) os_count++;
    EXPECT_EQ(os_count, 1);
}

TEST(BaseTest, ArchMacros) {
    int arch_count = 0;
    if (ARCH_X64) arch_count++;
    if (ARCH_X86) arch_count++;
    if (ARCH_ARM) arch_count++;
    if (ARCH_ARM64) arch_count++;
    EXPECT_GE(arch_count, 1); // >= 1 because some compilers define multiple
} 
#include "fstd/containers/vector.h"
#include <gtest/gtest.h>
#include <type_traits>

TEST(VectorTest, VectorInit) {
  fstd::Vector<int> vec{10};
  EXPECT_EQ(vec.size(), 10);
}

TEST(VectorTest, VectorAliasesInit) {
  fstd::Vector8<int> vec8{10};
  fstd::Vector16<int> vec16{10};
  fstd::Vector32<int> vec32{10};
  fstd::Vector64<int> vec64{10};

  // Yes I know it won't trigger failed test... but sizes need to be constexpr
  static_assert(std::is_same<ui8, decltype(vec8.size())>::value,
                "vec8 max_size is not ui8");
  static_assert(std::is_same<ui16, decltype(vec16.size())>::value,
                "vec16 max_size is not ui16");
  static_assert(std::is_same<ui32, decltype(vec32.size())>::value,
                "vec32 max_size is not ui32");
  static_assert(std::is_same<ui64, decltype(vec64.size())>::value,
                "vec64 max_size is not ui64");

  EXPECT_TRUE((std::is_same<ui8, decltype(vec8.size())>::value));
  EXPECT_TRUE((std::is_same<ui16, decltype(vec16.size())>::value));
  EXPECT_TRUE((std::is_same<ui32, decltype(vec32.size())>::value));
  EXPECT_TRUE((std::is_same<ui64, decltype(vec64.size())>::value));
}

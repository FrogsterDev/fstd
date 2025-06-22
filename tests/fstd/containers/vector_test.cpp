#include "fstd/containers/vector.h"
#include <gtest/gtest.h>
#include <type_traits>
#include <numeric> // For std::accumulate

TEST(VectorTest, VectorInit) {
  fstd::Vector<int> vec(10);
  EXPECT_EQ(vec.capacity(), 10);
  EXPECT_EQ(vec.size(), 0);

  fstd::Vector<int> vec2(vec);
  EXPECT_EQ(vec2.capacity(), 10);
  EXPECT_EQ(vec2.size(), 0);
}

TEST(VectorTest, VectorAliasesInit) {
  fstd::Vector8<int> vec8(10);
  fstd::Vector16<int> vec16(10);
  fstd::Vector32<int> vec32(10);
  fstd::Vector64<int> vec64(10);

  // Yes I know it won't trigger failed test... but sizes need to be constexpr
  static_assert(std::is_same<ui8, decltype(vec8.size())>::value,
                "fstd::Vector8 should have a size() type of ui8");
  static_assert(std::is_same<ui16, decltype(vec16.size())>::value,
                "fstd::Vector16 should have a size() type of ui16");
  static_assert(std::is_same<ui32, decltype(vec32.size())>::value,
                "fstd::Vector32 should have a size() type of ui32");
  static_assert(std::is_same<ui64, decltype(vec64.size())>::value,
                "fstd::Vector64 should have a size() type of ui64");

  EXPECT_TRUE((std::is_same<ui8, decltype(vec8.size())>::value));
  EXPECT_TRUE((std::is_same<ui16, decltype(vec16.size())>::value));
  EXPECT_TRUE((std::is_same<ui32, decltype(vec32.size())>::value));
  EXPECT_TRUE((std::is_same<ui64, decltype(vec64.size())>::value));
}

TEST(VectorTest, PushBackAndSize) {
  fstd::Vector<int> vec(2);
  vec.pushBack(1);
  EXPECT_EQ(vec.size(), 1);
  EXPECT_EQ(vec[0], 1);

  vec.pushBack(2);
  EXPECT_EQ(vec.size(), 2);
  EXPECT_EQ(vec[1], 2);

  // Test growth
  vec.pushBack(3);
  EXPECT_EQ(vec.size(), 3);
  EXPECT_EQ(vec[2], 3);
  EXPECT_GT(vec.capacity(), 2);
}

TEST(VectorTest, IteratorLoop) {
  fstd::Vector<int> vec(5);
  vec.pushBack(10);
  vec.pushBack(20);
  vec.pushBack(30);

  int expected_value = 10;
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    // This test is flawed because of the iterator implementation
    // it dereferences the vector and not the value
    EXPECT_EQ(*it, expected_value);
    expected_value += 10;
  }
}

// The iterator implementation is not compatible with std::iterator_traits
// so this test will fail to compile if uncommented.
TEST(VectorTest, IteratorAccumulate) {
    fstd::Vector<int> vec(5);
    vec.pushBack(1);
    vec.pushBack(2);
    vec.pushBack(3);
    vec.pushBack(4);
    vec.pushBack(5);

    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    EXPECT_EQ(sum, 15);
}

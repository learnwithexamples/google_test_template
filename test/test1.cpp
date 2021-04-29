#include "test1.h"

TEST(TESTSUITE1, testcase1) {
  EXPECT_EQ(1, 2) << "test if 1 equals 2";
}

TEST(TESTSUITE1, testcase2) {
  EXPECT_EQ(2, 2) << "test if 2 equals 2";
}

TEST(TESTSUITE1, testcase3) {
  EXPECT_EQ(1, class_c::minus(3, 2)) << "test if 3 - 2 equals 1";
}

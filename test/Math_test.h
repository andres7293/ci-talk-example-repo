#include <gtest/gtest.h>

#include "../src/Math.h"

class Math_Test : public ::testing::Test {
 protected:
  Math math{};
};

TEST_F(Math_Test, add) {
  ASSERT_EQ(math.add(1, 0), 1);
  ASSERT_EQ(math.add(-1, 0), -1);
  ASSERT_EQ(math.add(0, 0), 0);
  ASSERT_EQ(math.add(1212, 1), 1213);
}

TEST_F(Math_Test, sub) {
  ASSERT_EQ(math.sub(1, 0), 1);
  ASSERT_EQ(math.sub(-1, 0), -1);
  ASSERT_EQ(math.sub(0, 0), 0);
  ASSERT_EQ(math.sub(1212, 1), 1211);
}

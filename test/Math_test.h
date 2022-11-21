#include <gtest/gtest.h>
#include "../src/Math.h"

class Math_Test: public ::testing::Test
{
    protected:
        Math math{};
};

TEST_F(Math_Test, add)
{
    ASSERT_EQ(math.add(1, 0), 1);
}

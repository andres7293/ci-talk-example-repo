#include <gtest/gtest.h>

#include "Math_test.h"
#include "LinkedList_test.h"

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

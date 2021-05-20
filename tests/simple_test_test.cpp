#include "gtest/gtest.h"
#include "simple_test.h"

TEST(firstTest, test1) {

    simple_test obj;

    EXPECT_EQ (obj.add(674, 432),  674 + 432);
}
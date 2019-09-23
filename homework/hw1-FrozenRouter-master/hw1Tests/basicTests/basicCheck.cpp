#include "gtest/gtest.h"


TEST(basicCheckTestEqTest, testEq){
    EXPECT_EQ(1, 1);
}

TEST(basicCheckTestNeqTest, testNeq) {
    EXPECT_NE(1, 2);
}

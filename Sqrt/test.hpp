#pragma once
#include <gtest/gtest.h>
#include "Solution.hpp"
TEST(sqrt, one)
{
    auto test(1);
    MySqrt::Solution solution;
    const auto answer(1);
    EXPECT_EQ(answer, solution.mySqrt(test));
}
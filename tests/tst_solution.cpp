#include "gtest/gtest.h"
#include "solution.hpp"

namespace solution {

TEST(SolutionTest, basic)
{
    Fixture f;

    int a = 1;
    int b = 2;
    int expected = 3;
    int actual = f.addNumbers(a, b);

    EXPECT_EQ(expected, actual);
}

} // namespace solution

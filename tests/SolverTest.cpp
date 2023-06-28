#include "Solver.h"
#include <cmath>

#include <gtest/gtest.h>

class SolverTest : public ::testing::Test
{
public:
    SolverTest() = default;

protected:
    bool compare(double a, double b) const
    {
        return std::abs(a - b) < std::numeric_limits<double>::epsilon();
    }

    Solver::Solver solver;
};

TEST_F(SolverTest, no_roots)
{
    const auto roots = solver.solve(1, 0, 1);
    EXPECT_EQ(roots.size(), 0);
}

TEST_F(SolverTest, two_roots)
{
    const auto roots = solver.solve(1, 0, -1);
    EXPECT_EQ(roots.size(), 2);
    EXPECT_TRUE(compare(roots.at(0), 1));
    EXPECT_TRUE(compare(roots.at(1), -1));
}

TEST_F(SolverTest, two_roots_of_one)
{
    const auto roots = solver.solve(1, 2, 1);
    EXPECT_EQ(roots.size(), 2);
    EXPECT_TRUE(compare(roots.at(0), roots.at(1)));
    EXPECT_TRUE(compare(roots.at(0), -1));
    EXPECT_TRUE(compare(roots.at(1), -1));
}

TEST_F(SolverTest, throw_on_zero_a)
{
    EXPECT_THROW(solver.solve(0, 1, 1), std::invalid_argument);
}

TEST_F(SolverTest, small_coefficents)
{
    const auto roots = solver.solve(0.00000000000000127, 0.0000000000000002347, 0.0000000000000005667);
    EXPECT_EQ(roots.size(), 2);
    EXPECT_TRUE(compare(roots.at(0), roots.at(1)));
}

TEST_F(SolverTest, throw_on_NAN)
{
    EXPECT_THROW(solver.solve(NAN, NAN, NAN), std::invalid_argument);
}

TEST_F(SolverTest, throw_on_std_nan)
{
    EXPECT_THROW(solver.solve(std::nan("1"), std::nan("2"), std::nan("3")), std::invalid_argument);
}

TEST_F(SolverTest, throw_on_INFINITY)
{
    EXPECT_THROW(solver.solve(INFINITY, -INFINITY, INFINITY), std::invalid_argument);
}

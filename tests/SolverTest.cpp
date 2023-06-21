#include "Solver.h"

#include <gtest/gtest.h>

class SolverTest : public ::testing::Test
{
public:
    SolverTest() = default;

protected:
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
    EXPECT_EQ(roots.at(0), 1);
    EXPECT_EQ(roots.at(1), -1);
}

TEST_F(SolverTest, two_roots_of_one)
{
    const auto roots = solver.solve(1, 2, 1);
    EXPECT_EQ(roots.size(), 2);
    EXPECT_TRUE(roots.at(0) == roots.at(1));
    EXPECT_EQ(roots.at(0), -1);
    EXPECT_EQ(roots.at(1), -1);
}

TEST_F(SolverTest, throw_on_zero_a)
{
    EXPECT_THROW(solver.solve(0, 1, 1), std::exception);
}

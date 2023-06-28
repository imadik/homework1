#pragma once

#include <vector>

namespace Solver
{
    class Solver
    {
    public:
        Solver() = default;
        ~Solver() = default;
        std::vector<double> solve(double a, double b, double c) const;
    };
    
} // namespace Solver

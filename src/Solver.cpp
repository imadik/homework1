#include "Solver.h"
#include <cmath>
#include <stdexcept>

namespace Solver
{
    std::vector<double> Solver::solve(double a, double b, double c) const
    {
        std::vector<double> result{};
        if (std::abs(a) <= std::numeric_limits<double>::epsilon())
        {
            throw std::invalid_argument("a is zero");
        }
        else if (std::isnan(a) || std::isnan(b) || std::isnan(c))
        {
            throw std::invalid_argument("args is nan");
        }
        else if (std::isinf(a) || std::isinf(b) || std::isinf(c))
        {
            throw std::invalid_argument("args is infinity");
        }
        else
        {
            double D = b * b - 4 * a * c;
            if (!(D < -std::numeric_limits<double>::epsilon()))
            {
                if (std::abs(D) <= std::numeric_limits<double>::epsilon())
                {
                    const auto root = -b / (2 * a);
                    result = {root, root};
                }
                else if (D > std::numeric_limits<double>::epsilon())
                {
                    result = {
                        (-b + std::sqrt(D)) / (2 * a),
                        (-b - std::sqrt(D)) / (2 * a)
                    };
                }
            }
        }
        return result;
    }

} // namespace Solver

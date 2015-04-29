#pragma once
#include <string>

namespace mai
{
    namespace search
    {
        //
        //  functor ManhattanDistance
        //  to generate a heuristic value
        //
        struct ManhattanDistance
        {
            auto operator()(std::string const& curr, std::string const& goal) const -> std::size_t
            {
                std::size_t ret = 0;
                for (int index = 0; index != goal.size(); ++index)
                {
                    if ('0' == curr[index]) continue;
                    auto digit = curr[index] - '0';
                    ret += abs(index / 3 - digit / 3) + abs(index % 3 - digit % 3);// distance(row) plus distance(col)
                }

                return ret;
            }
        };

        //
        // functor MisplacedTiles
        // to generate a heuristic value
        //
        struct MisplacedTiles
        {
            auto operator()(std::string const& curr, std::string const& goal) const -> std::size_t
            {
                std::size_t count = 0;
                for (int i = 0; i != goal.size(); ++i) if (curr[i] != goal[i]) ++count;
                return count;
            }
        };
    }
}
#pragma once
#include <string>

namespace ai
{
	namespace search
	{
		struct ManhattanDistance
		{
			std::size_t operator()(std::string const& curr, std::string const& goal) const
			{
				std::size_t ret = 0;
				for (int index = 0; index != goal.size(); ++index)
				{
					if ('0' == curr[index])
						continue;

					auto digit = curr[index] - '0';
					ret += abs(index / 3 - digit / 3) + abs(index % 3 - digit % 3);// distance(row) plus distance(col)
				}

				return ret;
			}
		};

		struct MisplacedTiles
		{
			std::size_t operator()(std::string const& curr, std::string const& goal) const
			{
				std::size_t count = 0;
				for (int i = 0; i != goal.size(); ++i)
					if (curr[i] != goal[i]) ++count;
				return count;
			}
		};

		struct DefaultCostFunc
		{
			std::size_t operator()(std::string const& state) const
			{
				return state.size();
			}
		};
	}
}
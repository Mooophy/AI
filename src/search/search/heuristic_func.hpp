#pragma once
#include <string>

namespace ai
{
	namespace search
	{
		struct ManhattanDistance
		{
			std::size_t operator()(std::string const& state, std::string const& goal) const
			{
				std::size_t ret = 0;
				for (int index = 0; index != goal.size(); ++index)
				{
					if ('0' == state[index])
						continue;

					auto digit = state[index] - '0';
					ret += abs(index / 3 - digit / 3) + abs(index % 3 - digit % 3);// distance(row) plus distance(col)
				}

				return ret;
			}
		};
	}
}
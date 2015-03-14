#pragma once 

#include <string>

namespace ai
{
	namespace search
	{
		std::size_t manhattan_distance(std::string const& state, std::string const& goal)
		{
			std::size_t ret = 0;
			for (int index = 0; index != goal.size(); ++index)
			{
				if ('0' == state[index])
					continue;

				auto digit = state[index] - '0';
				ret += abs(index / 3 - digit / 3) + abs(index % 3 - index % 3);// distance(row) plus distance(col)
			}
			return ret;
		}
	}
}
#pragma once

#include <string>

namespace ai
{
	namespace search
	{
		struct Node
		{
			Node(std::string const& s, std::string const& p)
				: state(s), path(p)
			{}

			std::size_t depth() const
			{
				return path.size();
			}

			std::string state;
			std::string path;
		};
	}
}
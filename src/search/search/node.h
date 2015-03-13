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

			const std::string state;
			const std::string path;
		};
	}
}
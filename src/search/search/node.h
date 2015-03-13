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

			const std::string state;
			const std::string path;
		};
	}
}
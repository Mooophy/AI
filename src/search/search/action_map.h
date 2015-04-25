#pragma once

#include <map>
#include <functional>
#include <vector>
#include "node.hpp"


namespace ai
{
	namespace search
	{
		class ActionMap : public std::map < unsigned, std::vector<std::function<Node(Node const&)>> >
		{
			unsigned u(unsigned pos){ return pos - 3; }
			unsigned d(unsigned pos){ return pos + 3; }
			unsigned l(unsigned pos){ return pos - 1; }
			unsigned r(unsigned pos){ return pos + 1; }

		public:
			ActionMap();
		};
	}
}




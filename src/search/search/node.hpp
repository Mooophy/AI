#include <string>


#ifndef NODE_HPP
#define NODE_HPP

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


#endif // !NODE_HPP

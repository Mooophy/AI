#include <set>
#include <string>
#include <deque>

#include "node.hpp"
#include "action_map.hpp"

#ifndef DFS_HPP
#define DFS_HPP


namespace ai
{
	namespace search
	{
		struct DFS
		{
			DFS(Node const& source, Node const& goal)
				: visited_set{}, queue{}, path_to_goal{}, action_dictionary{}
			{

			}
			
			std::set<std::string> visited_set;
			std::deque<Node> queue;
			std::string path_to_goal;
			const ActionMap action_dictionary;
		};
	}
}


#endif // !DFS_HPP

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
			DFS(std::string const& source, std::string const& goal)
				: visited_set{}, dq{}, path_to_goal{}, action_dictionary{}
			{
				for (dq.push_front(Node(source, "")); !dq.empty();	/*	*/)
				{
					auto curr = dq.front();	dq.pop_front();
					if (goal == curr.state)
					{
						path_to_goal = curr.path;
						break;
					}

					for (auto make_child : action_dictionary.at(curr.state.find('0')))
					{
						auto child = make_child(curr);
						if (visited_set.end() != visited_set.find(child.state))
							dq.push_front(child);
					}

					visited_set.insert(curr.state);
				}
			}
			
			std::set<std::string> visited_set;
			std::deque<Node> dq;
			std::string path_to_goal;
			const ActionMap action_dictionary;
		};
	}
}


#endif // !DFS_HPP

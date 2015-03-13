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
				queue.push_front(source);
				while (! queue.empty())
				{
					auto curr = queue.front();
					queue.pop_front();
					
					if (is_goal(curr, goal))
					{
						path_to_goal = curr.path;
						break;
					}

					auto pos_of_empty_tile = curr.state.find('0');
					for (auto make_child : action_dictionary.at(pos_of_empty_tile))
					{
						auto child = make_child(curr);
						if (visited_set.end() != visited_set.find(child.state))
							queue.push_front(child);
					}

					visited_set.insert(curr.state);
				}
			}
			
			std::set<std::string> visited_set;
			std::deque<Node> queue;
			std::string path_to_goal;
			const ActionMap action_dictionary;

		private:
			bool is_goal(Node const& node, Node const& goal) const
			{
				return node.state == goal.state;
			}
		};
	}
}


#endif // !DFS_HPP

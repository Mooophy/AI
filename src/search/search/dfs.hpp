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
		class DFS
		{
		public:
			DFS(std::string const& source, std::string const& goal): 
				visited_set_{}, 
				dq_{}, 
				path_to_goal_{},
				action_dictionary{}
			{
				for (dq_.push_front(Node(source, ""));	!dq_.empty();	/**/)
				{
					auto curr = dq_.front();	dq_.pop_front();
					if (goal == curr.state)
					{
						path_to_goal_ = curr.path;
						break;
					}

					for (auto make_child : action_dictionary.at(curr.state.find('0')))
					{
						auto child = make_child(curr);
						if (visited_set_.end() != visited_set_.find(child.state))
							dq_.push_front(child);
					}

					visited_set_.insert(curr.state);
				}
			}

			std::set<std::string> const& visitted_set() const
			{
				return visited_set_;
			}

			std::deque<Node> const& queue() const
			{
				return dq_;
			}

			std::string const& path_to_goal() const
			{
				return path_to_goal_;
			}

		private:
			std::set<std::string> visited_set_;
			std::deque<Node> dq_;
			std::string path_to_goal_;
		
		public:
			const ActionMap action_dictionary;
		};
	}
}


#endif // !DFS_HPP

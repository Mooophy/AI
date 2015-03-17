#pragma once

#include <set>
#include <string>
#include <deque>
#include <algorithm>

#include "node.h"
#include "action_map.h"

namespace  ai
{
	namespace search
	{
		class PDS
		{
		public:

			PDS(std::string const& source, std::string const& goal) :
				max_depth_{0},
				visited_set_{},
				dq_{},
				path_to_goal_{},
				action_dictionary{}
			{
				for (max_depth_ = 0;/* true */; ++max_depth_)
				{
					reset_containers();
					for (dq_.push_front(Node(source, ""));  !dq_.empty();	/* empty */)
					{
						auto curr = dq_.front();	dq_.pop_front();
						visited_set_.insert(curr.state);
						
						if (goal == curr.state)
						{
							path_to_goal_ = curr.path;
							return;
						}

						if (curr.depth() >= max_depth_)
							continue;
						
						for (auto make_child : action_dictionary.at(curr.state.find('0')))
						{
							auto child = make_child(curr);
							if (visited_set_.end() == visited_set_.find(child.state))
								dq_.push_front(child);
						}
					}
				}
			}

			std::set<std::string> const& visited_set() const
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

			std::size_t const& max_depth() const
			{
				return max_depth_;
			}

		private:
			std::size_t max_depth_;
			std::set<std::string> visited_set_;
			std::deque<Node> dq_;
			std::string path_to_goal_;

			void reset_containers()
			{
				visited_set_ = decltype(visited_set_){};
				dq_ = decltype(dq_){};
			}

		public:
			const ActionMap action_dictionary;
		};
	}
}
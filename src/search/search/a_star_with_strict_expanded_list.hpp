#pragma once

#include <string>
#include <unordered_set>

#include "heuristic_func.hpp"
#include "priority_queue.hpp"
#include "node.h"
#include "action_map.h"

namespace ai
{
	namespace search
	{
		//
		//	A star search 
		//
		template<typename HeuristicFunc, typename CostFunc = ai::search::DefaultCostFunc>
		class AStarSEL
		{
		public:
			struct LessThan
			{
				explicit LessThan(std::string const& g = "012345678")
					: goal(g), h{}, c{}
				{}

				bool operator()(Node const& lhs, Node const& rhs) const
				{
					return h(lhs.state, goal) + c(lhs.state) < h(rhs.state, goal) + c(rhs.state);
				}

				const std::string goal;
				const HeuristicFunc h;
				const CostFunc c;
			};

			AStarSEL(std::string const& source, std::string const& goal):
				q_{ LessThan{} },
				path_to_goal_{},
				expanded_list_{},
				action_dictionary{}
			{
				auto start = Node(source, "");
				for (q_.push(start); !q_.empty(); /* */)
				{
					auto curr = q_.top();	q_.pop();

					if (goal == curr.state)
					{
						path_to_goal_ = curr.path;
						return;
					}

					if (expanded_list_.end() != expanded_list_.find(curr.state))
						continue;

					expanded_list_.insert(curr.state);

					LessThan less_than;
					for (auto make_child : action_dictionary.at(curr.state.find('0')))
					{
						auto child = make_child(curr);
						if (expanded_list_.end() != expanded_list_.find(child.state))
							continue;

						auto const& b = q_.data().begin();
						auto const& e = q_.data().end();
						auto it = std::find_if(b, e, [&](Node & node){return child.state == node.state; });
						if (it == e)
							q_.push(child);
						else if (less_than(*it, child))
							*it = child;
					}
				}
			}

			using Q = ai::container::PriorityQueue < ai::search::Node >;

			Q const& queue() const
			{
				return q_;
			}

			std::string const& path_to_goal() const
			{
				return path_to_goal_;
			}
						
		private:
			Q q_;
			std::string path_to_goal_;
			std::unordered_set<std::string> expanded_list_;

		public:
			const ActionMap action_dictionary;
		};
	}
}
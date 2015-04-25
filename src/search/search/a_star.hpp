#pragma once

#include <string>
#include <queue>

#include "node.hpp"
#include "action_map.h"
#include "heuristic_func.hpp"

namespace ai
{
	namespace search
	{
		//
		//	A* search without Expanded List
		//
		template<typename HeuristicFunc, typename CostFunc = DefaultCostFunc>
		class AStar
		{
		public:
			struct GreaterThan
			{
				explicit GreaterThan(std::string const& g = "012345678")
					: goal(g), h{}, c{}
				{}

				bool operator()(Node const& lhs, Node const& rhs) const
				{
					return h(lhs.state, goal) + c(lhs.state) > h(rhs.state, goal) + c(rhs.state);
				}

				const std::string goal;
				const HeuristicFunc h;
				const CostFunc c;
			};

			using Q = std::priority_queue < Node, std::vector<Node>, GreaterThan > ;

			AStar(std::string const& source, std::string const& goal) :
				q_{ GreaterThan{} },
				path_to_goal_{},
				action_dictionary{}
			{
				auto start = Node(source, "");
				for (q_.push(start); !q_.empty(); /* */)
				{
					auto curr = q_.top(); q_.pop();
					if (curr.state == goal)
					{
						path_to_goal_ = curr.path;
						return;
					}

					for (auto const& make_child : action_dictionary.at(curr.state.find('0')))
					{
						auto child = make_child(curr);
						q_.push(child);
					}
				}
			}

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

		public:
			const ActionMap action_dictionary;
		};
	}
}
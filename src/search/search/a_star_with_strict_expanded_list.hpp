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
				frontier_{ LessThan{} },
				path_to_goal_{},
				expanded_list_{},
				action_dictionary{}
			{

			}

			using Q = ai::container::PriorityQueue < ai::search::Node >;
		private:
			Q frontier_;
			std::string path_to_goal_;
			std::unordered_set<std::string> expanded_list_;

		public:
			const ActionMap action_dictionary;
		};
	}
}
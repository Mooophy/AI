#pragma once

#include <string>
#include <queue>

#include "node.h"
#include "action_map.h"
#include "heuristic_func.hpp"

namespace ai
{
	namespace search
	{
		//
		//	A* search without Expanded List
		//
		template<typename HeuristicFunc, typename CostFunc>
		class AStar
		{
		public:
			struct GreaterThan
			{
				explicit GreaterThan(std::string const& g = "012345678")
					: goal(g), h{}, c{}
				{}

				bool operator(std::string const& lhs, std::string const& rhs) const
				{
					return h(lhs, goal) + c(lhs, goal) > h(rhs, goal) + c(rhs, goal);
				}

				const std::string goal;
				const HeuristicFunc h;
				const CostFunc c;
			};

			using Q = std::priority_queue < Node, std::vector<Node>, GreaterThan > ;

			AStar(std::string const& source, std::string const& goal) :
				q_{GreaterThan},
				path_to_goal_{},
				action_dictionary{}
			{

			}
		private:
			Q q_;
			std::string path_to_goal_;

		public:
			const ActionMap action_dictionary;

		};
	}
}
//not tested, not finished yet.

#pragma once

#include <unordered_set>
#include <string>
#include <queue>

#include "node.h"
#include "action_map.h"

namespace ai
{
	namespace search
	{
		class UCS
		{
		public:
			struct LongerThan
			{
				bool operator() (Node const& lhs, Node const& rhs)
				{
					return lhs.depth() > rhs.depth();
				}
			};
			using MinPriorityQueue = std::priority_queue < Node, std::vector < Node >, LongerThan >;

			UCS(std::string const& source, std::string const& goal) :
				frontier_{ LongerThan{} },
				path_to_goal_{},
				action_dictionary{}
			{
				// not implemented yet.
			}

			MinPriorityQueue const& frontier() const { return frontier_; }
			std::string const& path_to_goal() const { return path_to_goal_; }

		private:
			MinPriorityQueue frontier_;
			std::string path_to_goal_;

		public:
			const ActionMap action_dictionary;

		};
	}
}
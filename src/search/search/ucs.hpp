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
			struct CompareNodeForLongerPath
			{
				bool operator() (Node const& lhs, Node const& rhs)
				{
					return lhs.path.size() < rhs.path.size();
				}
			};
			using MinPriorityQueue = std::priority_queue < Node, std::vector < Node >, CompareNodeForLongerPath > ;
			using HashTable = std::unordered_set < std::string > ;

			UCS(std::string const& source, std::string const& goal) :
				visited_list_{},
				frontier_{ CompareNodeForLongerPath{} },
				path_to_goal_{},
				action_dictionary{}
			{
				// not implemented yet.
			}

			HashTable const& visited_list() const { return visited_list_; }
			MinPriorityQueue const& frontier() const { return frontier_; }
			std::string const& path_to_goal() const { return path_to_goal_; }

		private:
			HashTable visited_list_;
			MinPriorityQueue frontier_;
			std::string path_to_goal_;

		public:
			const ActionMap action_dictionary;

		};
	}
}
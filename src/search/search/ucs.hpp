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
		//
		//	Uniform Cost Search
		//
		class UCS
		{
			struct LongerThan
			{
				bool operator() (Node const& lhs, Node const& rhs)
				{
					return lhs.depth() > rhs.depth();
				}
			};
		public:
			using MinPriorityQueue = std::priority_queue < Node, std::vector < Node >, LongerThan >;

			UCS(std::string const& source, std::string const& goal) :
				frontier_{ LongerThan{} },
				path_to_goal_{},
				action_dictionary{}
			{
				for (frontier_.push(Node(source, "")); !frontier_.empty(); /* */)
				{
					auto curr = frontier_.top();	frontier_.pop();

					if (goal == curr.state)
					{
						path_to_goal_ = curr.state;
						return;
					}

					for (auto make_child : action_dictionary.at(curr.state.find('0')))
						frontier_.push(make_child(curr));
				}
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
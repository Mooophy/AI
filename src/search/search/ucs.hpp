//not tested, not finished yet.

#pragma once

#include <unordered_set>
#include <set>
#include <string>
#include <queue>
#include <iostream>

#include "node.h"
#include "action_map.h"
#include "priority_queue.hpp"

namespace ai
{
	namespace search
	{
		//
		//	Uniform Cost Search with Expanded List
		//
		class UCS
		{
			struct ShorterThan
			{
				bool operator() (Node const& lhs, Node const& rhs)
				{
					return lhs.depth() < rhs.depth();
				}
			};

		public:
			using MinPriorityQueue = ai::container::PriorityQueue < Node > ;

			UCS(std::string const& source, std::string const& goal) :
				frontier_{ ShorterThan{} },
				path_to_goal_{},
				expanded_list_{},
				action_dictionary{}
			{
				for (frontier_.push(Node(source, "")); !frontier_.empty(); /* */)
				{
					auto curr = frontier_.top();	frontier_.pop();

					if (goal == curr.state)
					{
						path_to_goal_ = curr.path;
						return;
					}

					if (expanded_list_.end() != expanded_list_.find(curr.state))
						continue;

					expanded_list_.insert(curr.state);

					for (auto make_child : action_dictionary.at(curr.state.find('0')))
					{
						auto child = make_child(curr);
						if (expanded_list_.end() != expanded_list_.find(child.state))
							continue;

						auto const& b = frontier_.data().begin();
						auto const& e = frontier_.data().end();
						auto it = std::find_if(b, e, [&](Node & node){return child.state == node.state; });
						if (it == e)
							frontier_.push(child);
						else if (it->depth() > child.depth())
							*it = child;
					}
				}
			}

			MinPriorityQueue const& frontier() const { return frontier_; }
			std::string const& path_to_goal() const { return path_to_goal_; }
			std::unordered_set<std::string> const& expanded_list() const { return expanded_list_; }

		private:
			MinPriorityQueue frontier_;
			std::string path_to_goal_;
			std::unordered_set<std::string> expanded_list_;

		public:
			const ActionMap action_dictionary;
		};
	}
}
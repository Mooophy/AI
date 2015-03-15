#pragma once 

#include <string>
#include <queue>
#include <set>
#include "node.h"
#include "action_map.h"

namespace ai
{
	namespace search
	{
		struct ManhattanDistance
		{
			std::size_t operator()(std::string const& state, std::string const& goal) const
			{
				std::size_t ret = 0;
				for (int index = 0; index != goal.size(); ++index)
				{
					if ('0' == state[index])
						continue;

					auto digit = state[index] - '0';
					ret += abs(index / 3 - digit / 3) + abs(index % 3 - digit % 3);// distance(row) plus distance(col)
				}

				return ret;
			}
		};

		template<typename HeuristicFunc>
		struct GreaterThan
		{
			explicit GreaterThan(HeuristicFunc h, std::string const& g = "012345678")
				: goal(g), heuristic(h)
			{}

			bool operator()(Node const& lhs, Node const& rhs) const
			{
				return heuristic(lhs.state, goal) > heuristic(rhs.state, goal);
			}

			const std::string goal;
			const HeuristicFunc heuristic;
		};

		template<typename HeuristicFunc>
		class BestFirstSearch
		{
		public:
			using MinPriorityQueue = std::priority_queue < Node, std::vector<Node>, GreaterThan<HeuristicFunc> >;

			BestFirstSearch(std::string const& source, std::string const& goal): 
				visited_set_{},
				pq_( GreaterThan < HeuristicFunc > (HeuristicFunc()) ),
				path_to_goal_{},
				action_dictionary{}
			{
				for (pq_.push(Node(source, ""));	!pq_.empty();	/* */)
				{
					auto curr = pq_.top();	pq_.pop();
					visited_set_.insert(curr.state);
					
					if (goal == curr.state)
					{
						path_to_goal_ = curr.path;
						break;
					}

					for (auto make_child : action_dictionary.at(curr.state.find('0')))
					{
						auto child = make_child(curr);
						if (visited_set_.end() == visited_set_.find(child.state))
							pq_.push(child);
					}
				}
			}

			std::set<std::string> const& visited_set() const
			{
				return visited_set_;
			}
			MinPriorityQueue const& queue() const
			{
				return queue_;
			}
			std::string const& path_to_goal() const
			{
				return path_to_goal_;
			}

		private:
			std::set<std::string> visited_set_;
			MinPriorityQueue pq_;
			std::string path_to_goal_;

		public:
			const ActionMap action_dictionary;
		};
	}
}
#pragma once
#include <queue>
#include <unordered_set>
#include <algorithm>
#include "node.hpp"

namespace ai
{
	class BFS
	{
	public:
		std::string init, goal;

		BFS(std::string i, std::string g) :
			init{ i },
			goal{ g },
			visited_list{},
			final_path{},
			is_found{ false },
			q{},
			max_q_lenth{ 0 }
		{
			bfs();
		}

		std::string get_final_path() const
		{
			return final_path;
		}

		std::size_t get_max_q_length() const
		{
			return max_q_lenth;
		}

	private:
		std::unordered_set<std::string> visited_list;
		std::string final_path;
		bool is_found;
		std::queue<Node> q;
		std::size_t max_q_lenth;

		void bfs()
		{
			auto source = Node{ init, "" };
			for (q.push(source); !q.empty(); max_q_lenth = std::max(max_q_lenth, q.size()))
			{
				auto curr = q.front(); q.pop();
				if (curr.state == goal)
				{
					final_path = curr.path; return;
				}

				for (auto c : curr.valid_children())
					if (!is_visited(c.state)) visit(c.state), q.push(c);
			}
		}

		bool is_visited(std::string state) const
		{
			return visited_list.cend() != std::find(visited_list.cbegin(), visited_list.cend(), state);
		}

		void visit(std::string state)
		{
			visited_list.insert(state);
		}
	};
}
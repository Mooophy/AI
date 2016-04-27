#pragma once
#include <queue>
#include <unordered_set>
#include <algorithm>
#include "node.hpp"
#include "search.hpp"

namespace ai
{
    class BFS : search
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

        virtual std::string get_final_path() const override
        {
            return final_path;
        }

        virtual std::size_t get_max_q_length() const override
        {
            return max_q_lenth;
        }

        virtual std::size_t get_num_of_states_expanded() const override
        {
            return visited_list.size();
        }

        virtual float get_running_time() const override
        {
            return 0.1f;
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
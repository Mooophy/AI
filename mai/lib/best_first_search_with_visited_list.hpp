#pragma once 

#include <string>
#include <queue>
#include <set>
#include <chrono>
#include "node.hpp"
#include "heuristic_func.hpp"
#include "function_dictionary.hpp"

namespace mai
{
    namespace search
    {
        template<typename HeuristicFunc>
        class BestFSWithVList
        {
            struct Greater
            {
                Greater(HeuristicFunc h, std::string const& g) : goal(g), heuristic(h){}
                bool operator()(Node const& lhs, Node const& rhs) const
                {
                    return heuristic(lhs.state, goal) > heuristic(rhs.state, goal);
                }

                const std::string goal;
                const HeuristicFunc heuristic;
            };

            using MinPriorityQueue = std::priority_queue < Node, std::vector<Node>, GreaterThan<HeuristicFunc> > ;
        public:
            BestFSWithVList(std::string const& source, std::string const& goal) :
                max_q_length_{ 0u },
                visited_{},
                pq_{ Greater{} },
                final_path_{},
                running_time_{ 0.0f },
                func_dic_{}
            {
                auto start = Time::now();

                for (pq_.push(Node(source, "")); !pq_.empty();	/* */)
                {
                    auto curr = pq_.top();	pq_.pop();
                    visited_.insert(curr.state);

                    if (goal == curr.state){ path_to_goal_ = curr.path; goto Done; }
                    for (auto make_child : action_dictionary.at(curr.state.find('0')))
                    {
                        auto child = make_child(curr);
                        if (visited_.end() == visited_.find(child.state))   pq_.push(child);
                    }
                }

            Done:
                auto done = Time::now();
                running_time_ = std::chrono::duration<float>(done - start).count();
            }

        private:
            std::size_t max_q_length_;
            std::set<std::string> visited_;
            MinPriorityQueue pq_;
            std::string final_path_;
            float running_time_;
            const mai::search::FunctionDictionary func_dic_;
        };
    }
}
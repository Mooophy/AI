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
                Greater(std::string const& g) : goal(g), h{}{}
                bool operator()(Node const& lhs, Node const& rhs) const { return h(lhs.state, goal) > h(rhs.state, goal); }

                const std::string goal;
                const HeuristicFunc h;
            };

            using MinPriorityQueue = std::priority_queue < Node, std::vector<Node>, Greater > ;
            using Time = std::chrono::high_resolution_clock;
        public:
            BestFSWithVList(std::string const& source, std::string const& goal) :
                max_q_length_{ 0u },
                visited_{},
                pq_{ Greater{ goal } },
                final_path_{},
                running_time_{ 0.0f },
                func_dic_{}
            {
                auto start = Time::now();

                for (pq_.push(Node(source, "")); !pq_.empty();	/* */)
                {
                    auto curr = pq_.top();	pq_.pop();
                    visited_.insert(curr.state);

                    if (goal == curr.state){ final_path_ = curr.path; goto Done; }

                    for (auto make_child : func_dic_.at(curr.state.find('0')))
                    {
                        auto child = make_child(curr);
                        if (visited_.end() == visited_.find(child.state))   pq_.push(child);
                    }

                    if (pq_.size() > max_q_length_) max_q_length_ = pq_.size();
                }

            Done:
                auto done = Time::now();
                running_time_ = std::chrono::duration<float>(done - start).count();
            }

            auto max_q_length() const -> std::size_t { return max_q_length_; }
            auto visited() const -> std::set<std::string> const& { return visited_; }
            auto path() const -> std::string const& { return final_path_; }
            auto running_time() const -> float { return running_time_; }

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
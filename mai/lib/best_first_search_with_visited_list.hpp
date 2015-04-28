#pragma once 

#include <string>
#include <queue>
#include <unordered_set>
#include <chrono>
#include "time_record.hpp"
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
        public:
            BestFSWithVList(std::string const& source, std::string const& goal) 
                : max_q_length_{ 0 }, visited_{}, pq_{ Greater{ goal } }, final_path_{}, running_time_{ 0.0f }, func_dic_{}
            {
                auto timing = mai::utility::TimeRecord{ running_time_ };
                for (pq_.push(Node(source, "")); !pq_.empty(); max_q_length_ = std::max(max_q_length_, pq_.size()))
                {
                    auto curr = pq_.top();	pq_.pop();
                    visited_.insert(curr.state);
                    if (goal == curr.state){ final_path_ = curr.path; return; }

                    for (auto make_child : func_dic_.at(curr.state.find('0')))
                    {
                        auto child = make_child(curr);
                        if (visited_.end() == visited_.find(child.state))   pq_.push(child);
                    }
                }
            }

            auto max_q_length() const -> std::size_t { return max_q_length_; }
            auto visited() const -> std::unordered_set<std::string> const& { return visited_; }
            auto path() const -> std::string const& { return final_path_; }
            auto running_time() const -> float { return running_time_; }

        private:
            std::size_t max_q_length_;
            std::unordered_set<std::string> visited_;
            MinPriorityQueue pq_;
            std::string final_path_;
            float running_time_;
            const mai::search::FunctionDictionary func_dic_;
        };
    }
}
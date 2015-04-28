#pragma once

#include <unordered_set>
#include <string>
#include <queue>
#include <iostream>
#include <chrono>
#include "time_record.hpp"
#include "node.hpp"
#include "function_dictionary.hpp"
#include "priority_queue.hpp"

namespace mai
{
    namespace search
    {
        //
        //	Uniform Cost Search with Expanded List
        //
        class UniformCostSearch
        {
            struct Shorter
            {
                bool operator() (Node const& lhs, Node const& rhs) const
                {
                    return lhs.path.size() < rhs.path.size();
                }
            };

        public:
            using MinPriorityQueue = mai::container::PriorityQueue < Node > ;

            UniformCostSearch(std::string const& source, std::string const& goal) :
                max_q_length_{ 0 },
                q_{ Shorter{} },
                final_path_{},
                expanded_{},
                running_time_{ 0.0f },
                func_dic_{}
            {
                auto timing = mai::utility::TimeRecord{ running_time_ };
                for (q_.push(Node(source, "")); !q_.empty(); max_q_length_ = std::max(max_q_length_, q_.size()))
                {
                    auto curr = q_.top();	q_.pop();
                    if (goal == curr.state){ final_path_ = curr.path; return; }
                    if (expanded_.end() != expanded_.find(curr.state)) continue;

                    expanded_.insert(curr.state);
                    for (auto make_child : func_dic_.at(curr.state.find('0')))
                    {
                        auto child = make_child(curr);
                        if (expanded_.end() != expanded_.find(child.state)) continue;

                        auto it = std::find_if(q_.data().begin(), q_.data().end(), [&](Node const& node){ return child.state == node.state; });
                        if (it == q_.data().end()) q_.push(child);
                        else if (it->path.size() > child.path.size()) *it = child;
                    }
                }
            }

            auto max_q_length() const -> std::size_t { return max_q_length_; }
            auto running_time() const -> float { return running_time_; }
            auto path() const -> std::string const&{ return final_path_; }
            auto expanded() const -> std::unordered_set<std::string> const& { return expanded_; }

        private:
            std::size_t max_q_length_;
            MinPriorityQueue q_;
            std::string final_path_;
            std::unordered_set<std::string> expanded_;
            float running_time_;
            const mai::search::FunctionDictionary func_dic_;
        };
    }
}
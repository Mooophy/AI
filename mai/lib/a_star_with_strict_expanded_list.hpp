#pragma once

#include <string>
#include <unordered_set>
#include <chrono>
#include "time_record.hpp"
#include "node.hpp"
#include "function_dictionary.hpp"
#include "heuristic_func.hpp"
#include "default_cost_func.hpp"
#include "priority_queue.hpp"

namespace mai
{
    namespace search
    {
        template<typename HeuristicFunc, typename CostFunc = mai::search::DefaultCostFunc>
        class AStarSEL
        {
            struct Less
            {
                explicit Less(std::string const& g) : goal(g), h{}, c{} {}
                auto operator()(Node const& lhs, Node const& rhs) const -> bool
                {
                    return h(lhs.state, goal) + c(lhs) < h(rhs.state, goal) + c(rhs);
                }

                const std::string goal;
                const HeuristicFunc h;
                const CostFunc c;
            };

            using Q = mai::container::PriorityQueue < Node > ;
        public:
            AStarSEL(std::string const& source, std::string const& goal) 
                : max_q_length_{ 0u }, expanded_{}, q_{ Less{ goal } }, final_path_{}, func_dic_{}
            {
                auto timing = mai::utility::TimeRecord{ running_time_ };
                search(source, goal);
            }

            auto max_q_length() const -> std::size_t { return max_q_length_; }
            auto running_time() const -> float { return running_time_; }
            auto path() const -> std::string const&{ return final_path_; }
            auto expanded() const -> std::unordered_set<std::string> const& { return expanded_; }
        private:
            std::size_t max_q_length_;
            std::unordered_set<std::string> expanded_;
            Q q_;
            std::string final_path_;
            float running_time_;
            const mai::search::FunctionDictionary func_dic_;

            auto search(std::string const& source, std::string const& goal) -> void
            {
                auto less = Less{ goal };
                for (q_.push(Node{ source, "" }); !q_.empty(); max_q_length_ = std::max(max_q_length_, q_.size()))
                {
                    auto curr = q_.top();	q_.pop();
                    if (goal == curr.state){ final_path_ = curr.path; break; }
                    if (expanded_.end() != expanded_.find(curr.state)) continue;
                    expanded_.insert(curr.state);

                    for (auto make_child : func_dic_.at(curr.state.find('0')))
                    {
                        auto child = make_child(curr);
                        if (expanded_.end() != expanded_.find(child.state)) continue;
                        auto it = std::find_if(q_.data().begin(), q_.data().end(), [&](Node const& node){ return child.state == node.state; });

                        if (it == q_.data().end()) q_.push(child);
                        else if (less(child, *it)) *it = child;
                    }
                }
            }
        };
    }
}
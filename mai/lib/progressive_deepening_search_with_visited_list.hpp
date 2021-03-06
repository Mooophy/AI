#pragma once
#include <unordered_set>
#include <string>
#include <deque>
#include <algorithm>
#include <chrono>
#include "time_record.hpp"
#include "node.hpp"
#include "function_dictionary.hpp"

namespace mai
{
    namespace search
    {
        //
        //  class PDSWithVList
        //  Implementation for "progressive deepening search with visited list"
        //
        class PDSWithVList
        {
        public:
            //
            //  constructor
            //
            PDSWithVList(std::string const& source, std::string const& goal) 
                : max_depth_{ 0 }, max_q_length_{ 0 }, visited_{}, q_{}, final_path_{}, running_time_{ 0 }, func_dic_{}
            {
                auto timing = mai::utility::TimeRecord{ running_time_ };
                search(source, goal);
            }

            //
            //  public interfaces
            //
            auto max_depth() const -> std::size_t { return max_depth_; }
            auto max_q_length() const -> std::size_t { return max_q_length_; }
            auto visited() const -> std::unordered_set<std::string> const& { return visited_; }
            auto path() const -> std::string const& { return final_path_; }
            auto running_time() const -> float { return running_time_; }

        private:
            //
            //  data members
            //
            std::size_t max_depth_, max_q_length_;
            std::unordered_set<std::string> visited_;
            std::deque < mai::search::Node > q_;
            std::string final_path_;
            float running_time_;
            const mai::search::FunctionDictionary func_dic_;

            //
            //  algorithm 
            //
            auto search(std::string const& source, std::string const& goal) -> void
            {
                for (max_depth_ = 0; /* true */; ++max_depth_)
                {
                    visited_.clear();
                    q_.clear();
                    for (q_.push_front(Node(source, "")); !q_.empty(); max_q_length_ = std::max(max_q_length_, q_.size()))
                    {
                        auto curr = q_.front();	q_.pop_front();
                        visited_.insert(curr.state);

                        if (goal == curr.state){ final_path_ = curr.path; return; }
                        if (curr.path.size() >= max_depth_) continue;

                        for (auto make_child : func_dic_.at(curr.state.find('0')))
                        {
                            auto child = make_child(curr);
                            if (visited_.end() == visited_.find(child.state)) q_.push_front(child);
                        }
                    }
                }
            }
        };
    }
}
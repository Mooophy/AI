#pragma once
#include <stack>
#include "search.hpp"

namespace ai 
{
    class PDS : Search
    {
    public:
    private:
        std::string final_path;
        std::stack<Node> q;
        std::size_t max_q_lenth;

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
            return 0;
        }

        virtual float get_running_time() const override
        {
            return 0.1f;
        }


    };
}
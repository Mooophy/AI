#pragma once
#include <string>

namespace ai 
{
    class search
    {
        virtual std::string get_final_path() const = 0;
        virtual std::size_t get_max_q_length() const = 0;
        virtual std::size_t get_num_of_states_expanded()const = 0;
        virtual float get_running_time() const = 0;
    };
}
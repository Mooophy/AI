#pragma once

#include <string>

namespace mai
{
    namespace search
    {
        struct Node
        {
            Node() = default;
            Node(std::string const& s, std::string const& p) : state(s), path(p){}

            std::string state, path;
        };
    }
}
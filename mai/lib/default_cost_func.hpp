#pragma once
#include "node.hpp"

namespace mai
{
    namespace search
    {
        //
        //  functor DefaultCostFunc
        //  to calculate cost value
        //
        struct DefaultCostFunc
        {
            auto operator()(mai::search::Node const& node) const -> std::size_t
            {
                return node.path.size();
            }
        };
    }
}
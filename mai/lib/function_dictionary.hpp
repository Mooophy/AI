#pragma once

#include <map>
#include <functional>
#include <vector>
#include "node.hpp"

namespace mai
{
    namespace search
    {
        class FunctionDictionary : public std::map < unsigned, std::vector<std::function<Node(Node const&)>> >
        {
            auto fill_dic() -> void
            {
                auto u = [](unsigned pos){ return pos - 3; };
                auto d = [](unsigned pos){ return pos + 3; };
                auto l = [](unsigned pos){ return pos - 1; };
                auto r = [](unsigned pos){ return pos + 1; };

                auto make_child = [&](Node const& parent, std::function<unsigned(unsigned)> move_func, char direction) -> Node
                {
                    auto pos = parent.state.find('0');
                    auto stt = parent.state;
                    std::swap(stt[pos], stt[move_func(pos)]);
                    return mai::search::Node{ stt, parent.path + direction };
                };

                auto up = [&](Node const& parent) -> Node { return make_child(parent, u, 'U'); };
                auto dw = [&](Node const& parent) -> Node { return make_child(parent, d, 'D'); };
                auto lt = [&](Node const& parent) -> Node { return make_child(parent, l, 'L'); };
                auto rt = [&](Node const& parent) -> Node { return make_child(parent, r, 'R'); };

                using FuncList = std::vector < std::function<Node(Node const&)> > ;

                //  adress:
                //	0	1	2
                //	3	4	5
                //	6	7	8

                (*this)[0] = FuncList{ dw, rt };
                (*this)[2] = FuncList{ dw, lt };
                (*this)[6] = FuncList{ up, rt };
                (*this)[8] = FuncList{ up, lt };

                (*this)[1] = FuncList{ dw, lt, rt };
                (*this)[3] = FuncList{ up, dw, rt };
                (*this)[5] = FuncList{ up, dw, lt };
                (*this)[7] = FuncList{ up, lt, rt };

                (*this)[4] = FuncList{ up, dw, lt, rt };
            }

        public:
            FunctionDictionary(){ fill_dic(); }
        };
    }
}
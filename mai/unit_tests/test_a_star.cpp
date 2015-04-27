#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lib/a_star.hpp"
#include "../lib/heuristic_func.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
    TEST_CLASS(test_a_star)
    {
    public:

        //0.003s
        TEST_METHOD(a_star_876543210)
        {
            auto astar = mai::search::AStar < mai::search::ManhattanDistance > {"876543210", "012345678"};
            std::string expect_path = "LLUURRDDLLUURRDDLLUURRDDLLUU";

            Assert::AreEqual(expect_path, astar.path());
            Assert::AreEqual(1259u, astar.num_of_expansions());
            Assert::AreEqual(1924u, astar.max_q_length());
        }

    };
}
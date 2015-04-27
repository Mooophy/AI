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

        //0.015s
        TEST_METHOD(a_star_with_ManhattanDistance_481302675)
        {
            auto astar = mai::search::AStar < mai::search::ManhattanDistance > {"481302675", "012345678"};
            std::string expect_path = "ULDDRUURDDLLUU";

            Assert::AreEqual(expect_path, astar.path());
            Assert::AreEqual(4306u, astar.num_of_expansions());
            Assert::AreEqual(8082u, astar.max_q_length());
        }

        //0.105s
        TEST_METHOD(a_star_with_MisplacedTiles_481302675)
        {
            auto astar = mai::search::AStar < mai::search::MisplacedTiles > {"481302675", "012345678"};
            std::string expect_path = "ULDDRUURDDLLUU";
            Assert::AreEqual(expect_path, astar.path());
            Assert::AreEqual(33460u, astar.num_of_expansions());
            Assert::AreEqual(53545u, astar.max_q_length());
        }

    };
}
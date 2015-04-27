#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lib/a_star_with_strict_expanded_list.hpp"
#include "../lib/priority_queue.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
	TEST_CLASS(test_a_star_with_strict_expanded_list)
	{
	public:
		
        // < 0.001s
        TEST_METHOD(a_star_sel_with_ManhattanDistance_876543210)
		{
            auto astar_sel = mai::search::AStarSEL < mai::search::ManhattanDistance > { "876543210", "012345678" };
            std::string expect_path = "LLUURRDDLLUURRDDLLUURRDDLLUU";

            Assert::AreEqual(expect_path, astar_sel.path());
            Assert::AreEqual(265u, astar_sel.expanded().size());
            Assert::AreEqual(151u, astar_sel.max_q_length());
		}

        // 5s
        TEST_METHOD(a_star_sel_with_MisplacedTiles_876543210)
        {
            auto astar_sel = mai::search::AStarSEL < mai::search::MisplacedTiles > { "876543210", "012345678" };
            std::string expect_path = "UULLDDRRUULLDDRRUULLDDRRUULL";

            Assert::AreEqual(expect_path, astar_sel.path());
            Assert::AreEqual(60584u, astar_sel.expanded().size());
            Assert::AreEqual(20411u, astar_sel.max_q_length());
        }

	};
}
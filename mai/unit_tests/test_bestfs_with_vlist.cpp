#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lib/best_first_search_with_visited_list.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
    TEST_CLASS(test_bestfs_with_vlist)
    {
    public:

        //<0.001s
        TEST_METHOD(bestfs_ctor)
        {
            auto bestfs = mai::search::BestFSWithVList < mai::search::ManhattanDistance > {"876543210", "012345678"};
            Assert::AreEqual(std::string("UULLDDRRUULLDDRRUULLDDRRUULL"), bestfs.path());
            Assert::AreEqual(35u, bestfs.visited().size());
            Assert::AreEqual(19u, bestfs.max_q_length());
        }

    };
}
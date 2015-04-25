#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lib/progressive_deepening_search_with_visited_list.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
	TEST_CLASS(test_pds_with_vlist)
	{
	public:
		
		TEST_METHOD(pds_ctor)
		{
            auto pds = mai::search::ProgressiveDeepeningSearchWithVisitedList("102345678", "012345678");
            Assert::AreEqual(std::string{ "L" }, pds.path());
            Assert::AreEqual(3u, pds.visited().size());
		}

        //12.5s
        TEST_METHOD(pds_876543210)
        {
            auto pds = mai::search::ProgressiveDeepeningSearchWithVisitedList("876543210", "012345678");
            std::string expect_path = "LLUURRDDLLUURRDDLLUURRDDLLUU";

            Assert::AreEqual(expect_path, pds.path());
            Assert::AreEqual(14409u, pds.visited().size());
            Assert::AreEqual(25u, pds.max_q_length());
            Assert::AreEqual(28u, pds.max_depth());
            Assert::IsTrue(12.0f < pds.running_time() && 15.0f > pds.running_time());
        }

	};
}
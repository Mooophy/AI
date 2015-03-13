#include "stdafx.h"
#include "CppUnitTest.h"
#include "../search/pds.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test
{
	TEST_CLASS(test_pds)
	{
	public:
		
		TEST_METHOD(ctor)
		{
			ai::search::PDS pds("102345678", "012345678");
			Assert::AreEqual(std::string{"L"}, pds.path_to_goal());
			Assert::AreEqual(3u, pds.visited_set().size());
		}

		TEST_METHOD(ctor_assignment_part1)
		{
			ai::search::PDS pds("876543210", "012345678");
			std::string expect = "LLUURRDDLLUURRDDLLUURRDDLLUU";
			Assert::AreEqual(expect, pds.path_to_goal());
			Assert::AreEqual(14409u, pds.visited_set().size());
		}

	};
}
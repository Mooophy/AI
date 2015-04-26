#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lib/heuristic_func.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
	TEST_CLASS(test_heuristic_func)
	{
	public:
		
        TEST_METHOD(manhattan_distance)
		{
            auto h = mai::search::ManhattanDistance{};
            auto distance = h("724506831", "012345678");
            Assert::AreEqual(18u, distance);
		}

        TEST_METHOD(misplaced_tiles)
        {
            auto h = mai::search::MisplacedTiles{};

            auto v1 = h("724506831", "012345678");
            Assert::AreEqual(9u, v1);
            auto v2 = h("012345678", "012345678");
            Assert::AreEqual(0u, v2);
            auto v3 = h("812345670", "012345678");
            Assert::AreEqual(2u, v3);
        }

	};
}
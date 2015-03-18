#include "stdafx.h"
#include "CppUnitTest.h"
#include "../search/heuristic_func.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test
{
	TEST_CLASS(test_heuristic_func)
	{
	public:
		
		TEST_METHOD(manhattan_distance)
		{
			ai::search::ManhattanDistance h;
			auto distance = h("724506831", "012345678");
			Assert::AreEqual(18u, distance);
		}

		TEST_METHOD(misplaced_tiles)
		{
			ai::search::MisplacedTiles h;

			auto v1 = h("724506831", "012345678");
			Assert::AreEqual(9u, v1);

			auto v2 = h("012345678", "012345678");
			Assert::AreEqual(0u, v2);

			auto v3 = h("812345670", "012345678");
			Assert::AreEqual(2u, v3);
		}

	};
}
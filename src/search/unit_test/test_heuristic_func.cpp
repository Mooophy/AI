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

	};
}
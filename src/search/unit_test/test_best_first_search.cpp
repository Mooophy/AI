#include "stdafx.h"
#include "CppUnitTest.h"
#include "../search/best_first_search.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test
{
	TEST_CLASS(test_best_first_search)
	{
	public:
		
		TEST_METHOD(manhattan_distance)
		{
			ai::search::ManhattanDistance h;
			auto distance = h("724506831", "012345678");
			Assert::AreEqual(18u, distance);
		}

		TEST_METHOD(greater_than)
		{
			ai::search::ManhattanDistance h;
			ai::search::GreaterThan<ai::search::ManhattanDistance> greater(h);
		
			ai::search::Node l1("724506831", "");
			ai::search::Node r1("812345670", "");
			Assert::IsTrue(greater(l1, r1));

			ai::search::Node l2("356218074", "");
			ai::search::Node r2("812345670", "");
			Assert::IsTrue(greater(l2, r2));
		}

	};
}
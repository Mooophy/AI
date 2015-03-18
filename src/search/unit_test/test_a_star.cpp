#include "stdafx.h"
#include "CppUnitTest.h"
#include "../search/a_star.hpp"
#include "../search/heuristic_func.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test
{
	TEST_CLASS(test_a_star)
	{
	public:
		
		TEST_METHOD(ctor)
		{
			ai::search::AStar<ai::search::ManhattanDistance> astar("012345678", "012345678");

			Assert::AreEqual(9u, astar.action_dictionary.size());
			Assert::AreEqual(std::string(), astar.path_to_goal());

		}

	};
}
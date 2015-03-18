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
		//1ms
		TEST_METHOD(ctor)
		{
			ai::search::AStar<ai::search::ManhattanDistance> astar("102345678", "012345678");

			Assert::AreEqual(9u, astar.action_dictionary.size());
			Assert::AreEqual(std::string("L"), astar.path_to_goal());
		}

		//45ms
		TEST_METHOD(source_876543210)
		{
			ai::search::AStar<ai::search::ManhattanDistance> astar("876543210", "012345678");
			Assert::AreEqual(std::string("UDLLUURRDDLLUURRDDLLUURRDDLLUU"), astar.path_to_goal());
		}

		//infinity
		//TEST_METHOD(source_168342750)
		//{
		//	ai::search::AStar<ai::search::ManhattanDistance> astar("168342750", "012345678");
		//	Assert::AreEqual(std::string("UDLLUURRDDLLUURRDDLLUURRDDLLUU"), astar.path_to_goal());
		//}

		//infinity
		//TEST_METHOD(source_481302675)
		//{
		//	ai::search::AStar<ai::search::ManhattanDistance> astar("481302675", "012345678");
		//	Assert::AreEqual(std::string("UDLLUURRDDLLUURRDDLLUURRDDLLUU"), astar.path_to_goal());
		//}

		//infinity
		//TEST_METHOD(source_123804765)
		//{
		//	ai::search::AStar<ai::search::ManhattanDistance> astar("123804765", "012345678");
		//	Assert::AreEqual(std::string("UDLLUURRDDLLUURRDDLLUURRDDLLUU"), astar.path_to_goal());
		//}
	};
}
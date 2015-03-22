#include "stdafx.h"
#include "CppUnitTest.h"
#include "../search/a_star_with_strict_expanded_list.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test
{
	TEST_CLASS(test_a_star_with_strict_expanded_list)
	{
	public:
		
		TEST_METHOD(ctor)
		{
			ai::search::AStarSEL< ai::search::ManhattanDistance> astar_sel("102345678", "012345678");

			Assert::AreEqual(9u, astar_sel.action_dictionary.size());
			Assert::AreEqual(std::string("L"), astar_sel.path_to_goal());
		}

		//2s
		TEST_METHOD(souce_481302675)
		{
			ai::search::AStarSEL< ai::search::ManhattanDistance> astar_sel("481302675", "012345678");
			std::string expect = "URDDLURULLDRURDDLULURDRULLDRDLUURRDLULDDRURDLURDLULURRDDLURULL"; //<---this has problem. need to figure out
			Assert::AreEqual(expect, astar_sel.path_to_goal());
			Assert::AreEqual(274u, astar_sel.expanded_list().size());
		}

		//6ms
		TEST_METHOD(souce_876543210)
		{
			ai::search::AStarSEL< ai::search::ManhattanDistance> astar_sel("876543210", "012345678");
			std::string expect = "UULLDDRRUULLDDRRUULLDDRRUULL";
			Assert::AreEqual(expect, astar_sel.path_to_goal());
			Assert::AreEqual(34u, astar_sel.expanded_list().size());
		}

		//9m
		TEST_METHOD(souce_123804765)
		{
			ai::search::AStarSEL< ai::search::ManhattanDistance> astar_sel("123804765", "012345678");
			std::string expect = "";
			Assert::AreEqual(expect, astar_sel.path_to_goal());
			Assert::AreEqual(181440u, astar_sel.expanded_list().size());
		}
	};
}
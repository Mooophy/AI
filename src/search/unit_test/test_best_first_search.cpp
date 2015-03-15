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

		TEST_METHOD(ctor)
		{
			using namespace ai::search;
			BestFirstSearch< ManhattanDistance > best_first_search("102345678", "012345678");
			Assert::AreEqual(std::string("L"), best_first_search.path_to_goal());
		}

		//8ms
		TEST_METHOD(souce_876543210)
		{
			using namespace ai::search;
			BestFirstSearch< ManhattanDistance > best_first_search("876543210", "012345678");
			std::string expect = "UULLDDRRUULLDDRRUULLDDRRUULL";
			Assert::AreEqual(expect, best_first_search.path_to_goal());
			Assert::AreEqual(35u, best_first_search.visited_set().size());
		}

		//33ms
		TEST_METHOD(souce_168342750)
		{
			using namespace ai::search;
			BestFirstSearch< ManhattanDistance > best_first_search("168342750", "012345678");
			std::string expect = "LUULDRDLUURRDDLUURDLDRUULL";
			Assert::AreEqual(expect, best_first_search.path_to_goal());
			Assert::AreEqual(64u, best_first_search.visited_set().size());
		}

		//152ms
		TEST_METHOD(souce_481302675)
		{
			using namespace ai::search;
			BestFirstSearch< ManhattanDistance > best_first_search("481302675", "012345678");
			std::string expect = "ULDRURDDLULURRDLDRUULL";
			Assert::AreEqual(expect, best_first_search.path_to_goal());
			Assert::AreEqual(173u, best_first_search.visited_set().size());
		}

		//infinity
		TEST_METHOD(souce_123804765)
		{
			using namespace ai::search;
			BestFirstSearch< ManhattanDistance > best_first_search("123804765", "012345678");
			std::string expect = "ULDRURDDLULURRDLDRUULL";
			Assert::AreEqual(expect, best_first_search.path_to_goal());
			Assert::AreEqual(173u, best_first_search.visited_set().size());
		}
	};
}
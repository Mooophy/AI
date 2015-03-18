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

		//12s
		TEST_METHOD(souce_876543210)
		{
			ai::search::PDS pds("876543210", "012345678");
			std::string expect = "LLUURRDDLLUURRDDLLUURRDDLLUU";
			Assert::AreEqual(expect, pds.path_to_goal());
			Assert::AreEqual(14409u, pds.visited_set().size());
		}

		//5s
		TEST_METHOD(souce_168342750)
		{
			ai::search::PDS pds("168342750", "012345678");
			std::string expect = "LLUURRDLULDDRUULDRRDLLUU";
			Assert::AreEqual(expect, pds.path_to_goal());
			Assert::AreEqual(11053u, pds.visited_set().size());
		}

		//0.7s
		TEST_METHOD(souce_481302675)
		{
			ai::search::PDS pds("481302675", "012345678");
			std::string expect = "ULDDRUURDDLLUU";
			Assert::AreEqual(expect, pds.path_to_goal());
			Assert::AreEqual(3600u, pds.visited_set().size());
		}

		//inifinity
		//TEST_METHOD(souce_123804765)
		//{
		//	ai::search::PDS pds("123804765", "012345678");
		//	std::string expect = "ULDDRUURDDLLUU";
		//	Assert::AreEqual(expect, pds.path_to_goal());
		//	Assert::AreEqual(3600u, pds.visited_set().size());
		//}
	};
}
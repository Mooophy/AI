#include "stdafx.h"
#include "CppUnitTest.h"
#include "../search/ucs.hpp"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test
{
	TEST_CLASS(test_ucs)
	{
	public:
		
		TEST_METHOD(ctor)
		{
			
			ai::search::UCS ucs("102345678", "012345678");
			Assert::AreEqual(std::string{ "L" }, ucs.path_to_goal());
		}

		TEST_METHOD(souce_876543210)
		{
			ai::search::UCS ucs("876543210", "012345678");
			std::string expect = "LLUURRDDLLUURRDDLLUURRDDLLUU";
			Assert::AreEqual(expect, ucs.path_to_goal());
		}

		//7m
		TEST_METHOD(souce_168342750)
		{
			ai::search::UCS ucs("168342750", "012345678");
			std::string expect = "LLURURDDLUURDLLDRRUULL";
			Assert::AreEqual(expect, ucs.path_to_goal());
			Assert::AreEqual(3783u, ucs.expanded_list().size());
		}

		//2s
		TEST_METHOD(souce_481302675)
		{
			ai::search::UCS ucs("481302675", "012345678");
			std::string expect = "ULDDRUURDDLLUU";
			Assert::AreEqual(expect, ucs.path_to_goal());
			Assert::AreEqual(90539u, ucs.expanded_list().size());
		}

		//14m
		TEST_METHOD(souce_123804765)
		{
			ai::search::UCS ucs("123804765", "012345678");
			std::string expect = "";
			Assert::AreEqual(expect, ucs.path_to_goal());
			Assert::AreEqual(181440u, ucs.expanded_list().size());
		}
	};
}
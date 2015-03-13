#include "stdafx.h"
#include "CppUnitTest.h"
#include "../search/node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test
{		
	TEST_CLASS(test_node)
	{
	public:
		
		TEST_METHOD(ctor)
		{
			ai::search::Node node("876543210", "LLUUDDR");
			Assert::AreEqual(std::string("876543210"), node.state);
			Assert::AreEqual(std::string("LLUUDDR"), node.path);
		}

	};
}
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../search/priority_queue.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test
{
	TEST_CLASS(test_priority_queue)
	{
	public:
		
		TEST_METHOD(parent)
		{
			auto seq = { 5, 6, 9, 3, 2, 7 };
			Assert::IsTrue(seq.begin() == ai::container::parent(seq.begin(), seq.begin() + 1));
			Assert::IsTrue(seq.begin() == ai::container::parent(seq.begin(), seq.begin() + 2));
		}

		TEST_METHOD(left_child)
		{
			auto seq = { 5, 6, 9, 3, 2, 7 };
			auto left = ai::container::left_child(seq.begin(), seq.begin());
			Assert::IsTrue(left == seq.begin() + 1);
		}

		TEST_METHOD(right_child)
		{
			auto seq = { 5, 6, 9, 3, 2, 7 };
			auto right = ai::container::right_child(seq.begin(), seq.begin());
			Assert::IsTrue(right == seq.begin() + 2);
		}

	};
}
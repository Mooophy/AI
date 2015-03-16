#include "stdafx.h"
#include "CppUnitTest.h"
#include "../search/priority_queue.hpp"
#include <vector>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test
{
	TEST_CLASS(test_priority_queue)
	{
	public:
		
		TEST_METHOD(parent)
		{
			auto seq = { 5, 6, 9, 3, 2, 7 };
			auto p = ai::container::parent(seq.begin(), seq.begin());
			Assert::IsTrue(seq.begin() == ai::container::parent(seq.begin(), seq.begin() + 1));
			Assert::IsTrue(seq.begin() == ai::container::parent(seq.begin(), seq.begin() + 2));
		}

		TEST_METHOD(left_child)
		{
			auto seq = { 5, 6, 9, 3, 2, 7 };
			auto left = ai::container::left_child(seq.begin(), seq.end(), seq.begin());
			Assert::IsTrue(left == seq.begin() + 1);
		}

		TEST_METHOD(right_child)
		{
			auto seq = { 5, 6, 9, 3, 2, 7 };
			auto right = ai::container::right_child(seq.begin(), seq.end(), seq.begin());
			Assert::IsTrue(right == seq.begin() + 2);
		}

		TEST_METHOD(heapify)
		{
			std::vector<int> seq { 5, 6, 9, 3, 2, 7 };
			ai::container::heapify(seq.begin(), seq.end(), seq.begin(), std::greater<int>());
			auto expect = { 9, 6, 7, 3, 2, 5 };
			Assert::IsTrue(std::equal(seq.cbegin(), seq.cend(), expect.begin()));
		}

		TEST_METHOD(build_heap)
		{
			std::vector<int> seq{ 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
			ai::container::build_heap(seq.begin(), seq.end(), std::greater<int>());
			auto expect = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
			Assert::IsTrue(std::equal(seq.cbegin(), seq.cend(), expect.begin()));
		}
	};
}
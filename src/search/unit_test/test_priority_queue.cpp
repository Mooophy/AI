#include "stdafx.h"
#include "CppUnitTest.h"
#include "../search/priority_queue.hpp"
#include "../search/node.h"
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

		TEST_METHOD(default_ctor)
		{
			//test with int
			ai::container::PriorityQueue<int> pq(std::greater < int > {});

			//test with node
			auto greater = [](ai::search::Node const& lhs, ai::search::Node const& rhs) -> bool
			{
				return lhs.depth() > rhs.depth();
			};
			ai::container::PriorityQueue<ai::search::Node> frontier(std::move(greater));
		}

		TEST_METHOD(ctor_with_il)
		{
			//test with int
			ai::container::PriorityQueue<int> pq({ 1, 2, 3, 4, 5 }, std::greater<int>());
			
			//test with node
			auto nodes = { ai::search::Node("000", ""), ai::search::Node("001", ""), ai::search::Node("010", "") };
			auto greater = [](ai::search::Node const& lhs, ai::search::Node const& rhs) -> bool
			{
				return lhs.depth() > rhs.depth();
			};
			ai::container::PriorityQueue<ai::search::Node> frontier(std::move(nodes), greater);
		}

		TEST_METHOD(ctor_with_first_last)
		{
			//test with int
			std::vector<int> v{ 1, 2, 3, 4, 5 };
			ai::container::PriorityQueue<int> pq(v.cbegin(), v.cend(), std::greater<int>());

			//test with node
			auto nodes = { ai::search::Node("000", ""), ai::search::Node("001", ""), ai::search::Node("010", "") };
			auto greater = [](ai::search::Node const& lhs, ai::search::Node const& rhs) -> bool
			{
				return lhs.depth() > rhs.depth();
			};
			ai::container::PriorityQueue<ai::search::Node> frontier(nodes.begin(), nodes.end(), greater);
		}

		TEST_METHOD(top)
		{
			//test with node
			auto nodes = { ai::search::Node("012345678", "L"), ai::search::Node("012345678", "LD"), ai::search::Node("012345678", "LLUU") };
			auto greater = [](ai::search::Node const& lhs, ai::search::Node const& rhs) -> bool
			{
				return lhs.depth() > rhs.depth();
			};
			ai::container::PriorityQueue<ai::search::Node> frontier(nodes.begin(), nodes.end(), greater);

			Assert::AreEqual(std::string("LLUU"), frontier.top().path);
		}

		TEST_METHOD(size)
		{
			//test with node
			auto nodes = { ai::search::Node("012345678", "L"), ai::search::Node("012345678", "LD"), ai::search::Node("012345678", "LLUU") };
			auto greater = [](ai::search::Node const& lhs, ai::search::Node const& rhs) -> bool
			{
				return lhs.depth() > rhs.depth();
			};
			ai::container::PriorityQueue<ai::search::Node> frontier(nodes.begin(), nodes.end(), greater);

			Assert::AreEqual(3u, frontier.size());
		}

		TEST_METHOD(empty)
		{
			//test with node
			auto nodes = { ai::search::Node("012345678", "L"), ai::search::Node("012345678", "LD"), ai::search::Node("012345678", "LLUU") };
			auto greater = [](ai::search::Node const& lhs, ai::search::Node const& rhs) -> bool
			{
				return lhs.depth() > rhs.depth();
			};
			ai::container::PriorityQueue<ai::search::Node> frontier(nodes.begin(), nodes.end(), greater);

			Assert::IsFalse(frontier.empty());
		}

		TEST_METHOD(push)
		{
			//test with node
			auto nodes = { ai::search::Node("012345678", "L"), ai::search::Node("012345678", "LD"), ai::search::Node("012345678", "LLUU") };
			auto greater = [](ai::search::Node const& lhs, ai::search::Node const& rhs) -> bool
			{
				return lhs.depth() > rhs.depth();
			};
			ai::container::PriorityQueue<ai::search::Node> frontier(std::move(greater));

			for (auto && node : nodes)
				frontier.push(node);

			Assert::AreEqual(std::string("LLUU"), frontier.data()[0].path);
			Assert::AreEqual(std::string("L"), frontier.data()[1].path);
			Assert::AreEqual(std::string("LD"), frontier.data()[2].path);
		}

		TEST_METHOD(pop)
		{
			//test with node
			auto nodes = { ai::search::Node("012345678", "L"), ai::search::Node("012345678", "LD"), ai::search::Node("012345678", "LLUU") };
			auto greater = [](ai::search::Node const& lhs, ai::search::Node const& rhs) -> bool
			{
				return lhs.depth() > rhs.depth();
			};
			ai::container::PriorityQueue<ai::search::Node> frontier(nodes.begin(), nodes.end(), greater);

			Assert::AreEqual(3u, frontier.size());
			Assert::AreEqual(std::string("LLUU"), frontier.data()[0].path);
			
			frontier.pop();
			Assert::AreEqual(2u, frontier.size());
			Assert::AreEqual(std::string("LD"), frontier.data()[0].path);

			frontier.pop();
			Assert::AreEqual(1u, frontier.size());
			Assert::AreEqual(std::string("L"), frontier.data()[0].path);

			frontier.pop();
			Assert::AreEqual(0u, frontier.size());
			Assert::IsTrue(frontier.empty());
		}

		TEST_METHOD(contains)
		{
			//setup
			auto nodes = { ai::search::Node("012345678", "L"), ai::search::Node("012345678", "LD"), ai::search::Node("012345678", "LLUU") };
			auto greater = [](ai::search::Node const& lhs, ai::search::Node const& rhs) -> bool
			{
				return lhs.depth() > rhs.depth();
			};
			ai::container::PriorityQueue<ai::search::Node> frontier(nodes.begin(), nodes.end(), greater);

			//test
			ai::search::Node node("012345678", "LLUU");
			auto it = std::find_if(frontier.data().cbegin(), frontier.data().cend(), [=](ai::search::Node const& n)
			{
				return n.path == node.path && n.state == node.state;
			});
			Assert::IsTrue(it != frontier.data().cend());

			//pop and test again
			frontier.pop();
			it = std::find_if(frontier.data().cbegin(), frontier.data().cend(), [=](ai::search::Node const& n)
			{
				return n.path == node.path && n.state == node.state;
			});
			Assert::IsTrue(it == frontier.data().cend());

		}
	};
}
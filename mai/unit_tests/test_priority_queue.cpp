#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lib/node.hpp"
#include "../lib/priority_queue.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
    TEST_CLASS(test_priority_queue)
    {
    public:

        TEST_METHOD(pq_parent)
        {
            auto seq = { 5, 6, 9, 3, 2, 7 };
            auto p = mai::container::parent(seq.begin(), seq.begin());
            Assert::IsTrue(seq.begin() == mai::container::parent(seq.begin(), seq.begin() + 1));
            Assert::IsTrue(seq.begin() == mai::container::parent(seq.begin(), seq.begin() + 2));
        }

        TEST_METHOD(pq_left_child)
        {
            auto seq = { 5, 6, 9, 3, 2, 7 };
            auto left = mai::container::left_child(seq.begin(), seq.end(), seq.begin());
            Assert::IsTrue(left == seq.begin() + 1);
        }

        TEST_METHOD(pq_right_child)
        {
            auto seq = { 5, 6, 9, 3, 2, 7 };
            auto right = mai::container::right_child(seq.begin(), seq.end(), seq.begin());
            Assert::IsTrue(right == seq.begin() + 2);
        }

        TEST_METHOD(pq_heapify)
        {
            auto seq = std::vector < int > { 5, 6, 9, 3, 2, 7 };
            mai::container::heapify(seq.begin(), seq.end(), seq.begin(), std::greater<int>());
            auto expect = { 9, 6, 7, 3, 2, 5 };
            Assert::IsTrue(std::equal(seq.cbegin(), seq.cend(), expect.begin()));
        }

        TEST_METHOD(pq_build_heap)
        {
            auto seq = std::vector < int > { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
            mai::container::build_heap(seq.begin(), seq.end(), std::greater<int>());
            auto expect = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
            Assert::IsTrue(std::equal(seq.cbegin(), seq.cend(), expect.begin()));
        }

        TEST_METHOD(pq_default_ctor)
        {
            //test with int
            auto pq = mai::container::PriorityQueue<int>(std::greater < int > {});

            //test with node
            auto greater = [](mai::search::Node const& lhs, mai::search::Node const& rhs) -> bool
            {
                return lhs.path.size() > rhs.path.size();
            };
            auto frontier = mai::container::PriorityQueue<mai::search::Node>(std::move(greater));
        }

        TEST_METHOD(pq_ctor_with_il)
        {
            //test with int
            auto pq = mai::container::PriorityQueue<int>({ 1, 2, 3, 4, 5 }, std::greater<int>());

            //test with node
            auto nodes = { mai::search::Node("000", ""), mai::search::Node("001", ""), mai::search::Node("010", "") };
            auto greater = [](mai::search::Node const& lhs, mai::search::Node const& rhs) -> bool
            {
                return lhs.path.size() > rhs.path.size();
            };
            auto frontier = mai::container::PriorityQueue<mai::search::Node>(std::move(nodes), greater);
        }

        TEST_METHOD(pq_ctor_with_first_last)
        {
            //test with int
            std::vector<int> v{ 1, 2, 3, 4, 5 };
            auto pq = mai::container::PriorityQueue<int>(v.cbegin(), v.cend(), std::greater<int>());

            //test with node
            auto nodes = { mai::search::Node("000", ""), mai::search::Node("001", ""), mai::search::Node("010", "") };
            auto greater = [](mai::search::Node const& lhs, mai::search::Node const& rhs) -> bool
            {
                return lhs.path.size() > rhs.path.size();
            };
            auto frontier = mai::container::PriorityQueue<mai::search::Node>(nodes.begin(), nodes.end(), greater);
        }

        TEST_METHOD(pq_top)
        {
            //test with node
            auto nodes = { mai::search::Node("012345678", "L"), mai::search::Node("012345678", "LD"), mai::search::Node("012345678", "LLUU") };
            auto greater = [](mai::search::Node const& lhs, mai::search::Node const& rhs) -> bool
            {
                return lhs.path.size() > rhs.path.size();
            };
            auto frontier = mai::container::PriorityQueue<mai::search::Node>(nodes.begin(), nodes.end(), greater);

            Assert::AreEqual(std::string("LLUU"), frontier.top().path);
        }

        TEST_METHOD(pq_size)
        {
            //test with node
            auto nodes = { mai::search::Node("012345678", "L"), mai::search::Node("012345678", "LD"), mai::search::Node("012345678", "LLUU") };
            auto greater = [](mai::search::Node const& lhs, mai::search::Node const& rhs) -> bool
            {
                return lhs.path.size() > rhs.path.size();
            };
            auto frontier = mai::container::PriorityQueue<mai::search::Node>(nodes.begin(), nodes.end(), greater);

            Assert::AreEqual(3u, frontier.size());
        }

        TEST_METHOD(pq_empty)
        {
            //test with node
            auto nodes = { mai::search::Node("012345678", "L"), mai::search::Node("012345678", "LD"), mai::search::Node("012345678", "LLUU") };
            auto greater = [](mai::search::Node const& lhs, mai::search::Node const& rhs) -> bool
            {
                return lhs.path.size() > rhs.path.size();
            };
            auto frontier = mai::container::PriorityQueue<mai::search::Node>(nodes.begin(), nodes.end(), greater);

            Assert::IsFalse(frontier.empty());
        }

        TEST_METHOD(pq_push)
        {
            //test with node
            auto nodes = { mai::search::Node("012345678", "L"), mai::search::Node("012345678", "LD"), mai::search::Node("012345678", "LLUU") };
            auto greater = [](mai::search::Node const& lhs, mai::search::Node const& rhs) -> bool
            {
                return lhs.path.size() > rhs.path.size();
            };
            auto frontier = mai::container::PriorityQueue<mai::search::Node>(std::move(greater));

            for (auto && node : nodes)frontier.push(node);

            Assert::AreEqual(std::string("LLUU"), frontier.data()[0].path);
            Assert::AreEqual(std::string("L"), frontier.data()[1].path);
            Assert::AreEqual(std::string("LD"), frontier.data()[2].path);
        }

        TEST_METHOD(pq_pop)
        {
            //test with node
            auto nodes = { mai::search::Node("012345678", "L"), mai::search::Node("012345678", "LD"), mai::search::Node("012345678", "LLUU") };
            auto greater = [](mai::search::Node const& lhs, mai::search::Node const& rhs) -> bool
            {
                return lhs.path.size() > rhs.path.size();
            };
            auto frontier = mai::container::PriorityQueue<mai::search::Node>(nodes.begin(), nodes.end(), greater);

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

        TEST_METHOD(pq_contains)
        {
            //setup
            auto nodes = { mai::search::Node("012345678", "L"), mai::search::Node("012345678", "LD"), mai::search::Node("012345678", "LLUU") };
            auto greater = [](mai::search::Node const& lhs, mai::search::Node const& rhs) -> bool
            {
                return lhs.path.size() > rhs.path.size();
            };
            auto frontier = mai::container::PriorityQueue<mai::search::Node>(nodes.begin(), nodes.end(), greater);

            //test
            auto node = mai::search::Node("012345678", "LLUU");
            auto it = std::find_if(frontier.data().cbegin(), frontier.data().cend(), [=](mai::search::Node const& n)
            {
                return n.path == node.path && n.state == node.state;
            });
            Assert::IsTrue(it != frontier.data().cend());

            //pop and test again
            frontier.pop();
            it = std::find_if(frontier.data().cbegin(), frontier.data().cend(), [=](mai::search::Node const& n)
            {
                return n.path == node.path && n.state == node.state;
            });
            Assert::IsTrue(it == frontier.data().cend());
        }

    };
}
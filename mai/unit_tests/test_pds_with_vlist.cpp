#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lib/progressive_deepening_search_with_visited_list.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
    TEST_CLASS(test_pds_with_vlist)
    {
    public:

        TEST_METHOD(pds_ctor)
        {
            auto pds = mai::search::PDSWithVList("102345678", "012345678");
            Assert::AreEqual(std::string{ "L" }, pds.path());
            Assert::AreEqual(3u, pds.visited().size());
        }

        //0.25s
        TEST_METHOD(pds_876543210)
        {
            auto pds = mai::search::PDSWithVList("876543210", "012345678");
            std::string expect_path = "LLUURRDDLLUURRDDLLUURRDDLLUU";

            Assert::AreEqual(expect_path, pds.path());
            Assert::AreEqual(14409u, pds.visited().size());
            Assert::AreEqual(25u, pds.max_q_length());
            Assert::AreEqual(28u, pds.max_depth());
        }

        //0.112s
        TEST_METHOD(pds_168342750)
        {
            auto pds = mai::search::PDSWithVList("168342750", "012345678");
            std::string expect_path = "LLUURRDLULDDRUULDRRDLLUU";

            Assert::AreEqual(expect_path, pds.path());
            Assert::AreEqual(11053u, pds.visited().size());
            Assert::AreEqual(22u, pds.max_q_length());
            Assert::AreEqual(24u, pds.max_depth());
        }

        //0.009s
        TEST_METHOD(pds_481302675)
        {
            auto pds = mai::search::PDSWithVList("481302675", "012345678");
            std::string expect_path = "ULDDRUURDDLLUU";

            Assert::AreEqual(expect_path, pds.path());
            Assert::AreEqual(3600u, pds.visited().size());
            Assert::AreEqual(15u, pds.max_q_length());
            Assert::AreEqual(15u, pds.max_depth());
        }

        //infinity
        TEST_METHOD(pds_123804765)
        {
            //auto pds = mai::search::PDSWithVList("123804765", "012345678");
            //std::string expect_path = "";

            //Assert::AreEqual(expect_path, pds.path());
            //Assert::AreEqual(3600u, pds.visited().size());
            //Assert::AreEqual(15u, pds.max_q_length());
            //Assert::AreEqual(15u, pds.max_depth());
            //Assert::IsTrue(0.2f < pds.running_time() && 1.5f > pds.running_time());
        }

        //<0.001s
        TEST_METHOD(pds_042158367)
        {
            auto pds = mai::search::PDSWithVList("042158367", "012345678");
            std::string expect_path = "DDRRULUL";

            Assert::AreEqual(expect_path, pds.path());
            Assert::AreEqual(231u, pds.visited().size());
            Assert::AreEqual(8u, pds.max_q_length());
            Assert::AreEqual(8u, pds.max_depth());
        }

    };
}
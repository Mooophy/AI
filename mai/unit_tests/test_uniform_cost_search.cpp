#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lib/uniform_cost_search.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
    TEST_CLASS(test_uniform_cost_search)
    {
    public:

        //0.04s
        TEST_METHOD(ucs_481302675)
        {
            auto ucs = mai::search::UniformCostSearch{ "481302675", "012345678" };
            std::string expect_path = "ULDDRUURDDLLUU";

            Assert::AreEqual(expect_path, ucs.path());
            Assert::AreEqual(3783u, ucs.expanded().size());
            Assert::AreEqual(2404u, ucs.max_q_length());
        }

    };
}
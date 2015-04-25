#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lib/node.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
    TEST_CLASS(test_node)
    {
    public:

        TEST_METHOD(node_ctor)
        {
            auto n = mai::search::Node{ "876543210", "LLUUDDR" };
            Assert::AreEqual(std::string("876543210"), n.state);
            Assert::AreEqual(std::string("LLUUDDR"), n.path);
        }

    };
}
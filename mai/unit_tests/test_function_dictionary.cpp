#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lib/function_dictionary.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{
	TEST_CLASS(test_function_dictionary)
	{
	public:
		
		TEST_METHOD(function_dictionary_ctor)
		{
            auto dic = mai::search::FunctionDictionary();

            Assert::AreEqual(9u, dic.size());
            Assert::AreEqual(2u, dic.at(0).size());
            Assert::AreEqual(3u, dic.at(1).size());
            Assert::AreEqual(2u, dic.at(2).size());
            Assert::AreEqual(3u, dic.at(3).size());
            Assert::AreEqual(4u, dic.at(4).size());
            Assert::AreEqual(3u, dic.at(5).size());
            Assert::AreEqual(2u, dic.at(6).size());
            Assert::AreEqual(3u, dic.at(7).size());
            Assert::AreEqual(2u, dic.at(8).size());
		}

        TEST_METHOD(function_dictionary_case1)
        {
            auto dic = mai::search::FunctionDictionary();
            auto children = std::vector < mai::search::Node > {};
            auto parent = mai::search::Node{ "876543210", "" };
            for (auto make_child : dic.at(8u))
                children.push_back(make_child(parent));

            Assert::AreEqual(2u, children.size());
            Assert::AreEqual(std::string("876540213"), children[0].state);  // move up
            Assert::AreEqual(std::string("876543201"), children[1].state);  // move left
            Assert::AreEqual('U', children[0].path[0]);
            Assert::AreEqual('L', children[1].path[0]);
        }

	};
}
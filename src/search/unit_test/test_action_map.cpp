#include "stdafx.h"
#include "CppUnitTest.h"
#include "../search/action_map.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test
{
	TEST_CLASS(test_action_map)
	{
	public:
		
		TEST_METHOD(ctor)
		{
			ai::search::ActionMap actions;

			Assert::AreEqual(9u, actions.size());
			Assert::AreEqual(2u, actions.at(0).size());
			Assert::AreEqual(3u, actions.at(1).size());
			Assert::AreEqual(2u, actions.at(2).size());
			Assert::AreEqual(3u, actions.at(3).size());
			Assert::AreEqual(4u, actions.at(4).size());
			Assert::AreEqual(3u, actions.at(5).size());
			Assert::AreEqual(2u, actions.at(6).size());
			Assert::AreEqual(3u, actions.at(7).size());
			Assert::AreEqual(2u, actions.at(8).size());
		}

		TEST_METHOD(subscript)
		{
			ai::search::ActionMap const actions;
			std::vector<ai::search::Node> children;
			ai::search::Node parent("876543210", "");
			for (auto make_child : actions.at(8))
				children.push_back(make_child(parent));

			Assert::AreEqual(2u, children.size());
			Assert::IsTrue("876540213" == children[0].state);
			Assert::IsTrue("876543201" == children[1].state);
			Assert::IsTrue("U" == children[0].path);
			Assert::IsTrue("L" == children[1].path);
		}

	};
}
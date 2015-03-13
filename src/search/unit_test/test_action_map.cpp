#include "stdafx.h"
#include "CppUnitTest.h"
#include "../search/action_map.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test
{
	TEST_CLASS(test_action_map)
	{
	public:
		
		TEST_METHOD(u_child)
		{
			ai::search::Node parent("876543210", "");
			auto uc = ai::search::u_child(parent);

			Assert::AreEqual(uc.path, std::string("U"));
			Assert::AreEqual(uc.state, std::string("876540213"));
		}

		TEST_METHOD(d_child)
		{
			ai::search::Node parent("876540213", "");
			auto uc = ai::search::d_child(parent);

			Assert::AreEqual(uc.path, std::string("D"));
			Assert::AreEqual(uc.state, std::string("876543210"));
		}

		TEST_METHOD(l_child)
		{
			ai::search::Node parent("876543210", "");
			auto uc = ai::search::l_child(parent);

			Assert::AreEqual(uc.path, std::string("L"));
			Assert::AreEqual(uc.state, std::string("876543201"));
		}

		TEST_METHOD(r_child)
		{
			ai::search::Node parent("876543201", "");
			auto uc = ai::search::r_child(parent);

			Assert::AreEqual(uc.path, std::string("R"));
			Assert::AreEqual(uc.state, std::string("876543210"));
		}

		TEST_METHOD(ctor)
		{
			ai::search::ActionMap const actions;

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


			std::vector<ai::search::Node> children;
			ai::search::Node parent("876543210", "");
			for (auto& make_child : actions.at(8))
				children.push_back(make_child(parent));
			Assert::AreEqual(2u, children.size());
		}
	};
}
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../search/frontier.hpp"
#include "../search/node.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test
{
	TEST_CLASS(test_frontier)
	{
		struct Less
		{
			bool operator()(ai::search::Node const& lhs, ai::search::Node const& rhs)
			{
				return lhs.depth() < rhs.depth();
			};
		};
		using Frontier = ai::search::Frontier < ai::search::Node, Less >;
		using Node = ai::search::Node;
	public:
		
		TEST_METHOD(default_ctor)
		{
			Frontier frontier;
		}

		TEST_METHOD(push_pop)
		{
			Frontier frontier;
			Assert::IsTrue(frontier.empty());

			for (auto n : { Node("012345678", "L"), Node("012345678", "LUUU"), Node("012345678", "LUUU") })
				frontier.push(n);
			Assert::AreEqual(3u, frontier.size());
			Assert::IsTrue("012345678" == frontier.top().state);
			Assert::IsTrue("L" == frontier.top().path);
			
			frontier.pop();


		}

	};
}
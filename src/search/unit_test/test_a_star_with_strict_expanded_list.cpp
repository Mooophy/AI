#include "stdafx.h"
#include "CppUnitTest.h"
#include "../search/a_star_with_strict_expanded_list.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test
{
	TEST_CLASS(test_a_star_with_strict_expanded_list)
	{
	public:
		
		TEST_METHOD(ctor)
		{
			ai::search::AStarSEL< ai::search::ManhattanDistance> astar_sel("102345678", "012345678");
		}

	};
}
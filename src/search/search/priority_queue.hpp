//
// ai::container::priority_queue
//			class template;
//			support iteration like std::vector;
//			implmented using pseudocode from CLRS.
//

#pragma once

#include <assert.h>
#include <functional>

namespace ai
{
	namespace container
	{
		template<typename Iterator>
		inline Iterator parent(Iterator first,Iterator it)
		{
			return first + (it - first - 1) / 2;
		}

		//return left child if within range, return last otherwise
		template<typename Iterator>
		inline Iterator left_child(Iterator first, Iterator last, Iterator it)
		{
			auto size = last - first;
			auto offset = 2 * (it - first) + 1;
			return offset > size ? last : first + offset;
		}

		//return right child if within range, return last otherwise
		template<typename Iterator>
		inline Iterator right_child(Iterator first, Iterator last, Iterator it)
		{
			auto left = left_child(first, last, it);
			return left != last ? left + 1 : last;
		}

		template<typename Iterator, typename CompareFunc>
		void heapify(Iterator first, Iterator last, Iterator curr, CompareFunc && compare)
		{
			while (true)
			{
				auto left = ai::container::left_child(first, last, curr);
				auto right = ai::container::right_child(first, last, curr);

				//! find max or min amoung curr, left and right children, depending on the CommpareFunc passed in.
				auto max_min = (left != last && compare(*left, *curr)) ? left : curr;
				if (right != last && compare(*right, *max_min))	max_min = right;

				//!	exchange.
				if (max_min != curr)
				{
					std::swap(*max_min, *curr);
					curr = max_min;
				}
				else
				{
					return;
				}
			}
		}

		template<typename Iterator, typename CompareFunc >
		inline void build_heap(Iterator first, Iterator last, CompareFunc && compare)
		{
			auto size = last - first;
			for (auto curr = first + size / 2 - 1; /* */; --curr)
			{
				ai::container::heapify(first, last, curr, compare);
				if (curr == first) return;
			}
		}
	}
}
//
// ai::container::priority_queue
//			class template;
//			support iteration like std::vector;
//			implmented using pseudocode from CLRS.
//

#pragma once

#include <functional>

namespace ai
{
	namespace container
	{
		template<typename Iterator>
		inline Iterator parent(Iterator first, Iterator it)
		{
			return first + (it - first - 1) / 2;
		}

		template<typename Iterator>
		inline Iterator left_child(Iterator first, Iterator it)
		{
			return first + 2 * (it - first) + 1;
		}

		template<typename Iterator>
		inline Iterator right_child(Iterator first, Iterator it)
		{
			return ai::container::left(first,it) + 1;
		}

		template<typename Iterator, typename CompareFunc>
		void heapify(Iterator first, Iterator last, Iterator curr, CompareFunc && compare)
		{
			while (true)
			{
				auto left = ai::container::left_child(first, curr);
				auto right = ai::container::right_child(first, curr);

				//! find max or min amoung curr, left and right children, depending on what CommpareFunc passed in.
				auto max_min = (l < last && compare(*l, *curr)) ? l : curr;
				if (r < last && compare(*r, *max_min))	max_min = r;

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
		inline void build_heap(Iter first, Iter last, CompareFunc && compare)
		{
			auto size = last - first;
			for (auto curr = first + size / 2 - 1; curr != first - 1; --curr)
				ai::container::heapify(first, last, curr, compare);
		}
	}
}
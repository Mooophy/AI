//
// ai::container::priority_queue
//			class template;
//			support iteration like std::vector;
//			implmented using pseudocode from CLRS.
//

#pragma once

#include <vector>
#include <functional>
#include <stdexcept>
#include <algorithm>

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

		template<typename T>
		class PriorityQueue
		{
		public:
			using ValueType = T;
			using Vector = std::vector<T>;
			using SizeType = typename Vector::size_type;
			using Iterator = typename Vector::iterator;
			using CompareFunc = std::function<bool(ValueType const&, ValueType const&)>;

			explicit PriorityQueue(CompareFunc && c)
				: seq_{}, compare_{ std::move(c) }
			{}

			explicit PriorityQueue(std::initializer_list<ValueType>&& list, CompareFunc&& c ) 
				: seq_( std::move(list) ), compare_{ std::move(c) }
			{
				ai::container::build_heap(seq_.begin(), seq_.end(), compare_);
			}

			template<typename Iterator>
			PriorityQueue(Iterator first, Iterator last, CompareFunc&& c) 
				: seq_( first, last ), compare_{ std::move(c) }
			{
				ai::container::build_heap(seq_.begin(), seq_.end(), compare_);
			}

			Vector & data()
			{
				return seq_;
			}

			ValueType const& top() const
			{
				return seq_.front();
			}

			SizeType size() const
			{
				return seq_.size();
			}

			bool empty() const
			{
				return seq_.empty();
			}

			void push(ValueType const& new_val)
			{
				//! find the right place for added
				seq_.resize(size() + 1);
				auto curr = seq_.end() - 1;
				for (; curr > seq_.begin() && compare_(new_val, *parent(seq_.begin(), curr)); curr = parent(seq_.begin(), curr))
					*curr = *parent(seq_.begin(), curr);

				//! insert
				*curr = new_val;
			}

			void pop()
			{
				if (empty())
					throw std::underflow_error{ "heap underflow." };

				seq_.front() = seq_.back();
				seq_.resize(seq_.size() - 1);
				ai::container::heapify(seq_.begin(), seq_.end(), seq_.begin(), compare_);
			}
		private:
			Vector seq_;
			CompareFunc compare_;
		};
	}
}
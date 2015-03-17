#pragma once

#include <set>

namespace ai
{
	namespace search
	{
		//combine rb tree and priority queue.
		//used for UCS.
		template<typename T, typename CompareFunc>
		class Frontier
		{
		public:
			Frontier() = default;

			std::size_t size() const 
			{
				return set_.size();
			}

			bool empty() const
			{
				return set_.empty();
			}

			T const& top() const
			{
				return *set_.cbegin();
			}

			void push(T const& item)
			{
				set_.insert(item);
			}

			T pop()
			{
				auto top = *set_.begin();
				set_.erase(set_.begin());
				return top;
			}

		private:
			std::set<T,CompareFunc> set_;
		};
	}
}
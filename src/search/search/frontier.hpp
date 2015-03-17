#pragma once

#include <set>

namespace ai
{
	namespace search
	{
		//combine rb tree and priority queue.
		//used for UCS.
		template<typename T, typename CompareFunc>
		class OrderedFrontier
		{
		public:
			explicit OrderedFrontier(CompareFunc compare)
				: set_(compare)
			{}

			auto size() const -> decltype(set_.size())
			{
				return set_.size();
			}

			bool empty() const
			{
				return set_.empty();
			}

			void push(T const& item)
			{
				set_.insert(item);
			}

			T pop()
			{
				auto top = *data_.begin();
				set_.erase(data_.begin());
				return top;
			}

		private:
			std::set set_;
		};
	}
}
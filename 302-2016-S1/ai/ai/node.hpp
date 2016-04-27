#pragma once
#include <string>
#include <vector>
#include <algorithm>

namespace ai
{
	//
	//  struct Node 
	//  used in all search algorithms
	//
	struct Node
	{
		Node() = default;
		Node(std::string const& s, std::string const& p)
			: state(s), path(p)
		{}
		std::string state, path;

		auto valid_children() -> std::vector<Node>
		{
			auto valid_children = std::vector<Node>{};
			if (is_valid_to_up())
				valid_children.push_back(up());
			if (is_valid_to_rt())
				valid_children.push_back(rt());
			if (is_valid_to_dw())
				valid_children.push_back(dw());
			if (is_valid_to_lt())
				valid_children.push_back(lt());
			return valid_children;
		}

	private:

		auto index_of_0() const -> std::size_t { return state.find('0'); }

		auto is_valid_to_up() const -> bool { return index_of_0() > 2; }
		auto is_valid_to_rt() const -> bool { return (index_of_0() % 3) != 2; }
		auto is_valid_to_dw() const -> bool { return index_of_0() < 6; }
		auto is_valid_to_lt() const -> bool { return (index_of_0() % 3) != 0; }

		auto up() const -> Node
		{
			auto stt = state; std::swap(stt[index_of_0()], stt[index_of_0() - 3]);
			return Node{ stt, path + 'U' };
		}
		auto rt() const -> Node
		{
			auto stt = state; std::swap(stt[index_of_0()], stt[index_of_0() + 1]);
			return Node{ stt, path + 'R' };
		}
		auto dw() const -> Node
		{
			auto stt = state; std::swap(stt[index_of_0()], stt[index_of_0() + 3]);
			return Node{ stt, path + 'D' };
		}
		auto lt() const -> Node
		{
			auto stt = state; std::swap(stt[index_of_0()], stt[index_of_0() - 1]);
			return Node{ stt, path + 'L' };
		}
	};
}
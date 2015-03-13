#include "action_map.h"

ai::search::ActionMap::ActionMap()
{
	auto u_child = [=](Node const& parent) -> Node
	{
		auto pos_of_zero = parent.state.find('0');
		auto state = parent.state;
		std::swap(state[pos_of_zero], state[u(pos_of_zero)]);
		return Node(state, parent.path + 'U');
	};

	auto d_child = [=](Node const& parent) -> Node
	{
		auto pos_of_zero = parent.state.find('0');
		auto state = parent.state;
		std::swap(state[pos_of_zero], state[d(pos_of_zero)]);
		return Node(state, parent.path + 'D');
	};

	auto l_child = [=](Node const& parent) -> Node
	{
		auto pos_of_zero = parent.state.find('0');
		auto state = parent.state;
		std::swap(state[pos_of_zero], state[l(pos_of_zero)]);
		return Node(state, parent.path + 'L');
	};

	auto r_child = [=](Node const& parent) -> Node
	{
		auto pos_of_zero = parent.state.find('0');
		auto state = parent.state;
		std::swap(state[pos_of_zero], state[r(pos_of_zero)]);
		return Node(state, parent.path + 'R');
	};

	//adress:
	//	0	1	2
	//	3	4	5
	//	6	7	8

	using ActionList = std::vector < std::function<Node(Node const&)> >;

	(*this)[0] = ActionList{ d_child, r_child };
	(*this)[2] = ActionList{ d_child, l_child };
	(*this)[6] = ActionList{ u_child, r_child };
	(*this)[8] = ActionList{ u_child, l_child };

	(*this)[1] = ActionList{ d_child, l_child, r_child };
	(*this)[3] = ActionList{ u_child, d_child, r_child };
	(*this)[5] = ActionList{ u_child, d_child, l_child };
	(*this)[7] = ActionList{ u_child, l_child, r_child };

	(*this)[4] = ActionList{ u_child, d_child, l_child, r_child };
}
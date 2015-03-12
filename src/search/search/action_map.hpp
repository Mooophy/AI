#include "node.hpp"

#ifndef ACTION_MAP_HPP
#define ACTION_MAP_HPP

unsigned u(unsigned pos)
{
	return pos - 3;
}

unsigned d(unsigned pos)
{
	return pos + 3;
}

unsigned l(unsigned pos)
{
	return pos - 1;
}

unsigned r(unsigned pos)
{
	return pos + 1;
}

Node u_child(Node const& parent)
{
	auto pos_of_zero = parent.state.find('0');
	auto state = parent.state;
	std::swap(state[pos_of_zero], state[u(pos_of_zero)]);
	auto path = parent.path;
	path.push_back('U');
	
	return Node(state, path);
}

Node d_child(Node const& parent)
{
	auto pos_of_zero = parent.state.find('0');
	auto state = parent.state;
	std::swap(state[pos_of_zero], state[d(pos_of_zero)]);
	auto path = parent.path;
	path.push_back('D');

	return Node(state, path);
}

Node l_child(Node const& parent)
{
	auto pos_of_zero = parent.state.find('0');
	auto state = parent.state;
	std::swap(state[pos_of_zero], state[l(pos_of_zero)]);
	auto path = parent.path;
	path.push_back('L');

	return Node(state, path);
}

Node r_child(Node const& parent)
{
	auto pos_of_zero = parent.state.find('0');
	auto state = parent.state;
	std::swap(state[pos_of_zero], state[r(pos_of_zero)]);
	auto path = parent.path;
	path.push_back('R');

	return Node(state, path);
}


#endif // !ACTION_MAP_HPP

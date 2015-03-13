#include <map>
#include <functional>
#include <vector>

#include "node.hpp"


#ifndef ACTION_MAP_HPP
#define ACTION_MAP_HPP


namespace ai
{
	namespace search
	{
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


		struct ActionMap : public std::map < unsigned, std::vector<std::function<Node(Node const&)>> >
		{
			using ActionList = std::vector < std::function<Node(Node const&)> > ;

			ActionMap()
			{
				//adress:
				//	0	1	2
				//	3	4	5
				//	6	7	8

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
		};
	}
}
#endif // !ACTION_MAP_HPP

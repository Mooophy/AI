#include <iostream>

#include "action_map.hpp"
#include "dfs.hpp"
#include "node.hpp"

int main()
{
	ai::search::DFS dfs("102345678", "012345678");
	std::cout << dfs.path_to_goal() << std::endl;
	std::cout << "\nend\n";
	system("pause");
}
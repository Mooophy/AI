#include <iostream>
#include "bfs.hpp"

int main()
{
    auto bfs = ai::BFS{ "042158367", "012345678" };
    std::cout << bfs.get_final_path() << std::endl;
    std::cout << bfs.get_max_q_length() << std::endl;

    system("pause");
    return 0;
}
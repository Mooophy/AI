#include "algorithm.h"
#include "../lib/progressive_deepening_search_with_visited_list.hpp"
#include "../lib/best_first_search_with_visited_list.hpp"
#include "../lib/uniform_cost_search.hpp"
#include "../lib/a_star.hpp"
#include "../lib/a_star_with_strict_expanded_list.hpp"

using namespace std;


///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  Progressive Deepening Search with Visited List
//
////////////////////////////////////////////////////////////////////////////////////////////
string PDS_Visited_List(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, int ultimateMaxDepth)
{
    auto pds = mai::search::PDSWithVList(initialState, goalState);
    numOfStateExpansions = pds.visited().size(); 
    maxQLength = pds.max_q_length(); 
    actualRunningTime = pds.running_time();
    ultimateMaxDepth = pds.max_depth();
    return pds.path();
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  Best First Search with Visited List
//
////////////////////////////////////////////////////////////////////////////////////////////
string bestFirstSearch_Visited_List(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime)
{
    auto bestfs = mai::search::BestFSWithVList < mai::search::ManhattanDistance > {initialState, goalState};
    numOfStateExpansions = bestfs.visited().size();
    maxQLength = bestfs.max_q_length();
    actualRunningTime = bestfs.running_time();
    return bestfs.path();
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  Uniform Cost Search using the Strict ExpandedList
//
////////////////////////////////////////////////////////////////////////////////////////////
string uniformCost_Exp_List(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime)
{
    auto ucs = mai::search::UniformCostSearch{ initialState, goalState };
    numOfStateExpansions = ucs.expanded().size();
    maxQLength = ucs.max_q_length();
    actualRunningTime = ucs.running_time();
    return ucs.path();
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  A* without the ExpandedList
//
////////////////////////////////////////////////////////////////////////////////////////////
string aStar(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, heuristicFunction heuristic)
{
    if (heuristic == manhattanDistance)
    {
        auto astar = mai::search::AStar < mai::search::ManhattanDistance > { initialState, goalState } ;
        numOfStateExpansions = astar.num_of_expansions();
        maxQLength = astar.max_q_length();
        actualRunningTime = astar.running_time();
        return astar.path();
    }
    else
    {
        auto astar = mai::search::AStar < mai::search::MisplacedTiles > { initialState, goalState };
        numOfStateExpansions = astar.num_of_expansions();
        maxQLength = astar.max_q_length();
        actualRunningTime = astar.running_time();
        return astar.path();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  A* using the Strict ExpandedList
//
////////////////////////////////////////////////////////////////////////////////////////////
string aStar_Exp_List(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, heuristicFunction heuristic)
{
    if (heuristic == manhattanDistance)
    {
        auto astar_sel = mai::search::AStarSEL < mai::search::ManhattanDistance > { initialState, goalState };
        numOfStateExpansions = astar_sel.expanded().size();
        maxQLength = astar_sel.max_q_length();
        actualRunningTime = astar_sel.running_time();
        return astar_sel.path();
    }
    else
    {
        auto astar_sel = mai::search::AStarSEL < mai::search::MisplacedTiles > { initialState, goalState };
        numOfStateExpansions = astar_sel.expanded().size();
        maxQLength = astar_sel.max_q_length();
        actualRunningTime = astar_sel.running_time();
        return astar_sel.path();
    }
}

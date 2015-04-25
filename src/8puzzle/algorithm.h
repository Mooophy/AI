#include <set>
#include <stack>
#include <deque>
#include <ctime>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>

#include "puzzle.h"


const heuristicFunction HEURISTIC_FUNCTION=manhattanDistance;


//Progressive Deepening Seach with Visited List
string PDS_Visited_List(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, int ultimateMaxDepth);

//Best-First Search with Visited List
string bestFirstSearch_Visited_List(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime);

//Uniform Cost Search with Expanded List
string uniformCost_Exp_List(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime);

//A* Search
string aStar(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, heuristicFunction heuristic);

//A* using the Strict Expanded List
string aStar_Exp_List(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, heuristicFunction heuristic);
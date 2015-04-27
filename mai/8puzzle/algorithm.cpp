
#include "algorithm.h"
#include "../lib/progressive_deepening_search_with_visited_list.hpp"
#include "../lib/best_first_search_with_visited_list.hpp"
#include "../lib/uniform_cost_search.hpp"
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
string aStar(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, heuristicFunction heuristic){
    string path;
    clock_t startTime;

    startTime = clock();

    //***********************************************************************************************************
    // BEGIN_DUMMY_CODES - YOU SHOULD DELETE THIS BLOCK OF CODES AND REPLACE WITH YOUR ALGORITHM IMPLEMENTATION 
    //
    // run search algorithm here
    //
    //
    numOfStateExpansions = 777; //this is for testing only
    maxQLength = 333; //this is for testing only


    long i, j;

    j = 0;
    while (j < 99999){
        j++;
        i = 0;
        while (i < 99){
            i++;
        }
    }
    path = "LUULD";
    //
    // END_DUMMY_CODES
    //***********************************************************************************************************
    actualRunningTime = ((float)(clock() - startTime) / CLOCKS_PER_SEC);

    return path;
}



///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  A* using the Strict ExpandedList
//
////////////////////////////////////////////////////////////////////////////////////////////
string aStar_Exp_List(string const initialState, string const goalState, int &numOfStateExpansions, int& maxQLength, float &actualRunningTime, heuristicFunction heuristic){
    string path;
    clock_t startTime;

    startTime = clock();

    //***********************************************************************************************************
    // BEGIN_DUMMY_CODES - YOU SHOULD DELETE THIS BLOCK OF CODES AND REPLACE WITH YOUR ALGORITHM IMPLEMENTATION 
    //
    // run search algorithm here
    //
    //
    numOfStateExpansions = 777; //this is for testing only
    maxQLength = 333; //this is for testing only


    long i, j;

    j = 0;
    while (j < 99999){
        j++;
        i = 0;
        while (i < 99){
            i++;
        }
    }
    path = "LUULD";
    //
    // END_DUMMY_CODES
    //***********************************************************************************************************
    actualRunningTime = ((float)(clock() - startTime) / CLOCKS_PER_SEC);

    return path;
}

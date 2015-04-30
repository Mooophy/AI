#ifndef __NODES_H__
#define __NODES_H__

#include <string>
#include <iostream>
#include <math.h>

using namespace std;

const int MAX_ROWS=30;
const int MAX_COLS=30;
const int GRADATION=10;

enum heuristicFunction{misplacedTiles, manhattanDistance,euclidean};

class Node{
	

static int **dMap;

	
private:
    string id;
    string path;
    int pathLength;
    int hCost;
    int gCost;
    int fCost;
    int weight;
    int x, y; //coordinates of node
    int gradation;
    int index; //array index


public:
    int goalX, goalY;

    Node(const Node &p);
    Node(int _x, int _y, int _weight, int _goalX=-1, int _goalY=-1);


    void clear();
    int calcManhattanDistance(int xG, int yG);
    int h(heuristicFunction hFunction, int xG, int yG);
    void updateFCost(); 
    void updateHCost(heuristicFunction hFunction, int xG, int yG);
    
    bool goalMatch(int xG, int yG);
  
    const string getPath();
    const string getId();
    
    
    void setPath(string _path){ path = _path; }
    void setPathLength(int pLength){ pathLength = pLength;}
    
    int getPathLength();
    int getFCost();
    int getHCost() { return hCost; }
    int getX(){ return x;}
    int getY(){ return y;}
    int getWeight(){ return weight;}
    void setWeight(int w){ weight = w;}
    
    int getIndex(){return index;}
    void setIndex(int i){index = i;}
    
    int getGoalX(){ return goalX;}
    int getGoalY(){ return goalY;}
	
};


#endif

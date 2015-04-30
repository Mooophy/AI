#include "nodes.h"
#include <cmath>

using namespace std;



int Node::calcManhattanDistance(int xG, int yG){	
   return (abs(x-xG) + abs(y-yG));
}

void Node::updateHCost(heuristicFunction hFunction, int xG, int yG){
	hCost = h(hFunction, xG, yG);
}

void Node::updateFCost(){
	fCost = hCost + pathLength;
}

int Node::getFCost(){
	return fCost;
}

int Node::h(heuristicFunction hFunction, int xG, int yG){
	
	int hValue;
	
	switch(hFunction){
		case misplacedTiles:
		         
		        break;
		         
		case manhattanDistance:
		        		        
		        hValue = (abs(x-xG) + abs(y-yG));
		        break;         
		        
		case euclidean:
		        hValue = int(pow((x-xG),2) + pow((y-yG),2));
		        break;        
		           
	}
	
	return hValue;	
}


//constructor
Node::Node(const Node &p) : path(p.path){
	
	x = p.x;
	y = p.y;
	weight = p.weight;
	
	//path = p.path;
	pathLength = p.pathLength;
	hCost = p.hCost;
	fCost = p.fCost;
	gCost = p.gCost;
	gradation = p.gradation;
	goalX = p.goalX;
	goalY = p.goalY;
		
}


//constructor
Node::Node(int _x, int _y, int _weight, int _goalX, int _goalY){
	int n;
	
	//dMap = dMap;

	path = "";
	pathLength=0;
	hCost = 0;
	fCost = 0;
	x = _x;
	y = _y;
   weight = _weight;
   goalX = _goalX;
   goalY = _goalY;   
}

void Node::clear(){
	x = 0;
	y = 0;
	weight = 0;
	
	pathLength = 0;
	hCost = 0;
	fCost = 0;
	gCost = 0;
	gradation = 0;
	goalX = 0;
	goalY = 0;
}

//checks if the current state matches the goal state
bool Node::goalMatch(int xG, int yG){
	return (x == xG && y == yG);
}


const string Node::getPath(){
	return path;
}

int Node::getPathLength(){
	return pathLength;
}

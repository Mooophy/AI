#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;


enum heuristicFunction{misplacedTiles, manhattanDistance};



class Puzzle{
		
private:

    string path;
    int pathLength;
    int hCost;
    int fCost;
    int depth;
      
        
    int goalBoard[3][3];
    
    int x0, y0; //coordinates of the blank or 0-tile
    
    int board[3][3];
    unordered_set<string> statesList;


public:
    
    string strBoard;

    Puzzle(const Puzzle &p); //Constructor
    Puzzle(string const elements, string const goal);
    void initStartState();
	 
    void printBoard();
    int calcManhattanDistance(int n);
    int h(heuristicFunction hFunction);
    
  

    void updateFCost(); 
    void updateHCost(heuristicFunction hFunction);
    void updateDepth(){
		 depth++;
	 }		 

    bool goalMatch();
    string toString();
    string getString(){
		 return strBoard;
	 }
    
    bool canMoveLeft();
    bool canMoveRight();
    bool canMoveUp();
    bool canMoveDown();  
//----------------------------------------
	 bool canMoveLeft(int maxDepth);
	 bool canMoveDown(int maxDepth);
	 bool canMoveRight(int maxDepth);
	 bool canMoveUp(int maxDepth);	 
//----------------------------------------
	  
    Puzzle * moveLeft();
    Puzzle * moveRight();
    Puzzle * moveUp();
    Puzzle * moveDown();
	 
	 Puzzle* moveUp_avoidLocalLoop(bool &validMove);
	 Puzzle* moveDown_avoidLocalLoop(bool &validMove);
	 Puzzle* moveLeft_avoidLocalLoop(bool &validMove);
	 Puzzle* moveRight_avoidLocalLoop(bool &validMove);

    const string getPath();
    
    void setDepth(int d);
    int getDepth();
    
    int getPathLength();
    int getFCost();
	 int getHCost();
	 int getKey(); //same as getFCost()
	
	
	
};

#include "puzzle.h"
#include  <cmath>
#include  <assert.h>

using namespace std;


void Puzzle::setDepth(int d){
	depth = d;
}

int Puzzle::getDepth(){
	return depth;
}


int Puzzle::calcManhattanDistance(int n){
	int m=0;
	//
	// implement calculations here
	//
   return m;
}

void Puzzle::updateHCost(heuristicFunction hFunction){
	hCost = h(hFunction);
}

void Puzzle::updateFCost(){
	fCost = hCost + pathLength;
}

int Puzzle::getFCost(){
	return fCost;
}

int Puzzle::getHCost(){
	return hCost;
}


int Puzzle::getKey(){
	return getFCost();
}

int Puzzle::h(heuristicFunction hFunction){
	
	int sum=0;
	int h=0;
	int numOfMisplacedTiles=0;
	
	switch(hFunction){
		case misplacedTiles:
			      //
		         //
					//
               h = numOfMisplacedTiles; 					
		        break;
		         
		case manhattanDistance:		        		        
		        sum=0;
		        //
		        //
				  //
		        h=sum;
		        break;         
		           
	};
	
	return h;
	
}


//constructor
Puzzle::Puzzle(const Puzzle &p) : path(p.path){
	
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		    board[i][j] = p.board[i][j];
		    goalBoard[i][j] = p.goalBoard[i][j];
		}
	}	
	
	x0 = p.x0;
	y0 = p.y0;
	//path = p.path;
	pathLength = p.pathLength;
	hCost = p.hCost;
	fCost = p.fCost;	
	strBoard = toString();
	depth = p.depth;
	
}

//constructor
Puzzle::Puzzle(string const elements, string const goal){
	
	int n;
	
	n = 0;
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		    board[i][j] = elements[n] - '0';
		    if(board[i][j] == 0){
			    x0 = j;
			    y0 = i;
			 }
		    n++;
		} 
	}
		
	///////////////////////
	n = 0;
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		    goalBoard[i][j] = goal[n] - '0';
		    n++;
		} 
	}		
	///////////////////////	
	path = "";
	pathLength=0;
	hCost = 0;
	fCost = 0;
	depth = 0;
	strBoard = toString();

}


//converts board state into its string representation
string Puzzle::toString(){
  int n;
  string stringPath;
  
  n=0;
  for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		    //stringPath[n] = board[i][j] + '0'; //error
		    stringPath.insert(stringPath.end(), board[i][j] + '0');
		    n++;
		} 
  }
  
//  cout << "toString = " << stringPath << endl;
  
  return stringPath;
}

//checks if the current state matches the goal state
bool Puzzle::goalMatch(){
	
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		  //useful for debugging purposes only
		  //cout << endl << board[i][j]  << " compared to " << goalBoard[i][j];
		  if( board[i][j] != goalBoard[i][j]){
		     //cout << endl;
		     return false;
		  }
		}
	}
	cout << endl;
	return true;
}


bool Puzzle::canMoveLeft(){
	
/*
	if(x0 > 0){
		return true;
	} else {
		return false;
	}
*/
   
   return (x0 > 0);
	
}

const string Puzzle::getPath(){
	return path;
}

bool Puzzle::canMoveRight(){

   return (x0 < 2);
	
}


bool Puzzle::canMoveUp(){

   return (y0 > 0);
	
}

bool Puzzle::canMoveDown(){

   return (y0 < 2);
	
}

///////////////////////////////////////////////


bool Puzzle::canMoveLeft(int maxDepth){

   if(depth < maxDepth){   
       return (x0 > 0);
	} else {
		return false;
	}		
}
bool Puzzle::canMoveRight(int maxDepth){
   if(depth < maxDepth){
      return (x0 < 2);
	} else {
		return false;
	}
}


bool Puzzle::canMoveUp(int maxDepth){
   if(depth < maxDepth){
     return (y0 > 0);
	} else {
		return false;
	}
	
}

bool Puzzle::canMoveDown(int maxDepth){
   if(depth < maxDepth){  
     return (y0 < 2);
	} else {
		return false;
	}
}

///////////////////////////////////////////////

Puzzle *Puzzle::moveLeft(){
	
	Puzzle *p = new Puzzle(*this);
	
	
   if(x0 > 0){
		
		p->board[y0][x0] = p->board[y0][x0-1];
		p->board[y0][x0-1] = 0;
		
		p->x0--;
		
		p->path = path + "L";
		p->pathLength = pathLength + 1;  
		p->depth = depth + 1; 
		
		
	}
	p->strBoard = p->toString();
	return p;
	
}


Puzzle *Puzzle::moveRight(){
	
	Puzzle *p = new Puzzle(*this);
	
	
   if(x0 < 2){
		
		p->board[y0][x0] = p->board[y0][x0+1];
		p->board[y0][x0+1] = 0;
		
		p->x0++;
		
		p->path = path + "R";
		p->pathLength = pathLength + 1; 
     	
		p->depth = depth + 1;
		
	}
	
	p->strBoard = p->toString();
	
	return p;
	
}


Puzzle *Puzzle::moveUp(){
	
	Puzzle *p = new Puzzle(*this);
	
	
   if(y0 > 0){
		
		p->board[y0][x0] = p->board[y0-1][x0];
		p->board[y0-1][x0] = 0;
		
		p->y0--;
		
		p->path = path + "U";
		p->pathLength = pathLength + 1;  
	
		p->depth = depth + 1;
		
	}
	p->strBoard = p->toString();
	return p;
	
}

Puzzle *Puzzle::moveDown(){
	
	Puzzle *p = new Puzzle(*this);
	
	
   if(y0 < 2){
		
		p->board[y0][x0] = p->board[y0+1][x0];
		p->board[y0+1][x0] = 0;
		
		p->y0++;
		
		p->path = path + "D";
		p->pathLength = pathLength + 1;  
		
		p->depth = depth + 1;
		
	}
	p->strBoard = p->toString();	
	return p;
	
}

/////////////////////////////////////////////////////

//Applies only to the Start state
void Puzzle::initStartState(){
	statesList.insert(this->strBoard);
}

Puzzle *Puzzle::moveUp_avoidLocalLoop(bool &validMove){
	
	Puzzle *p = new Puzzle(*this);
	
	//
	//
	return p;
	
}
//---
Puzzle *Puzzle::moveRight_avoidLocalLoop(bool &validMove){
	
	Puzzle *p = new Puzzle(*this);
	
	//
	//
	return p;
	
}

//---
Puzzle *Puzzle::moveLeft_avoidLocalLoop(bool &validMove){
	
	Puzzle *p = new Puzzle(*this);
	
	//
	//
	return p;
	
}

Puzzle *Puzzle::moveDown_avoidLocalLoop(bool &validMove){
	
	Puzzle *p = new Puzzle(*this);
	
	//
	//
	return p;	
}


void Puzzle::printBoard(){
	cout << "board: "<< endl;
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){	
		  cout << endl << "board[" << i << "][" << j << "] = " << board[i][j];
		}
	}
	cout << endl;
	
}

int Puzzle::getPathLength(){
	return pathLength;
}

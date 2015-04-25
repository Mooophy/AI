//////////////////////////////////////////////////////////////////////////
//  8-PUZZLE PROBLEM
//  SAMPLE SOLUTION - with BATCH TESTING
//
//////////////////////////////////////////////////////////////////////////
/*
 * Flicker-free implementation of the 8-puzzle board game using the BGI
 * graphics library for Windows.
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "graphics.h"
//#include "puzzle.h" //may be utilised but not required for the assignment
#include "algorithm.h"

using namespace std;

#define OUTPUT_LENGTH 2 /* Length of output string. */

const int HEIGHT = 400; /**< Height of board for rendering in pixels. */
const int WIDTH  = 400; /**< Width of board for rendering in pixels. */

/**
 * Update the board and draw it to the screen. This function displays the
 * board updates in a flicker-free way.
 *
 * @param board 3 x 3 array containing the current board state,
 *              0 indicates an empty space.
 */


//////////////////////////////////////////////////////
// Function prototypes

 
void displayBoard(string const elements); 
void AnimateSolution(string const initialState, string const goalState, string path);

////////////////////////////////////////////////////// 
 
void update(int **board) {
    /* Setting up the graphics. */
    static bool setup = false;

    if(!setup) {
        int graphDriver = 0;
        int graphMode = 0;
        initgraph(&graphDriver, &graphMode, "", WIDTH, HEIGHT);
        setup = true;
    }

    /* Variables for the function. */
    int xIncrement = (WIDTH - 40) / 3;        /* Grid's raster width. */
    int yIncrement = ((HEIGHT - 6) - 40) / 3; /* Grid's raster height. */
    int x = 0;            /* Temporary x positions. */
    int y = 0;            /* Temporary y positions. */
    char outputString[OUTPUT_LENGTH]; /* Holder for output strings in the GUI. */
    static bool visual;   /* Indicator which visual page to draw to
                           * to prevent flickers. */

    /* Initalising the variables. */
    strncpy(outputString, "", OUTPUT_LENGTH);
    /* Even though this is not necessary here the protected version of "strcpy"
       is used in this case. It should ALWAYS be used to prevent boundary
       overwrites! */

    /* Initialising the GUI. */
    setactivepage(visual);
    setbkcolor(BLACK);
    cleardevice();
    setfillstyle(SOLID_FILL, WHITE);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 6);
    settextjustify(CENTER_TEXT, CENTER_TEXT);

    /* Display different coloured squares for different numbers. */
    y = 10;
    for(int i = 0; i < 3; i++) {
        x = 10;
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 0) {
                setcolor(board[i][j]);
                bar(x, y, x + xIncrement, y + yIncrement);
            }
            x += 10;
            x += xIncrement;
        }
        y += 10;
        y += yIncrement;
    }

    /* Display the actual numbers. */
    y = 8 * HEIGHT / 40;
    for(int i = 0; i < 3; i++) {
        x = WIDTH / 6;
        for(int j = 0; j < 3; j++) {
            setcolor(WHITE);
            setbkcolor(board[i][j]);
            if(board[i][j] != 0) {
                snprintf(outputString, OUTPUT_LENGTH, "%d", board[i][j]);
                /* Even though this is also not necessary here the protected
                   version of "sprintf" is used in this case. It should ALWAYS
                   be used to prevent boundary overwrites! */
                outtextxy(x, y, outputString);
                moveto(0, 0);
            }
            x += 2 * (WIDTH / 6);
        }
        y += 13 * HEIGHT / 40;
    }

    /* Set the page to display. */
    setvisualpage(visual);
    visual = !visual;

    delay(1000);
}


void displayBoard(string const elements) {
    /* Setting up the graphics. */
    
    int board[3][3];
    
    /* - works!
    
    int **board;
    
    board = new int*[3];
    
    board[0] = new int[3];
    board[1] = new int[3];
    board[2] = new int[3];
    */
    
    
    int n=0;
    
    for(int i=0; i < 3;i++){
	    for(int j=0; j < 3;j++){
		    
		    board[i][j] = elements.at(n) - '0';
  		    //board[i][j] = atoi(elements.at(n)); //error!
		    
		    //cout << "Elements = "  << elements.at(n) << endl; //works too!
		    //cout << "Elements = " << "board[" << i << "][" << j << "] = " << board[i][j] << endl; //works!
		    
		    n++;
		    
		 }   
	 }
    
    
    static bool setup = false;

    if(!setup) {
        int graphDriver = 0;
        int graphMode = 0;
        initgraph(&graphDriver, &graphMode, "", WIDTH, HEIGHT);
        setup = true;
        
        settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
        settextjustify(CENTER_TEXT, CENTER_TEXT);
        outtextxy(getmaxx()/2,getmaxy()/2,"press any key to start.");
        cout << endl << endl << "press any key to start." << endl << endl;
        getch();
        
    }

    /* Variables for the function. */
    int xIncrement = (WIDTH - 40) / 3;        /* Grid's raster width. */
    int yIncrement = ((HEIGHT - 6) - 40) / 3; /* Grid's raster height. */
    int x = 0;            /* Temporary x positions. */
    int y = 0;            /* Temporary y positions. */
    char outputString[OUTPUT_LENGTH]; /* Holder for output strings in the GUI. */
    static bool visual;   /* Indicator which visual page to draw to
                           * to prevent flickers. */

    /* Initalising the variables. */
    strncpy(outputString, "", OUTPUT_LENGTH);
    /* Even though this is not necessary here the protected version of "strcpy"
       is used in this case. It should ALWAYS be used to prevent boundary
       overwrites! */

    /* Initialising the GUI. */
    setactivepage(visual);
    setbkcolor(BLACK);
    cleardevice();
    setfillstyle(SOLID_FILL, WHITE);
    settextstyle(GOTHIC_FONT, HORIZ_DIR, 6);
    settextjustify(CENTER_TEXT, CENTER_TEXT);

    /* Display different coloured squares for different numbers. */
    y = 10;
    for(int i = 0; i < 3; i++) {
        x = 10;
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 0) {
                setcolor(board[i][j]);
                bar(x, y, x + xIncrement, y + yIncrement);
            }
            x += 10;
            x += xIncrement;
        }
        y += 10;
        y += yIncrement;
    }

    /* Display the actual numbers. */
    y = 8 * HEIGHT / 40;
    for(int i = 0; i < 3; i++) {
        x = WIDTH / 6;
        for(int j = 0; j < 3; j++) {
            setcolor(WHITE);
            setbkcolor(board[i][j]);
            if(board[i][j] != 0) {
                snprintf(outputString, OUTPUT_LENGTH, "%d", board[i][j]);
                /* Even though this is also not necessary here the protected
                   version of "sprintf" is used in this case. It should ALWAYS
                   be used to prevent boundary overwrites! */
//                outtextxy(x, y, (char *)elements[i+j*3]);   
                outtextxy(x, y, outputString);
                moveto(0, 0);
            }
            x += 2 * (WIDTH / 6);
        }
        y += 13 * HEIGHT / 40;
    }

    /* Set the page to display. */
    setvisualpage(visual);
    visual = !visual;

    delay(1000);
}



void AnimateSolution(string const initialState, string const goalState, string path){

	int step=1;
	
	cout << endl << "--------------------------------------------------------------------" << endl;

	if (path==""){
		 cout << endl << "Nothing to animate." << endl;
	} else {
	    cout << endl << "Animating solution..." << endl;
	    cout << "Plan of action = " << path << endl;
	}
	
	Puzzle *p = new Puzzle(initialState, goalState);
	string strState;
		
	strState = p->toString();
   displayBoard(strState);
	
	cout << "--------------------------------------------------------------------" << endl;
	      
	for(int i=0; i < path.length(); i++){
		
		cout << endl << "Step #" << step << ")  ";
		switch(path[i]){
			
			case 'U': p = p->moveUp(); cout << "[UP]" << endl;
			          break;
			case 'D': p = p->moveDown(); cout << "[DOWN]" << endl;
			          break;
			case 'L': p = p->moveLeft(); cout << "[LEFT]" << endl;
			          break;
         case 'R': p = p->moveRight(); cout << "[RIGHT]" << endl;
			          break;
 		}
 		strState = p->toString();
      displayBoard(strState);
      
      step++;
	}
	
	delete p;	
	cout << endl << "Animation done." << endl;
	cout << "--------------------------------------------------------------------" << endl;
	
	//getch();
}



/**
 * Main function to kick off the game.
 */



int main( int argc, char* argv[] ){
   
   string path;
	
	if(argc < 5){
		cout << "SYNTAX: main.exe <TYPE_OF_RUN = batch_run/single_run> ALGORITHM_NAME \"INITIAL STATE\" \"GOAL STATE\" " << endl;
		exit(0);
	}
	
	string typeOfRun(argv[1]);
	string algorithmSelected(argv[2]);
	string initialState(argv[3]);
	string goalState(argv[4]);
	
 
	int pathLength=0;
	int depth=0;
   int numOfStateExpansions=0;	
	int maxQLength=0;
	float actualRunningTime=0.0;	
	//=========================================================================================================
	
	if(typeOfRun == "single_run") cout << endl << "============================================<< EXPERIMENT RESULTS >>============================================" << endl;
	
	//=========================================================================================================
	//Run algorithm
	if(algorithmSelected == "PDS_Visited_List" ){			
		path = PDS_Visited_List(initialState,  goalState, numOfStateExpansions, maxQLength, actualRunningTime, 5000);		

	} else if(algorithmSelected == "bestFirstSearch_Visited_List" ){
		path = bestFirstSearch_Visited_List(initialState, goalState, numOfStateExpansions, maxQLength, actualRunningTime); 
				
	}  else if(algorithmSelected == "uniformCost_Exp_List" ){
		path = uniformCost_Exp_List(initialState, goalState, numOfStateExpansions, maxQLength, actualRunningTime);
		
	}  else if(algorithmSelected == "aStar_Misplaced" ){		
		path = aStar(initialState, goalState, numOfStateExpansions, maxQLength, actualRunningTime, misplacedTiles);
		
	}  else if(algorithmSelected == "aStar_Manhattan" ){
		path = aStar(initialState, goalState, numOfStateExpansions, maxQLength, actualRunningTime, manhattanDistance);
	
	}  else if(algorithmSelected == "aStar_Exp_List_Misplaced" ){
		path = aStar_Exp_List(initialState, goalState, numOfStateExpansions, maxQLength, actualRunningTime, misplacedTiles);
	
	}  else if(algorithmSelected == "aStar_Exp_List_Manhattan" ){
		path = aStar_Exp_List(initialState, goalState, numOfStateExpansions, maxQLength, actualRunningTime, manhattanDistance);		
	}
		
	pathLength = path.size();
		
//Display name of algorithm	
	if(algorithmSelected == "PDS_Visited_List" ){
		cout << setw(28) << std::left << "1) PDS_Visited_List";	
    	
	} else if(algorithmSelected == "bestFirstSearch_Visited_List" ){
		cout << setw(28) << std::left << "2) Best_First_Visited_List";				
	} else if(algorithmSelected == "BFS_Visited_List" ){
		cout << setw(28) << std::left << "2) BFS_Visited_List";			
	
	}  else if(algorithmSelected == "uniformCost_Exp_List" ){
		cout << setw(28) << std::left << "3) UC_Exp_List";			
	
	}  else if(algorithmSelected == "aStar_Misplaced" ){
		cout << setw(28) << std::left << "4) ASTAR_Misplaced";			
	
	}  else if(algorithmSelected == "aStar_Manhattan" ){
		cout << setw(28) << std::left << "5) ASTAR_Manhattan";			
	
	}  else if(algorithmSelected == "aStar_Exp_List_Misplaced" ){
		cout << setw(28) << std::left << "6) ASTAR_Exp_Misplaced";
		
	}  else if(algorithmSelected == "aStar_Exp_List_Manhattan" ){
		cout << setw(28) << std::left << "7) ASTAR_Exp_Manhattan";		
   	
	}
	
	
	if(typeOfRun == "batch_run"){	
		
		cout  << setprecision(6) << std::setfill(' ')   << std::fixed << std::right << ' ' << setw(10) << pathLength; 
		cout  << setprecision(6) << std::setfill(' ')   << std::fixed << std::right << ' ' <<  setw(10) << numOfStateExpansions; 
		cout  << setprecision(6) << std::setfill(' ')   << std::fixed << std::right << ' ' <<  setw(15) << maxQLength; 
		cout  << setprecision(6) << std::setfill(' ')   << std::fixed << std::right << ' ' <<  setw(15) << actualRunningTime << endl; 
		
	} else if(typeOfRun == "single_run"){	
		cout << setprecision(6) << setw(25) << std::setfill(' ') <<  std::right << endl << endl << "Initial State:" << std::fixed << ' ' << setw(12) << initialState << endl;
		cout << setprecision(6) << setw(25) << std::setfill(' ') <<  std::right << "Goal State:" << std::fixed << ' ' << setw(12) << goalState << endl;
		cout << setprecision(6) << setw(25) << std::setfill(' ') <<  std::right << endl <<  "Path Length:" << std::fixed << ' ' << setw(12) << pathLength << endl;
		cout << setprecision(6) << setw(25) << std::setfill(' ') <<  std::right << "Num Of State Expansions:" << std::fixed << ' ' << setw(12) <<  numOfStateExpansions << endl;
		cout << setprecision(6) << setw(25) << std::setfill(' ') <<  std::right << "Max Q Length:" << std::fixed << ' ' << setw(12) << maxQLength << endl;
		cout << setprecision(6) << setw(25) << std::setfill(' ') <<  std::right << "Actual Running Time:" << std::fixed << ' ' << setprecision(6) << setw(12) <<  actualRunningTime << endl;
		cout << "================================================================================================================" << endl << endl;	
		
		if(path != "") {
			 AnimateSolution(initialState, goalState, path);
		}
	}

    /* Show that we have exited without an error. */
    return 0;
}


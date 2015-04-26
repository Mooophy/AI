/*
 * Flicker-free implementation of the 8-puzzle board game using the BGI
 * graphics library for Windows.
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


#include "graphics.h"


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
//
void AnimateSolution(string const initialState, string path);

void update(int **board);

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
    
     
    
    int n=0;
    
    for(int i=0; i < 3;i++){
	    for(int j=0; j < 3;j++){
		    
		    board[i][j] = elements.at(n) - '0';
  		       
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



void AnimateSolution(string const initialState, string path){

	int step=1;
	
//	cout << endl << "********************************************************************" << endl;
	cout << endl << "--------------------------------------------------------------------" << endl;


	if (path==""){
		 cout << endl << "Nothing to animate." << endl;
	} else {
	    cout << endl << "Animating solution..." << endl;
	    cout << "Solution path = " << path << endl;
	}
	

	
	Puzzle *p = new Puzzle(initialState, "123804765");
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
	cout << endl << "Done." << endl;
	cout << "--------------------------------------------------------------------" << endl;
	
	getch();

	
}




///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    ARTIFICIAL INTELLIGENCE 159302
//    INVERTED PENDULUM SIMULATION
// 
//	  Description: Inverted pendulum simulation with fuzzy logic engine and animation functions
//
//    Run Parameters: 
//
//    Keys for Operation: 
//
//	  History:  dates of revision
//              March 3, 2015
//
//    Start-up code by:  Dr. Napoleon Reyes, n.h.reyes@massey.ac.nz
//    					 Computer Science, INMS
//						 Massey University-Albany
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <deque>
#include <set>
#include <vector>
#include <fstream>

#include "sprites.h" 
#include "graphics.h"
#include "nodes.h"
#include "transform.h"
#include "algorithm.h"
#include "fuzzylogic.h"

using namespace std;


/// Global Variables ///////////////////////////////////////////////////////////////////////

float WORLD_MAXX, WORLD_MAXY;
int fieldX1, fieldY1, fieldX2, fieldY2; //playing field boundaries
BoundaryType worldBoundary,deviceBoundary;
char keyPressed[5];
fuzzy_system_rec g_fuzzy_system;



struct WorldStateType{
	
	void init(){
		x=0.0;
		x_dot=0.0;
		x_double_dot = 0.0;
		angle = 0.0;
		angle_dot = 0.0;
		angle_double_dot = 0.0;
		F = 0.0;
	}
	
	float x;
	float x_dot;
	float x_double_dot;
	float angle;
	float angle_dot;
	float angle_double_dot;
	
	float const mb=0.1;
	float const g=9.8;
	float const m=1.1; // mass of cart & broom
	float const l=0.5;
	
	float F;
};


struct DataSetType{
   vector<float> x;
   vector<float> y;
   vector<vector<float> > z; 
};

DataSetType dataSet;

int NUM_OF_DATA_POINTS;

// Function Prototypes ////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////
float getKey() {
   
	  float F=0.0;
	
     if(GetAsyncKeyState(VK_LEFT) < 0) {     
        //"LEFT ARROW";
		  F=-7.0;
	  }
	  
	  if(GetAsyncKeyState(VK_RIGHT) < 0) { 
        F=7.0;  
    
        //"RIGHT ARROW"
	  }
	  
	  return F;
}

////////////////////////////////////////////////////////////////////////////////



void initPendulumWorld(){
	
	//widescreen
   fieldX1 = getmaxx() / 10;
   fieldX2 = getmaxx() - (getmaxx() / 10);
   fieldY1 = getmaxy() / 9;
   fieldY2 = getmaxy() - (getmaxy() / 9);
    
  
    worldBoundary.x1 = -2.4;
    //worldBoundary.y1 = 1.2;
	worldBoundary.y1 = 3;
    worldBoundary.x2 = 2.4;
    worldBoundary.y2 = -0.4;

    deviceBoundary.x1 = fieldX1;
    deviceBoundary.y1 = fieldY1;
    deviceBoundary.x2 = fieldX2;
    deviceBoundary.y2 = fieldY2;
       
    WORLD_MAXX=worldBoundary.x2-worldBoundary.x1;
    WORLD_MAXY=worldBoundary.y2-worldBoundary.y1;
	
}

void drawInvertedPendulumWorld(){
	
	setcolor(WHITE);
	rectangle(xDev(worldBoundary,deviceBoundary,worldBoundary.x1),yDev(worldBoundary,deviceBoundary,worldBoundary.y1),
	          xDev(worldBoundary,deviceBoundary,worldBoundary.x2),yDev(worldBoundary,deviceBoundary,worldBoundary.y2));
   //~ setcolor(YELLOW);
	//~ rectangle(xDev(worldBoundary,deviceBoundary,worldBoundary.x1),yDev(worldBoundary,deviceBoundary,worldBoundary.y2+0.07),
	          //~ xDev(worldBoundary,deviceBoundary,worldBoundary.x2),yDev(worldBoundary,deviceBoundary,worldBoundary.y2));
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	
	setcolor(WHITE);
	outtextxy((deviceBoundary.x1 + deviceBoundary.x2)/2, deviceBoundary.y1 - 3 * textheight("H"),"ARTIFICIAL INTELLIGENCE 159302");
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	outtextxy((deviceBoundary.x1 + deviceBoundary.x2)/2, deviceBoundary.y1 - 2 * textheight("H"),"INVERTED PENDULUM");
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	outtextxy((deviceBoundary.x1 + deviceBoundary.x2)/2, deviceBoundary.y1 - textheight("H"),"FUZZY LOGIC CONTROLLER");
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy((deviceBoundary.x2 - textwidth("START-UP CODE by:  n.h.reyes@massey.ac.nz")), deviceBoundary.y2 + textheight("H"),"START-UP CODE by:  n.h.reyes@massey.ac.nz  (C) Massey University 2015");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// BEGIN - DYNAMICS OF THE SYSTEM
float calc_angular_acceleration( const WorldStateType& s){		
	float a_double_dot=0.0;
	
	a_double_dot = (s.m * s.g * sin(s.angle) - (cos(s.angle) * (s.F + ((s.mb) * s.l * s.angle_dot * s.angle_dot * sin(s.angle) ) ) )  )
               	/ (  ((4/3)*s.m * s.l) - (s.mb * s.l * cos(s.angle) * cos(s.angle)));
	return a_double_dot;
}

float calc_horizontal_acceleration( const WorldStateType& s){	
	float x_double_dot=0.0;
	
	x_double_dot = ( s.F + s.mb * s.l * (s.angle_dot * s.angle_dot)* sin(s.angle) - s.angle_double_dot * cos(s.angle)   )/ s.m;	
	return x_double_dot; 
}
// END - DYNAMICS OF THE SYSTEM
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void displayInfo(const WorldStateType& s){
	setcolor(WHITE);
	outtextxy((deviceBoundary.x1 + deviceBoundary.x2)/2, deviceBoundary.y1 - 2 * textheight("H"),"INVERTED PENDULUM");
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	outtextxy((deviceBoundary.x1 + deviceBoundary.x2)/2, deviceBoundary.y1 - textheight("H"),"FUZZY LOGIC CONTROLLER");
	settextstyle(SMALL_FONT, HORIZ_DIR, 6);
	
	char angleStr[120];
	char xStr[120];
	
	float a=((s.angle*180/3.14));
	
	if(a > 360){
		a = a / 360.0;
	}
	
	sprintf(xStr,"x = %4.2f",s.x);
	outtextxy((deviceBoundary.x2 - textwidth("n.h.reyes@massey.ac.nz")), deviceBoundary.y2 - (7*textheight("H")),xStr);
	
	sprintf(angleStr,"angle = %4.2f",a);
	outtextxy((deviceBoundary.x2 - textwidth("n.h.reyes@massey.ac.nz")), deviceBoundary.y2 - (6*textheight("H")),angleStr);
	
	sprintf(angleStr,"F = %4.2f",s.F);
	outtextxy((deviceBoundary.x2 - textwidth("n.h.reyes@massey.ac.nz")), deviceBoundary.y2 - (5*textheight("H")),angleStr);

}


void runInvertedPendulum(){
	
	float inputs[4];
	
	WorldStateType prevState, newState;
	srand(time(NULL));  // Seed the random number generator
			
    initPendulumWorld();
	
	static BOOL page;
	
	float const h=0.002;
	float externalForce=0.0;
	
	prevState.init();
	newState.init();
	
	//-------------------------------------------------
	//Start at the origin
	//Cart cart(0.0, worldBoundary.y2 + 0.06);
	//Rod rod(0.0, worldBoundary.y2 + 0.06);
	//-------------------------------------------------
	
	//Start somewhere on the left
	//Cart cart(-1.0, worldBoundary.y2 + 0.06);
	Cart cart(-1.0, worldBoundary.y2 + 0.125);
	//Rod rod(-1.0, worldBoundary.y2 + 0.06);
	Rod rod(-1.0, worldBoundary.y2 + 0.125 + 0.35);
	
	//---------------------------------------------------------------
    //***************************************************************
    //Set the initial angle of the pole with respect to the vertical
	prevState.angle = 8 * (3.14/180);  //initial angle  = 8 degrees
	
	
    initFuzzySystem(&g_fuzzy_system);	
	
	//~ display_All_MF (g_fuzzy_system);
    //~ getch();
		
	while((GetAsyncKeyState(VK_ESCAPE)) == 0 ) {
		
         setactivepage(page);
         cleardevice();
		 drawInvertedPendulumWorld();
	
	     //retrieve inputs
		 inputs[in_theta] = prevState.angle;
		 inputs[in_theta_dot] = prevState.angle_dot;
		 inputs[in_x] = prevState.x;
		 inputs[in_x_dot] = prevState.x_dot;
		
         //1) Enable this only after your fuzzy system has been completed already.
         //Remember, you need to define the rules, membership function parameters and rule outputs.
         //prevState.F = fuzzy_system(inputs, g_fuzzy_system); //call the fuzzy controller
		 
		 externalForce=0.0;
		 externalForce = getKey(); //manual operation
		 
		 if(externalForce != 0.0)
		 	prevState.F = externalForce;
         //~ cout << "F = " << prevState.F << endl; //for debugging purposes only
		
		 //---------------------------------------------------------------------------
		 // **************************************************************************
		 // BEGIN - DYNAMICS OF THE SYSTEM

		 //Calculate the new state of the world
		 newState.angle_double_dot = calc_angular_acceleration(prevState);
		 newState.angle_dot = prevState.angle_dot + (h * newState.angle_double_dot); 
		 newState.angle = prevState.angle + (h * newState.angle_dot);
		 newState.F = prevState.F;				 
		 newState.x_double_dot = calc_horizontal_acceleration(prevState); 
		 newState.x_dot = prevState.x_dot + (h * newState.x_double_dot);
         newState.x = prevState.x + (h * newState.x_dot);

		 prevState.x = newState.x;		
 		 prevState.angle = newState.angle;
		 prevState.x_dot = newState.x_dot;
		 prevState.angle_dot = newState.angle_dot;		
		 prevState.angle_double_dot = newState.angle_double_dot;
		 prevState.x_double_dot = newState.x_double_dot;
		 //--------------------------	 		 
		 cart.setX(newState.x);
		 rod.setX(newState.x);
		 rod.setAngle(newState.angle);		 
		 cart.draw();
		 rod.draw();
		 // END - DYNAMICS OF THE SYSTEM
		 // **************************************************************************
		 //---------------------------------------------------------------------------
		 displayInfo(newState);
		 
	    setvisualpage(page);
       page = !page;  //switch to another page
   }	
	
    //2) Enable this only after your fuzzy system has been completed already.
	//free_fuzzy_rules(&g_fuzzy_system);
}


void generateControlSurface_Angle_vs_Angle_Dot(){	
	float inputs[4];
	
	cout << "Generating control surface (Angle vs. Angle_Dot)..." << endl;
	WorldStateType prevState, newState;
	srand(time(NULL));  // Seed the random number generator
			
    initPendulumWorld();
	
	static BOOL page;
	
	float const h=0.002;
	
	prevState.init();
	newState.init();
	

	//-------------------------------------------------

	//~ Cart cart(-1.0, worldBoundary.y2 + 0.125);
	//~ Rod rod(-1.0, worldBoundary.y2 + 0.125 + 0.35);
	//-------------------------------------------------
	
		
    initFuzzySystem(&g_fuzzy_system);	
	
	
    float angle_increment;
    float angle_dot_increment;

    float minAngle=0;
    float maxAngle=0;
    float angle=0.0;

    float angle_dot=0.0;
    float minAngleDot=0;
    float maxAngleDot=0;

    NUM_OF_DATA_POINTS=100;

//---------------------------------
    dataSet.x.resize(NUM_OF_DATA_POINTS);
    dataSet.y.resize(NUM_OF_DATA_POINTS);
    dataSet.z.resize(NUM_OF_DATA_POINTS);

    for(int y=0; y < NUM_OF_DATA_POINTS; y++){
       dataSet.z[y].resize(NUM_OF_DATA_POINTS);	
    }
//---------------------------------    
    minAngleDot= -0.3;
    maxAngleDot=  0.3;
    angle_dot_increment=(maxAngleDot-minAngleDot)/float(NUM_OF_DATA_POINTS);
    angle_dot=minAngleDot;
//---------------------------------
    minAngle=(-12.0)*3.14/180.0;
    maxAngle=(12.0)*3.14/180.0;
    angle_increment=(maxAngle-minAngle)/float(NUM_OF_DATA_POINTS);   

//---------------------------------
    for(int row=0; row < NUM_OF_DATA_POINTS; row++){
    	 dataSet.y[row] = angle_dot;
         prevState.angle_dot = angle_dot;
         angle=minAngle;

         for(int col=0; col < NUM_OF_DATA_POINTS; col++){
             prevState.x=0.0;
		     prevState.x_dot=0.0;
		     prevState.x_double_dot = 0.0;
		     prevState.angle = angle;
		     prevState.angle_dot = angle_dot;
		     prevState.angle_double_dot = 0.0;
		     prevState.F = 0.0; 


             dataSet.x[col] = angle;
	         prevState.angle = angle;


			 inputs[in_theta] = prevState.angle;
			 inputs[in_theta_dot] = prevState.angle_dot;
			 inputs[in_x] = prevState.x;
			 inputs[in_x_dot] = prevState.x_dot;
			
	         prevState.F = 0.0;  //nothing is done.//fuzzy_system(inputs, g_fuzzy_system);
			
			
			 //---------------------------------------------------------------------------
			 //Calculate the new state of the world
			 //Updating angle
			 
			 newState.angle_double_dot = calc_angular_acceleration(prevState);
			 newState.angle_dot = prevState.angle_dot + (h * newState.angle_double_dot); 
			 newState.angle = prevState.angle + (h * newState.angle_dot);
			 newState.F = prevState.F;
			
			 //Updating x
					 
			 newState.x_double_dot = calc_horizontal_acceleration(prevState); 
			 newState.x_dot = prevState.x_dot + (h * newState.x_double_dot);
	         newState.x = prevState.x + (h * newState.x_dot);

	//Update previous state
			 prevState.x = newState.x;		
	 		 prevState.angle = newState.angle;
			 prevState.x_dot = newState.x_dot;
			 prevState.angle_dot = newState.angle_dot;		
			 prevState.angle_double_dot = newState.angle_double_dot;
			 prevState.x_double_dot = newState.x_double_dot;
			 
			 //--------------------------
			 inputs[in_theta] = prevState.angle;
			 inputs[in_theta_dot] = prevState.angle_dot;
			 inputs[in_x] = prevState.x;
			 inputs[in_x_dot] = prevState.x_dot;
			
	       prevState.F = fuzzy_system(inputs, g_fuzzy_system);
			 dataSet.z[row][col] = prevState.F; //record Force calculated
			 
	//Set next case to examine; increment data points		 
          angle = angle + angle_increment;    
      }
      angle_dot = angle_dot + angle_dot_increment;		 
   }	
   
   free_fuzzy_rules(&g_fuzzy_system);
   cout << "done collecting data." << endl;

}




void saveDataToFile(string fileName){
	cout << "Saving control surface to file: " << fileName << "..." << endl;
	ofstream myfile;
	myfile.open (fileName, std::ofstream::out | std::ofstream::app);
	
	//Column Header
	for(int col=0; col < NUM_OF_DATA_POINTS; col++){
		if(col == 0){
		    myfile << "0.00, " << dataSet.x[col] << ",";
		} else if (col < (NUM_OF_DATA_POINTS-2)) {
			myfile << dataSet.x[col] << ",";
		} else {
			myfile << dataSet.x[col] << ",";
		}
	}
	
	for(int row=0; row < NUM_OF_DATA_POINTS; row++){
	  for(int col=0; col < NUM_OF_DATA_POINTS; col++){
		  if(col == 0){			  
			  myfile << dataSet.y[row] << ", " << dataSet.z[row][col] << ","; //with Row header
		  }else if(col < (NUM_OF_DATA_POINTS-2)) {			  
           myfile << dataSet.z[row][col] << ",";
		  } else {
			  myfile << dataSet.z[row][col] << ",";
		  }
     }
	  myfile << endl;
   }
 
   myfile.close();
   cout << "Data set saved (File: " << fileName << ")" << endl;
	
}

void clearDataSet(){
	
	//Column Header
   for(int col=0; col < NUM_OF_DATA_POINTS; col++){
		dataSet.x[col] = 0.0;		    
   }
	
   for(int row=0; row < NUM_OF_DATA_POINTS; row++){
   	  dataSet.y[row] = 0.0;	
	  for(int col=0; col < NUM_OF_DATA_POINTS; col++){		  
		  dataSet.z[row][col] = 0.0;		  
     }	
   }   
   cout << "DataSet cleared." << endl;
	
}


////////////////////////////////////////////////////////////////////////////////////

int main(void) {
	
   int graphDriver = 0,graphMode = 0;
   
   initgraph(&graphDriver, &graphMode, "", 1280, 1024); // Start Window
   clearDataSet();
   try{
		runInvertedPendulum();
	
		//3) Enable this only after your fuzzy system has been completed already.
		//generateControlSurface_Angle_vs_Angle_Dot();
		
		//4) Enable this only after your fuzzy system has been completed already.
		//saveDataToFile("data_angle_vs_angle_dot.txt");
		
   }
   catch(...){
    	cout << "Exception caught!\n";
   }
	return 0;
} 


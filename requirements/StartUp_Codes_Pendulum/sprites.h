#ifndef __SPRITES_H__
#define __SPRITES_H__

#include <stddef.h>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <math.h>

#include "graphics.h"
#include "transform.h"

extern BoundaryType worldBoundary,deviceBoundary;
extern char keyPressed[5];

enum Position {LEFT_SIDE, RIGHT_SIDE};


  //~ L = 0.5 'Distance from pivot to broom center of mass (m)
  //~ M = 1.1 'Mass of cart plus broom (kg)
  //~ MB = 0.1 'Mass of broom (kg)
  //~ X_POS_MIN = -2.4
  //~ X_POS_MAX = 2.4
  //~ WORLD_X1 = -2.4
  //~ WORLD_Y1 = 1.2
  //~ WORLD_X2 = 2.4
  //~ WORLD_Y2 = -0.4
  //~ CART_HALF_WIDTH = 0.25
  //~ HALF_WHEELBASE = 0.265625
  //~ CART_HT = 0.35
  //~ AXLE_HT = 0.16
  //~ WHEEL_RADIUS = 0.125
  //~ PIVOT_HT = 0.1
  //~ ZERO_POS = 3.86
  //~ THRM_WIDTH = 0.3125
  //~ F_THRM_HT = 0.3125
  //~ BROOM_HALF_WIDTH = 0.078125
  //~ BROOM_LENGTH = 2
  //~ BROOM_HALF_ANGLE = 0.04

class Rod{
	
public:
	  //Cart(float sx = 0.0, float sy = 0.0, float l=0.5, float h=0.35, float wheelRadius_=0.125, float s=0.0){
	  Rod(float sx = 0.0, float sy = 0.0, float a=0.0){
		  x = sx;
		  y = sy;
		  angle = a;
		  length=2.0;
		  halfWidth=0.078125;
		  halfAngle=0.04; //not used
		  pivotHeight=0.1;
		  axleHeight=0.16;
        theta_b = 0.03904265; //0.04
		  
	  } 
    
	  void setAngle(float a){
		  angle = a;
	  }
	  void setX(const float& _x){
		 x = _x;
	  }
	  
	  void draw(){
		  
		  int poly[8];
		  float points[8];
		  	   
//Vertices of a polynomial
		  
		  float r=0.0; //r=x/cos(theta) 
		  
		  r = float(sqrt(pow(halfWidth,2) + pow(length,2)));
		  
		  //top left
		  points[0] = x + ((sin(angle - theta_b)*r));
		  points[1] = (cos(angle - theta_b)*r);
		  
		  //top right
		  points[2] = x + (sin(angle + theta_b)*r); //WORKS fine
		  //points[2] = sin(angle + theta_b);  //WORKS fine
		  points[3] = cos(angle + theta_b)*r; //* original
		 
////////////
		  
		  float theta_p = 90.0*3.14/180.0;
		  
		  //bottom right
		  points[4] = x + ((sin(angle + theta_p)*halfWidth));
		  points[5] = (cos(angle + theta_p)*halfWidth);
		  		  		  
		  //bottom left				  
		  points[6] = x + ((sin(angle - theta_p)*halfWidth));
		  points[7] = (cos(angle - theta_p)*halfWidth);
		  
		  //~ fillellipse(xDev(worldBoundary,deviceBoundary,points[6]),
		              //~ yDev(worldBoundary,deviceBoundary,points[7]),10,10);
		  
	/*	
	//this works, too!
	
	if(angle < 0.0){	 		  
		  //bottom right
		  //points[4] = x + (cos(angle) * theta_b);
		  points[4] = x + ( halfWidth *   cos(angle + (90.0*3.14/180.0) ));
		  //points[5] = -sin(angle) * theta_b; //* original
		  points[5] = ( halfWidth *   sin(angle + (90.0*3.14/180.0) ));
		  		  
		  //bottom left
		  //points[6] = x - (cos(angle) * theta_b);
		  points[6] = x + ( halfWidth *   cos(angle - (90.0*3.14/180.0) ));
		  //points[7] = (sin(angle) * theta_b);
		  points[7] = ( halfWidth *   sin(angle - (90.0*3.14/180.0) ));
	} else if(angle > 0.0) {
		
		 //bottom right
		 points[4] = x + ( halfWidth *   cos(angle-(90.0*3.14/180.0) ));
		 points[5] = ( halfWidth *   sin(angle - (90.0*3.14/180.0) ));
		  		  
		 //bottom left
		 points[6] = x + ( halfWidth *   cos(angle + (90.0*3.14/180.0) ));
		 points[7] = ( halfWidth *   sin(angle + (90.0*3.14/180.0) ));
	} else {
		
		 //bottom right
		 points[4] = x + ( halfWidth);
		 points[5] = halfWidth *   sin(angle);
		  		  
		 //bottom left
		 points[6] = x - ( halfWidth);
		 points[7] = halfWidth *   sin(angle);
	}
		  
		*/  
		  //~ //top left
		  //~ points[0] = x + sin(angle - theta_b);
		  //~ points[1] = cos(angle - theta_b);
		  
		  //~ //top right
		  //~ points[2] = x + sin(angle + theta_b); //WORKS fine
		  //~ //points[2] = sin(angle + theta_b);  //WORKS fine
		  //~ points[3] = cos(angle + theta_b); //* original
		 
		
		 		  
		  //~ //bottom right
		  //~ points[4] = x + (cos(angle) * theta_b);
		  //~ points[5] = -sin(angle) * theta_b; //* original
		  		  
		  //~ //bottom left
		  //~ points[6] = x - (cos(angle) * theta_b);
		  //~ points[7] = (sin(angle) * theta_b);
		  
//~ //Vertices of a polynomial		  
		  for(int i=0; i < 8; i = i + 2){
	        poly[i] = xDev(worldBoundary,deviceBoundary,points[i]);
	        poly[i+1] = yDev(worldBoundary,deviceBoundary,points[i+1]);
	     }     
        setcolor(WHITE);
		  setfillstyle(SOLID_FILL, LIGHTBLUE);     
		  fillpoly(4,poly);   
		  //----------
		  
		  setfillstyle(SOLID_FILL, DARKGRAY);    		
		  		  
		  int radius = (halfWidth/2) * ((deviceBoundary.x2-deviceBoundary.x1)/(worldBoundary.x2-worldBoundary.x1));
		  //draw wheels
		  fillellipse(xDev(worldBoundary,deviceBoundary,x),
		              yDev(worldBoundary,deviceBoundary,pivotHeight/3),radius,radius);
  		  
		  
	  }
private:
    float x, y;
    float angle;
    float length;
    float halfWidth;
    float halfAngle;
    float pivotHeight;
    float axleHeight;
    float theta_b;
    

};



class Cart{
	
public:
	  //Cart(float sx = 0.0, float sy = 0.0, float l=0.5, float h=0.35, float wheelRadius_=0.125, float s=0.0){
	  Cart(float sx = 0.0, float sy = 0.0, float l=0.5, float h=0.35, float wheelRadius_=0.125, float s=0.0){
		  x = sx;
		  y = sy;
		  length = l;
		  height = h;
		  speed = s;
		  wheelRadius = wheelRadius_;
		  halfWheelBase=0.265625;
		  cartHalfWidth= 0.25;
		  
	  }   
	  void draw(){
		  
		  int poly[8];
		  float points[8];
		  
//Vertices of a polynomial
		  //top left
		  points[0] = x - cartHalfWidth;
		  points[1] = y + height;
		  
		  //top right
		  points[2] = x + cartHalfWidth;
		  points[3] = y + height;
		  
		  //bottom right
		  points[4] = x + cartHalfWidth;
		  points[5] = y;
		  
		  //bottom left
		  points[6] = x - cartHalfWidth;
		  points[7] = y;
		  
//Vertices of a polynomial		  
		  for(int i=0; i < 8; i = i + 2){
	        poly[i] = xDev(worldBoundary,deviceBoundary,points[i]);
	        poly[i+1] = yDev(worldBoundary,deviceBoundary,points[i+1]);
	     }     
        setcolor(WHITE);
		  setfillstyle(SOLID_FILL, RED);     
		  fillpoly(4,poly);   
		  
		  //draw left wheel
		  setcolor(WHITE);
		  
		  setfillstyle(SOLID_FILL, DARKGRAY);    		
		  		  
		  int radius = int(wheelRadius * ((deviceBoundary.x2-deviceBoundary.x1)/(worldBoundary.x2-worldBoundary.x1)));
		  //cout << "radius = " << radius << endl;
		  //draw wheels
		  fillellipse(xDev(worldBoundary,deviceBoundary,x + (cartHalfWidth/2)),
		              yDev(worldBoundary,deviceBoundary,y),radius,radius);
		  fillellipse(xDev(worldBoundary,deviceBoundary,x - (cartHalfWidth/2)),
		              yDev(worldBoundary,deviceBoundary,y),radius,radius);	
		  setcolor(BLACK);
		  circle(xDev(worldBoundary,deviceBoundary,x + (cartHalfWidth/2)),
		              yDev(worldBoundary,deviceBoundary,y),radius);
		  circle(xDev(worldBoundary,deviceBoundary,x - (cartHalfWidth/2)),
		              yDev(worldBoundary,deviceBoundary,y),radius);	
		  
		  //draw spindle
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        fillellipse(xDev(worldBoundary,deviceBoundary,x + (cartHalfWidth/2)),
		              yDev(worldBoundary,deviceBoundary,y),radius/4,radius/4);
		  fillellipse(xDev(worldBoundary,deviceBoundary,x - (cartHalfWidth/2)),
		              yDev(worldBoundary,deviceBoundary,y),radius/4,radius/4);	
	  }

    void setX(const float& _x){
		 x = _x;
	 }		 
	
private:
    float x, y;
    float length;
    float speed;
    float height;
    float wheelRadius;
    float halfWheelBase;
    float cartHalfWidth;

};



#endif

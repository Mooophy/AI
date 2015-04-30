#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__


#include <math.h>
 

using namespace std;

const float M_PI = 3.14159265358979323846f;  //use M_PI from math.h instead

typedef struct
{
  float x1,y1,x2,y2;
} BoundaryType; 



/// Function Prototypes ////////////////////////////////////////////////////////////////////

float degToRad(float deg);
int xDev(BoundaryType WorldBound,BoundaryType DevBound,float xworld);
int yDev(BoundaryType WorldBound,BoundaryType DevBound,float yworld);


#endif


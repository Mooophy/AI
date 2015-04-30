#include "transform.h"
 

using namespace std;

/////////////////////////////////////////////////////////////////////////////////
// World-to-Device Coordinates Transformation 

int xDev(BoundaryType WorldBound,BoundaryType DevBound,float xworld)
{
    float xslope,xint;
    
    if((WorldBound.x2-WorldBound.x1) == 0)
      xslope = (DevBound.x2-DevBound.x1)/(WorldBound.x2-WorldBound.x1+.001);
    else
      xslope = (DevBound.x2-DevBound.x1)/(WorldBound.x2-WorldBound.x1);
    xint = DevBound.x1-xslope*WorldBound.x1;

    return (int)ceil(xslope*xworld+xint);
}

int yDev(BoundaryType WorldBound,BoundaryType DevBound,float yworld)
{
    float yslope,yint;
    
    if((WorldBound.y2-WorldBound.y1) == 0.0)
       yslope = (DevBound.y2-DevBound.y1)/(WorldBound.y2-WorldBound.y1+.001);
    else
       yslope = (DevBound.y2-DevBound.y1)/(WorldBound.y2-WorldBound.y1);
    yint = DevBound.y1-yslope*WorldBound.y1;

    return (int)ceil(yslope*yworld+yint);
}


float degToRad(float deg) {
	return(deg * M_PI / 180.0);
}



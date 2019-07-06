#include "point.hh"

#include <vector>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

std::vector<coord2D> points;

void
ClearPoints()
{
    points.clear();
}

std::vector<coord2D>
GetPoints()
{
    return points;
}

void 
AddPoints(float posx, float posy)
{
    points.push_back(coord2D{posx, posy});

    if(points.size() > 1){
        ClearPoints();
    }
}

void
DrawPoints()
{
    glPointSize(10);
    glColor3f(255, 0, 0);
    glBegin(GL_POINTS);
    for(int i=0; i<points.size(); i++){
        float x = (float) points.at(i).x;
        float y = (float) points.at(i).y;
        glVertex2f((float)(x), (float)(y));
    }
    glEnd();
}
#include "line.hh"

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

std::vector<Line_t> lines;
std::vector<Point_t> points;

void 
AddPoints(float posx, float posy)
{
    if(points.size() >= 2){
        AddLines();
    }
    points.push_back(Point{posx, posy});
}

void
ClearPoints()
{
    points.clear();
}

void
AddLines()
{
    lines.push_back(Line{
        points.at(0),
        points.at(1)
    });

    ClearPoints();
}

void
DeleteLines(int index)
{
    lines.erase(lines.begin() + index);
}

void
PrettyPrint()
{
    std::cout << "Points: " << (points.size() + (lines.size() * 2)) << " | Lines: " << lines.size();
    std::cout << "LastAddedMouseCoordinate: (" << points.at(points.size()-1).posx << " " <<  points.at(points.size()-1).posy << ")";
    std::cout << "           \r";
    fflush(stdout);
}

void
DrawPoints()
{
    glColor3f(255, 0, 0);
    glBegin(GL_POINTS);
    for(uint8_t i=0; i<points.size(); i++){
        float x = (float) points.at(i).posx;
        float y = (float) points.at(i).posx;
        glVertex2f((float)(x), (float)(y));
    }
    glEnd();
}

void
DrawLines()
{

}
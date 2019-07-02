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
    points.push_back(Point{posx, posy});

    if(points.size() > 1){
        AddLines();
        ClearPoints();
    }
}

void
ClearPoints()
{
    points.clear();
}

void
AddLines()
{
    if(points.size() < 2) return;
    else {
        lines.push_back(Line{
            points.at(0),
            points.at(1)
        });
    }

    DrawLines();
}

void
DeleteLines(int index)
{
    lines.erase(lines.begin() + index);
}

void
ClearLines()
{
    lines.clear();
}

void
PrettyPrint()
{
    std::cout << "Points: " << (points.size() + (lines.size() * 2)) << " | Lines: " << lines.size();
    std::cout << "           \r";
    fflush(stdout);
}

void
DrawPoints()
{
    glPointSize(10);
    glColor3f(255, 0, 0);
    glBegin(GL_POINTS);
    for(uint8_t i=0; i<points.size(); i++){
        float x = (float) points.at(i).posx;
        float y = (float) points.at(i).posy;
        glVertex2f((float)(x), (float)(y));
    }
    glEnd();
}

void
DrawLines()
{
    glPointSize(10);
    glColor3f(255, 255, 255);
    glBegin(GL_LINES);
    for(uint8_t i=0; i<lines.size(); i++){
        float x1 = (float) lines.at(i).pos1.posx;
        float y1 = (float) lines.at(i).pos1.posy;
        float x2 = (float) lines.at(i).pos2.posx;
        float y2 = (float) lines.at(i).pos2.posy;
        
        glVertex2f((float)(x1), (float)(y1));
        glVertex2f((float)(x2), (float)(y2));
    }
    glEnd();

    glColor3f(255, 0, 0);
    glBegin(GL_POINTS);
    for(uint8_t i=0; i<lines.size(); i++){
        float x1 = (float) lines.at(i).pos1.posx;
        float y1 = (float) lines.at(i).pos1.posy;
        float x2 = (float) lines.at(i).pos2.posx;
        float y2 = (float) lines.at(i).pos2.posy;

        glVertex2f((float)(x1), (float)(y1));
        glVertex2f((float)(x2), (float)(y2));
    }
    glEnd();
}
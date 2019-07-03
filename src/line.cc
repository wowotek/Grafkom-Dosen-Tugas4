#include "line.hh"

#include <iostream>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

std::vector<Line_t> lines;
std::vector<Point_t> points;
std::vector<Point_t> intersections;

bool drawPolygons = true;

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
    for(int i=0; i<points.size(); i++){
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
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    for(int i=0; i<lines.size(); i++){
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
    for(int i=0; i<lines.size(); i++){
        float x1 = (float) lines.at(i).pos1.posx;
        float y1 = (float) lines.at(i).pos1.posy;
        float x2 = (float) lines.at(i).pos2.posx;
        float y2 = (float) lines.at(i).pos2.posy;

        glVertex2f((float)(x1), (float)(y1));
        glVertex2f((float)(x2), (float)(y2));
    }
    glEnd();
}

Point
IntersectionCalculator(Line line1, Line line2)
{
    // Line A
    float x1a = line1.pos1.posx;
    float y1a = line1.pos1.posy;
    float x1b = line1.pos2.posx;
    float y1b = line1.pos2.posy;

    float ma = (y1b-y1a) / (x1b-x1a);
    float ca = y1a - (ma * x1a);
    float da = sqrt(((x1b - x1a)*(x1b - x1a)) + ((y1b - y1a)*(y1b - y1a)));

    // Line B
    float x2a = line2.pos1.posx;
    float y2a = line2.pos1.posy;
    float x2b = line2.pos2.posx;
    float y2b = line2.pos2.posy;

    float mb = (y2b-y2a) / (x2b-x2a);
    float cb = y2a - (mb * x2a);
    float db = sqrt(((x2b - x2a)*(x2b - x2a)) + ((y2b - y2a)*(y2b - y2a)));

    // Output Intersection
    float xo = (cb - ca) / (ma - mb);
    float yo = (ma * xo) + ca;

    return Point{xo, yo};
}

void
CalculateIntersections()
{
    if(lines.size() < 2) return;

    glPointSize(5);
    for(int i=0; i<lines.size(); i++){
        for(int j=0; j<lines.size(); j++){
            if(j == i) break;
            
            intersections.push_back(IntersectionCalculator(lines.at(i), lines.at(j)));
        }
    }
}

void 
DrawIntersection()
{
    CalculateIntersections();

    glColor4ub(0, 0, 1, 15);
    glBegin(GL_POLYGON);
    for(int i=0; i<intersections.size(); i++){
        glVertex2f(intersections[i].posx, intersections[i].posy);
    }
    glEnd();
}

void
ClearIntesections()
{
    intersections.clear();
}
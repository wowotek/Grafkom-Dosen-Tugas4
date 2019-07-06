#include "line.hh"

#include <iostream>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

std::vector<Line_t> lines;
std::vector<coord2D> points;
std::vector<coord2D> intersections;

bool drawPolygons = true;
bool drawIntersectionPoints = true;
bool drawLinePoints = true;
bool drawLine = true;

void
SwitchDrawPolygons()
{
    drawPolygons = !drawPolygons;
}

void
SwitchDrawIntersectionPoints()
{
    drawIntersectionPoints = !drawIntersectionPoints;
}

void
SwitchDrawLinePoints()
{
    drawLinePoints = !drawLinePoints;
}

void
SwitchDrawLine()
{
    drawLine = !drawLine;
}

void 
AddPoints(float posx, float posy)
{
    points.push_back(coord2D{posx, posy});

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
    std::cout << " | Polygons : " << drawPolygons;
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
        float x = (float) points.at(i).x;
        float y = (float) points.at(i).y;
        glVertex2f((float)(x), (float)(y));
    }
    glEnd();
}

void
DrawLines()
{
    if(drawLine){
        glPointSize(10);
        glColor3f(0, 0, 0);
        glBegin(GL_LINES);
        for(int i=0; i<lines.size(); i++){
            float x1 = (float) lines.at(i).pos1.x;
            float y1 = (float) lines.at(i).pos1.y;
            float x2 = (float) lines.at(i).pos2.x;
            float y2 = (float) lines.at(i).pos2.y;
            
            glVertex2f((float)(x1), (float)(y1));
            glVertex2f((float)(x2), (float)(y2));
        }
        glEnd();
    }

    if(drawLinePoints){
        glColor3f(255, 0, 0);
        glBegin(GL_POINTS);
        for(int i=0; i<lines.size(); i++){
            float x1 = (float) lines.at(i).pos1.x;
            float y1 = (float) lines.at(i).pos1.y;
            float x2 = (float) lines.at(i).pos2.x;
            float y2 = (float) lines.at(i).pos2.y;

            glVertex2f((float)(x1), (float)(y1));
            glVertex2f((float)(x2), (float)(y2));
        }
        glEnd();
    }
}

coord2D
IntersectionCalculator(Line line1, Line line2)
{
    // Line A
    float x1a = line1.pos1.x;
    float y1a = line1.pos1.y;
    float x1b = line1.pos2.x;
    float y1b = line1.pos2.y;

    float ma = (y1b-y1a) / (x1b-x1a);
    float ca = y1a - (ma * x1a);
    float da = sqrt(((x1b - x1a)*(x1b - x1a)) + ((y1b - y1a)*(y1b - y1a)));

    // Line B
    float x2a = line2.pos1.x;
    float y2a = line2.pos1.y;
    float x2b = line2.pos2.x;
    float y2b = line2.pos2.y;

    float mb = (y2b-y2a) / (x2b-x2a);
    float cb = y2a - (mb * x2a);
    float db = sqrt(((x2b - x2a)*(x2b - x2a)) + ((y2b - y2a)*(y2b - y2a)));

    // Output Intersection
    float xo = (cb - ca) / (ma - mb);
    float yo = (ma * xo) + ca;


    return coord2D{xo, yo};
}

void
CalculateIntersections()
{
    if(lines.size() < 2) return;

    ClearIntesections();
    
    for(int i=0; i<lines.size(); i++){
        for(int j=0; j<lines.size(); j++){
            if(j == i) break;
            coord2D ip = IntersectionCalculator(lines.at(i), lines.at(j));

            Line linesi = lines.at(i);
            Line linesj = lines.at(j);

            if( ip.x > glutGet(GLUT_WINDOW_WIDTH) || ip.y > glutGet(GLUT_WINDOW_HEIGHT) ||
                ip.x < 0 || ip.y < 0 || ip.x == NAN || ip.y == NAN || 
                ip.x == INFINITY || ip.y == INFINITY) continue;
            
            intersections.push_back(coord2D{ip.x, ip.y});
        }
    }
}

void 
DrawIntersectionPoints()
{
    if(drawIntersectionPoints){
        glPointSize(10);
        glColor4f(0, 1, 0, 1);
        glBegin(GL_POINTS);
        for(int i=0; i<intersections.size(); i++){
            glVertex2f(intersections[i].x, intersections[i].y);
        }
        glEnd();
    }
}

void
DrawIntersectionPolygons()
{
    if(drawPolygons){
        glColor4f(0, 1, 1, 0.255);
        glBegin(GL_POLYGON);
        for(int i=0; i<intersections.size(); i++){
            glVertex2f(intersections[i].x, intersections[i].y);
        }
        glEnd();
    }
}

void
ClearIntesections()
{
    intersections.clear();
}
#include "draw.hh"

#include "common.hh"
#include "point.hh"
#include "line.hh"
#include "intersection.hh"

bool drawLinePoints = true;
bool drawLine = true;
bool drawIntersectionPoints = true;
bool drawPolygons = true;

void
SwitchDrawPolygons() 
{ drawPolygons = !drawPolygons; }

void
SwitchDrawIntersectionPoints()  
{ drawIntersectionPoints = !drawIntersectionPoints; }

void
SwitchDrawLinePoints() 
{ drawLinePoints = !drawLinePoints; }

void
SwitchDrawLine() 
{ drawLine = !drawLine; }

void
UpdateCallback(float mousex, float mousey)
{
    AddPoints(mousex, mousey);

    std::vector<coord2D> points = GetPoints();
    if(points.size() > 1){
        AddLines(points.at(0), points.at(1));
        ClearPoints();
    }

    std::vector<Line> line = GetLines();
    if(line.size() > 1){
        CalculateIntersections(line);
    }
}

void 
DrawAll()
{
    if(drawLinePoints) DrawLinesPoints();
    if(drawLine) DrawLines();
    if(drawIntersectionPoints) DrawIntersectionPoints();
    if(drawPolygons) DrawIntersectionPolygons();

    DrawPoints();
}

void
ClearAll()
{
    ClearIntesections();
    ClearLines();
    ClearPoints();
}
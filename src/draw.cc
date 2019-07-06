#include "draw.hh"

#include "point.hh"
#include "line.hh"
#include "intersection.hh"

bool drawLinePoints = true;
bool drawLine = true;
bool drawIntersectionPoints = true;
bool drawPolygons = true;

void
SwitchDrawPolygons() { drawPolygons = !drawPolygons; }

void
SwitchDrawIntersectionPoints()  { drawIntersectionPoints = !drawIntersectionPoints; }

void
SwitchDrawLinePoints() { drawLinePoints = !drawLinePoints; }

void
SwitchDrawLine() { drawLine = !drawLine; }

void
updateCallback()
{

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
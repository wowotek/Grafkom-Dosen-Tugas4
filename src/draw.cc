#include "draw.hh"

bool drawPolygons = true;
bool drawIntersectionPoints = true;
bool drawLinePoints = true;
bool drawLine = true;

void
SwitchDrawPolygons()
    { drawPolygons = !drawPolygons; }

void
SwitchDrawIntersectionPoints() 
    { drawIntersectionPoints = !drawIntersectionPoints; }

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
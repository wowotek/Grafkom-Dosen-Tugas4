#ifndef INTERSECTION_HH
#define INTERSECTION_HH

#include "common.hh"

void ClearIntesections();
coord2D IntersectionCalculator(Line, Line);
void CalculateIntersections(std::vector<Line>);
void DrawIntersectionPoints();
void DrawIntersectionPolygons();

#endif
#ifndef INTERSECTION_HH
#define INTERSECTION_HH

#include "common.hh"

#include <vector>

void ClearIntesections();
coord2D IntersectionCalculator(Line, Line);
void CalculateIntersections(std::vector<Line>);
void DrawIntersectionPoints();
void DrawIntersectionPolygons();

#endif
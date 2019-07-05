#ifndef LINE_HH
#define LINE_HH

#include <stdint.h>
#include <vector>

#include "common.hh"

void AddPoints(float, float);
void ClearPoints();
void DrawPoints();

void AddLines();
void DeleteLines(int);
void ClearLines();
void DrawLines();

void PrettyPrint();

void ClearIntesections();
coord2D IntersectionCalculator(Line, Line);
void CalculateIntersections();
void SwitchDrawPolygons();
void DrawIntersection();

#endif
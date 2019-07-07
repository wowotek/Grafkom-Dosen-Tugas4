#ifndef LINE_HH
#define LINE_HH

#include "common.hh"

#include <vector>

std::vector<Line> GetLines();
void AddLines(coord2D ab, coord2D cd);
void DeleteLines(int);
void ClearLines();
void DrawLines();
void DrawLinesPoints();

#endif
#ifndef POINT_HH
#define POINT_HH

#include "common.hh"

#include <vector>

void ClearPoints();
std::vector<coord2D> GetPoints();
void AddPoints(float, float);
void DrawPoints();

#endif
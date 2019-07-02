#ifndef LINE_HH
#define LINE_HH

#include <stdint.h>
#include <vector>

std::vector<Line> lines;
std::vector<Point> points;

typedef struct Point_t Point;
typedef struct Line_t Line;

void addPoints(float, float);
void eraseAllPoint();

void addLines();
void deleteLines();

#endif
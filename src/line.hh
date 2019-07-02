#ifndef LINE_HH
#define LINE_HH

#include <stdint.h>
#include <vector>

typedef struct Point_t {
    float posx;
    float posy;
} Point;
typedef struct Line_t {
    Point pos1;
    Point pos2;
} Line;

void addPoints(float, float);
void clearPoints();
void printPoints();
void drawPoints();

void addLines();
void deleteLines(int);
void printLines();
void drawLines();

#endif
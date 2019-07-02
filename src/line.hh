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

void AddPoints(float, float);
void ClearPoints();
void DrawPoints();

void AddLines();
void DeleteLines(int);
void ClearLines();
void DrawLines();

void PrettyPrint();

#endif
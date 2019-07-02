#include "line.hh"

typedef struct Point_t 
{
    float posx;
    float posy;
} Point;

typedef struct Line_t 
{
    Point pos1;
    Point pos2;
} Line;

void 
addPoints(float posx, float posy)
{
    points.push_back(Point{posx, posy});
}

void
eraseAllPoint()
{
    points = {};
}

void
addLines()
{
    lines.push_back(Line{
        points.at(0),
        points.at(1)
    });

    eraseAllPoint();
}

void
deleteLines()
{

}
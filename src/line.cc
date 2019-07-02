#include "line.hh"

#include <iostream>

std::vector<Line_t> lines;
std::vector<Point_t> points;

void 
addPoints(float posx, float posy)
{
    if(points.size() >= 2){
        addLines();
    }
    points.push_back(Point{posx, posy});
}

void
clearPoints()
{
    points.clear();
}

void
printPoints()
{
    for(int i=0; i<points.size(); i++){
        std::cout << "(" << points.at(i).posx << " " << points.at(i).posy << ")";
    }

    std::cout << std::endl;
}

void
drawPoints()
{
    
}


void
addLines()
{
    lines.push_back(Line{
        points.at(0),
        points.at(1)
    });

    clearPoints();
}

void
deleteLines(int index)
{
    lines.erase(lines.begin() + index);
}

void
printLines()
{
    for(int i=0; i<lines.size(); i++){
        std::cout << "((" << lines.at(i).pos1.posx << " " << lines.at(i).pos1.posy << ") (" << lines.at(i).pos2.posx << " " << lines.at(i).pos2.posy << ")), ";
    }

    std::cout << std::endl;
}

void
drawLines()
{

}
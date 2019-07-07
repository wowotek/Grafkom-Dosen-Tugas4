/*
 * an implementation of draw, draw all lines, points, and intersections
 * Copyright (C) 2018  Erlangga Ibrahim
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "draw.hh"

#include "common.hh"
#include "point.hh"
#include "line.hh"
#include "intersection.hh"

bool drawLinePoints = true;
bool drawLine = true;
bool drawIntersectionPoints = true;
bool drawPolygons = false;

void
SwitchDrawPolygons() 
{ drawPolygons = !drawPolygons; }

void
SwitchDrawIntersectionPoints()  
{ drawIntersectionPoints = !drawIntersectionPoints; }

void
SwitchDrawLinePoints() 
{ drawLinePoints = !drawLinePoints; }

void
SwitchDrawLine() 
{ drawLine = !drawLine; }

void
UpdateCallback(float mousex, float mousey)
{
    AddPoints(mousex, mousey);

    std::vector<coord2D> points = GetPoints();
    if(points.size() > 1){
        AddLines(points.at(0), points.at(1));
        ClearPoints();
    }

    std::vector<Line> line = GetLines();
    if(line.size() > 1){
        CalculateIntersections(line);
    }
}

void 
DrawAll()
{
    if(drawLinePoints) DrawLinesPoints();
    if(drawLine) DrawLines();
    if(drawIntersectionPoints) DrawIntersectionPoints();
    if(drawPolygons) DrawIntersectionPolygons();

    DrawPoints();
}

void
ClearAll()
{
    ClearIntesections();
    ClearLines();
    ClearPoints();
}
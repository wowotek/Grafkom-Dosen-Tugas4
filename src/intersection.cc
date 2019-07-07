/*
 * implementation of intersection prototype, control all intersection point
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

#include "intersection.hh"

#include <math.h>
#include <vector>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

std::vector<coord2D> intersections;

void
ClearIntesections()
{
    intersections.clear();
}

coord2D
IntersectionCalculator(Line line1, Line line2)
{
    // Line A
    float x1a = line1.pos1.x;
    float y1a = line1.pos1.y;
    float x1b = line1.pos2.x;
    float y1b = line1.pos2.y;

    float ma = (y1b-y1a) / (x1b-x1a);
    float ca = y1a - (ma * x1a);

    // Line B
    float x2a = line2.pos1.x;
    float y2a = line2.pos1.y;
    float x2b = line2.pos2.x;
    float y2b = line2.pos2.y;

    float mb = (y2b-y2a) / (x2b-x2a);
    float cb = y2a - (mb * x2a);

    // Output Intersection
    float xo = (cb - ca) / (ma - mb);
    float yo = (ma * xo) + ca;

    return coord2D{xo, yo};
}

void
CalculateIntersections(std::vector<Line> lines)
{
    if(lines.size() < 2) return;

    ClearIntesections();
    
    for(uint8_t i=0; i<lines.size(); i++){
        for(uint8_t j=0; j<lines.size(); j++){
            if(j == i) break;
            coord2D ip = IntersectionCalculator(lines.at(i), lines.at(j));
            
            intersections.push_back(coord2D{ip.x, ip.y});
        }
    }
}

void 
DrawIntersectionPoints()
{
    glPointSize(10);
    glColor4f(0, 1, 0, 1);
    glBegin(GL_POINTS);
    for(uint8_t i=0; i<intersections.size(); i++){
        glVertex2f(intersections[i].x, intersections[i].y);
    }
    glEnd();
}

void
DrawIntersectionPolygons()
{
    glColor4f(0, 1, 1, 0.255);
    glBegin(GL_TRIANGLE_FAN);
    for(uint8_t i=0; i<intersections.size(); i++){
        glVertex2f(intersections[i].x, intersections[i].y);
    }
    glEnd();
}
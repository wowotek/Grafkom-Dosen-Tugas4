/*
 * implementation of point controller, handle all point adding, and calculation
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

#include "point.hh"

#include <vector>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

std::vector<coord2D> points;

void
ClearPoints()
{
    points.clear();
}

std::vector<coord2D>
GetPoints()
{
    return points;
}

void 
AddPoints(float posx, float posy)
{
    points.push_back(coord2D{posx, posy});
}

void
DrawPoints()
{
    glPointSize(10);
    glColor3f(255, 0, 0);
    glBegin(GL_POINTS);
    for(uint8_t i=0; i<points.size(); i++){
        float x = (float) points.at(i).x;
        float y = (float) points.at(i).y;
        glVertex2f((float)(x), (float)(y));
    }
    glEnd();
}
/*
 * implementation of line controller, handle all the line calculation
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

#include "line.hh"

#include <math.h>
#include <stdint.h>
#include <vector>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

std::vector<Line_t> lines;

std::vector<Line_t>
GetLines()
{
    return lines;
}

void
AddLines(coord2D ab, coord2D cd)
{
    lines.push_back(Line{ab, cd});
}

void
DeleteLines(int index)
{
    lines.erase(lines.begin() + index);
}

void
ClearLines()
{
    lines.clear();
}

void
DrawLines()
{
    glPointSize(10);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    for(uint8_t i=0; i<lines.size(); i++){
        float x1 = (float) lines.at(i).pos1.x;
        float y1 = (float) lines.at(i).pos1.y;
        float x2 = (float) lines.at(i).pos2.x;
        float y2 = (float) lines.at(i).pos2.y;
        
        glVertex2f((float)(x1), (float)(y1));
        glVertex2f((float)(x2), (float)(y2));
    }
    glEnd();
}

void
DrawLinesPoints()
{
    glColor3f(255, 0, 0);
    glBegin(GL_POINTS);
    for(uint8_t i=0; i<lines.size(); i++){
        float x1 = (float) lines.at(i).pos1.x;
        float y1 = (float) lines.at(i).pos1.y;
        float x2 = (float) lines.at(i).pos2.x;
        float y2 = (float) lines.at(i).pos2.y;

        glVertex2f((float)(x1), (float)(y1));
        glVertex2f((float)(x2), (float)(y2));
    }
    glEnd();
}
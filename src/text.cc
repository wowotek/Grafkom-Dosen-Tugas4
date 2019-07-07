/*
 * handle of drawing all text on the screen
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

#include "text.hh"

#include <vector>
#include <GL/glut.h>

std::vector<ScreenText> screentexts;

void
AddScreenText(std::string text, coord2D position, color3f color)
{
    screentexts.push_back(ScreenText_t{
        text,
        position,
        color
    });
}

void
AddScreenText(std::string text, coord2D position)
{
    screentexts.push_back(ScreenText_t{
        text,
        position,
        color3f{0, 0, 0}
    });
}

void
AddScreenText(std::string text)
{
    screentexts.push_back(ScreenText_t{
        text,
        coord2D{0, 10},
        color3f{0, 0, 0}
    });
}

void
AddScreenText(ScreenText screenText)
{
    screentexts.push_back(screenText);
}

void
RemoveScreenText(uint8_t index)
{
    screentexts.erase(screentexts.begin() + index);
}

void
ClearScreenText()
{
    screentexts.clear();
}

void
DrawScreenText()
{
    for(uint8_t i=0; i<screentexts.size(); i++){
        ScreenText st = screentexts.at(i);
        const char * text = st.text.c_str();

        glColor3f(unpack3(st.color));
        glRasterPos2f(unpack2(st.coordinate));
        for(uint8_t j=0; j<strlen(text); j++){
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[j]);
        }
    }
}
/*
 * text drawing definitions
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

#ifndef TEXT_HH
#define TEXT_HH

#include <string>
#include <cstring>
#include "common.hh"

typedef struct ScreenText_t {
    std::string text;
    coord2D coordinate;
    color3f color;
} ScreenText;

void AddScreenText(std::string, coord2D, color3f);
void AddScreenText(std::string, coord2D);
void AddScreenText(std::string);
void AddScreenText(ScreenText);
void RemoveScreenText(uint8_t index);
void ClearScreenText();

void DrawScreenText();

#endif
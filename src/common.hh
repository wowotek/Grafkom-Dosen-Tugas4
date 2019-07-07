/*
 * A helper file to construct and define handful off vectors
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

#ifndef COMMON_HH
#define COMMON_HH

#define unpack3(vec3) vec3.x, vec3.y, vec3.z
#define unpack2(vec2) vec2.x, vec2.y

template <typename T>
struct vec3{
    T x, y, z;
};

template <typename T>
struct vec2{
    T x, y;
};

typedef vec3<float> vec3f;
typedef vec3f color3f;

typedef vec2<float> vec2f;
typedef vec2f coord2D;

typedef struct Line_t {
    coord2D pos1;
    coord2D pos2;
} Line;

#endif
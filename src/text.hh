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
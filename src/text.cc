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

        glRasterPos2f(unpack2(st.coordinate));
        glColor3f(unpack3(st.color));
        for(uint8_t j=0; j<strlen(text); j++){
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
        }
    }
}
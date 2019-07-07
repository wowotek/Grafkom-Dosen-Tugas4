/*
 * main program
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

#include <iostream>
#include <cstring>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "draw.hh"
#include "text.hh"

float WIDTH = 640;
float HEIGHT = 640;
float ASPECT_RATIO = WIDTH / HEIGHT;

void
RenderDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.8, 0.8, 0.8, 1);

    DrawAll();
    DrawScreenText();
    
    glutSwapBuffers();
}

void
UpdateScreen(GLint time)
{
    glutPostRedisplay();
    glutTimerFunc(time, UpdateScreen, time);
}

void
MouseEvent(int button, int state, int posx, int posy)
{
    if(button == 0 && state == GLUT_UP){
        UpdateCallback(posx, posy);
    }
}

void
KeyboardEvent(unsigned char key, int, int)
{
    if(key == 'r'){
        ClearAll();
    }
    
    if (key == 'd'){
        SwitchDrawPolygons();
    }

    if (key == 'p'){
        SwitchDrawLinePoints();
    }

    if (key == 'i'){
        SwitchDrawIntersectionPoints();
    }
    
    if (key == 'l'){
        SwitchDrawLine();
    }
}

void
Init(void)
{
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glutSetOption(GLUT_MULTISAMPLE, 16);

    glEnable(GL_MULTISAMPLE);
    glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);

    glutDisplayFunc(RenderDisplay);
    glutMouseFunc(MouseEvent);
    glutKeyboardFunc(KeyboardEvent);
    UpdateScreen(1000/120);
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0);

    AddScreenText(" R ", coord2D{1, 12}, color3f{1, 0, 0});
    AddScreenText("< > Reset Screen", coord2D{1, 12}, color3f{0, 0, 0});

    AddScreenText(" D ", coord2D{1, 27}, color3f{1, 0, 0});
    AddScreenText("< > Draw Polygon", coord2D{1, 27}, color3f{0, 0, 0});

    AddScreenText(" P ", coord2D{1, 42}, color3f{1, 0, 0});
    AddScreenText("< > Draw Line Points", coord2D{1, 42}, color3f{0, 0, 0});

    AddScreenText(" I ", coord2D{1, 57}, color3f{1, 0, 0});
    AddScreenText("< > Draw Intesection Points", coord2D{1, 57}, color3f{0, 0, 0});

    AddScreenText(" L ", coord2D{1, 72}, color3f{1, 0, 0});
    AddScreenText("< > Draw Line", coord2D{1, 72}, color3f{0, 0, 0});
}

int 
main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(2280, 480);
    glutCreateWindow("TUGAS 4 GRAFKOM");

    Init();

    glutMainLoop();
    return 0;
}
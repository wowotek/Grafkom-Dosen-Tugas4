#include <iostream>
#include <cstring>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "line.hh"

#define WIDTH 640
#define HEIGHT 480


const char infoString[] = "press R to reset the Screen";

void
RenderDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    DrawLines();
    DrawPoints();



    glColor3f(1, 1, 1);
    glRasterPos2f(0, 10);
    for(uint8_t i=0; i<strlen(infoString); i++){
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, infoString[i]);
    }
    glutSwapBuffers();
}

void
UpdateScreen(GLint time)
{
    RenderDisplay();
    glutPostRedisplay();
    glutTimerFunc(time, UpdateScreen, time);
}

void
MouseEvent(int button, int state, int posx, int posy)
{
    if(state == GLUT_UP){
        AddPoints(posx, posy);

        PrettyPrint();
        RenderDisplay();
        glutPostRedisplay();
    }
}

void
Init(void)
{
    glutDisplayFunc(RenderDisplay);
    glutMouseFunc(MouseEvent);

    UpdateScreen(1000/120);
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0);
}

int 
main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(2280, 480);
    glutCreateWindow("TUGAS 4 GRAFKOM");
    Init();

    glutMainLoop();
    return 0;
}
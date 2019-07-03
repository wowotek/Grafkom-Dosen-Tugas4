#include <iostream>
#include <cstring>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "line.hh"

float WIDTH = 640;
float HEIGHT = 640;
float ASPECT_RATIO = WIDTH / HEIGHT;

const char infoString[] = "press < > to reset the Screen";
const char Red[] = "press <R> to reset the Screen";

void
RenderDisplay(void)
{
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    DrawLines();
    DrawPoints();
    DrawIntersection();

    glColor3f(1, 0, 0);
    glRasterPos2f(0, 10);
    for(uint8_t i=0; i<strlen(infoString); i++){
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, Red[i]);
    }

    glColor3f(0, 0, 0);
    glRasterPos2f(0, 10);
    for(uint8_t i=0; i<strlen(infoString); i++){
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, infoString[i]);
    }

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
    if(state == GLUT_UP){
        AddPoints(posx, posy);
        PrettyPrint();
    }
}

void
KeyboardEvent(unsigned char key, int posx, int posy)
{
    if((int)(key)==114){
        ClearPoints();
        ClearLines();
        ClearIntesections();

        PrettyPrint();
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
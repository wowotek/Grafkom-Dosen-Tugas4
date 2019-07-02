#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#define WIDTH 640
#define HEIGHT 480

void
MouseEvent(int button, int state, int posx, int posy)
{
    std::cout << "Button : " << button << " State : " << state << " pos (" << posx << " " << posy << ")" << std::endl;
    fflush(stdout);
}

void
RenderDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

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
Init(void)
{
    glutDisplayFunc(RenderDisplay);
    glutMouseFunc(MouseEvent);

    UpdateScreen(1000/120);
    gluOrtho2D(0, WIDTH, HEIGHT, 0);
}

int 
main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(480, 480);
    glutCreateWindow("TUGAS 4 GRAFKOM");
    Init();

    glutMainLoop();
    return 0;
}
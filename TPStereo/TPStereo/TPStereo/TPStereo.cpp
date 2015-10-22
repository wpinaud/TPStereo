// TPStereo.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"


#include <GL/glut.h>

void
display(void)
{
    glDrawBuffer(GL_BACK_LEFT);
    glClearColor(1.0, 0.0, 0.0, 1.0); /* red */
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawBuffer(GL_BACK_RIGHT);
    glClearColor(0.0, 0.0, 1.0, 1.0); /* blue */
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_STEREO);
    glutCreateWindow("stereo example");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

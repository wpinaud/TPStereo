//
//  main.cpp
//  TPStereo
//
//  Created by Willis Pinaud on 22/10/2015.
//  Copyright © 2015 Centrale. All rights reserved.
//

#include <iostream>

#include <stdlib.h>
#include <stdio.h>
#include <GLUT/GLUT.h>

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

// TPStereo.cpp�: d�finit le point d'entr�e pour l'application console.
//
#include "stdafx.h"

#include <Windows.h>
#include <GL\GL.h>
#include <GL\glut.h>
#include <stdio.h>

#include <iostream>
using namespace std;

GLvoid souris(int bouton, int etat, int x, int y);

GLvoid GestionClavier(unsigned char touche, int x, int y); 
GLvoid deplacementSouris(int x, int y);

// Structure de donn�es simpliste
// pour stocker un sommet 3D et
// ses informations de couleur

typedef struct {
   float x;
   float y;
   float z;
   float r;
   float g;
   float b;
   //float a;
} vertex;


// Cr�ation des sommets du cube
vertex cube[8]={
   {-0.5f,-0.5f, 0.5f,1.0f,0.0f,0.0f},
   {-0.5f, 0.5f, 0.5f,0.0f,1.0f,0.0f},
   { 0.5f, 0.5f, 0.5f,0.0f,0.0f,1.0f},
   { 0.5f,-0.5f, 0.5f,1.0f,1.0f,1.0f},
   {-0.5f,-0.5f,-0.5f,1.0f,0.0f,0.0f},
   {-0.5f, 0.5f,-0.5f,0.0f,1.0f,0.0f},
   { 0.5f, 0.5f,-0.5f,0.0f,0.0f,1.0f},
   { 0.5f,-0.5f,-0.5f,1.0f,1.0f,1.0f}
};

// Cr�ation des faces du cube
int face[6][4] ={
   {0,1,2,3},
   {3,2,6,7},
   {4,5,6,7},
   {0,1,5,4},
   {1,5,6,2},
   {0,4,7,3}
};
// Quelques variables globales (c'est pas bien)
GLfloat pointSize = 1.0f;

// Rotations autour de X et Y
GLfloat angleX = 0.0f;
GLfloat angleY = 0.0f;
GLint oldX = 0;
GLint oldY = 0;
GLboolean boutonClick = false;

float parallax = 0.1;

void display(void)
{
    /*glDrawBuffer(GL_BACK_LEFT);
    glClearColor(1.0, 0.0, 0.0, 1.0); // rouge 
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawBuffer(GL_BACK_RIGHT);
    glClearColor(0.0, 0.0, 1.0, 1.0); // bleu 
    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();*/


	//glDrawBuffer(GL_BACK_LEFT); 
	/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(-0.75f,0.75f, 0.75f, -0.75f);

	glDrawBuffer(GL_BACK_RIGHT); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(-0.75f+parallax,0.75f, 0.75f+parallax, -0.75f);*/

    
	// Animation du cube!
	
   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();
   glRotatef(-angleY,1.0f,0.0f,0.0f);
   glRotatef(-angleX,0.0f,1.0f,0.0f);

// Dessin du cube colore
   // face par face

	glDrawBuffer(GL_BACK_LEFT); 
	 glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
   for(int i=0;i<6;i++){
      glBegin(GL_POLYGON);
      for(int j=0;j<4;j++){
         glColor3f(cube[face[i][j]].r, cube[face[i][j]].g, cube[face[i][j]].b);
         glVertex3f(cube[face[i][j]].x-parallax, cube[face[i][j]].y, cube[face[i][j]].z);
      }
      glEnd();
   }

  

   glDrawBuffer(GL_BACK_RIGHT); 
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
   for(int i=0;i<6;i++){
      glBegin(GL_POLYGON);
      for(int j=0;j<4;j++){
         glColor3f(cube[face[i][j]].r, cube[face[i][j]].g, cube[face[i][j]].b);
         glVertex3f(cube[face[i][j]].x+parallax, cube[face[i][j]].y, cube[face[i][j]].z);
      }
      glEnd();
   }


   glFlush();
   glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_STEREO| GLUT_DEPTH);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(600, 600);
    glutCreateWindow("stereo example");
	glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
	glutKeyboardFunc(GestionClavier);
	glutMouseFunc(souris);
	glutMotionFunc(deplacementSouris);
    glutMainLoop();
    return 0;
}

GLvoid GestionClavier(unsigned char touche, int x, int y) {
   
   // Suivant les touches pressees, nous aurons un comportement different de l'application

   switch(touche) {
      case 'p' : // carre plein
         parallax += 0.02;
         break;

	case 'm' : // carre plein
         parallax -= 0.02;
         break;

      case 'q' : // quitter
      case 27 :
         exit(0);
         break;
   }
   
   // Demande a GLUT de reafficher la scene
   glutPostRedisplay();
}
// Fonction de rappel de la souris
GLvoid souris(int bouton, int etat, int x, int y){
   // Test pour voir si le bouton gauche de la souris est appuy�
   //TODO
   if (bouton == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (etat == GLUT_UP) {
			boutonClick = false; 

		}
		else  {// state = GLUT_DOWN
			boutonClick = true;
			oldX = x; 
			oldY = y; 
		}
	}
   // si on relache le bouton gauche
   // TODO
}
GLvoid deplacementSouris(int x, int y) {
   // si le bouton gauche est appuye et qu'on se deplace
   // alors on doit modifier les angles de rotations du cube
   // en fonction de la derniere position de la souris
   // et de sa position actuelle
	
	if (boutonClick) {

		// update deltaAngle
		angleX -= (x - oldX) ;
		angleY -= (y - oldY) ;
	   // Appeler le re-affichage de la scene OpenGL
		glutPostRedisplay();

	}

	oldX = x; 
	oldY = y; 
}
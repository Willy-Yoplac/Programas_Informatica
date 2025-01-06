#ifdef _APPLE_
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <GL/freeglut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <cmath>

float black[] = {0,0,0}, white[]={1,1,1}, blue[] = {0,0,1}, marron[] = {0.5,0.35,0.05};
float red[] = {1,0,0}, green[]={0,1,0}, yellow[]={1,1,0};
float cyan[]={0,1,1}, pink[]={1,0.5,0.5}, orange[]={1,0.5,0};

void display(void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0,0,1);
    glLoadIdentity (); // limpia la matriz de tranformacion
    gluLookAt (1, 4, 9, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);// comando de vision de la camara
    
    glPushMatrix();
        glTranslated(-4,1,-5);
        glutWireTeapot(1.8);
    glPopMatrix();

    glPushMatrix();
    glScaled(0.6, 0.6, 0.6);
        glutWireTeacup(4);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-2.5, -2.5, 0);
    glScaled(0.8, 0.8, 0.8);
        glutWireTeacup(3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1, -4, 0);
    glScaled(1, 1, 0.8);
        glutWireTeacup(3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3, -1, 0);
    glScaled(0.8, 0.8, 0.8);
        glutWireTeacup(3);
    glPopMatrix();

    glScaled(0.3, 0.3, 0.3);
    glTranslated(-15,0,-5);
    glutWireTeaspoon(8);
    glTranslated(-6,0,-5);
    glutWireTeaspoon(8);
    glTranslated(-4,0,-5);
    glutWireTeaspoon(8);
    glTranslated(-2,0,-5);
    glutWireTeaspoon(8);

    glutSwapBuffers();
}
void reshape (int w, int h)
{ glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION); // activa la matriz de proyeccion o visualizacion
  glLoadIdentity ();// limpia la venta
  glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
  glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //Inicializa la ventana
    glutInitWindowSize(600,600); //Tamaño de la ventana
    glutInitWindowPosition(100,100); //Posición de la ventana
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Juego de te Newell");
    glutDisplayFunc(display); //Evento renderizado
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}

//g++ dem.cpp -lGL -lGLU -lglut -o ./dem && ./dem
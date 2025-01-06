//#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<iostream>
#include<cmath>
#include <stdlib.h>
#define M_PI 3.1415

float blue[]={0,0,1}, green[]={0,1,0}, orange[]={0.9,0.6,0.1}, cyan[]={0,1,1}, red[]={1,0,0}, yellow[]={1,1,0};
float purple[]={1,0,1}, white[]={1,1,1}, black[]={0,0,0}, brown[]={0.5,0.35,0.05}, pink[]={0.9,0.7,0.7};

void ejes(float k)
{
    glBegin(GL_LINES);
    glColor3f(0,1,0);
    glVertex3f(-k,0,0);
    glVertex3f(k,0,0);
    glColor3f(0,1,0);
    glVertex3f(0,-k,0);
    glVertex3f(0,k,0);
    glColor3f(0,0,1);
    glVertex3f(0,0,-k);
    glVertex3f(0,0,k);
    glEnd();
}

void toro(float y, float angulo, float num1, float num2, float *color)
{
    glPushMatrix();
    glColor3fv(color);
    glTranslated(0,y,0);
    glRotated(angulo,0,1,0);
    glutWireTorus(num1,num2,50,50);
    glPopMatrix();
}

static void display(void)
{
    glClearColor(0,0.5,0.5,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    ejes(500);

//toro uno
toro(1,90,0.2,1.5,black);

//toro dos
toro(4,180,0.1,2,cyan);

//toro tres
toro(7,120,0.2,2,brown);

//toro cuatro
toro(10,100,0.2,2,yellow);

//toro cinco
toro(13,100,0.2,2,black);



    GLUquadricObj *Cilindro;
    glPushMatrix();
    glRotated(90,1,0,0);
    Cilindro = gluNewQuadric();
    gluQuadricDrawStyle(Cilindro,GLU_FILL);
    //gluCylinder(cilindro, base,base, altura, slicks,z)
    gluCylinder(Cilindro,2,2,5,100,20);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glOrtho(-15,15,-15,15,0.5,1000);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (30.0, 30.0, 30.0, 0, 0, 0.0, 0.0, 1.0, 0.0);
}

const GLfloat light_ambient[] = {.3f, .3f, .3f, 1.0f};
const GLfloat light_diffuse[] = {.5f, .5f, .5f, 1.0f};
const GLfloat light_specular[] = {2.0f, 2.0f, 2.0f, 1.0f};
const GLfloat light_position[] = {2.0f, -4.0f, 2.0f, 0.0f};

const GLfloat mat_ambient[] = {0.5f, 0.5f, 0.5f, 1.0f};
const GLfloat mat_diffuse[] = {0.5f, 0.5f, 0.5f, 1.0f};
const GLfloat mat_specular[] = {2.0f, 2.0f, 2.0f, 1.0f};
const GLfloat high_shininess[] = {100.0f};

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(1,1);
    glutCreateWindow("Graficas 3D- Yoplac Willy");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glCullFace(GL_BACK); ///descarta caras posteriores

    glEnable(GL_DEPTH_TEST); ///permite prueba de profundidad
    glDepthFunc(GL_LESS); ///prueba de profundidad

    glEnable(GL_LIGHT0); ///activacion de luz difusa y ambiental
    glEnable(GL_NORMALIZE); ///+ precision en iluminacion y sombreado
    glEnable(GL_COLOR_MATERIAL); ///determina el material para reflejar el color
    glEnable(GL_LIGHTING); ///iluminacion en escena

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
    return EXIT_SUCCESS;
}

//g++ cadenas.cpp -lGL -lGLU -lglut -o ./cadenas && ./cadenas
//g++ arbol_navidad.cpp -lGL -lGLU -lglut -o ./arbol_navidad && ./arbol_navidad
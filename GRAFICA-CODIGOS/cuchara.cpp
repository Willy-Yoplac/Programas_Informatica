#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut.h>
#endif
#include <stdlib.h>
#include <cmath>
#include <iostream>

GLUquadricObj *cilindro;

using namespace std;

void Linea(float *X0, float *X1, float *C, float A = 1, int f = 1, int P = 0)
{
    glColor3fv(C);
    glLineWidth(A);
    glEnable(GL_LINE_STIPPLE);
    switch (P)
    {
        case 1: glLineStipple (f, 0x0101); break;
        case 2: glLineStipple (f, 0xAAAA); break;
        case 3: glLineStipple (f, 0x00FF); break;
        case 4: glLineStipple (f, 0x0c0F); break;
        case 5: glLineStipple (f, 0x1C47); break;
        default: glLineStipple (f, 0xFFFF); break;
    }
    glBegin(GL_LINES);
    glVertex3fv(X0);
    glVertex3fv(X1);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    glLineWidth(1);
}

void Ejes(int c)
{
    float P[]={-10.0,0.0,0.0} , P1[]={10.0,0.0,0.0};
    float P2[]={0.0,-10.0,0.0}, P3[]={0.0,10.0,0.0};
    float P4[]={0.0,0.0,-10.0} , P5[]={0.0,0.0,10.0};
    float C1[]={1,0,0}, C2[]={0,0,1}, C3[]={0,1,0};
    switch (c)// linea punteada
    {    glPushMatrix();
    gluLookAt(10, 10, 10,0,0,0,1,1, 0);
    glTranslated(0,0,0);
    glutSolidTorus(1, 1.2, 20, 20);
    glPopMatrix();
        case 0:
            {
                Linea(P,P1,C1,2,2,1);
                Linea(P2,P3,C2,2,2,1);
                Linea(P4,P5,C3,2,2,1);
                break;
            }
        default :{ // linea solida de grosor c
            Linea(P,P1,C1,c);
            Linea(P2,P3,C2,c);
            Linea(P4,P5,C3,c);
        }
    }
}


void cilindros() {
    glPushMatrix();
    cilindro = gluNewQuadric();
    gluQuadricDrawStyle(cilindro,GLU_FILL);
    gluCylinder(cilindro,5,5,8,100,100);
    glPopMatrix();
}

void display(void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float negro[] = {0,0,0}, blanco[]={1,1,1}, azul[] = {0,0,1}, marron[] = {0.5,0.35,0.05};
    float rojo[] = {1,0,0}, verde[]={0,1,0}, amarillo[]={1,1,0}, lila[] = {1,0.7,0.75};
    float cyan[]={0,1,1}, rosado[]={1,0.5,0.5}, naranja[]={1,0.5,0}, gris[] = {0.75,0.75,0.75};
    float celeste[]={0.19,0.75,0.75};

    glPushMatrix();
    gluLookAt(20, 20, 20,0,0,0,1,1, 0);
    Ejes(1);
    glTranslated(0,0,3);
    glutWireCylinder(2, 4, 20, 10);
    glPopMatrix();

    glPushMatrix();
    gluLookAt(10, 10, 10,0,0,0,1,1, 0);
    glTranslated(0,0,0);
    glutWireTorus(1, 1.2, 20, 20);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glFrustum(-1,1,-1,1,1.5,40);
    glOrtho(-15,15,-15,15,0.5,1000);
    glMatrixMode(GL_MODELVIEW);
}

void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 : // tecla Esc
        case 'q': {
        exit(EXIT_SUCCESS); // Terminar la aplicación
        break;
        }
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); //Inicializa la ventana
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glutInitWindowSize(1000,1000); //Tamaño de la ventana

    glutInitWindowPosition(100,100); //Posición de la ventana
    glutCreateWindow("CILINDRO");
    glutDisplayFunc(display); //Evento renderizado
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    // glutReshapeFunc(resize);
    //glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}
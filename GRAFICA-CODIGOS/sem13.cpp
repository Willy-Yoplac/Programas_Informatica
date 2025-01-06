#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<iostream>
#include<cmath>
#include <stdlib.h>
#define M_PI 3.1415

GLubyte blue1[]={0,0,225}, blue2[]={104,117,125}, black[]={0,0,255};

void ejes(float k)
{
    glBegin(GL_LINES);
    glColor3f(0,1,1);
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

void polRegular(float r,float s1,float x, float y, float z, GLenum t)
{
    glPushMatrix();
    glTranslated(x,y,z);
    glPolygonMode(GL_FRONT_AND_BACK,t);
    glBegin(GL_POLYGON);
    for(float theta=0;theta<=2*M_PI;theta=theta+2*M_PI/s1)
    {
        glVertex3f(r*cos(theta),r*sin(theta),0);
    }
    glEnd();
    glPopMatrix();
}

void cilindroSolido(float r1,float h,float s1)
{
    for(float t=0;t<2*M_PI;t=t+2*M_PI/s1)
    {
        glBegin(GL_POLYGON);
        glVertex3f(r1*cos(t),r1*sin(t),-h/2);
        glVertex3f(r1*cos(t+2*M_PI/s1),r1*sin(t+2*M_PI/s1),-h/2);
        glVertex3f(r1*cos(t+2*M_PI/s1),r1*sin(t+2*M_PI/s1),h/2);
        glVertex3f(r1*cos(t),r1*sin(t),h/2);
        glEnd();
    }
    polRegular(r1,s1,0,0,h/2,GL_FILL);
    polRegular(r1,s1,0,0,-h/2,GL_FILL);
}

void perno (float x=0,float y=0,float z=0,float s=1,float ang=0,float u1=0,float u2=0,float u3=0)
{
    glPushMatrix();
    glTranslated(x,y,z);
    glRotated(ang,u1,u2,u3);

   /* glcolor3ub(97,97,97);
    cilindroSolido(5,20,50);*/

    //SOPORTE DEL PERNO
    glPushMatrix();
    glTranslated(0,0,12);
    glColor3ub(112,112,112);
    cilindroSolido(10,4,50);
    glPopMatrix();

    //CABEZA DEL PERNO
    glPushMatrix();
    glTranslated(0,0,17);
    glColor3ub(103,103,103);
    cilindroSolido(7,6,5);
    glPopMatrix();

    //DECORACION
    glColor3ub(0,0,0);
    polRegular(4.5,50,0,0,20,GL_FILL);

    glPopMatrix();
}


void rueda(float x=0,float y=0,float z=0,float ang=0)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    glRotatef(ang,0,1,0);
    if(ang==0)

     {   //LLANTA
         glColor3ub(26,26,26);
         cilindroSolido(12,5,50);
         //INTERIOR 1
         glColor3ub(80,80,80);
         polRegular(8,50,0,0,2.5,GL_FILL);

         //INTERIOR 2
         glColor3ub(44,44,44);
         polRegular(7,50,0,0,2.5,GL_FILL);

         //INTERIOR 3
         glColor3ub(80,80,80);
         polRegular(3.5,50,0,0,2.5,GL_FILL);

         glColor3ub(0,0,0);
         glLineWidth(3);
         polRegular(3,50,0,0,2.5,GL_LINE);

//         for (int t=0;t<2*M_PI;t=t+2*M_PI/5)
//         {
//             perno(1.8*cos(t),1.8*sin(t),2.2,0.06);
//         }
        }

     else if (ang==180)
     {

        //INTERI0R 1
         glColor3ub(80,80,80);
         polRegular(8,50,0,0,2.5,GL_FILL);

         //INTERIOR 2
         glColor3ub(44,44,44);
         polRegular(7,50,0,0,2.5,GL_FILL);

         //INTERIOR 3
         glColor3ub(80,80,80);
         polRegular(3.5,50,0,0,2.5,GL_FILL);

         glColor3ub(0,0,0);
         glLineWidth(3);
         polRegular(3,50,0,0,2.5,GL_LINE);

         //LLANTA
         glColor3ub(26,26,26);
         cilindroSolido(12,5,50);

     }
    glPopMatrix();
}

void paralelepipedo(float b, float h,float w,float x, float y, float z, GLubyte *piso,GLubyte *paredes)
{
    glPushMatrix();
    glTranslated(x,y,z);

    glBegin(GL_POLYGON);
    glColor3ubv(piso);
    glVertex3f(0,0,0);
    glVertex3f(-b,0,0);
    glVertex3f(-b,0,-w);
    glVertex3f(0,0,-w);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ubv(paredes);

    glVertex3f(-b,0,0);
    glVertex3f(-b,h,0);
    glVertex3f(0,0,0);
    glVertex3f(0,h,0);

    glVertex3f(0,0,-w);
    glVertex3f(0,h,-w);
    glVertex3f(-b,0,-w);
    glVertex3f(-b,h,-w);

    glVertex3f(-b,0,0);
    glVertex3f(-b,h,0);
    glVertex3f(-b,0,0);
    glVertex3f(-b,h,0);
    glEnd();
    glPopMatrix();
}


//void cilindro (double b1,double b2, double h, GLint s1, GLint st)
//{
//    GLubyte blanco[]={225,225,255};
//    glColor3ubv(blanco);
//    for(float theta=0; theta<=2*M_PI;theta=theta+2*M_PI/s1)
//        {glBegin(GL_LINE_STRIP);
//        for(float i=0; i<=h;i=i+h/st)
//        {
//            glVertex3f(b1*cos(theta),b2*sin(theta),i);
//        }
//        glEnd();
//        }
//    for(float i=0; i<=h;i+i+h/st)
//    {glBegin(GL_LINE_STRIP);
//     for(float theta=0; theta<=2*M_PI;theta=theta+2*M_PI/s1)
//        {
//            glVertex3f(b1*cos(theta),b2*sin(theta),i);
//        }
//        glEnd();
//
//    }
//
//}



static void display(void)
{
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    ejes(100);

    //RUEDAS Y CAJA
    rueda(20,0,-15,180);
    rueda(-20,0,-15,180);
    paralelepipedo(70,15,25,35,0,12.5,blue1,blue1);
    rueda(20,0,15);
    rueda(-20,0,15);



   // SOPORTE DEL TECHO
    glColor3ub(133,133,133);

    glPushMatrix();
    glRotated(90,1,0,0);
    glTranslated(-15,-7,-20);
    cilindroSolido(1.5,10,50);
    glPopMatrix();

    glPushMatrix();
    glRotated(90,1,0,0);
    glTranslated(-15,7,-20);
    cilindroSolido(1.5,10,50);
    glPopMatrix();

    glPushMatrix();
    glRotated(90,1,0,0);
    glTranslated(20,-7,-20);
    cilindroSolido(1.5,10,50);
    glPopMatrix();

    glPushMatrix();
    glRotated(90,1,0,0);
    glTranslated(20,7,-20);
    cilindroSolido(1.5,10,50);
    glPopMatrix();

    //TECHO
    glPushMatrix();
    glTranslated(2,25,0);
    paralelepipedo(50,1,22,25,0,11,blue2,blue2);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glOrtho(-50,50,-50,50,0.5,1000);
   //gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 60.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (30.0, 30.0, 30.0, 0, 0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(1,1);
    glutCreateWindow("Gráficas 3D");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return EXIT_SUCCESS;
}

//g++ sem13.cpp -lGL -lGLU -lglut -o ./sem13 && ./sem13

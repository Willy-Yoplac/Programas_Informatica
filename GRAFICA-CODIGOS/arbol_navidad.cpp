//#include<windows.h>    // - > descomentar si usas Windows
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<iostream>
#include<cmath>
#include <stdlib.h>

float blue[]={0,0,1};
float green[]={0,0.9,0.1};
float marron[]={0.55,0.28,0.14};
float cyan[]={0,0.8,0.8};
float red[]={1,0,0};
float red2[]={0.4,0,0};
float yellow[]={1,1,0};
float yellow2[]={1,1,0.3};
float purple[]={1,0,1};
float white[]={1,1,1};
float black[]={0,0,0};

float green1[]={0.2,0.8,0},green2[]={0.2,0.4,0};
float pink[]={0.93,0.54,0.44}, orange[]={1,0.1,0}, brown[]={185.0/255.0,122.0/255.0,87.0/255.0};
float crema[]={0.937,0.784,0.125};
float rufo[]={162.0/255, 18.0/255, 7.0/255};
float geranio[]={235.0/255.0, 40.0/255.0, 40.0/255.0};


void key(unsigned char key, int x, int y){
    switch (key) {
    case 27 : // tecla Esc
    case 'q': {
        exit(EXIT_SUCCESS); // Terminar la aplicación
        break;
        }
    }
    glutPostRedisplay();
}

void arbol(float *vr,float *ld,float *C,GLenum modo){
    glColor3fv(C);
    glBegin(modo);

    glVertex2d(vr[0],vr[1]);
    glVertex2d(vr[0]+ld[0],vr[1]);
    glVertex2d(vr[0]+ld[0],vr[1]+ld[1]);
    glVertex2d(vr[0],vr[1]+ld[1]);
    glEnd();

    glBegin(modo);
    glVertex2d(vr[0]+ld[0],vr[1]+ld[1]/6);
    glVertex2d(vr[0]+ld[0]+ld[1]/2,vr[1]+ld[1]/6);
    glVertex2d(vr[0]+ld[0]+ld[1]/2,vr[1]+4*ld[1]/20);
    glVertex2d(vr[0]+ld[0],vr[1]+4*ld[1]/20);
    glEnd();

    glBegin(modo);
    glVertex2d(vr[0]+ld[0],vr[1]+ld[1]/3);
    glVertex2d(vr[0]+ld[0]+ld[1]/3,vr[1]+ld[1]/3);
    glVertex2d(vr[0]+ld[0]+ld[1]/3,vr[1]+11*ld[1]/30);
    glVertex2d(vr[0]+ld[0],vr[1]+11*ld[1]/30);
    glEnd();
}

void circulo(float x,float y ,float r ,float *color, int mod,float Theta1,float Theta2){
    glColor3fv(color);
    switch (mod){
        case 1 : glBegin(GL_LINE_STRIP); break;
        case 2 : glBegin(GL_POLYGON); break;
    }

    for (float i = Theta1;i >= Theta2; i = i -0.01){
        glVertex2f(r*cos(i)+x,r*sin(i)+y);
    }
    glEnd();
}

void rama(){

    glColor3fv(green2);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(-0.58,0.15);
    glVertex2f(-0.5,0.07);
    glVertex2f(-0.5,0.04);
    glVertex2f(-0.54,0.19);
    glVertex2f(-0.48,0.15);
    glVertex2f(-0.52,0.24);
    glVertex2f(-0.45,0.21);
    glVertex2f(-0.46,0.31);
    glVertex2f(-0.41,0.28);
    glVertex2f(-0.45,0.35);
    glVertex2f(-0.38,0.32);
    glVertex2f(-0.42,0.4);
    glVertex2f(-0.35,0.36);
    glVertex2f(-0.39,0.45);
    glVertex2f(-0.44,0.23);
    glVertex2f(-0.53,0.24);
    glVertex2f(-0.29,0.41);
    glVertex2f(-0.21,0.55);
    glVertex2f(-0.29,0.41);
    glVertex2f(-0.31,0.51);
    glVertex2f(-0.31,0.39);
    glVertex2f(-0.35,0.49);
    glVertex2f(-0.34,0.37);
    glVertex2f(-0.37,0.48);
    glVertex2f(-0.34,0.37);
    glVertex2f(-0.2,0.4);
     glVertex2f(-0.36,0.34);
    glVertex2f(-0.2,0.38);
     glVertex2f(-0.4,0.3);
    glVertex2f(-0.21,0.36);
    glVertex2f(-0.44,0.24);
    glVertex2f(-0.33,0.27);
    glVertex2f(-0.49,0.1);
    glVertex2f(-0.38,0.13);
    glVertex2f(-0.48,0.13);
    glVertex2f(-0.37,0.17);
    glVertex2f(-0.49,0.08);
    glVertex2f(-0.41,0.11);

    glEnd();

    glColor3fv(green1);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(-0.5,0.04);
    glVertex2f(-0.39,0.09);
    glVertex2f(-0.5,0.06);
    glVertex2f(-0.56,0.15);
    glVertex2f(-0.48,0.13);
    glVertex2f(-0.54,0.21);
    glVertex2f(-0.44,0.23);
    glVertex2f(-0.52,0.33);
    glVertex2f(-0.46,0.2);
    glVertex2f(-0.54,0.28);
    glVertex2f(-0.49,0.1);
    glVertex2f(-0.41,0.13);
    glVertex2f(-0.48,0.14);
    glVertex2f(-0.36,0.19);

    glVertex2f(-0.47,0.18);
    glVertex2f(-0.33,0.24);

    glVertex2f(-0.46,0.2);
    glVertex2f(-0.32,0.27);

    glVertex2f(-0.44,0.24);
    glVertex2f(-0.31,0.3);

    glVertex2f(-0.43,0.26);
    glVertex2f(-0.29,0.33);

    glVertex2f(-0.41,0.28);
    glVertex2f(-0.5,0.38);

    glVertex2f(-0.39,0.31);
    glVertex2f(-0.47,0.42);

    glVertex2f(-0.37,0.34);
    glVertex2f(-0.45,0.44);

    glVertex2f(-0.33,0.38);
    glVertex2f(-0.42,0.48);

    glVertex2f(-0.3,0.4);
    glVertex2f(-0.35,0.51);

    glVertex2f(-0.29,0.41);
    glVertex2f(-0.17,0.48);

    glVertex2f(-0.29,0.41);
    glVertex2f(-0.2,0.5);
    glVertex2f(-0.29,0.41);
    glVertex2f(-0.19,0.51);

    glVertex2f(-0.3,0.4);
    glVertex2f(-0.2,0.42);

    glVertex2f(-0.35,0.36);
    glVertex2f(-0.23,0.39);
    glVertex2f(-0.38,0.32);
    glVertex2f(-0.23,0.38);
    glEnd();
    circulo(0,0,0.5,marron,1,M_PI,M_PI_2+0.6);
}

void ramas(){
    glTranslatef(0.5,-0.1,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();

    glTranslatef(-1,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();

    glTranslatef(-1,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(-0.8,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();

    glTranslatef(-0.8,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(-0.6,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();

    glTranslatef(-0.6,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(-0.4,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();

    glTranslatef(-0.4,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(-0.2,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();

    glTranslatef(-0.2,0.2,0.0);
    rama();
    glTranslatef(0,0.2,0.0);
    rama();
    glTranslatef(0,0.2,0.0);
    rama();

    glRotated(180,0,1,0);
    glTranslatef(1,-2.4,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();

    glTranslatef(-1,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();

    glTranslatef(-1,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(-0.8,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();

    glTranslatef(-0.8,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(-0.6,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();

    glTranslatef(-0.6,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(-0.4,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();

    glTranslatef(-0.4,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();
    glTranslatef(-0.2,0.2,0.0);
    rama();
    glTranslatef(0.2,0.0,0.0);
    rama();

    glTranslatef(-0.2,0.2,0.0);
    rama();
    glTranslatef(0,0.2,0.0);
    rama();
    glTranslatef(0,0.2,0.0);
    rama();
}

void estrella(){
    float A[]={0,0};

    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);

    glColor3fv(crema);
    glVertex2f(0.0, 0.0);

    glVertex2f (0.0, 5.0);

    glColor3fv(orange);
    glVertex2f(1.82, 2.5);

    glEnd();
/////////////
    glShadeModel (GL_SMOOTH);
    glBegin(GL_TRIANGLES);

    glColor3fv(crema);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 5.0);

    glColor3fv(orange);
    glVertex2f(-1.82, 2.5);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3fv(yellow);
    glVertex2f(0,0);
    glVertex2f(0,5);
    glEnd();
}

void estrella2(){
    estrella();
    glRotatef(72, 0, 0, 1);
    estrella();
    glRotatef(72, 0, 0, 1);
    estrella();
    glRotatef(72, 0, 0, 1);
    estrella();
    glRotatef(72, 0, 0, 1);
    estrella();
    glRotatef(72, 0, 0, 1);
    estrella();
}

void estrellas_amarillas(){
    glScalef(0.3,0.3,0.3);
    glRotatef(30, 0, 0, 1);
    glTranslatef(-25,-25,0.0);
    estrella2();

    glTranslatef(-50,-25,0.0);
    estrella2();

    glTranslatef(0,-30,0.0);
    estrella2();

    glTranslatef(10,-25,0.0);
    estrella2();

    glTranslatef(-25,-15,0.0);
    estrella2();

    glTranslatef(-30,-7,0.0);
    estrella2();

    glTranslatef(80,50,0.0);
    estrella2();

    glTranslatef(30,-5,0.0);
    estrella2();

    glTranslatef(-10,-50,0.0);
    estrella2();

    glTranslatef(-10,-50,0.0);
    estrella2();

    glTranslatef(-30,35,0.0);
    estrella2();
}

void baston(void){

    glColor3fv(white);
    glLineWidth(20);/*
    glBegin(GL_LINES);
    glVertex2f(0, -5);
    glVertex2f(0,0);
    glEnd();*/

    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -5);
    glVertex2f(-0.5,0);
    glVertex2f(+0.5,0);
    glVertex2f(+0.5,-5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    for(float i = 0 ; i <=M_PI/4 +0.1 ; i = i + 0.01){

        glVertex2f(-1.5 +2*cos(i) , 2*sin(i));
        glVertex2f(-1.5 +1*cos(i) , 1*sin(i));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-1.5 +1.5*cos(M_PI/4) , 1.5*sin(M_PI/4));
    for(float i = M_PI/4 ; i <=M_PI/2 +0.1 ; i = i + 0.01){

        glVertex2f(-1.5 +2*cos(i) , 2*sin(i));
        glVertex2f(-1.5 +1*cos(i) , 1*sin(i));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-1.5 +1.5*cos(M_PI/2) , 1.5*sin(M_PI/2));
    for(float i = M_PI/2 ; i <=3*M_PI/4 +0.1; i = i + 0.01){

        glVertex2f(-1.5 +2*cos(i) , 2*sin(i));
        glVertex2f(-1.5 +1*cos(i) , 1*sin(i));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-1.5 +1.5*cos(3*M_PI/4) , 1.5*sin(3*M_PI/4));
    for(float i = 3*M_PI/4 ; i <=M_PI +0.01; i = i + 0.01){

        glVertex2f(-1.5 +2*cos(i) , 2*sin(i));
        glVertex2f(-1.5 +1*cos(i) , 1*sin(i));
    }
    glEnd();
    /*
    glPointSize(20);
    glBegin(GL_POINTS);
    for(float i = 0 ; i <=M_PI ; i = i + 0.01){

        glVertex2f(-1.5 +1.5*cos(i) , 1.5*sin(i));
    }


    glEnd();*/
    glColor3fv(red);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,-3.2);
    glVertex2f(+0.5,-2.8);
    glVertex2f(+0.5,-3.8);
    glVertex2f(-0.5,-4.2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.5,-1.2);
    glVertex2f(+0.5,-0.8);
    glVertex2f(+0.5,-1.8);
    glVertex2f(-0.5,-2.2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.5, 0.3);
    glVertex2f(+0.5, 0.7);
    glVertex2f(+0.5, -0.3);
    glVertex2f(-0.5,-0.7);
    glEnd();

    glColor3fv(white);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, 0.2);
    glVertex2f(+0.5, 0.2);
    glVertex2f(+0.5, -0.3);
    glVertex2f(-0.5,-0.7);
    glEnd();


    glColor3fv(red);
    glBegin(GL_POLYGON);
    glVertex2f(-1.5 +1.5*cos(3*M_PI/4- M_PI/5) , 1.5*sin(3*M_PI/4 - M_PI/5));
    for(float i = 3*M_PI/4 - M_PI/5 ; i <=M_PI - M_PI/5 +0.01; i = i + 0.01){

        glVertex2f(-1.5 +2*cos(i) , 2*sin(i));
        glVertex2f(-1.5 +1*cos(i) , 1*sin(i));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-1.5 +1.5*cos(M_PI/4 - M_PI/5) , 1.5*sin(M_PI/4 - M_PI/5 ));
    for(float i = M_PI/4  - M_PI/5; i <=M_PI/2 - M_PI/5 +0.01; i = i + 0.01){

        glVertex2f(-1.5 +2*cos(i) , 2*sin(i));
        glVertex2f(-1.5 +1*cos(i) , 1*sin(i));
    }
    glEnd();

}

void bastones(){
    glScalef(3,4,3.5);

    glRotated(180,0,1,0);
    glTranslated(0,20,0);
    baston();

    glScalef(1.3,0.8,1);
    glRotated(180,0,1,0);
    glRotated(290,0,0,1);
    glTranslated(0,14,0);
    baston();

    glRotated(-30,0,0,1);
    glTranslated(38,-2,0);
    baston();

    glRotated(180,1,0,0);
    glRotated(180,0,1,0);
    glRotated(40,0,0,1);
    glTranslated(28,12,0);
    baston();
}

void catala(double *XY, float a, float b, float *Color, int M , int G){
    glColor3fv(Color);
    switch (M){
        case 1:{glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
        glPointSize(G);
        break;
        }
        case 2:{glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(G);
        break;
        }
        default:glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
    glBegin(GL_POLYGON);
    glVertex2dv(XY);
    for (float i=0;i<2*M_PI;i=i+0.0001){

        glVertex2f(XY[0]+(a - b) * cos(i) + b * cos(i * ((a / b) - 1)), XY[1]+(a - b) * sin(i) - b * sin(i * ((a / b) - 1)));
        glColor3fv(green2);
    glEnd;}
}

void Circunferencia(double *XY, float R, float *rgb, int M, float T){
    glColor3fv(rgb);
    switch (M) {
         case 2: {  glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
                    glPointSize(T);
                    break;
                  }
         case 3: {glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                  glLineWidth(T);
                  break;
                 }
        default: { glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                }
        }
    glBegin(GL_POLYGON);
    for (float i = 0; i <= 2*M_PI ; i = i + 0.05)
        glVertex2f(R*cos(i) + XY[0], R*sin(i) + XY[1]);
    glEnd();
}

void hojas(){
    for (int i = 0; i < 3; i++){
        double C10[] = { 0.2*cos(i*M_PI/2) , 0.2*sin(i*M_PI/2) };
           catala(C10, 0.32,0.04,  green, 0,2);
        }

for (int i = 0; i < 3; i++){
    double C5[] = { 0.05*cos(i*M_PI/2) , 0.05*sin(i*M_PI/2) };
            Circunferencia(C5, 0.04, red, 1, 128);
        }
}

void hojas2(){
    glScalef(9,9,9);
    glTranslated(0.7,-3.5,0);
    hojas();

    glRotated(-30,0,0,1);
    glTranslated(-1.2,1.8,0);
    hojas();

    glRotated(110,0,0,1);
    glTranslated(-2,1.5,0);
    hojas();

    glRotated(-40,0,0,1);
    glTranslated(1.2,2.2,0);
    hojas();
}

void circunferencia(float *XY, float r,float tetha1, float tetha2,float *C, float *C2, int M=1, int G=3){
    for(int j=1;j<=2;j=j+1){
        glColor3fv(C);
        switch(M)
        {
            case 2: {
                glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
                glPointSize(G);
                break;
            }
            case 3: {
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                glLineWidth(G);
                break;
            }
            default: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
        glBegin(GL_POLYGON);

        for (float i=tetha1; i<=tetha2;i=i+0.001)
        {
            glVertex2f((r*cos(i)+XY[0])*pow(-1,j),r*sin(i)+XY[1]);
            glColor3fv(C2);
        }
        glEnd();
    }
}

void bola1(float x, float y,float s1){
    glPushMatrix();
    glTranslated(x,y,0);
    glScaled(s1,s1,1);

    float a[]={0,0};
    float a1[]={-0.5,0};
    float a2[]={0,0.5};
    circunferencia(a, 1,0, 2*M_PI,red2,red, 1, 3);
    circunferencia(a1, 0.2,0, 2*M_PI,white,white, 1, 3);
    circunferencia(a2, 0.2,0, 2*M_PI,white,white, 1, 3);

    glPopMatrix();
}
void bola2(float x, float y,float s1){
    glPushMatrix();
    glTranslated(x,y,0);
    glScaled(s1,s1,1);

    float a[]={0,0};
    circunferencia(a,1,0,2*M_PI,orange,yellow2,1,3);

    glPopMatrix();
}

void esferas(){
    glPushMatrix();
    bola1(-0.7,8.5,0.5);
    bola2(1.2,8,0.5);
    bola1(0,6,0.5);
    bola2(2.5,3.8,0.5);
    bola1(2,2,0.5);
    bola2(1,-1,0.5);
    bola1(-3.3,1,0.5);
    bola2(3,-3.8,0.5);
    bola1(2,-2.5,0.5);
    bola1(2.5,-5,0.5);
    bola1(5.5,-1.5,0.5);
    bola1(7,-4,0.5);
    bola2(6,-5,0.5);
    bola1(4.5,-4.5,0.5);
    bola2(4,-6,0.5);
    bola2(8.5,-7,0.5);
    bola1(2.5,-8.5,0.5);
    bola2(-4.5,0,0.5);
    bola1(-1.7,-2,0.5);
    bola2(-3.5,-3,0.5);
    bola1(-1,-4.5,0.5);
    bola2(-5,-5,0.5);
    bola1(-7,-5.5,0.5);
    bola2(-8.5,-6.5,0.5);
    bola1(-8.3,-8.5,0.5);
    bola1(-3,-7,0.5);
    bola2(0.8,-4.7,0.5);
    glPopMatrix();
}

void triangulo(){
    glBegin(GL_TRIANGLES);
    glShadeModel(GL_SMOOTH);
    glColor3fv(rufo);
    glVertex2f(0,1.8);
    glColor3fv(rufo);
    glVertex2f(0,0);
    glColor3fv(geranio);
    glVertex2f(0.54,0.74);
    glEnd();
}

void procesos(){
    triangulo();
    glPushMatrix();
    glRotated(180,0,1,0);
    triangulo();
    glPopMatrix();
}

void estrellas_rojas(){
    glPushMatrix();
    glScalef(0.4,0.4,0.4);
    glTranslated(-0.5,6.5,0);
    glRotated(45,0,0,1);
    for(int i=0;i<5;i++){
        glPushMatrix();
        glRotated(72*i,0,0,1);
        procesos();
        glPopMatrix();
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4.2,-1.8,0);
    glScalef(0.4,0.4,0.4);
    glRotated(45,0,0,1);
    for(int i=0;i<5;i++){
        glPushMatrix();
        glRotated(72*i,0,0,1);
        procesos();
        glPopMatrix();
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3.2,-4.6,0);
    glScalef(0.4,0.4,0.4);
    glRotated(45,0,0,1);
    for(int i=0;i<5;i++){
        glPushMatrix();
        glRotated(72*i,0,0,1);
        procesos();
        glPopMatrix();
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4.5,-6.5,0);
    glScalef(0.4,0.4,0.4);
    glRotated(45,0,0,1);
    for(int i=0;i<5;i++){
        glPushMatrix();
        glRotated(72*i,0,0,1);
        procesos();
        glPopMatrix();
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-3,-9,0);
    glScalef(0.4,0.4,0.4);
    glRotated(45,0,0,1);
    for(int i=0;i<5;i++){
        glPushMatrix();
        glRotated(72*i,0,0,1);
        procesos();
        glPopMatrix();
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.5,-6.5,0);
    glScalef(0.4,0.4,0.4);
    glRotated(45,0,0,1);
    for(int i=0;i<5;i++){
        glPushMatrix();
        glRotated(72*i,0,0,1);
        procesos();
        glPopMatrix();
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(7,-6.2,0);
    glScalef(0.4,0.4,0.4);
    glRotated(45,0,0,1);
    for(int i=0;i<5;i++){
        glPushMatrix();
        glRotated(72*i,0,0,1);
        procesos();
        glPopMatrix();
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.8,-9.2,0);
    glScalef(0.4,0.4,0.4);
    glRotated(45,0,0,1);
    for(int i=0;i<5;i++){
        glPushMatrix();
        glRotated(72*i,0,0,1);
        procesos();
        glPopMatrix();
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(1,-3.3,0);
    glScalef(0.4,0.4,0.4);
    glRotated(45,0,0,1);
    for(int i=0;i<5;i++){
        glPushMatrix();
        glRotated(72*i,0,0,1);
        procesos();
        glPopMatrix();
    }
    glEnd();
    glPopMatrix();
}

void rectangulo(){
    glLineWidth(2.5);
    glBegin(GL_LINE_LOOP);
    glColor3fv(orange);
    glVertex2f(0,0);
    glVertex2f(0.4,0.4);
    glVertex2f(0.3,0.8);
    glVertex2f(0,0.5);
    glEnd();
}
//g++ arbol_navidad.cpp -lGL -lGLU -lglut -o ./arbol_navidad && ./arbol_navidad
void palito(){
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3fv(yellow);
    glVertex2f(0,0);
    glVertex2f(0,1.6);
    glEnd();
    glBegin(GL_LINES);
    glColor3fv(yellow);
    glVertex2f(0,1);
    glVertex2f(0.2,1.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3fv(yellow);
    glVertex2f(0,1.3);
    glVertex2f(0.2,1.5);
    glEnd();

    glRotated(180,0,1,0);
    glBegin(GL_LINES);
    glColor3fv(yellow);
    glVertex2f(0,0);
    glVertex2f(0,1.6);
    glEnd();
    glBegin(GL_LINES);
    glColor3fv(yellow);
    glVertex2f(0,1);
    glVertex2f(0.2,1.2);
    glEnd();
    glBegin(GL_LINES);
    glColor3fv(yellow);
    glVertex2f(0,1.3);
    glVertex2f(0.2,1.5);
    glEnd();
}

void procesos2(){
    rectangulo();
    glPushMatrix();
    glRotated(180,0,1,0);
    rectangulo();
    glPopMatrix();
}

void copos(){
    glPushMatrix();
    glTranslated(-0.3,0,0);
    glScalef(0.45,0.45,0.45);
    procesos2();
    palito();
    for(int i=0;i<4;i++){
    glRotated(90*i,0,0,1);
    procesos2();
    }
    glEnd();
    for(int i=0;i<8;i++){
    glRotated(45*i,0,0,1);
    palito();
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(4,-2.5,0);
    glScalef(0.45,0.45,0.45);
    procesos2();
    palito();
    for(int i=0;i<4;i++){
    glRotated(90*i,0,0,1);
    procesos2();
    }
    glEnd();
    for(int i=0;i<8;i++){
    glRotated(45*i,0,0,1);
    palito();
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-2.1,-3.5,0);
    glScalef(0.45,0.45,0.45);
    procesos2();
    palito();
    for(int i=0;i<4;i++){
    glRotated(90*i,0,0,1);
    procesos2();
    }
    glEnd();
    for(int i=0;i<8;i++){
    glRotated(45*i,0,0,1);
    palito();
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(1,-6.1,0);
    glScalef(0.45,0.45,0.45);
    procesos2();
    palito();
    for(int i=0;i<4;i++){
    glRotated(90*i,0,0,1);
    procesos2();
    }
    glEnd();
    for(int i=0;i<8;i++){
    glRotated(45*i,0,0,1);
    palito();
    }
    glEnd();
    glPopMatrix();
}

void glTranslatef(GLfloat x, GLfloat y, GLfloat z);

void glRotatef(GLfloat ang, GLfloat x, GLfloat y, GLfloat z);

void display(void){
glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
float c[]={0,-5},l[]={1,30};
    glLoadIdentity();
    gluLookAt (0, 0, 14, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    glTranslated(0,-20,0);
    arbol(c,l,marron,GL_POLYGON);

    glRotated(180,0,1,0);
    arbol(c,l,marron,GL_POLYGON);

    glScalef(15,15,15);
    ramas();

    //Estrellas principal
    glScalef(0.05,0.05,0.05);
    glTranslatef(-10,10,0.0);
    estrella2();

    //Estrellas amarillas
    estrellas_amarillas();

    //4 bastones
    bastones();

    //4 hojas
    hojas2();
    glPopMatrix();

    esferas();

    estrellas_rojas();

    copos();

    glFlush();
    glutSwapBuffers();
}

void reshape (int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-1.5, 1.5, -1.5, 1.5, 1.5, 20.0);
    glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    //glShadeModel(GL_FLAT);
    //glEnable(GL_DEPTH_TEST);
    glutInitWindowSize (750, 750);
    glutInitWindowPosition (1, 1);
    glutCreateWindow("Arbol de Navidad ");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}
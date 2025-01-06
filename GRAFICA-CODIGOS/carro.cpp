#ifdef __APPLE__
#include <GLUT/glut.h>
#else

#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<math.h>

double rotate_y = 0;
double rotate_x = 0;

void Linea(float *X0, float *X1, float *C, float A = 1, int f = 1, int P = 0)
{
    glColor3fv(C);
    glLineWidth(A);
    glEnable(GL_LINE_STIPPLE);
    switch (P){
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

void tornillo(){
        glColor3f(0,0,0);
        //float i=0;
        for(float i=M_PI/2; i<2*M_PI+M_PI/2; i+=72*M_PI/180){
            glBegin(GL_POLYGON);
                glVertex3d(0+0.3*cos(i),0.1+0.3*sin(i),0);
                glVertex3d(-0.1+0.3*cos(i),0.03+0.3*sin(i),0);
                glVertex3d(-0.06+0.3*cos(i),-0.08+0.3*sin(i),0);
                glVertex3d(0.06+0.3*cos(i),-0.08+0.3*sin(i),0);
                glVertex3d(0.1+0.3*cos(i),0.03+0.3*sin(i),0);
            glEnd();
        }

}

void circulo(){
    glColor3f(0.7,0.7,0.7);
    glBegin(GL_POLYGON);
        for(float i=0; i<2*M_PI; i+=0.001)
            glVertex3f(1.5*cos(i),1.5*sin(i),0);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        for(float i=0; i<2*M_PI; i+=0.001)
            glVertex3f(0.5*cos(i),0.5*sin(i),0);
    glEnd();

    glBegin(GL_POLYGON);
        for(float i=0; i<65*M_PI/180; i+=0.001)
            glVertex3d(1.3*cos(i),1.3*sin(i),0);

        for(float i=115*M_PI/180; i<M_PI; i+=0.001)
            glVertex3d(-0.8*cos(i),0.8*sin(i),0);
    glEnd();

    glBegin(GL_POLYGON);
        for(float i= 72*M_PI/180; i<137*M_PI/180 ; i+=0.001)
            glVertex3d(1.3*cos(i),1.3*sin(i),0);

        for(float i=43*M_PI/180; i<108*M_PI/180; i+=0.001)
            glVertex3d(-0.8*cos(i),0.8*sin(i),0);
    glEnd();

    glBegin(GL_POLYGON);
        for(float i=144*M_PI/180; i<202*M_PI/180 ; i+=0.001)
            glVertex3d(1.3*cos(i),1.3*sin(i),0);

        for(float i=-22*M_PI/180; i<36*M_PI/180 ; i+=0.001)
            glVertex3d(-0.8*cos(i),0.8*sin(i),0);
    glEnd();

    glBegin(GL_POLYGON);
        for(float i=209*M_PI/180; i<274*M_PI/180 ; i+=0.001)
            glVertex3d(1.3*cos(i),1.3*sin(i),0);

        for(float i=-94*M_PI/180; i<-29*M_PI/180 ; i+=0.001)
            glVertex3d(-0.8*cos(i),0.8*sin(i),0);
    glEnd();

    glBegin(GL_POLYGON);
        for(float i=281*M_PI/180; i<353*M_PI/180 ; i+=0.001)
            glVertex3d(1.3*cos(i),1.3*sin(i),0);

        for(float i=-173*M_PI/180; i<-101*M_PI/180 ; i+=0.001)
            glVertex3d(-0.8*cos(i),0.8*sin(i),0);
    glEnd();

    tornillo();
}

void Ejes(int c){
    float P[]={-20.0,0.0,0.0} , P1[]={20.0,0.0,0.0};
    float P2[]={0.0,-20.0,0.0}, P3[]={0.0,20.0,0.0};
    float P4[]={0.0,0.0,-20.0} , P5[]={0.0,0.0,20.0};
    float C1[]={1,0,0}, C2[]={0,0,1}, C3[]={0,1,0};
    switch (c){ // linea punteada
    case 0:{
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

void Rueda(){
    glColor3f(0.03,0.01,0.031);
    glEnable(GL_COLOR_MATERIAL);
    glutSolidTorus(0.6,1.5,50,50);
}

void techo(){

    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        glVertex3d(5,3.7,3);
        glVertex3d(5,3.7,-3);
        glVertex3d(-5,3.7,-3);
        glVertex3d(-5,3.7,3);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex3d(5,4,3);
        glVertex3d(5,3.7,3);
        glVertex3d(5,3.7,-3);
        glVertex3d(5,4,-3);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex3d(5,4,-3);
        glVertex3d(5,3.7,-3);
        glVertex3d(-5,3.7,-3);
        glVertex3d(-5,4,-3);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex3d(-5,4,3);
        glVertex3d(-5,3.7,3);
        glVertex3d(5,3.7,3);
        glVertex3d(5,4,3);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex3d(-5,4,-3);
        glVertex3d(-5,3.7,-3);
        glVertex3d(-5,3.7,3);
        glVertex3d(-5,4,3);
    glEnd();

    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        glVertex3d(5,4,3);
        glVertex3d(5,4,-3);
        glVertex3d(-5,4,-3);
        glVertex3d(-5,4,3);
    glEnd();

}

void punto(){
    glColor3d(0,0,0);
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex3d(-10,1,4);
        glVertex3d(-10,-1,4);
        glVertex3d(10,-1,4);
        glVertex3d(10,1,4);
    glEnd();
}

void cuerpo(){

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(10,-1,4);
        glVertex3f(10,-1,-4);
        glVertex3f(-10,-1,-4);
        glVertex3f(-10,-1,4);
    glEnd();
    glColor3f(0,0,1);
    /////////////////////
    glBegin(GL_POLYGON);
        glVertex3f(10,1,4);
        glVertex3f(10,-1,4);
        glVertex3f(10,-1,-4);
        glVertex3f(10,1,-4);
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
        glVertex3d(10,1,-4);
        glVertex3d(10,-1,-4); //ok
        glVertex3d(-10,-1,-4);
        glVertex3d(-10,1,-4);
    glEnd();
    /////////////////

    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
        glVertex3d(-10,1,4);
        glVertex3d(-10,-1,4);
        glVertex3d(10,-1,4);  // ok
        glVertex3d(10,1,4);
    glEnd();

    ////////////////////

    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
        glVertex3d(-10,1,-4);
        glVertex3d(-10,-1,-4);
        glVertex3d(-10,-1,4); // ok
        glVertex3d(-10,1,4);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex3d(10,1,4);
        glVertex3d(10,1,-4);
        glVertex3d(-10,1,-4);
        glVertex3d(-10,1,4);
    glEnd();

}

void cilindro(){
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    glColor3f(0.8,0.8,0.8);
    gluCylinder(quadratic,0.2,0.2,2.8,20,30);
}

void cilindro2(){
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    glColor3f(0.4,0.4,0.4);
    gluCylinder(quadratic,0.4,0.4,1,20,30);
}



void carro() {

        glPushMatrix();
    glTranslated(5,0,-5);
    cilindro2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5,0,-5);
    cilindro2();
    glPopMatrix();


    ////////////////////////////////////

    glPushMatrix();
    glTranslated(5,0,-5);
    Rueda();
    glTranslated(0,0,-0.3);
    circulo();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5,0,-5);
    Rueda();
    glTranslated(0,0,-0.3);
    circulo();
    glPopMatrix();

    //punto();

    cuerpo();

    /////////////////////////////////7
    glPushMatrix();
    glRotatef(90,1,0,0);
    glTranslated(4,2,-3.7);
    cilindro();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,1,0,0);
    glTranslated(4,-1,-3.7);
    cilindro();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,1,0,0);
    glTranslated(-4,2,-3.7);
    cilindro();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,1,0,0);
    glTranslated(-4,-1,-3.7);
    cilindro();
    glPopMatrix();
    /////////////////////////////////
        glPushMatrix();
    techo();
    glPopMatrix();



    glPushMatrix();
    glTranslated(5,0,4);
    cilindro2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5,0,4);
    cilindro2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(5,0,5);
    Rueda();
    glTranslated(0,0,0.3);
    circulo();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5,0,5);
    Rueda();
    glTranslated(0,0,0.3);
    circulo();
    glPopMatrix();
}




void Display(void)
{

glClearColor(1,1,1,0);//color el cual se limpia la ventana
glClear(GL_COLOR_BUFFER_BIT);//limpia la ventana
glLoadIdentity();
gluLookAt (15, 15 , 15, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
Ejes(1);

glRotatef(rotate_x,1,0,0);
glRotatef(rotate_y,1,0,0);

float color[3]={1,1,0}, blanco[3]={1,1,1}, celeste[3]={0,1,1}, morado[3] = {1,0,1}, negro[3]={0,0,0}, verde[3]={0,0.8,0.23}, oro[3]={1,0.84,0}, marron[3]={0.5,0.25,0}, sombra[3]={0.3,0.3,0.3},rojo[3]={1,0,0};

carro();


glFlush();// se asegura de dibujar los comando en vez de alamcenarlos
glutSwapBuffers();

}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-8, 8, -8, 8, 8, 60.0);
    glMatrixMode (GL_MODELVIEW);
}

void specialKeys(int key, int x, int y){
    if(key == GLUT_KEY_RIGHT) {rotate_y += 10;}

    if(key == GLUT_KEY_LEFT) {rotate_y -= 5;}

    if(key == GLUT_KEY_UP) {rotate_x += 10;}

    if(key == GLUT_KEY_DOWN) {rotate_x -= 5;}

    glutPostRedisplay();
}


int main (int argc,char** argv)
{
    //funcion glut para la inicializacion de la ventana
    glutInit(&argc,argv);//inicializamos
    glutInitWindowSize(700,700);// tamanio de la ventana
    glutInitWindowPosition(40,40);//posicionde la ventana
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Computacion Grafica");// crea la venta con nombre

    //funcion glut para el manejo de eventos
    glutDisplayFunc(Display);// evento de renderizado

    glutSpecialFunc(specialKeys);

    glutReshapeFunc(reshape);
    // inicializacion del bucle indefinido de eventos

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-20,20,-20,20);
    glutMainLoop();


    return EXIT_SUCCESS;
}
//g++ carro.cpp -lGL -lGLU -lglut -o ./carro && ./carro
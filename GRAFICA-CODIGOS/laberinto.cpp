#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <cmath>

float blue[]={0,0,1};
float green[]={0,0.5,0};
float orange[]={0.9,0.6,0.1};
float cyan[]={0,1,1};
float red[]={1,0,0};
float yellow[]={1,1,0};
float purple[]={1,0,1};
float white[]={1,1,1};
float black[]={0,0,0};
float brown[]={0.5,0.35,0.05};

float tX = -80;
float tY = 50;
float tAng = 0;
float escala = 1;

void inicio()
{
    glMatrixMode(GL_PROJECTION);
    float a=900;
    float b=1000;
    gluOrtho2D(-a,a,-b,b);
    glClearColor(1,1,1,1);
}

void linea(float *V1, float *V2, float *C, float G)
{
    glColor3fv(C);
    glLineWidth(G);
    glBegin(GL_LINES);

    glVertex2d(V1[0],V1[1]);
    glVertex2d(V2[0],V2[1]);

    glEnd();
}

void mariposa (float *XY, float *c, float R)
{
    glBegin(GL_POLYGON);

    for(float i=0; i<7*M_PI/16;i=i+0.001 )
    {
        float r=2*(exp(cos(i))-(2*cos(4*i))-pow((sin(i/12)),5));
        float  x=sin(i)*r*R;
        float y=r*cos(i)*R;
        glColor3fv(c);
        glVertex2f(x+XY[0],y+XY[1]);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(c);
    for(float i=7*M_PI/16; i<9.5*M_PI/16;i=i+0.001 )
        {
      float  r=2*(exp(cos(i))-(2*cos(4*i))-pow((sin(i/12)),5));
      float  x=sin(i)*r*R;
        float y=r*cos(i)*R;
        glVertex2f(x+XY[0],y+XY[1]);
        }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(c);
    for(float i=9.5*M_PI/16; i<14*M_PI/16;i=i+0.001 ){

      float  r=2*(exp(cos(i))-(2*cos(4*i))-pow((sin(i/12)),5));

      float  x=sin(i)*r*R;
      float  y=r*cos(i)*R;

      glVertex2f(x+XY[0],y+XY[1]);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(c);
       for(float i=9.5*M_PI/16; i<13.8*M_PI/16;i=i+0.001 ){
       float r=2*(exp(cos(i))-(2*cos(4*i))-pow((sin(i/12)),5));
       float x=-sin(i)*r*R;
        float y=r*cos(i)*R;
        glVertex2f(x+XY[0],y+XY[1]);
        }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3fv(c);
    for(float i=7*M_PI/16; i<9.5*M_PI/16;i=i+0.001 )
    {
        float  r=2*(exp(cos(i))-(2*cos(4*i))-pow((sin(i/12)),5));
        float  x=-sin(i)*r*R;
        float  y=r*cos(i)*R;

        glVertex2f(x+XY[0],y+XY[1]);
    }

    glEnd();
    glBegin(GL_POLYGON);
    glColor3fv(c);

    for(float i=0; i<6.8*M_PI/16;i=i+0.001 )
    {
    float r=2*(exp(cos(i))-(2*cos(4*i))-pow((sin(i/12)),5));
    float x=-sin(i)*r*R;
    float y=r*cos(i)*R;
    glVertex2f(x+XY[0],y+XY[1]);
    }

    glEnd();
    glBegin(GL_POLYGON);
    glColor3fv(c);

    for(float i=14.2*M_PI/16; i<17.7*M_PI/16;i=i+0.001)
    {
    float r=2*(exp(cos(i))-(2*cos(4*i))-pow((sin(i/12)),5));
    float x=sin(i)*r*R;
    float y=r*cos(i)*R;
    glVertex2f(x+XY[0],y+XY[1]);
    }

    glEnd();
}

static void key(unsigned char key, int x, int y)
{
    float paso = 1;

    switch(key)
    {
    case 'a':
    case 'A':
        tX -= paso;
        break;
    case 'd':
    case 'D':
        tX += paso;
        break;
    case 'w':
    case 'W':
        tY += paso;
        break;
    case 's':
    case 'S':
        tY -= paso;
        break;
    case 'q':
    case 'Q':
        tAng += M_PI*2;
        break;
    case '+':
        if (escala <= 3) {
            escala += .5;
        }
        break;
    case '-':
        if (escala >= 1) {
            escala -= .5;
        }
        break;
    }
    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho(-100,100,-100*h/w,100*h/w,-1,1);
    glMatrixMode(GL_MODELVIEW);
}

void display (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,0,0);
    float A[] = {-80,-40};
    float B[] = {80,-40};
    float C1[] = {80,60};
    float D[] = {-80,60};
    float E[] = {-80,40};
    float F[] = {80,-20};
    float G[] = {-60,40};
    float H[] = {-60,-20};
    float I[] = {-40,0};
    float J[] = {-60,-20};
    float K[] = {40,-20};
    float L[] = {60,40};

    float M[] = {60,-40};
    float N[] = {-20,40};
    float R[] = {0,40};
    float O[] = {-20,20};
    float P[] = {20,20};
    float QQ[] = {0,0};

    
    
    float S[] = {20,40};
    float T[] = {-40,60};
    float U[] = {-40,0};

    float LL[] = {20,20};
    float MM[] = {20,-20};

    float AA[] = {-20,0};
    float BB[] = {20,0};

    linea(AA,BB,black,3);
    float a1 = AA[1]-6;
    if (tX >= AA[0]-5 and tX <= BB[0]+4)
    {
        if (tY >= a1 and tY <= a1+5) {
            tY = a1;
        } else if (tY >= a1+6 and tY <= a1+10) {
            tY = a1+10;
        }
    }

    linea(D,C1,black,3);
    linea(C1,F,black,3);
    linea(B,A,black,3);
    linea(A,E,black,3);

    linea(K,J,black,3);
    float a = J[1]-6;
    if (tX >= J[0]-5 and tX <= K[0]+4)
    {
        if (tY >= a and tY <= a+5) {
            tY = a;
        } else if (tY >= a+6 and tY <= a+10) {
            tY = a+10;
        }
    }
    
    
    linea(H,G,black,3);
    float g1 = H[0]-6;
    if (tY >= H[1]-5 and tY <= G[1]+4)
    {
        if (tX >= g1 and tX <= g1+5) {
            tX = g1;
        } else if (tX >= g1+6 and tX <= g1+10) {
            tX = g1+10;
        }
    }

    linea(LL,MM,black,3);
    float gg1 = MM[0]-6;
    if (tY >= MM[1]-5 and tY <= LL[1]+4)
    {
        if (tX >= gg1 and tX <= gg1+5) {
            tX = gg1;
        } else if (tX >= gg1+6 and tX <= gg1+10) {
            tX = gg1+10;
        }
    }

   // linea(I,U,green,3);

    
    linea(N,L,black,3);
    float f1 = N[1]-6;
    if (tX >= N[0]-5 and tX <= L[0]+4)
    {
        if (tY >= f1 and tY <= f1+5) {
            tY = f1;
        } else if (tY >= f1+6 and tY <= f1+10) {
            tY = f1+10;
        }
    }
    
    linea(N,O,black,3);
    float h1 = O[0]-6;
    if (tY >= O[1]-5 and tY <= N[1]+4)
    {
        if (tX >= h1 and tX <= h1+5) {
            tX = h1;
        } else if (tX >= h1+6 and tX <= h1+11) {
            tX = h1+11;
        }
    }


    linea(T,U,black,3);
    float k1 = U[0]-6;
    if (tY >= U[1]-5 and tY <= T[1]+4)
    {
        if (tX >= k1 and tX <= k1+5) {
            tX = k1;
        } else if (tX >= k1+6 and tX <= k1+11) {
            tX = k1+11;
        }
    }
    linea(L,M,black,3);
    float n1 = M[0]-6;
    if (tY >= M[1]-5 and tY <= L[1]+4)
    {
        if (tX >= n1 and tX <= n1+5) {
            tX = n1;
        } else if (tX >= n1+6 and tX <= n1+11) {
            tX = n1+11;
        }
    }

    //linea(A25,A26,red,3);

    float C[] = {0,0};
    glPushMatrix();
    glTranslated(tX,tY,0);
    glRotated(tAng,0,0,1);
    glScaled(escala,escala,1);
    mariposa(C,red,1);
    mariposa(C,yellow,0.7);
    mariposa(C,cyan,0.5);
    mariposa(C,green,0.3);
    glPopMatrix();

    float d = 80;
    float x = 5;
    if (tX >= d-x ) tX = d-x;
    if (tX <= -d) tX = -d+x;
    float b = 50;
    float c = 10;
    if (tY >= b) tY = b;
    if (tY <= -b+c) tY = -b+c;

    //gluLookAt (10, 10, 15.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0);

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,600); //Tamaño de la ventana
    glutInitWindowPosition(100,1); //Posición de la ventana
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Laberinto con Mariposa");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    inicio();
    glutMainLoop();

    return EXIT_SUCCESS;
}
//g++ laberinto.cpp -lGL -lGLU -lglut -o ./laberinto && ./laberinto
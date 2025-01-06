//#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

static int spin = 0;

float rufo[]={162.0/255, 18.0/255, 7.0/255};
float geranio[]={235.0/255.0, 40.0/255.0, 40.0/255.0};

float crema[]={0.937,0.784,0.125};
float blue[] = {0, 0, 1};
float green[] = {0, 0.5, 0};
float orange[] = {0.9, 0.6, 0.1};
float cyan[] = {0, 1, 1};
float red[] = {1, 0, 0};
float yellow[] = {1, 1, 0};
float purple[] = {1, 0, 1};
float white[] = {1, 1, 1};
float black[] = {0, 0, 0};
float brown[] = {0.5, 0.35, 0.05};

void init(void)
{
    glClearColor(0, 0, 0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
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

void display(void)
{
    GLfloat position[] = {-1.0, 0.0, 1.5, 0.8}; // Iluminación del sol

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -6.0);

    // Sol
    glPushMatrix();
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glTranslated(-3.8, 0.0, 1.5);
    glDisable(GL_LIGHTING);
    glColor3fv(yellow);
    glutSolidSphere(1.5, 50, 45);
    glEnable(GL_LIGHTING);
    glPopMatrix();

    // LUNA
    glRotated((GLdouble)spin, 0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslated(-1.0, 0.0, 1.5);
    glDisable(GL_LIGHTING);
    glColor3fv(blue);
    glutSolidSphere(0.5, 30, 20);
    glEnable(GL_LIGHTING);
    glPopMatrix();

    // PLANETA /////////////////////////////
    if (abs(spin % 360) < 10 || abs(spin % 360) > 350) {
        // Si el sol y la luna están alineados (dentro del rango de ángulos), cancelar la iluminación del sol
        glDisable(GL_LIGHT0);
    } else {
        glEnable(GL_LIGHT0);
    }

    glPushMatrix();
    glColor3fv(cyan); // Color celeste para el planeta Tierra
    glutSolidSphere(1.0, 30, 16);
    glPopMatrix();
    ////////////////////////////////////////
    glPopMatrix();

   //Estrellas principal
    glScalef(0.05,0.05,0.05);
    glTranslatef(-10,10,0.0);
    estrella2();


    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a': // Especifica la tecla 'a'
        spin = (spin + 10) % 360;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1800, 900);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

// g++ pruebas.cpp -lGL -lGLU -lglut -o ./pruebas && ./pruebas
// 
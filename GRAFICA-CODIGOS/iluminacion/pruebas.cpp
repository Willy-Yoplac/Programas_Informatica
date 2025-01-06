#include <GL/glut.h>
#include <math.h> // sirve para utilizar funciones matematicas
static int spin = 0;

void init(void)
{
    glClearColor(0, 1, 0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}
// Variables para la estrella
GLfloat star_position[] = {2.0, 2.5, 1.0, 1.0};
GLfloat star_color[] = {1.0, 1.0, 1.0};

void drawStar()
{
    const float PI = 3.14159265358979323846;
    const float angle = 2 * PI / 5; // Ángulo entre cada punta de la estrella

    glBegin(GL_POLYGON);
    for (int i = 0; i < 5; ++i)
    {
        float x = sin(i * angle);
        float y = cos(i * angle);
        glVertex2f(x, y);
    }
    glEnd();
}
/*
void drawStar()
{
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.7);
    glVertex2f(0.2, 0.3);
    glVertex2f(0.6, 0.2);
    glVertex2f(0.3, 0.0);
    glVertex2f(0.4, -0.5);
    glVertex2f(0.0, -0.3);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.4, 0.0);
    glVertex2f(-0.7, 0.2);
    glVertex2f(-0.2, 0.3);
    glVertex2f(0.0, 0.7);
    glEnd();
}*/


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
    glColor3f(1.0, 1.0, 0.0); // Color amarillo para el sol
    glutSolidSphere(1.5, 50, 45);
    glEnable(GL_LIGHTING);
    glPopMatrix();

    // LUNA
    glRotated((GLdouble)spin, 0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslated(-1.0, 0.0, 1.5);
    glDisable(GL_LIGHTING);
    glColor3f(0.3, 0.3, 0.3); // Color azul para la luna
    glutSolidSphere(0.5, 60, 60);
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
    // Configuración del material del planeta
    GLfloat planet_diffuse[] = {0.0, 0.6, 1.0}; // Color celeste para el planeta Tierra
    GLfloat planet_specular[] = {1.0, 1.0, 1.0, 1.0}; // Componente especular blanco para el brillo
    GLfloat planet_shininess[] = {100.0}; // Brillo del material

    glMaterialfv(GL_FRONT, GL_DIFFUSE, planet_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, planet_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, planet_shininess);
    
    glutSolidSphere(1.0, 60, 60);
    glPopMatrix();
    ////////////////////////////////////////

    // ESTRELLA ///////////////////////////////
    glPushMatrix();
    glTranslatef(star_position[0], star_position[1], star_position[2]);
    glDisable(GL_LIGHTING);
    glColor3fv(star_color);
    drawStar(); // Dibuja la estrella usando la función personalizada drawStar
    glEnable(GL_LIGHTING);
    glPopMatrix();
    //////////////////////////////////////////

    glPopMatrix();
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
        spin = (spin + 6) % 360;
        glutPostRedisplay();
        break;
    case 's': // Especifica la tecla 's'
        star_position[1] -= 0.2; // Mueve la estrella hacia arriba
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
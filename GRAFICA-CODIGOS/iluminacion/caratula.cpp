#include <GL/glut.h>

// Colores           --------- CARATULA --------
float cyan[]={0,0.8,0.8};
float red[]={1,0,0};
float green[]={0,0.9,0.1};
float black[]={0,0,0};
float white[]={1,1,1};

void representaLetra(const char* str, float x, float y, void* fondo)
{
    glRasterPos2f(x, y);
    while (*str)
    {
        glutBitmapCharacter(fondo, *str);
        str++;
    }
}

void Titulo()
{
    glColor3fv(white); 
    representaLetra("UNIVERSIDAD NACIONAL MAYOR DE SAN MARCOS", -0.75, 0.5, GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3fv(white); 
    representaLetra("Universidad del Peru. Decana de America", -0.55, 0.4, GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3fv(red); 
    representaLetra("Simulacion de un Eclipse", -0.35, 0.25, GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3fv(red);
    representaLetra("Protector de Pantalla DVD", -0.35, 0.15, GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3fv(green); 
    representaLetra("Integrantes:", -0.2, -0, GLUT_BITMAP_HELVETICA_18);
    
    glColor3fv(white); 
    representaLetra("Castillo Melchor Julios Deciderio", -0.35, -0.1, GLUT_BITMAP_HELVETICA_18);
    representaLetra("Yoplac Tejada Willy Jovan", -0.3, -0.2, GLUT_BITMAP_HELVETICA_18);

}

void dibuja()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Titulo();

    glFlush();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition (520, 100);
    glutCreateWindow("PROYECTO FINAL - COMPUTACION GRAFICA");
    glClearColor(0, 0, 0, 0.0); // Fondo negro

    glutDisplayFunc(dibuja);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}

// g++ caratula.cpp -lGL -lGLU -lglut -o ./caratula && ./caratula
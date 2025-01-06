// Libreriaa
#include <GL/glut.h>
//sirve para utilizar la funcion gluSphere
#include <cstdlib> // Para generar números aleatorios
#include <vector>  // se utiliza para incluir la biblioteca estándar de contenedores

// Colores:
float yellow[] = {1, 1, 0};
float white[]={1,1,1};
float cyan[]={0,0.8,0.8};
float green[]={0,0.9,0.1};

// Tamaño de la ventana
const int ancho = 1800;
const int alto = 900;

// Estructura para almacenar información de las estrellas
struct estrella {
    float x, y, z;
};

// Vector para almacenar todas las estrellas
std::vector<estrella> stars; // variable que va ha contener todas las estrellas

// Valor para el spin del eclipse (angulo de rotacion de la eclipse)
static int spin = 0;

// Función para inicializar las estrellas
void EstrellasAleatorias(int numEstrella) {
    stars.clear();
    for (int i = 0; i < numEstrella; ++i) {
        estrella star;
        star.x = static_cast<float>(rand() % ancho) - (ancho / 2);
        star.y = static_cast<float>(rand() % alto) - (alto / 2);
        star.z = static_cast<float>(rand() % 500) + 1; // Profundidad en el espacio
        stars.push_back(star);
    }
}

// Función de dibujo
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // Posicion de la camara
    glLoadIdentity();

    // Dibujar las estrellas
    glColor3fv(white);
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    for (const auto& star : stars) {
        glVertex3f(star.x, star.y, -star.z); // Negamos la coordenada z para "acercar" las estrellas
    }
    glEnd();

    // Dibujar el eclipse
    glPushMatrix();
    glTranslatef(0.0, 0.0, -6.0);

    // Sol
    glPushMatrix();
    GLfloat position[] = {-1.0, 0.0, 1.5, 0.8}; // Iluminación del sol
    
    // configurar la posición de una luz
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
    glColor3f(0.3, 0.3, 0.3); // Color gris para la luna
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

    glPopMatrix();
k
    glFlush();
    glutSwapBuffers();
}

// Función para cambiar el tamaño de la ventana
void reshape(int width, int height) {
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, static_cast<double>(width) / static_cast<double>(height), 1.0, 1000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 500.0,  // Posición de la cámara
              0.0, 0.0, 0.0,    // Punto de mira
              0.0, 1.0, 0.0);   // Vector de arriba
}

// Función para actualizar la posición de la luna
void actualizar(int value) {
    spin = (spin + 1) % 360;
    glutPostRedisplay();
    glutTimerFunc(25, actualizar, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(ancho, alto);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("ECLIPSE SOLAR - COM. GRAFICA");
    glEnable(GL_DEPTH_TEST);

    // Inicializamos las estrellas
    EstrellasAleatorias(1000); // Puedes ajustar el número de estrellas

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(25, actualizar, 0);

    // Habilitar la luz GL_LIGHT1 para las estrellas
    glEnable(GL_LIGHT1);
    GLfloat star_position[] = {0.0, 0.0, 1.0, 0.0}; // Posición de la luz de las estrellas
    glLightfv(GL_LIGHT1, GL_POSITION, star_position);
    GLfloat star_ambient[] = {1.0, 1.0, 1.0, 1.0}; // Luz ambiental para las estrellas
    glLightfv(GL_LIGHT1, GL_AMBIENT, star_ambient);
    GLfloat star_diffuse[] = {1.0, 1.0, 1.0, 1.0}; // Luz difusa para las estrellas
    glLightfv(GL_LIGHT1, GL_DIFFUSE, star_diffuse);

    glutMainLoop();
    return 0;
}


// g++ eclipse.cpp -lGL -lGLU -lglut -o ./eclipse && ./eclipse
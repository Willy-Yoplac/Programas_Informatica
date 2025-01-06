#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

static int spin = 0;

float blue[] = {0,0,1};
float green[]={0,0.5,0};
float orange[]={0.9,0.6,0.1};
float cyan[]={0,1,1};
float red[]={1,0,0};
float yellow[]={1,1,0};
float purple[]={1,0,1};
float white[]={1,1,1};
float black[]={0,0,0};
float brown[]={0.5,0.35,0.05};

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}

/*  Here is where the light position is reset after the modeling
 *  transformation (glRotated) is called.  This places the
 *  light at a new position in world coordinates.  The cube
 *  represents the position of the light.
 */
void display(void)
{
   GLfloat position[] = { 0.0, 0.0, 1.5, 1.0 };

   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glPushMatrix ();
   glTranslatef (0.0, 0.0, -5.0);

   glPushMatrix ();
   glRotated ((GLdouble) spin, 1.0, 0.0, 0.0);
   glLightfv (GL_LIGHT0, GL_POSITION, position);

   glTranslated (0.0, 0.0, 1.5);
   glDisable (GL_LIGHTING);
   glColor3fv (yellow);
   glutSolidSphere (0.1,15,10);   //
   glEnable (GL_LIGHTING);
   glPopMatrix ();


   glutSolidSphere (1.0, 30, 16);

   glPopMatrix ();
   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN) {
            spin = (spin + 10) % 360;
            glutPostRedisplay();
         }
         break;
      default:
         break;
   }
}

// iluminacion y textura
const GLfloat light_ambient[] = {.3f, .3f, .3f, 1.0f};
const GLfloat light_diffuse[] = {.5f, .5f, .5f, 1.0f};
const GLfloat light_specular[] = {2.0f, 2.0f, 2.0f, 1.0f};
const GLfloat light_position[] = {2.0f, -4.0f, 2.0f, 0.0f};

const GLfloat mat_ambient[] = {0.5f, 0.5f, 0.5f, 1.0f};
const GLfloat mat_diffuse[] = {0.5f, 0.5f, 0.5f, 1.0f};
const GLfloat mat_specular[] = {2.0f, 2.0f, 2.0f, 1.0f};
const GLfloat high_shininess[] = {100.0f};

//

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMouseFunc(mouse);

   // para la iluminacion 
       glCullFace(GL_BACK); ///descarta caras posteriores

    glEnable(GL_DEPTH_TEST); ///permite prueba de profundidad
    glDepthFunc(GL_LESS); ///prueba de profundidad

    glEnable(GL_LIGHT0); ///activacion de luz difusa y ambiental
    glEnable(GL_NORMALIZE); ///+ precision en iluminacion y sombreado
   // glEnable(GL_COLOR_MATERIAL); ///determina el material para reflejar el color
    glEnable(GL_LIGHTING); ///iluminacion en escena

   glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

// 
   glutMainLoop();
   return 0;
}

//g++ iluminacion2.cpp -lGL -lGLU -lglut -o ./iluminacion2 && ./iluminacion2
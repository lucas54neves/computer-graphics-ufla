#include <GL/glut.h>
#include <stdlib.h>

float rotationRateXAxis = 0.0;
float rotationRateYAxis = 0.0;
float rotationRateZAxis = 0.0;

void init(void) {
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}

void display(void) {
   GLdouble eqn0[4] = {0.0, -1.0, 0.0, 1.0};
   GLdouble eqn1[4] = {0.0, 1.0, 0.0, 1.0};
   GLdouble eqn2[4] = {1.0, 0.0, 0.0, 1.0};
   GLdouble eqn3[4] = {-1.0, 0.0, 0.0, 1.0};

   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(1.0, 1.0, 1.0);
   glPushMatrix();
      glTranslatef(0.0, 0.0, -5.0);
      glRotatef(rotationRateXAxis, 1.0, 0.0, 0.0);
      glRotatef(rotationRateYAxis, 0.0, 1.0, 0.0);
      glRotatef(rotationRateZAxis, 0.0, 0.0, 1.0);

      glClipPlane(GL_CLIP_PLANE0, eqn0);
      glEnable(GL_CLIP_PLANE0);

      glClipPlane(GL_CLIP_PLANE1, eqn1);
      glEnable(GL_CLIP_PLANE1);

      glClipPlane(GL_CLIP_PLANE2, eqn2);
      glEnable(GL_CLIP_PLANE2);

      glClipPlane(GL_CLIP_PLANE3, eqn3);
      glEnable(GL_CLIP_PLANE3);

      glutWireSphere(2.0, 40, 32);
   glPopMatrix();

   glFlush();
}

void reshape(int w, int h) {
   glViewport(0, 0,(GLsizei) w,(GLsizei) h); 
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0,(GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
   switch(key) {
      case 27:
         exit(0);
         break;
      case 'x':
         rotationRateXAxis += 1;
         break;
      case 'y':
         rotationRateYAxis += 2;
         break;
      case 'z':
         rotationRateZAxis += 3;
         break;
   }
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(500, 500); 
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
	glutIdleFunc(display);
   glutMainLoop();
   return 0;
}

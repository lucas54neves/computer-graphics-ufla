// Bibliotecas
#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>

// Constantes globais
GLfloat ratio;
static int anguloHorizontal = 0, anguloVertical = 0;
static int segmento1 = 0, segmento2 = 0, segmento3 = 0;
static int dedo1 = 0, dedo2 = 0, dedo3 = 0;

// Inicializa os parametros globais de OpenGL
void init(void) {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glShadeModel(GL_SMOOTH);						
   glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_CULL_FACE);	
   glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);

   // Luz Ambiente
   float globalAmb[] = { 0.1f, 0.1f, 0.1f, 1.f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmb);

   // Primeira Luz
   glEnable(GL_LIGHT0);

   float light0[4][4] = {
      // Ambiente
      {0.1f, 0.1f, 0.1f, 1.f},
      // Difusa
      {0.8f, 0.8f, 0.8f, 1.f},
      // Especular
      { 1.f,  1.f,  1.f, 1.f },
      // Positicao
      {0.f, 0.f, 1.f, 1.f}
   };

   // Luz, Caracteristica, Endereco da primeira componente
   glLightfv(GL_LIGHT0, GL_AMBIENT,  &light0[0][0]);
   glLightfv(GL_LIGHT0, GL_DIFFUSE,  &light0[1][0]);
   glLightfv(GL_LIGHT0, GL_SPECULAR, &light0[2][0]);
   glLightfv(GL_LIGHT0, GL_POSITION, &light0[3][0]);

   // Segunda Luz
	glEnable(GL_LIGHT1);

   float light1[4][4] = {
      // Ambiente
      {0.1f, 0.3f, 0.3f, 3.f},
      // Difusa
      {0.8f, 0.5f, 0.5f, 1.f},
      // Especular
      { 1.f,  1.f,  1.f, 1.f },
      // Positicao
      {1.f, 0.f, 0.f, 1.f}
   };

   // Luz, Caracteristica, Endereco da primeira componente
   glLightfv(GL_LIGHT1, GL_AMBIENT,  &light1[0][0]);
   glLightfv(GL_LIGHT1, GL_DIFFUSE,  &light1[1][0]);
   glLightfv(GL_LIGHT1, GL_SPECULAR, &light1[2][0]);
   glLightfv(GL_LIGHT1, GL_POSITION, &light1[3][0]);
}

// Posicao do usuario
void PosicaoUser() {
	// Define o volume de recorte
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90,ratio,0.01,200);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
      0.0f, 0.0f, -0.0f,
      0.0f, 0.0f, -8.0f,
      0.0f, 1.0f, 0.0f
   );

}

// Trata o redimensionamento da janela OpenGL
void reshape(int w, int h) {
   // Previne a divisao por zero, quando a imagem eh muito pequena
   // Nao eh posicao fazer uma janela de largura zero
	if (h == 0) {
		h = 1;
   }

	ratio = 1.0f * w / h;
	
   // Reseta o sistema de coordenadas antes de moficiar
	glMatrixMode(GL_PROJECTION);
   
	// Seta o viewport para seja a janela inteira
   glViewport(0, 0, w, h);

	PosicaoUser();
}

void DesenharCubo() {
	glBegin(GL_QUADS);
		// Face frontal
		glNormal3f(0, 0, 1);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		// Face de tras
		glNormal3f(0, 0, -1);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		// Face de cima
		glNormal3f(0, 1, 0);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		// Face de baixo
		glNormal3f(0, -1, 0);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		// Face da direita
		glNormal3f(1,0,0);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		// Face da esquerda
		glNormal3f(-1, 0, 0);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	PosicaoUser();
	
	glMatrixMode(GL_MODELVIEW);

   // Rotaciona o desenho pelos eixos
   glTranslatef(0.0f, 0.0f, -30.0f);
   glRotatef(anguloHorizontal, 0, 1, 0);
   glRotatef(anguloVertical, 1, 0, 0);
   glTranslatef(0.0f, 0.0f, 30.0f);

   // Pe esquerdo
   glPushMatrix();
      // Desenho do pe
      glTranslatef(-2.0f, -10.0f, -30.0f);
      glColor3f(1.0f, 1.0f, 1.0f);
      DesenharCubo();
   glPopMatrix();

   // Pe direito
   glPushMatrix();
      // Desenho do pe
      glTranslatef(2.0f, -10.0f, -30.0f);
      glColor3f(1.0f, 1.0f, 1.0f);
      DesenharCubo();
   glPopMatrix();

   // Tronco
   glPushMatrix();
      // Desenho do tronco
      glTranslatef(0.0f, -2.0f, -30.0f);
      glScalef(5.0f, 7.0f, 1.0f);
      glColor3f(1.0f, 0.0f, 0.0f);
      DesenharCubo();
   glPopMatrix();

   // Cabeca
   glPushMatrix();
      // Desenho da cabeca
      glTranslatef(0.0f, 6.0f, -30.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      DesenharCubo();
   glPopMatrix();

   // Braco da direita
   glPushMatrix();
      // Movimento do segmento 1
      glTranslatef(3.0f, 2.0f, 0.0f);
      glRotatef((GLfloat) segmento1, 0.0, 0.0, 1.0);
      glTranslatef(-3.0f, -2.0f, 0.0f);
      
      glPushMatrix();
         // Desenho do segmento 1
         glTranslatef(7.0f, 2.0f, -30.0f);
         glScalef(2.0f, 1.0f, 1.0f);
         glColor3f(0.0f, 0.0f, 1.0f);
         DesenharCubo();
      glPopMatrix();

      glPushMatrix();
         // Movimento do segmento 2
         glTranslatef(9.0f, 2.0f, 0.0f);
         glRotatef((GLfloat) segmento2, 0.0, 0.0, 1.0);
         glTranslatef(-9.0f, -2.0f, 0.0f);
         
         glPushMatrix();
            // Desenho do segmento 2
            glTranslatef(11.0f, 2.0f, -30.0f);
            glScalef(2.0f, 1.0f, 1.0f);
            glColor3f(0.0f, 1.0f, 0.0f);
            DesenharCubo();
         glPopMatrix();

         // Segmento 3
         glPushMatrix();
            // Movimento do segmento 3
            glTranslatef(13.0f, 2.0f, 0.0f);
            glRotatef((GLfloat) segmento3, 0.0, 0.0, 1.0);
            glTranslatef(-13.0f, -2.0f, 0.0f);

            // Desenho do segmento
            glTranslatef(15.0f, 2.0f, -30.0f);
            glScalef(2.0f, 1.0f, 1.0f);
            glColor3f(0.0f, 0.0f, 1.0f);
            DesenharCubo();

            // Dedo 1   
            glPushMatrix();
               // Desenho do segmento 1 do dedo
               glTranslatef(1.5f, 0.5f, 0.0f);
               glScalef(0.5f, 0.25f, 0.25f);
               glColor3f(1.0f, 0.0f, 0.0f);
               DesenharCubo();

               glPushMatrix();
                  // Movimento do segmento 2 do dedo
                  glTranslatef(1.0, 0.0, 0.0);
                  glRotated((GLfloat) -dedo1, 0.0, 0.0, 1.0);
                  glTranslatef(-1.0, 0.0, 0.0);

                  // Desenho do segmento 2 do dedo
                  glTranslatef(2.0f, 0.0f, 0.0f);
                  glScalef(1.0f, 0.25f, 0.25f);
                  glColor3f(0.0f, 1.0f, 0.0f);
                  DesenharCubo();
               glPopMatrix();
            glPopMatrix();

            // Dedo 2
            glPushMatrix();
               // Desenho do segmento do dedo
               glTranslatef(1.5f, -0.5f, 0.5f);
               glScalef(0.5f, 0.25f, 0.25f);
               glColor3f(0.0f, 1.0f, 0.0f);
               DesenharCubo();

               glPushMatrix();
                  // Movimento do segmento 2 do dedo
                  glTranslatef(1.0, 0.0, 0.0);
                  glRotated((GLfloat) dedo2, 0.0, 0.0, 1.0);
                  glTranslatef(-1.0, 0.0, 0.0);

                  // Desenho do segmento 2 do dedo
                  glTranslatef(2.0f, 0.0f, 0.0f);
                  glScalef(1.0f, 0.25f, 0.25f);
                  glColor3f(1.0f, 0.0f, 0.0f);
                  DesenharCubo();
               glPopMatrix();
            glPopMatrix();

            // Dedo 3
            glPushMatrix();
               // Desenho do segmento do dedo
               glTranslatef(1.5f, -0.5f, -0.5f);
               glScalef(0.5f, 0.25f, 0.25f);
               glColor3f(1.0f, 0.0f, 1.0f);
               DesenharCubo();

               glPushMatrix();
                  // Movimento do segmento 2 do dedo
                  glTranslatef(1.0, 0.0, 0.0);
                  glRotated((GLfloat) dedo3, 0.0, 0.0, 1.0);
                  glTranslatef(-1.0, 0.0, 0.0);

                  // Desenho do segmento 2 do dedo
                  glTranslatef(2.0f, 0.0f, 0.0f);
                  glScalef(1.0f, 0.25f, 0.25f);
                  glColor3f(0.0f, 0.0f, 1.0f);
                  DesenharCubo();
               glPopMatrix();
            glPopMatrix();

         glPopMatrix();

      glPopMatrix();
   
   glPopMatrix();
   
   // Braco da esquerda   
   glPushMatrix();
      // Movimento do segmento 1
      glTranslatef(-3.0f, 2.0f, 0.0f);
      glRotatef((GLfloat) -segmento1, 0.0, 0.0, 1.0);
      glTranslatef(3.0f, -2.0f, 0.0f);

      glPushMatrix();
         // Desenho do segmento 1
         glTranslatef(-7.0f, 2.0f, -30.0f);
         glScalef(2.0f, 1.0f, 1.0f);
         glColor3f(0.0f, 0.0f, 1.0f);
         DesenharCubo();
      glPopMatrix();

      glPushMatrix();
         // Movimento do segmento 2
         glTranslatef(-9.0f, 2.0f, 0.0f);
         glRotatef((GLfloat) -segmento2, 0.0, 0.0, 1.0);
         glTranslatef(9.0f, -2.0f, 0.0f);
         
         glPushMatrix();
            // Desenho do segmento 2
            glTranslatef(-11.0f, 2.0f, -30.0f);
            glScalef(2.0f, 1.0f, 1.0f);
            glColor3f(0.0f, 1.0f, 0.0f);
            DesenharCubo();
         glPopMatrix();

         // Segmento 3
         glPushMatrix();
            // Movimento do segmento 3
            glTranslatef(-13.0f, 2.0f, 0.0f);
            glRotatef((GLfloat) -segmento3, 0.0, 0.0, 1.0);
            glTranslatef(13.0f, -2.0f, 0.0f);

            // Desenho do segmento
            glTranslatef(-15.0f, 2.0f, -30.0f);
            glScalef(2.0f, 1.0f, 1.0f);
            glColor3f(0.0f, 0.0f, 1.0f);
            DesenharCubo();

            // Dedo 1   
            glPushMatrix();
               // Desenho do segmento 1 do dedo
               glTranslatef(-1.5f, 0.5f, 0.0f);
               glScalef(0.5f, 0.25f, 0.25f);
               glColor3f(1.0f, 0.0f, 0.0f);
               DesenharCubo();

               glPushMatrix();
                  // Movimento do segmento 2 do dedo
                  glTranslatef(-1.0, 0.0, 0.0);
                  glRotated((GLfloat) dedo1, 0.0, 0.0, 1.0);
                  glTranslatef(1.0, 0.0, 0.0);

                  // Desenho do segmento 2 do dedo
                  glTranslatef(-2.0f, 0.0f, 0.0f);
                  glScalef(1.0f, 0.25f, 0.25f);
                  glColor3f(0.0f, 1.0f, 0.0f);
                  DesenharCubo();
               glPopMatrix();
            glPopMatrix();

            // Dedo 2
            glPushMatrix();
               // Desenho do segmento do dedo
               glTranslatef(-1.5f, -0.5f, 0.5f);
               glScalef(0.5f, 0.25f, 0.25f);
               glColor3f(0.0f, 1.0f, 0.0f);
               DesenharCubo();

               glPushMatrix();
                  // Movimento do segmento 2 do dedo
                  glTranslatef(-1.0, 0.0, 0.0);
                  glRotated((GLfloat) -dedo2, 0.0, 0.0, 1.0);
                  glTranslatef(1.0, 0.0, 0.0);

                  // Desenho do segmento 2 do dedo
                  glTranslatef(-2.0f, 0.0f, 0.0f);
                  glScalef(1.0f, 0.25f, 0.25f);
                  glColor3f(1.0f, 0.0f, 0.0f);
                  DesenharCubo();
               glPopMatrix();
            glPopMatrix();

            // Dedo 3
            glPushMatrix();
               // Desenho do segmento do dedo
               glTranslatef(-1.5f, -0.5f, -0.5f);
               glScalef(0.5f, 0.25f, 0.25f);
               glColor3f(1.0f, 0.0f, 1.0f);
               DesenharCubo();

               glPushMatrix();
                  // Movimento do segmento 2 do dedo
                  glTranslatef(-1.0, 0.0, 0.0);
                  glRotated((GLfloat) -dedo3, 0.0, 0.0, 1.0);
                  glTranslatef(1.0, 0.0, 0.0);

                  // Desenho do segmento 2 do dedo
                  glTranslatef(-2.0f, 0.0f, 0.0f);
                  glScalef(1.0f, 0.25f, 0.25f);
                  glColor3f(0.0f, 0.0f, 1.0f);
                  DesenharCubo();
               glPopMatrix();
            
            glPopMatrix();

         glPopMatrix();

      glPopMatrix();

   glPopMatrix();

	glutSwapBuffers();
}

// Funcao que controla o teclado
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
      // Termina o problema quando a tecla ESC for pressionada
      case 27:
         exit(0);
         break;
      // Move no sentido antihorario horizontalmente
      case 'm':
      	anguloHorizontal++;
         break;
      // Move no sentido horario horizontalmente
      case 'n':
      	anguloHorizontal--;
         break;
      // Move no sentido antihorario verticalmente
      case 'k':
      	anguloVertical++;
         break;
      // Move no sentido horario verticalmente
      case 'j':
      	anguloVertical--;
         break;
      case 'q':
         segmento1 = (segmento1 + 5) % 360;
         glutPostRedisplay();
         break;
      case 'Q':
         segmento1 = (segmento1 - 5) % 360;
         glutPostRedisplay();
         break;
      case 'w':
         segmento2 = (segmento2 + 5) % 360;
         glutPostRedisplay();
         break;
      case 'W':
         segmento2 = (segmento2 - 5) % 360;
         glutPostRedisplay();
         break;
      case 'e':
         segmento3 = (segmento3 + 5) % 360;
         glutPostRedisplay();
         break;
      case 'E':
         segmento3 = (segmento3 - 5) % 360;
         glutPostRedisplay();
         break;
      case 'r':
         dedo1 = (dedo1 + 5) % 360;
         glutPostRedisplay();
         break;
      case 'R':
         dedo1 = (dedo1 - 5) % 360;
         glutPostRedisplay();
         break;
      case 't':
         dedo2 = (dedo2 + 5) % 360;
         glutPostRedisplay();
         break;
      case 'T':
         dedo2 = (dedo2 - 5) % 360;
         glutPostRedisplay();
         break;
      case 'y':
         dedo3 = (dedo3 + 5) % 360;
         glutPostRedisplay();
         break;
      case 'Y':
         dedo3 = (dedo3 - 5) % 360;
         glutPostRedisplay();
         break;
      default:        
         break;
  }
}

void menu(void) {
   std::cout << "====================================" << std::endl;
   std::cout << "Guia do teclado" << std::endl;
   std::cout << "====================================" << std::endl;
   std::cout << "[ESC] – Para sair" << std::endl;
   std::cout << "====================================" << std::endl;
   std::cout << "====================================" << std::endl;
   std::cout << "Movimento do desenho" << std::endl;
   std::cout << "[m/n] – Para girar horizontalmente o desenho" << std::endl;
   std::cout << "[k/j] – Para girar verticalmente o desenho" << std::endl;
   std::cout << "====================================" << std::endl;
   std::cout << "Movimento do braco" << std::endl;
   std::cout << "[q/Q] – Para mover o segmento 1" << std::endl;
   std::cout << "[w/W] – Para mover o segmento 2" << std::endl;
   std::cout << "[e/E] – Para mover o segmento 3" << std::endl;
   std::cout << "====================================" << std::endl;
   std::cout << "Movimento do dedo" << std::endl;
   std::cout << "[r/R] – Para mover o dedo 1" << std::endl;
   std::cout << "[t/T] – Para mover o dedo 2" << std::endl;
   std::cout << "[y/Y] – Para mover o dedo 3" << std::endl;
   std::cout << "====================================" << std::endl;
}

void arrow_keys (int a_keys, int x, int y) {
	switch (a_keys) {
      // Quando a tecla para cima for pressionada
		case GLUT_KEY_UP:
         // Vai para o modo de tela inteira
			glutFullScreen();
			break;
      // Quando a tecla para baico for pressionada
	    case GLUT_KEY_DOWN:
			glutInitWindowSize(700, 500);
			break;
		default:
			break;
	}
}

int main(int argc, char** argv) {
   menu();
   glutInit(&argc, argv); 
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
   glutInitWindowPosition(0,0);
   glutInitWindowSize(800, 600); 
   glutCreateWindow("GCC124 - Robo colorido que movimenta"); 
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(arrow_keys);
   glutIdleFunc(display);
   glutMainLoop();
   return 0;       
}
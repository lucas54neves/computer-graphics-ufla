// Biblioteca utilizada
#include <GL/glut.h>

// Variaveis utilizadas
GLfloat horzangle = -45.0,vertangle = 30.0, distance = -3.0;

void RenderScene(void) {
  glMatrixMode(GL_MODELVIEW); 
  glLoadIdentity(); 
  glTranslatef(0.0f,0.0f,distance); 
  glRotatef(vertangle,1.0f,0.0f,0.0f); 
  glRotatef(horzangle,0.0f,1.0f,0.0f);
  glEnable(GL_DEPTH_TEST);
  glClearColor(1.0f,1.0f,1.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();
  // Eixos cartesianos
  glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.7f,0.0f,0.0f);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.5f,0.0f);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.7f);
  glEnd();
  // Chao da casa
  glBegin(GL_POLYGON);
    // Cor Aqua
    glColor3f(0.000f, 1.000f, 1.000f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.4f,0.0f,0.0f);
    glVertex3f(0.4f,0.0f,0.4f);
    glVertex3f(0.0f,0.0f,0.4f);
  glEnd();
  // Fundos da casa
  glBegin(GL_POLYGON);
    // Cor vermelho indiano
    glColor3f(0.804f, 0.361f, 0.361f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.2f,0.0f);
    glVertex3f(0.2f,0.3f,0.0f);
    glVertex3f(0.4f,0.2f,0.0f);
    glVertex3f(0.4f,0.0f,0.0f);
  glEnd();
  // Lateral da direita (inicialmente)
  glBegin(GL_POLYGON);
    // Cor ouro
    glColor3f(1.000f, 0.843f, 0.000f);
    glVertex3f(0.4f,0.0f,0.0f);
    glVertex3f(0.4f,0.0f,0.4f);
    glVertex3f(0.4f,0.2f,0.4f);
    glVertex3f(0.4f,0.2f,0.0f);
  glEnd();
  // Lateral da esquerda (inicialmente)
  glBegin(GL_POLYGON);
    // Cor Dark Khaki
    glColor3f(0.741f, 0.718f, 0.420f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.4f);
    glVertex3f(0.0f,0.2f,0.4f);
    glVertex3f(0.0f,0.2f,0.0f);
  glEnd();
  // Janela da direita inferior
  glBegin(GL_POLYGON);
    // Cor azul
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.4001f,0.05f,0.3f);
    glVertex3f(0.4001f,0.05f,0.35f);
    glVertex3f(0.4001f,0.1f,0.35f);
    glVertex3f(0.4001f,0.1f,0.3f);
  glEnd();
  // Janela da direita superior
  glBegin(GL_POLYGON);
    // Cor azul
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.4001f,0.125f,0.3f);
    glVertex3f(0.4001f,0.125f,0.35f);
    glVertex3f(0.4001f,0.175f,0.35f);
    glVertex3f(0.4001f,0.175f,0.3f);
  glEnd();
  // Telhado
  glBegin(GL_QUAD_STRIP);
    // Cor verde
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f,0.2f,0.0f);
    glVertex3f(0.0f,0.2f,0.4f);
    glVertex3f(0.2f,0.3f,0.0f);
    glVertex3f(0.2f,0.3f,0.4f);
    glVertex3f(0.4f,0.2f,0.0f);
    glVertex3f(0.4f,0.2f,0.4f);
  glEnd();
  // Frente da casa
  glBegin(GL_POLYGON);
    // Cor vermelha
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.4f);
    glVertex3f(0.0f,0.2f,0.4f);
    glVertex3f(0.2f,0.3f,0.4f);
    glVertex3f(0.4f,0.2f,0.4f);
    glVertex3f(0.4f,0.0f,0.4f);
  glEnd();
  // Porta
  // Efeito de porta aberta
  glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(0.15f,0.0f,0.4001f);
    glVertex3f(0.25f,0.0f,0.4001f);
    glVertex3f(0.25f,0.1f,0.4001f);
    glVertex3f(0.15f,0.1f,0.4001f);
  glEnd();
  glBegin(GL_POLYGON);
    // Cor azul
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.15f,0.0f,0.4f);
    glVertex3f(0.25f,0.0f,0.45f);
    glVertex3f(0.25f,0.1f,0.45f);
    glVertex3f(0.15f,0.1f,0.4f);
  glEnd();
  // Janela da direita inferior
  glBegin(GL_POLYGON);
    // Cor azul
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.05f,0.05f,0.4001f);
    glVertex3f(0.10f,0.05f,0.4001f);
    glVertex3f(0.10f,0.1f,0.4001f);
    glVertex3f(0.05f,0.1f,0.4001f);
  glEnd();
  // Janela da direita superior
  glBegin(GL_POLYGON);
    // Cor azul
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.05f,0.125f,0.4001f);
    glVertex3f(0.10f,0.125f,0.4001f);
    glVertex3f(0.10f,0.175f,0.4001f);
    glVertex3f(0.05f,0.175f,0.4001f);
  glEnd();
  // Janela do meio
  glBegin(GL_POLYGON);
    // Cor azul
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.15f,0.125f,0.4001f);
    glVertex3f(0.25f,0.125f,0.4001f);
    glVertex3f(0.25f,0.175f,0.4001f);
    glVertex3f(0.15f,0.175f,0.4001f);
  glEnd();
  // Janela da esquerda infeior
  glBegin(GL_POLYGON);
    // Cor azul
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.3f,0.125f,0.4001f);
    glVertex3f(0.35f,0.125f,0.4001f);
    glVertex3f(0.35f,0.175f,0.4001f);
    glVertex3f(0.3f,0.175f,0.4001f);
  glEnd();
  // Janela da esquerda supeior
  glBegin(GL_POLYGON);
    // Cor azul
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.3f,0.05f,0.4001f);
    glVertex3f(0.35f,0.05f,0.4001f);
    glVertex3f(0.35f,0.1f,0.4001f);
    glVertex3f(0.3f,0.1f,0.4001f);
  glEnd();
  glFlush();
  glPopMatrix();
  glutSwapBuffers();
}

// Funcao que faz o movimento do mouse
void mouse(int button, int state, int mousex, int mousey) { 
  // Rotaciona a casa para esquerda
  if(button==GLUT_LEFT_BUTTON){
  	horzangle -= 15;
  }
  // Rotaciona a casa para direita
  else if(button==GLUT_RIGHT_BUTTON){
  	horzangle += 15;
  }
  // Rotaciona a casa para cima
  else if(button==GLUT_MIDDLE_BUTTON){
  	vertangle -= 15;	
  }
  RenderScene();
}

// Funcao que faz o movimento do teclado
void KeyBoard(unsigned char a, int x, int y) {
  // Rotaciona a casa para direita
	if(a == 'a'){
		horzangle -= 5;
	}
  // Rotaciona a casa para esquerda
	else if(a == 'd'){
		horzangle += 5;
	}
  // Rotaciona a casa para cima
	else if(a == 'w'){
		vertangle -= 5;
	}
  // Rotaciona a casa para baixo
	else if(a == 's'){
		vertangle += 5;
 	}
  // Aumenta o tamanho da imagem
 	else if(a == 'p'){
		distance += 0.5;
 	}
  // Diminui o tamanho da imagem
 	else if(a == 'o'){
		distance -= 0.5;
 	}
 	RenderScene();
}
  
void ChangeSize(GLsizei width,GLsizei height) { 
  glViewport(0,0,width,height); 
  glMatrixMode(GL_PROJECTION); 
  glLoadIdentity(); 
  gluPerspective(30.0,width/height,1.0,10.0); 
} 
  
int main(int argc, char* argv[]) { 
  glutInit(&argc, argv);
  // Buffer de profundidade
  glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB); 
  glutInitWindowSize (500, 500); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow("Atividade A do REO3"); 
  glutDisplayFunc(RenderScene);
  glutReshapeFunc(ChangeSize);
  glutMouseFunc(mouse);
  glutKeyboardFunc(KeyBoard);
  glutMainLoop(); 
  return 0;
} 

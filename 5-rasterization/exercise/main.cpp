/*
    Computacao Grafica
    Exercicio para nota 4
    Nome: Lucas Antonio Lopes Neves
*/

// Bibliotecas
#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>
#include <unistd.h>

int x1, x2, y1, y2;
bool desenhoAtivo = true;

void init(void){
	glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(4.0f);
}

void gerarLinhas() {    
    glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
    glEnd();
} 
          
void display(void) {   
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 720.0, 0.0, 480.0);
    glFlush();
}

/*
    Funcao que controla as teclas para escolher se desenha ou nao
    Se alguma tecla for pressionada, desativa a funcao de desenhoAtivo
    Se outra tecla for pressionada, ativa novamente a funcao
    Por definicao, o programa inicia com a funcao de desenhar ativada
    Se a tecla ESQ for pressionada, a tela eh limpa
*/
void keyboard (unsigned char key, int x, int y) {
    if (key == 27) {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    desenhoAtivo = !desenhoAtivo;
}

void idle(void) {
	if(desenhoAtivo) {
		x1 = 360;
		y1 = 240;
		x2 = rand() % 720; 
		y2 = rand() % 480;  
		gerarLinhas();
		usleep(250);
	    display();
	}	
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(300, 200); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Desenho de retas aleatorias");
  	init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glutMainLoop();
}
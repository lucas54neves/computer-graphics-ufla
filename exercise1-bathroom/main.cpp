/*
    Atividade Relativa ao REO2 de  Computação Gráfica (10A)
    Professora: Ana Paula Piovesan Malchiori
    Desenvolvido por Lucas Antonio Lopes Neves
*/

#include <GL/glut.h>
#include <math.h>
#include <GL/gl.h>

// Definicao do valor do PI
#define PI 3.1415926535898

// Funcao que desenha uma esfera, passando por parametro
// o raio e o centro da esfera
void esfera(float raio, float x, float y) {
	GLfloat circle_points = 100;
	float angle;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < circle_points; i++) {
		angle = 2.0*PI*i/circle_points;
		glVertex2f(cos(angle)*raio+x, sin(angle)*raio+y);
	}
	glEnd();
	glFlush();
}

// Funcao que desenha uma quadrilatero, passando por parametro
// a largura, o comprimento e o centro do quadrilatero
void quadrilatero(float largura, float comprimento, float x, float y) {
    glBegin(GL_LINE_LOOP);
        // Ponto 1
        glVertex2f(x-(largura/2), y+(comprimento/2));
        // Ponto 2
        glVertex2f(x-(largura/2), y-(comprimento/2));
        // Ponto 3
        glVertex2f(x+(largura/2), y-(comprimento/2));
        // Ponto 4
        glVertex2f(x+(largura/2), y+(comprimento/2));
    glEnd();
    glFlush();
}

// Funcao que desenha o vaso sanitario
void vasoSanitatio() {
    // Chama a funcao quadrilatero com os parametros desejados
    // para desenhar a parte de cima do vaso
    quadrilatero(0.1, 0.025, 0.4, 0.85);
    // Desenha a parte de baixo
    glBegin(GL_LINE_STRIP);
        glVertex2f(0.35, 0.8375);
        glVertex2f(0.38, 0.775);
        glVertex2f(0.42, 0.775);
        glVertex2f(0.45, 0.8375);
    glEnd();
    glFlush();
}

// Funcao que desenha a pia
void pia() {
    // Chama o a funcao quadrilatero com os parametros desejados
    // para desenhar a lateral da pia
    quadrilatero(0.1, 0.1, 0.6, 0.85);
    // Chama o a funcao quadrilatero com os parametros desejados
    // para desenhar o centro da pia
    quadrilatero(0.06, 0.05, 0.6, 0.84);
    // Chama o a funcao quadrilatero com os parametros desejados
    // para desenhar a torneira da pia
    quadrilatero(0.02, 0.01, 0.6, 0.885);
    // Chama o a funcao esfera com os parametros desejados
    // para desenhar a saida da agua
    esfera(0.005, 0.6, 0.845);
}

// Funcao que desenha o armario
void armario() {
    // Chama o a funcao quadrilatero com os parametros desejados
    quadrilatero(0.1, 0.1, 0.15, 0.25);
}

// Funcao que desenha o espelho
void espelho() {
    // Chama o a funcao quadrilatero com os parametros desejados
    quadrilatero(0.02, 0.3, 0.15, 0.55);
}

// Funcao que desenha o chuveiro
void chuveiro() {
    float centro_x = 0.85;
    float centro_y = 0.6;
    // Chama o a funcao quadrilatero com os parametros desejados
    // para desenhar as paredes do chuveiro
    quadrilatero(0.1, 0.2, centro_x, centro_y);
    // Chama o a funcao quadrilatero com os parametros desejados
    // para desenhar as laterais do chuveiro
    quadrilatero(0.08, 0.18, centro_x, centro_y);
    // Chama o a funcao esfera com os parametros desejados
    // para desenhar a esfera que sai a agua do chuveiro
    esfera(0.0075, centro_x, centro_y);
    // Desenha as linhas diagonais do banheiro
    glBegin(GL_LINES);
        glVertex2f(0.81, 0.69);
        glVertex2f(0.845, 0.615);
        glVertex2f(0.89, 0.69);
        glVertex2f(0.855, 0.615);
        glVertex2f(0.81, 0.51);
        glVertex2f(0.845, 0.585);
        glVertex2f(0.89, 0.51);
        glVertex2f(0.855, 0.585);
    glEnd();
    glFlush();
}

// Funcao que desenha a banheira
void banheira() {
    // Chama o a funcao quadrilatero com os parametros desejados
    // para desenhar a lateral da banheira
    quadrilatero(0.3, 0.15, 0.8, 0.15);
    // Chama o a funcao quadrilatero com os parametros desejados
    // para desenhar o centro da banheira
    quadrilatero(0.28, 0.13, 0.8, 0.15);
    // Chama o a funcao esfera com os parametros desejados
    // para desenhar a esfera que sai a agua da banheira
    esfera(0.0075, 0.865, 0.15);
}

void displayMe(void) {
    glColor3f(0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    armario();
    espelho();
    pia();
    vasoSanitatio();
    chuveiro();
    banheira();
    glBegin(GL_LINE);
        glVertex2f(0.81, 0.69);
        glVertex2f(0.845, 0.615);
        glVertex2f(0.89, 0.69);
        glVertex2f(0.855, 0.615);
        glVertex2f(0.81, 0.51);
        glVertex2f(0.845, 0.585);
        glVertex2f(0.89, 0.51);
        glVertex2f(0.855, 0.585);
    glEnd();
    glFlush();
}

void init (void) {
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
 
// Declaracao inicial do tamanho da tela, posicao
// e modo de diplay
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Atividade 1 - Banheiro");
    init();
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}

// Bibliotecas
#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>

// Variaveis globais
float xrot;
float yrot;
float zrot;
float ratio;
float AlfaVidro=0.5f;

// Funcao que inicializa os parametros globais do OpenGL
void init(void) {
    // Habilita Smooth Shading
    glShadeModel(GL_SMOOTH);
    // Fundo preto
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	glEnable(GL_COLOR_MATERIAL); 
	// Habilita o ZBuffer
	glEnable(GL_DEPTH_TEST);
}

// Funcao que trata o redimensionamento da janela OpenGL
void reshape(int w, int h) {
	// Previne a divisao por zero, quando a janela eh muito pequena
	if (h == 0) {
		h = 1;
    }

	ratio = 1.0f * w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
    glViewport(0, 0, w, h);
	// Seta o angulo de visao
	gluPerspective(50,ratio,1,200);
	// Define a posicao do observador
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 5, 0, 0, 0, 0.0f, 1.0f, 0.0f);

}

// Funcao que desenha um cubo
void DrawSquare(GLfloat alfa, int color) {
    glBegin(GL_QUADS);
		if (color == 1) {
            glColor4f(0.7f,0.7f,0, alfa);
        } else if (color == 2) {
            glColor4f(0,0,0.7f, alfa);
        } else if (color == 3) {
            glColor4f(0.7f,0,0, alfa);
        }
        // Front Face
        glVertex3f(-1.0f, -1.0f,  1.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);
        glVertex3f( 1.0f,  1.0f,  1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);
        // Back Face
        if (color == 1) {
            glColor4f(0.7f,0.7f,0, alfa);
        } else if (color == 2) {
            glColor4f(0,0,0.7f, alfa);
        } else if (color == 3) {
            glColor4f(0.7f,0,0, alfa);
        };
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glVertex3f( 1.0f,  1.0f, -1.0f);
        glVertex3f( 1.0f, -1.0f, -1.0f);
        // Top Face
            if (color == 1) {
            glColor4f(0.7f,0.7f,0, alfa);
        } else if (color == 2) {
            glColor4f(0,0,0.7f, alfa);
        } else if (color == 3) {
            glColor4f(0.7f,0,0, alfa);
        }
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);
        glVertex3f( 1.0f,  1.0f,  1.0f);
        glVertex3f( 1.0f,  1.0f, -1.0f);
        // Bottom Face
        if (color == 1) {
            glColor4f(0.7f,0.7f,0, alfa);
        } else if (color == 2) {
            glColor4f(0,0,0.7f, alfa);
        } else if (color == 3) {
            glColor4f(0.7f,0,0, alfa);
        }
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f( 1.0f, -1.0f, -1.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        // Right face
        if (color == 1) {
            glColor4f(0.7f,0.7f,0, alfa);
        } else if (color == 2) {
            glColor4f(0,0,0.7f, alfa);
        } else if (color == 3) {
            glColor4f(0.7f,0,0, alfa);
        }
        glVertex3f( 1.0f, -1.0f, -1.0f);
        glVertex3f( 1.0f,  1.0f, -1.0f);
        glVertex3f( 1.0f,  1.0f,  1.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);
        // Left Face
        if (color == 1) {
            glColor4f(0.7f,0.7f,0, alfa);
        } else if (color == 2) {
            glColor4f(0,0,0.7f, alfa);
        } else if (color == 3) {
            glColor4f(0.7f,0,0, alfa);
        }
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f,  1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);
	glEnd();
}

// Funcao que faz o desenho
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// Habilita o BLEND
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	
	
	glPushMatrix();
		glTranslatef(1, 0, 0);
        glScalef(0.5, 0.5, 0.5);
		glRotatef(-xrot, 1.0, 0.0, 0.0);
		glRotatef(-yrot, 0.0, 1.0, 0.0);
		glRotatef(-zrot, 0.0, 0.0, 1.0);
		DrawSquare(0.2, 1);
	glPopMatrix();

    glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPushMatrix();
		glTranslatef(0, 0, 0);
        glScalef(1.0, 1.0, 1.0);
		glRotatef ( xrot, 1.0, 0.0, 0.0 );
		glRotatef ( yrot, 0.0, 1.0, 0.0 );
		glRotatef ( zrot, 0.0, 0.0, 1.0 );
		DrawSquare(0.5, 2);
	glPopMatrix();

    glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPushMatrix();
		glTranslatef(-0.5, 0, 0);
        glScalef(1.5, 1.5, 1.5);
		glRotatef ( -xrot, 1.0, 0.0, 0.0 );
		glRotatef ( -yrot, 0.0, 1.0, 0.0 );
		glRotatef ( -zrot, 0.0, 0.0, 1.0 );
		DrawSquare(0.5, 3);
	glPopMatrix();

	xrot+=0.3f;
	yrot+=0.2f;
	zrot+=0.4f;
	glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 
	glutInitWindowPosition(0,0);
	glutInitWindowSize(700, 500);
	glutCreateWindow("Exercicio sobre transparencia de Computacao Grafica");
    init();
    glutDisplayFunc(display);  
	glutReshapeFunc(reshape);
	// glutKeyboardFunc(keyboard);
	glutIdleFunc(display);
	glutMainLoop();
    return 1;
}
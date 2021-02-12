// **********************************************************************
//	FirstTransp.cpp   --   Exemplo de Transpar�ncias
//		
//
// **********************************************************************

#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>


float xrot;
float yrot;
float zrot;
float ratio;
float AlfaVidro=0.5f;

// **********************************************************************
//  void init(void)
//		Inicializa os par�metros globais de OpenGL
//
// **********************************************************************
void init(void)
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);				// Black Background
	
	glEnable(GL_COLOR_MATERIAL); 
	
	glEnable(GL_DEPTH_TEST); // habilita ZBuffer

}

// **********************************************************************
//  void reshape( int w, int h )
//		trata o redimensionamento da janela OpenGL
//
// **********************************************************************
void reshape( int w, int h )
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0)
		h = 1;

	ratio = 1.0f * w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
    glViewport(0, 0, w, h);

	// Seta o �ngulo de vis�o
	gluPerspective(50,ratio,1,200);

	// Define a posi��o do observador
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 5,
		      0,0,0,
			  0.0f,1.0f,0.0f);

}
// **********************************************************************
//  void DrawCube()
//
//
// **********************************************************************
void DrawCube(GLfloat alfa)
{

	glBegin ( GL_QUADS );
		// Front Face
		glColor4f(0.7f,0.7f,0, alfa);
		glVertex3f(-1.0f, -1.0f,  1.0f);
		glVertex3f( 1.0f, -1.0f,  1.0f);
		glVertex3f( 1.0f,  1.0f,  1.0f);
		glVertex3f(-1.0f,  1.0f,  1.0f);
		// Back Face
		glColor4f(0,0,0.7f, alfa);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f,  1.0f, -1.0f);
		glVertex3f( 1.0f,  1.0f, -1.0f);
		glVertex3f( 1.0f, -1.0f, -1.0f);
		// Top Face
		glColor4f(0.7f,0,0.7f, alfa);
		glVertex3f(-1.0f,  1.0f, -1.0f);
		glVertex3f(-1.0f,  1.0f,  1.0f);
		glVertex3f( 1.0f,  1.0f,  1.0f);
		glVertex3f( 1.0f,  1.0f, -1.0f);
		// Bottom Face
		glColor4f(0.7f,0.7f,0.7f, alfa);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f( 1.0f, -1.0f, -1.0f);
		glVertex3f( 1.0f, -1.0f,  1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		// Right face
		glColor4f(0,0.5f,0, alfa);
		glVertex3f( 1.0f, -1.0f, -1.0f);
		glVertex3f( 1.0f,  1.0f, -1.0f);
		glVertex3f( 1.0f,  1.0f,  1.0f);
		glVertex3f( 1.0f, -1.0f,  1.0f);
		// Left Face
		glColor4f(0.7f,0,0, alfa);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f,  1.0f);
		glVertex3f(-1.0f,  1.0f,  1.0f);
		glVertex3f(-1.0f,  1.0f, -1.0f);
	glEnd();
}

// **********************************************************************
//  void DesenhaPlano(GLfloat alfa)
//
//
// **********************************************************************
void DesenhaPlano(GLfloat alfa)
{
	glBegin(GL_QUADS);
		glVertex3f(-1.0f, -1.0f,  1.0f);
		glVertex3f( 1.0f, -1.0f,  1.0f);
		glVertex3f( 1.0f,  1.0f,  1.0f);
		glVertex3f(-1.0f,  1.0f,  1.0f);
	glEnd();
}

// **********************************************************************
//  void DesenhaVidro(GLfloat alfa)
//
//
// **********************************************************************
void DesenhaVidro(GLfloat alfa)
{
	static float x= -2;
	static float delta = -0.02f;
	glPushMatrix();
		glTranslatef(x,0,0);
		if ((x > 2) || (x < -2))
			delta *= -1;
		x += delta;
		glColor4f(1,1,1,alfa);
		DesenhaPlano(1);
	glPopMatrix();

}
// **********************************************************************
//  void display( void )
// **********************************************************************
void display( void )
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


	// Desbilita o BLEND par ao primeiro objeto
	glDisable(GL_BLEND);
	glPushMatrix();
		glTranslatef(0,0,-1);
		glRotatef ( xrot, 1.0, 0.0, 0.0 );
		glRotatef ( yrot, 0.0, 1.0, 0.0 );
		glRotatef ( zrot, 0.0, 0.0, 1.0 );

		// habilita remo��o de faces traseiras
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		DrawCube(0.5);		
	glPopMatrix();
	
	// Habilita o BLEND para ao segundo objeto
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	
	
	// NovaCorNaTela = CorDoObjeto * AlfaDoObjeto + CorAntigaNaTele * (1-AlfaDoObjeto)

	glPushMatrix();
		glTranslatef(0,0,0);
		DesenhaVidro(AlfaVidro);
	glPopMatrix();

	xrot+=0.3f;
	yrot+=0.2f;
	zrot+=0.4f;
	glutSwapBuffers();
}

// **********************************************************************
//  void keyboard ( unsigned char key, int x, int y )
//
//
// **********************************************************************
void keyboard ( unsigned char key, int x, int y )  
{
	switch ( key ) 
	{
    case 27:        
      exit ( 0 );   
      break;        
  }
}

// **********************************************************************
//  void main ( int argc, char** argv )
//
//
// **********************************************************************
int main ( int argc, char** argv )   
{
	glutInit            ( &argc, argv ); 
	glutInitDisplayMode ( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA ); 
	glutInitWindowPosition (0,0);
	glutInitWindowSize  ( 700, 500 ); 
	glutCreateWindow    ( "T�picos em Computa��o Gr�fica - Teste (UM) com Transparencias..." ); 
		
	init ();
	
	glutDisplayFunc ( display );  
	glutReshapeFunc ( reshape );
	glutKeyboardFunc ( keyboard );
	glutIdleFunc ( display );
	glutMainLoop ( );          
	return 1;
}



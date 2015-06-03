
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>
#include <time.h>
#include <math.h>

int state ,chr,chr1;



GLfloat LightAmbient[]= { 0.5f, 0.5f, 0.5f, 1.0f };

GLfloat LightDiffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };

GLfloat LightPosition[]= { 5.0f, 25.0f, 15.0f, 1.0f };

GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};

static int view_state = 0, light_state = 0,speed_state=0;

int spin;

int st;


void setOrthographicProjection()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
	glClearColor(0.0,0.0,1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
}
void resetPerspectiveProjection()
{
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}
void marquee()
{
int z=30;
	z--;
	if(z==30)
		z=600;
	glutPostRedisplay();
}
void screen1()
{

char a1[]="         Graphical Implementation of ";
    char a2[]="ELECTRONIC CONFIGURATION of";
	char a3[]="               NOBLE GASES";
	char a4[]="SUBMITTED BY";
	char a5[]="ANOOP D V                                                                                             DILIP KUMAR B"   ;
	char a6[]="  1BY12CS010                                                                                                                       1BY12CS020"  ;
	char a7[]="Under the guidance of";
	char a8[]="Mrs.AMBIKA G N";
	char a9[]="Asst. Professor";
	char a10[]="               BMSIT,Yelahanka,Bangalore";
	char a11[]="Press W to watch ";
	char a12[]="Mr. ANIL G N";
	char a13[]="Asst. Professor";
	char a14[]="Dept of CSE";
	char a15[]="BMSIT";
	int i;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	setOrthographicProjection();
	glPushMatrix();
	glLoadIdentity();
	glClearColor(10.0/256.0,10.0/256.0,0.0/256.0,0.0);
	glColor3f(256.0/256.0,100.0/256.0,0.0);
	glRectf(0,0,800,10);
	glColor3f(256.0/256.0,100.0/256.0,0.0);
	glRectf(0,35,800,45);
	glColor3f(250.0/256.0,200.0/255.0,1.0);
	glColor3f(256.0/256.0,100.0/256.0,0.0);
	glRectf(0,0,7,700);
	glColor3f(256.0/256.0,100.0/256.0,0.0);
	glRectf(25,0,32,700);
	glColor3f(0.2,0.8,0.2);
	glRectf(10,15,22,30);
	glRectf(10,517,22,532);
	glRectf(10,544,22,559);
	glRectf(10,571,22,586);
	glColor3f(256.0/256.0,100.0/256.0,0.0);
	glRectf(768,0,775,700);
	glColor3f(256.0/256.0,100.0/256.0,0.0);
	glRectf(792,0,810,700);
	glColor3f(250.0/256.0,200.0/255.0,1.0);
	glColor3f(256.0/256.0,100.0/256.0,0.0);
	glRectf(0,590,800,710);
	glColor3f(256.0/256.0,100.0/256.0,0.0);
	glRectf(0,563,800,570);
	glColor3f(0.2,0.8,0.2);
	glRectf(779,15,789,33);
	glRectf(779,50,789,65);
	glRectf(779,75,789,90);
	glRectf(779,571,789,586);

	glColor3f(1.0,0.5,0.0);
	glRasterPos2f(270.0,500.0);
	for(i=0;i<sizeof(a1);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24  ,a1[i]);
	glColor3f(1.0,0.5,0.0);
	glRasterPos2f(270.0,475.0);
	for(i=0;i<sizeof(a2);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24  ,a2[i]);
	glColor3f(1.0,0.5,0.0);
	glRasterPos2f(270.0,450.0);
	for(i=0;i<sizeof(a3);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24  ,a3[i]);

	glColor3f(1.0,0.2,0.3);
	glRasterPos2f(335.0,370.0);
	for(i=0;i<sizeof(a4);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24  ,a4[i]);

	glColor3f(0.0,0.5,1.0);
	glRasterPos2f(100.0,290.0);
	for(i=0;i<sizeof(a5);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24  ,a5[i]);

	glColor3f(0.0,0.5,1.0);
	glRasterPos2f(100.0,270.0);
	for(i=0;i<sizeof(a6);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 ,a6[i]);

	glColor3f(1.0,0.0,0.0);
	glRasterPos2f(300.0,220.0);
	for(i=0;i<sizeof(a7);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24  ,a7[i]);

	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(100.0,200.0);
	for(i=0;i<sizeof(a8);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,a8[i]);


	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(100.0,180.0);
	for(i=0;i<sizeof(a9);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,a9[i]);


	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(100.0,160.0);
	for(i=0;i<sizeof(a9);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,a14[i]);

	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(100.0,140.0);
	for(i=0;i<sizeof(a9);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,a15[i]);



	glColor3f(1.0,0.0,0.0);
	glRasterPos2f(10.0,20.0);
	for(i=0;i<sizeof(a10);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,a10[i]);

	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(580.0,200.0);
	for(i=0;i<sizeof(a12);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,a12[i]);

	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(580.0,180.0);
	for(i=0;i<sizeof(a13);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,a13[i]);

	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(580.0,160.0);
	for(i=0;i<sizeof(a9);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,a14[i]);

	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(580.0,140.0);
	for(i=0;i<sizeof(a9);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,a15[i]);

	glColor3f(0.2,0.6,0.3);
	glRasterPos2f(300.0,100.0);
	for(i=0;i<sizeof(a11);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,a11[i]);

	glPopMatrix();
	resetPerspectiveProjection();

	glutIdleFunc(marquee);
	glutSwapBuffers();
	glFlush();
}

void Sprint( int x, int y,int z,char *st)

{

	int l,i;

	l=strlen( st );

	glRasterPos3i( x,y,z);

	for( i=0; i < l; i++)

	{

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);

	}

}





static void timer1(int te)

{

	spin++;

	if (spin > 360) spin = 0;

		glutPostRedisplay();

	glutTimerFunc( 1000,timer1,4);

}

void init(void)

{

   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
   glEnable(GL_DEPTH_TEST);
   glLightfv(GL_LIGHT1 ,GL_AMBIENT, LightAmbient);
   glLightfv(GL_LIGHT1 ,GL_DIFFUSE, LightDiffuse);
   glLightfv(GL_LIGHT1 ,GL_POSITION, LightPosition);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT1);
}

void Draw_atom_Hy(GLfloat x, GLfloat y, GLfloat z, int elec, int orbit)
{
	glColor3f(0.0,1.0,0.5);
	Sprint(22,-20,2,"HYDROGEN");
	Sprint(20, 25,2,"  7tH : 1");
	glRotatef( 60, 1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef( x, y, z);
	glColor3f( 1.0, 0.0, 0.0);
	glutSolidSphere( 5, 16, 10);
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 10, 16, 32);
	glPushMatrix();
	glTranslatef(0, 10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	/*glPushMatrix();
	glTranslatef(0, -10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();*/
	glPopMatrix();
	glPopMatrix();
}

void Draw_atom_He(GLfloat x, GLfloat y, GLfloat z, int elec, int orbit)
{
	glColor3f(0.0,1.0,0.5);
	Sprint(22,-20,2,"HELIUM");
	Sprint(20, 25,2,"  1st : 2");
	glRotatef( 60, 1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef( x, y, z);
	glColor3f( 1.0, 0.0, 0.0);
	glutSolidSphere( 5, 16, 10);
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 10, 16, 32);
	glPushMatrix();
	glTranslatef(0, 10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}



void Draw_atom_Ne(GLfloat x, GLfloat y, GLfloat z, int elec, int orbit)
{
	int i;
	glColor3f(0.0,1.0,0.5);
	Sprint(22,-20,2,"NEON");
	Sprint(20, 25,2,"  1st : 2");
	Sprint(20, 22,2,"  2nd : 8");
	glRotatef( 60, 1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef( x, y, z);
	glColor3f( 1.0, 0.0, 0.0);
	glutSolidSphere( 5, 16, 8);
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 10, 16, 32);
	glPushMatrix();
	glTranslatef(0, 10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 1.0, 0.0, 0.0);
	glRotatef(360 - orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 15, 16, 32);

	for ( i=0; i < 8; i++)

    {
		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 15, 0);
		glColor3f(0.0, 1.0, 0.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
   }
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void Draw_atom_Ar(GLfloat x, GLfloat y, GLfloat z, int elec, int orbit)

{

	int i;
	glColor3f(0.0,1.0,0.5);
	Sprint(22,-20,2,"ARGON");
	Sprint(20, 25,2,"  1st : 2");
	Sprint(20, 22,2,"  2nd : 8");
	Sprint(20, 19,2,"  3rd : 8");
	glRotatef( 60, 1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef( x, y, z);
	glColor3f( 1.0, 0.0, 0.0);
	glutSolidSphere( 5, 16, 8);
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 10, 16, 32);
	glPushMatrix();
	glTranslatef(0, 10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 1.0, 0.0, 0.0);
	glRotatef(360 - orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 15, 16, 32);
	for ( i=0; i < 8; i++)

	{

		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 15, 0);
		glColor3f(0.0, 1.0, 0.0);
  	              glutSolidSphere( 1, 16, 8);
		glPopMatrix();

	}

	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 0.0, 0.0, 1.0);
	glRotatef(270 - orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 20, 16, 32);
	for ( i=0; i < 8; i++)

	{

		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 20, 0);
		glColor3f(0.9, .5, .1);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}



void Draw_atom_Kr(GLfloat x, GLfloat y, GLfloat z, int elec, int orbit)

{

	int i;
	glColor3f(0.0,1.0,0.5);
	Sprint(22,-20,2,"KRYPTON");
	Sprint(20, 25,2,"  1st : 2");
	Sprint(20, 22,2,"  2nd : 8");
	Sprint(20, 19,2,"  3rd : 18");
	Sprint(20, 16,2,"  4th : 8");
	glRotatef( 60, 1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef( x, y, z);
	glColor3f( 1.0, 0.0, 0.0);
	glutSolidSphere( 5, 16, 8);
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 10, 16, 32);
	glPushMatrix();
	glTranslatef(0, 10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -10, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 1.0, 0.0, 0.0);
	glRotatef(360-orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 15, 16, 32);
	for ( i=0; i <8; i++)
	{
		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 15, 0);
		glColor3f(0.0, 1.0, 0.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 0.0, 0.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 20, 16, 32);
	for ( i=0; i < 18; i++)
	{
		glPushMatrix();
		glRotatef((360/18) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 20, 0);
		glColor3f(0.9, .5, .1);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 0.0, 1.0, 1.0);
	glRotatef(360 - orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 25, 16, 32);
	for ( i=0; i < 8; i++)
	{
		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 25, 0);
		glColor3f(1.0, 1.0, 0.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}
void Draw_atom_Xe(GLfloat x, GLfloat y, GLfloat z, int elec, int orbit)
{
	int i;
	glColor3f(0.0,1.0,0.5);
	Sprint(22,-20,2,"XENON");
	Sprint(20, 25,2,"  1st : 2");
	Sprint(20, 22,2,"  2nd : 8");
	Sprint(20, 19,2,"  3rd : 18");
	Sprint(20, 16,2,"  4th : 18");
	Sprint(20, 13,2,"  5th : 8");
	glRotatef( 60, 1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef( x, y, z);
	glColor3f( 1.0, 0.0, 0.0);
	glutSolidSphere( 5, 16, 8);
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 10, 16, 32);
	glPushMatrix();
	glTranslatef(0, 10, 0);
	glColor3f(0.0, 0.1, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -10, 0);
	glColor3f(0.0, 0.1, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 1.0, 0.0, 0.0);
	glRotatef(360-orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 15, 16, 32);
	for ( i=0; i <8; i++)
	{
		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 15, 0);
		glColor3f(0.0, 1.0, 0.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 0.0, 0.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 20, 16, 32);
	for ( i=0; i < 18; i++)
	{
		glPushMatrix();
		glRotatef((360/18) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 20, 0);
		glColor3f(0.9, .5, .1);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(60, 0.5, 0.0, 1.0);
	glRotatef(360-orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 25, 16, 32);
	for ( i=0; i < 18; i++)
	{
		glPushMatrix();
		glRotatef((360/18) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 25, 0);
		glColor3f(1,1,0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(50, .5, .8, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 30, 16, 32);
	for ( i=0; i < 8; i++)
	{
		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 30, 0);
		glColor3f(.9, .2, .0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void Draw_atom_Ra(GLfloat x, GLfloat y, GLfloat z, int elec, int orbit)
{
	int i;
	glColor3f(0.0,1.0,0.5);
	Sprint(22,-20,2,"RADON");
	Sprint(22, 25,2,"  1st : 2");
	Sprint(22, 22,2,"  2nd : 8");
	Sprint(22, 19,2,"  3rd : 18");
	Sprint(22, 16,2,"  4th : 32");
	Sprint(22, 13,2,"  5th : 18");
	Sprint(22, 10,2,"  6th : 8");
	glRotatef( 60, 1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef( x, y, z);
	glColor3f( 1.0, 0.0, 0.0);
	glutSolidSphere( 5, 16, 8);
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 8, 16, 32);
	glPushMatrix();
	glTranslatef(0, 8, 0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -8, 0);
               glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere( 1, 16, 8);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 1.0, 0.0, 0.0);
	glRotatef(360-orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 12, 16, 32);
	for ( i=0; i <8; i++)
	{
		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 12, 0);
		glColor3f(0.0, 1.0, 0.0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 0.0, 0.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 16, 16, 32);
	for ( i=0; i < 18; i++)
	{
		glPushMatrix();
		glRotatef((360/18) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 16, 0);
		glColor3f(0.9, .5, .1);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(60, 0.5, 0.0, 1.0);
	glRotatef(360-orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 20, 16, 32);
	for ( i=0; i <32; i++)
	{

	glPushMatrix();
		glRotatef((360/32) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 20, 0);
		glColor3f(1,1,0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(25, 0.0, 1.0, 1.0);
	glRotatef(orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 24, 16, 32);
	for ( i=0; i < 18; i++)
	{
		glPushMatrix();
		glRotatef((360/18) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 24, 0);
		glColor3f(.9, .2, .0);
		glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPushMatrix();
	glColor3f( 1.0, 1.0, 1.0);
	glRotatef(120, 0.5, 0.0, 0.5);
	glRotatef(360-orbit, 0, 0, 1);
	glutSolidTorus( 0.12, 28, 16, 32);
	for ( i=0; i <8; i++)
	{
		glPushMatrix();
		glRotatef((360/8) * i, 0.0, 0.0, 1.0);
		glTranslatef(0, 28, 0);

glColor3f(.9, 0.5, 1.0);

	glutSolidSphere( 1, 16, 8);
		glPopMatrix();
	}
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}
void invalid()
{
	glColor3f(1.0,0,5.0);
	Sprint(-10,0,2,"Please Press a KEY from 1 to 6 !");
}
void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-30.0, 30.0, -30.0, 30.0, -100.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (view_state == 1)
	{
		glColor3f( 1.0, 1.0, 1.0);
		Sprint(-8, 25,-10,"Perspective view");
		glMatrixMode (GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(65, 1, 1, 70);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt( 0, 0, 50, 0, 0, 0, 0, 1, 0);
	}
	else
	{
		glColor3f( 1.0, 1.0, 1.0);
		Sprint(-8, 25,-10,"Ortho view");
	}
	if (light_state == 1)
	{
		glDisable(GL_LIGHTING);
		glDisable(GL_COLOR_MATERIAL);
	}
	else
	{
		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);
	}
	glColor3f(1.0,0.0,0.0);

	Sprint(-30, 25,2,"1-Helium");
	Sprint(-30, 22,2,"2-Neon");
	Sprint(-30, 19,2,"3-Argon");
	Sprint(-30, 16,2,"4-Krypton");
	Sprint(-30, 13,2,"5-Xenon");
	Sprint(-30, 10,2,"6-Radon");
	Sprint(-30, 7,2,"7-hydrogen");
	Sprint(-30, 4,2,"ESC-exit");
	Sprint(-30,-25,2,"v-view ortho/perspective");
	Sprint(-30,-28,2,"l-lighting on/off");
    Sprint(-30, 4,2,"ESC-exit");
	glColor3f(0.0,1.0,0.0);
	Sprint(-17, 28,2,"ELECTRONIC CONFIGURATION OF NOBLE GASES");
	Sprint(-30, 28,2,"Keyboard Input");
	Sprint(20, 28,2,"orbit : electrons");
	if(state== 1)
	{
	Draw_atom_He( 0,0,0,1, spin++);
	}
	if(state == 2)
	{
	Draw_atom_Ne( 0,0,0,1, spin++);
	}
	if(state== 3)
	{
	Draw_atom_Ar( 0,0,0,1, spin++);
	}
              if(state== 4)
	{
	Draw_atom_Kr( 0,0,0,1, spin++);
	}
	if(state== 5)
	{
	Draw_atom_Xe( 0,0,0,1, spin++);
	}
	if(state== 6)
	{
	Draw_atom_Ra( 0,0,0,1, spin++);
	}
	if(state== 7)
	{
	Draw_atom_Hy( 0,0,0,1, spin++);
	}
	if(state== 8)
	{
		invalid();
	}
	glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
}
void specialKeyFunction(int key, int x, int y) // function to handle key pressing
{
	int w;
   switch(key)
	{
		case GLUT_KEY_RIGHT:
			 glutDisplayFunc(display);
			glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT:
			 glutDisplayFunc(screen1);
			glutPostRedisplay();
			break;
		case GLUT_KEY_HOME:
			glutPostRedisplay();
			break;

		case GLUT_KEY_F10:glutFullScreen(); break;


}
}
void keyboard (unsigned char key, int x, int y)

{

   switch (key)
   {
case 'w':glutDisplayFunc(display);
 case '1': state=1;
	   break;
   case '2':state=2;
	   break;
   case '3':state=3;
	   break;
   case '4':state=4;
	   break;
   case '5':state=5;
	   break;
   case '6':state=6;
	   break;
   case '7':state=7;
	   break;
   case 'v':
   case 'V':view_state = abs(view_state -1);
		break;
   case 'l':
   case 'L':light_state = abs(light_state -1);
		break;
  case 27:exit(0);
         break;
case '+':glutFullScreen(); break;
      default:state=7;
         break;
   }
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);
               glutInitWindowSize (1200, 700);
               glutInitWindowPosition (10, 10);
    glutCreateWindow (argv[0]);
    glutSetWindowTitle("GlutWindow");
    init ();
    glutDisplayFunc(screen1);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeyFunction);
    glutKeyboardFunc(keyboard);
    glutTimerFunc( 10,timer1, 1);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}

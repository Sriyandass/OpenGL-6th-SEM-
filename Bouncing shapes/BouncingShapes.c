#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif

#ifdef _WIN32
  #include <windows.h>
  #include "stdafx.h"
  #include <glut.h>
#endif

#ifdef __linux__
    #include <GL/glut.h>
#endif

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

/* definitions of circles */
#define PI 3.14159      // PI representation
#define NSEGMENTS 100   // number of circle segments
#define ORTHMAX 10.0    // width and length of actual frame
#define RADIUS 0.4      // radius

/* speed of animation of circles */
#define STEP1 0.02
#define STEP1N -0.02
#define STEP2 0.03
#define STEP2N -0.03
#define STEP3 0.04
#define STEP3N -0.04
#define STEP4 0.05
#define STEP4N -0.05
#define FACTOR 2.0

//definisions for square
#define VOL 150
#define NP 7
int sq_count = 3; //Numbber of squares
int sqtemp = 0;   //1 if squares are displayed
float L = 0.2;

struct square {
        int x;  // x position
        int y;  // y position
        int w;  // size
        int v;  // vertical velocity
        int vd; // vertical direction (1 or -1)
        int h;  // horizontal velocity
        int hd; // horizontal direction (1 or -1)
} *piec;

int ball_count = 3;  // Number of balls
/*
    Bouncing ball information
    ball_info[0][i] = x cord
    ball_info[1][i] = y cord
    ball_info[2][i] = x vector part
    ball_info[3][i] = y vector part
    ball_info[4][i] = Red Color Value
    ball_info[5][i] = Green Color Value
    ball_info[6][i] = blue Color Value
*/
float ball_info[7][10];
int temp = 0; //temporary variable to decide which idle function to use

/*
 * Defines parameters of the square to to be displayed
 * every square gets a unique colout and position
 * speed is the same as the 1st square to enable equal speed of all squares
 */
void SqPara(int i)
{
                switch(i)
                {
                    case 0:
                        piec[i].x = -100;
                        piec[i].y = 0;
                        piec[i].v = 8;
                        piec[i].h = 8;
                        break;
                    case 1:
                        piec[i].x = 10;
                        piec[i].y = 50;
                        break;
                    case 2:
                        piec[i].x = 50;
                        piec[i].y = 0;
                        break;
                    case 3:
                        piec[i].x = 75;
                        piec[i].y = 90;
                        break;
                    case 4:
                        piec[i].x = -50;
                        piec[i].y = 0;
                        break;
                    case 5:
                        piec[i].x = 100;
                        piec[i].y = -60;
                        break;
                    case 6:
                        piec[i].x = -120;
                        piec[i].y = -100;
                        break;
                }
                if((i % 2) == 0)
                {
                    piec[i].vd = 1;
                    piec[i].hd = 1;
                }
                else
                {
                    piec[i].vd = -1;
                    piec[i].hd = -1;
                }
                piec[i].w = 40;
                if (i != 0)
                {
                    piec[i].v = piec[i-1].v;
                    piec[i].h = piec[i-1].h;
                }
            return;
}

/*
 * Draws the aquares! Using glRectf(x1,y1,x2,y2);
 * (x1,y1) is a vertex and (x2,y2) is the diagonally opposite vertex
 */
void scene()
{
    int i;
    glClear(GL_DEPTH_BUFFER_BIT);
    for(i = 0; i < sq_count; i++)
    {
        switch(i)
        {
            case 0: glColor3f(0.0f, 1.0f, 0.0f); break;
            case 1: glColor3f(0.0f, 0.5f, 0.0f); break;
            case 2: glColor3f(0.0f, 0.0f, 0.5f); break;
            case 3: glColor3f(1.0f, 1.0f, 0.0f); break;
            case 4: glColor3f(0.5f, 0.0f, 0.0f); break;
            case 5: glColor3f(1.0f, 0.0f, 0.1f); break;
            case 6: glColor3f(1.0f, 1.0f, 1.0f); break;
        }
        glRectf(piec[i].x, piec[i].y, piec[i].x+piec[i].w, piec[i].y-piec[0].w);
    }
    glutSwapBuffers();
}

/*
 * Normal spetup fuction for a sqaure
 */
void setupSq(float R, float G, float B, GLdouble P)
{
    GLdouble N = 0 - P;
    glClearColor( R, G, B, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(N, P, N, P, N, P);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/*
 * This fuction checks for vertical collision of the squares
 * using the equation of sides and the known boundaries of the window and other squares
 */
void Vcollision (int P)
{
    int i;
    for (i = 0; i < sq_count;i ++)
    {
        if (i == P)
            continue;
        if ((piec[P].y == piec[i].y-piec[i].w) && (piec[P].x <= piec[i].x+piec[i].w) && (piec[P].x+piec[P].w >= piec[i].x))
        {
            piec[P].vd = -1;
            piec[P].y -= 1;
            if (piec[i].vd == -1)
                piec[i].vd=1;
            if (piec[P].v >= piec[i].v)
                piec[i].v--;
            else
            {
                piec[P].v++;
                piec[i].v++;
            }
        }
        else if ((piec[P].y - piec[P].w == piec[i].y) && (piec[P].x <= piec[i].x+piec[i].w) && (piec[P].x + piec[P].w >= piec[i].x))
        {
            piec[P].vd = 1;
            piec[P].y += 1;
            if (piec[i].vd == 1)
                piec[i].vd=-1;
            if (piec[P].v >= piec[i].v)
                piec[i].v--;
            else
            {
                piec[P].v++;
                piec[i].v++;
            }
        }
    }
}

/*
 * This fuction checks for horizontal collision of the squares
 * using the equation of sides and the known boundaries of the window and other squares
 */
void Hcollision (int P)
{
    int i;
    for (i = 0; i < sq_count; i++)
    {
        if (i == P)
            continue;
        if ((piec[P].x == piec[i].x + piec[i].w) && (piec[P].y >= piec[i].y - piec[i].w) && (piec[P].y - piec[P].w <= piec[i].y))
        {
            piec[P].hd = 1;
            piec[P].x += 1;
            if (piec[i].hd == 1)
                piec[i].hd = -1;
            if (piec[P].h >= piec[i].h)
                piec[i].h--;
            else
            {
                piec[P].h++;
                piec[i].h++;
            }
        }
        else if ((piec[P].x + piec[P].w == piec[i].x) && (piec[P].y >= piec[i].y - piec[i].w) && (piec[P].y - piec[P].w <= piec[i].y))
        {
            piec[P].hd = -1;
            piec[P].x -= 1;
            if (piec[i].hd == -1)
                piec[i].hd = 1;
            if (piec[P].h >= piec[i].h)
                piec[i].h--;
            else
            {
                piec[P].h++;
                piec[i].h++;
            }
        }
    }
}

/*
 * Defines the direction and speed of movement of the sqaures after a bounce
 * void glutTimerFunc(unsigned int msecs, void (*func)(int value), value);
 * registers the timer callback func to be triggered in at least msecs milliseconds.
 */
void move(int T)
{
        int i;
        if (T == 50)
            T = 1;
        for (i = 0; i < sq_count; i++)
        {
            if ((piec[i].v > 0) && (T%piec[i].v == 0))
            {
                piec[i].y += piec[i].vd;
                if (piec[i].y - piec[i].w <= -VOL)
                {
                    piec[i].vd = 1;
                    piec[i].y = -VOL + piec[i].w+1;
                    piec[i].v--;
                }
                else if (piec[i].y >= VOL)
                {
                    piec[i].vd = -1;
                    piec[i].y = VOL - 1;
                    piec[i].v--;
                }
                Vcollision(i);
            }
            if ((piec[i].h > 0) && (T % piec[i].h == 0))
            {
                piec[i].x += piec[i].hd;
                if (piec[i].x + piec[i].w >= VOL)
                {
                    piec[i].hd = -1;
                    piec[i].x = VOL-piec[i].w-1;
                    piec[i].h--;
                }
                else if (piec[i].x <= -VOL)
                {
                    piec[i].hd = 1;
                    piec[i].x = -VOL + 1;
                    piec[i].h--;
                }
                Hcollision(i);
            }
            if (piec[i].v <= 1)
                piec[i].v = 2;       // min-max speeds
            else if (piec[i].v > 30)
                piec[i].v = 31;
            if (piec[i].h <= 1)
                piec[i].h = 2;
            else if (piec[i].h > 30)
                piec[i].h = 31;
        }
        scene();
        glutTimerFunc(L, move, ++T);
}

/*
 * Draws a circle!
 * With a center point (xc,yc) and radius RADIUS (defined uptop)
 */
void drawBall(float xc, float yc)
{
    int j;
    GLfloat phi;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc, yc);

    for ( j = 0; j <= NSEGMENTS; j++)
    {
        phi = j * 2 * PI/NSEGMENTS;
        GLfloat x1 = xc + RADIUS*cos(phi);
        GLfloat y1 = yc + RADIUS*sin(phi);
        glVertex2f(x1, y1);
    }
    glEnd();
}

/*
 *  Displays the screen and draws the circles in the correct location.
 */
void ourDisplay(void)
{
    temp = 0;
    glClear(GL_DEPTH_BUFFER_BIT);
    int i;
    for (i = 0; i < ball_count; ++i)
    {
        glColor3f(ball_info[4][i],ball_info[5][i],ball_info[6][i]);
        drawBall(ball_info[0][i],ball_info[1][i]);
    }
    glutSwapBuffers();
    glutPostRedisplay();
}

/*
 * This function is the idle function that continuously gets prompted. It steps the animation
 * one move and changes the step based on whether or not the balls are hitting each other or
 * the exterior walls.
 */
void idle()
{
    int i,j;
    if(temp == 1)
    {
        int z=30;
        z--;
        if(z==30)
		z=600;
		temp =0;
    }
    else if(temp == 0)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Loops through the ball matrix based on the number of balls
        for ( i = 0; i < ball_count; ++i)
        {

            // Checks for Vertical Wall collition
            if ((ball_info[0][i] + ball_info[2][i] >=  (ORTHMAX - RADIUS)) || ball_info[0][i] + ball_info[2][i] <= RADIUS)
            {
                ball_info[2][i] = ball_info[2][i] * -1.0;
            }

            // Checks fro horizontal Wall collition
            if ((ball_info[1][i] + ball_info[3][i] >=  (ORTHMAX - RADIUS)) || ball_info[1][i] + ball_info[3][i] <= RADIUS)
            {
                ball_info[3][i] = ball_info[3][i] * -1.0;
            }

            // Loops through and checks for other ball collition
            for ( j = 0; j < ball_count; ++j)
            {

                // Calculates the distance between two circle's center
                float vector_bt_x, vector_bt_y, x_dis, y_dis;
                vector_bt_x = ball_info[0][i] - ball_info[0][j]; // dx
                vector_bt_y = ball_info[1][i] - ball_info[1][j]; // dy
                float check_value = (vector_bt_x * vector_bt_x)+(vector_bt_y * vector_bt_y);
                if (check_value <= 4*RADIUS*RADIUS)
                {
                    x_dis = ball_info[2][j] - ball_info[2][i]; // dv_x
                    y_dis = ball_info[3][j] - ball_info[3][i]; // dv_y
                    float dot_pro = (x_dis*vector_bt_x) + (y_dis*vector_bt_y);
                    if (dot_pro > 0)
                    {
                        float factor = (dot_pro / check_value);
                        float x_change, y_change;
                        x_change = vector_bt_x * factor;
                        y_change = vector_bt_y * factor;
                        ball_info[2][i] = ball_info[2][i] + x_change;
                        ball_info[3][i] = ball_info[3][i] + y_change;
                        ball_info[2][j] = ball_info[2][j] - x_change;
                        ball_info[3][j] = ball_info[3][j] - y_change;
                    }
                }
            }
            // Steps the animation one step
            ball_info[0][i] = ball_info[0][i] + ball_info[2][i];
            ball_info[1][i] = ball_info[1][i] + ball_info[3][i];
        }
    }
    glutPostRedisplay();
}

/*
 * This fuction sets up all the information about each circle and where it will
 * be positioned at the start and what their directional vectors will be.
 */
void setup()
{
    int i;
    srand(time(NULL));
    float start = RADIUS;
    float end = ORTHMAX - RADIUS;

    //Sets the directional vector for each the x and y for each ball
    //and the color of the given ball
    for (i = 0; i < ball_count; ++i)
    {
        float x, y;

        if (i % 2 == 0)
        {
            x = end - i;
            y = end - i;
        }
        else{
            x = start + i;
            y = end - i;
        }
        ball_info[0][i] = x;
        ball_info[1][i] = y;

        //Sets the directional vectors for each circle
        if (i % 5 == 0)
        {
            ball_info[2][i] =  STEP1;
            ball_info[3][i] =  STEP3;

        }
        else if (i % 5 == 1)
        {
            ball_info[2][i] = STEP1N;
            ball_info[3][i] = STEP2;

        }
        else if (i % 5 == 2)
        {
            ball_info[2][i] = STEP4;
            ball_info[3][i] = STEP1N;

        }
        else if(i % 5 == 3)
        {
            ball_info[2][i] = STEP2;
            ball_info[3][i] = STEP2N;

        }
        else
        {
            ball_info[2][i] = STEP3N;
            ball_info[3][i] = STEP4N;
        }
        ball_info[4][i] = rand()%100/100.0;
        ball_info[5][i] = rand()%100/100.0;
        ball_info[6][i] = rand()%100/100.0;
    }
}

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

/*
 * Creates the front page of the program that maps the charater array (an[]) at given positions.
 */
void screen1()
{
    temp = 1;
    char a1[]="   Graphical Implementation of ";
    char a2[]="  BOUNCING SQUARES AND";
	char a3[]="                 CIRCLES";
	char a4[]="SUBMITTED BY";
	char a5[]="SRIYANDASS A                                                             GOWRISH SHANBHOGUE";
	char a6[]="1BY12CS001                                                                 1BY12CS096";
	char a7[]="Under the guidance of";
	char a8[]="Mrs.MARI KIRTHIMA";
	char a9[]="Asst. Professor";
	char a10[]="     BMSIT,Yelahanka,Bangalore";
	char a11[]="   Press S for square and C for circle ";
	char a12[]="Ms. AMBIKA. G. N.";
	char a13[]="Asst. Professor";
	char a14[]="Dept of CSE                                                                   Dept of CSE";
	char a15[]="BMSIT                                                                            BMSIT";
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
	glRasterPos2f(240.0,500.0);
	for(i=0;i<sizeof(a1);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18  ,a1[i]);

	glColor3f(1.0,0.5,0.0);
	glRasterPos2f(240.0,475.0);
	for(i=0;i<sizeof(a2);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18  ,a2[i]);

	glColor3f(1.0,0.5,0.0);
	glRasterPos2f(240.0,450.0);
	for(i=0;i<sizeof(a3);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18  ,a3[i]);

	glColor3f(1.0,0.2,0.3);
	glRasterPos2f(295.0,370.0);
	for(i=0;i<sizeof(a4);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18  ,a4[i]);

	glColor3f(0.0,0.5,1.0);
	glRasterPos2f(70.0,290.0);
	for(i=0;i<sizeof(a5);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18  ,a5[i]);

	glColor3f(0.0,0.5,1.0);
	glRasterPos2f(70.0,270.0);
	for(i=0;i<sizeof(a6);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 ,a6[i]);

	glColor3f(1.0,0.0,0.0);
	glRasterPos2f(270.0,220.0);
	for(i=0;i<sizeof(a7);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18  ,a7[i]);

	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(70.0,200.0);
	for(i=0;i<sizeof(a8);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 ,a8[i]);

	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(70.0,180.0);
	for(i=0;i<sizeof(a9);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 ,a9[i]);

	glColor3f(1.0,0.0,0.0);
	glRasterPos2f(10.0,20.0);
	for(i=0;i<sizeof(a10);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 ,a10[i]);

	glColor3f(0.2,0.6,0.3);
	glRasterPos2f(220.0,100.0);
	for(i=0;i<sizeof(a11);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 ,a11[i]);

	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(510.0,200.0);
	for(i=0;i<sizeof(a12);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 ,a12[i]);

	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(510.0,180.0);
	for(i=0;i<sizeof(a13);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 ,a13[i]);

	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(70.0,160.0);
	for(i=0;i<sizeof(a14);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 ,a14[i]);

	glColor3f(1.0,1.0,0.0);
	glRasterPos2f(70.0,140.0);
	for(i=0;i<sizeof(a15);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 ,a15[i]);

    glutPostRedisplay();
	glPopMatrix();
	resetPerspectiveProjection();
	glutSwapBuffers();
	glFlush();
}

/*
 * Mouse clicks increase and decrease speed of balls or squares
 * Left mouse click speeds it up | Right mouse click slows it down.
 */
void myMouse(int butt, int state, int x, int y)
{
    int i;
    if (state == GLUT_DOWN && butt == GLUT_LEFT_BUTTON)
    {
        if(sqtemp != 1)
            /* incerase speed of ball by a factor of 2 */
            for ( i = 0; i < ball_count; ++i)
            {
                ball_info[2][i] = ball_info[2][i] * FACTOR;
                ball_info[3][i] = ball_info[3][i] * FACTOR;
            }
        else if(sqtemp == 1)
            /* incerase speed of square by a factor of 2 */
            for(i = 0; i < 7; i++)
            {
                piec[i].v = piec[i].v - 2;
                piec[i].h = piec[i].v - 2;
            }
    }
    if (state == GLUT_DOWN && butt == GLUT_RIGHT_BUTTON)
    {
        if(sqtemp != 1)
            /* slow speed of ball by a factor of 2 */
            for ( i = 0; i < ball_count; ++i)
            {
                ball_info[2][i] = ball_info[2][i] / FACTOR;
                ball_info[3][i] = ball_info[3][i] / FACTOR;
            }
        else if (sqtemp == 1)
            /* decrease speed of square by a factor of 2 */
            for(i = 0; i < sq_count; i++)
            {
                piec[i].v = piec[i].v + 2;
                piec[i].h = piec[i].v + 2;
            }
    }
}

/*
 * This fuction is used to specify keyboard fuctionalitites of the program:
 * e = exit the program.
 * s = display bouncing squares.
 * c = display bouncing circles.
 * - = decrease the number of circles or squares. Minimum value = 1.
 * + = increase the number of circles or squares. Maximum value = 7.
 */
void myKeyboard (unsigned char key, int x, int y)
{
    int i;
    switch (key)
    {
        case 'e': exit(0);
        case 's':
        case 'S':
        {
            sqtemp = 1;
            ball_count = 0;
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(scene);
            glutTimerFunc(0,move,1);
            piec = malloc(NP*sizeof(*piec));
            for (i = 0; i < sq_count; i++)
                SqPara(i);
            setupSq(0.0,0.0,0.0,VOL);
            glutPostRedisplay();
            break;
        }
        case 'c':
        case 'C':
        {
            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
            glutDisplayFunc(ourDisplay);
            setup();
            glutPostRedisplay();
            break;
        }
        case '-':
        {
            if (sqtemp == 1)
            {
                if(sq_count == 1)
                    return;
                sq_count--;
                setupSq(0.0,0.0,0.0,VOL);
            }
            else
            {
                if(ball_count == 1)
                    return;
                i = ball_count--;
                ball_info[0][i] = 0;
                ball_info[1][i] = 0;
                ball_info[2][i] = 0;
                ball_info[3][i] = 0;
                ball_info[4][i] = 0.0;
                ball_info[5][i] = 0.0;
                ball_info[6][i] = 0.0;
            }
            glutPostRedisplay();
            break;
        }
        case '+':
        {
            if (sqtemp == 1)
            {
                if(sq_count == 7)
                    return;
                SqPara(sq_count++);
                setupSq(0.0,0.0,0.0,VOL);
            }
            else
            {
                if(ball_count == 7)
                    return;
                int i = ball_count++;
                ball_info[0][i] = ball_info[0][i-1];
                ball_info[1][i] = ball_info[0][i-1];
                ball_info[2][i] = ball_info[2][i-1];
                ball_info[3][i] = ball_info[3][i-1];
                ball_info[4][i] = rand()%100/100.0;
                ball_info[5][i] = rand()%100/100.0;
                ball_info[6][i] = rand()%100/100.0;
            }
            glutPostRedisplay();
            break;
        }
    }
}

/*
 *  Standard init function
 */
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, ORTHMAX, 0.0, ORTHMAX);
}

int main(int argc, char** argv)
{
    printf("Press S for squares and C for circles.\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Bouncing Shapes");
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(myMouse);
    glutIdleFunc(idle);
    init();
    glutDisplayFunc(screen1);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}

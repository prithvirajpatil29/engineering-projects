#include<windows.h>
#include<GL/glut.h>
#include <math.h>
#include <iostream>
#include <stdio.h>

int a[16] = { 220,97,144,152,55,171,108,86,168,99,0,207,238,235,233,167 }; // array a,b,c for colors
int b[16] = { 53,194,110,152,153,184,137,3,55,138,0,43,240,255,203,8 };
int c[16] = { 5,243,133,253,33,228,141,18,46,95,75,1,253,204,169,130 };
static float angle = 0.0, ratioF;
static float x = 0.0f, y = 1.75f, z = 5.0f;
static float lx = 0.10f, ly = 0.10f, lz = -1.0f;
static GLint carDisplayList;
float theta = 0.01, fxincr = 0.1, fzincr = 0, temp, theta1, fx = -30, fz = 1;
int xxxx = 0, yyyy = 0, kk = 0, moveCarVar = 0;


void changeSize(int w, int h) {


	if (h == 0)
		h = 1;
	ratioF = 1.0f * w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45, ratioF, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f);
}

void drawCar()
{

	glTranslatef(0.0, 0.8, 0.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ZERO);
	//Drawing lines to draw a car. Each letter is the name of the coordinate point of the blueprint.
	glBegin(GL_LINE_LOOP);
		glVertex3f(-1.12, -.48, 0.7);//a
		glVertex3f(-0.86, -.48, 0.7);//b
		glVertex3f(-.74, -0.2, 0.7);//c
		glVertex3f(-.42, -.2, 0.7);//d
		glVertex3f(-0.3, -.48, 0.7);//e
		glVertex3f(.81, -0.48, 0.7);//f
		glVertex3f(.94, -0.2, 0.7);//g
		glVertex3f(1.24, -.2, 0.7);//h
		glVertex3f(1.38, -.48, 0.7);//i
		glVertex3f(1.52, -.44, 0.7);//j
		glVertex3f(1.52, .14, 0.7);//k
		glVertex3f(1.14, 0.22, 0.7);//l
		glVertex3f(0.76, .22, 0.7);//m
		glVertex3f(.52, 0.56, 0.7);//n
		glVertex3f(-0.1, 0.6, 0.7);//0
		glVertex3f(-1.02, 0.6, 0.7);//p
		glVertex3f(-1.2, 0.22, 0.7);//q
		glVertex3f(-1.2, -.28, 0.7);//r
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex3f(-1.12, -.48, -0.7);//a'
		glVertex3f(-0.86, -.48, -0.7);//b'
		glVertex3f(-.74, -0.2, -0.7);//c'
		glVertex3f(-.42, -.2, -0.7);//d'
		glVertex3f(-0.3, -.48, -0.7);//e'
		glVertex3f(.81, -0.48, -0.7);//f'
		glVertex3f(.94, -0.2, -0.7);//g'
		glVertex3f(1.24, -.2, -0.7);//h'
		glVertex3f(1.38, -.48, -0.7);//i'
		glVertex3f(1.52, -.44, -0.7);//j'
		glVertex3f(1.52, .14, -0.7);//k'
		glVertex3f(1.14, 0.22, -0.7);//l'
		glVertex3f(0.76, .22, -0.7);//m'
		glVertex3f(.52, 0.56, -0.7);//n'
		glVertex3f(-0.1, 0.6, -0.7);//o'
		glVertex3f(-1.02, 0.6, -0.7);//p'
		glVertex3f(-1.2, 0.22, -0.7);//q'
		glVertex3f(-1.2, -.28, -0.7);//r'
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(-1.12, -.48, 0.7);//a
		glVertex3f(-1.12, -.48, -0.7);//a'
		glVertex3f(-0.86, -.48, 0.7);//b
		glVertex3f(-0.86, -.48, -0.7);//b'
		glVertex3f(-.74, -0.2, 0.7);//c
		glVertex3f(-.74, -0.2, -0.7);//c'
		glVertex3f(-.42, -.2, 0.7);//d
		glVertex3f(-.42, -.2, -0.7);//d'
		glVertex3f(-0.3, -.48, 0.7);//e
		glVertex3f(-0.3, -.48, -0.7);//e'
		glVertex3f(.81, -0.48, 0.7);//f
		glVertex3f(.81, -0.48, -0.7);//f'
		glVertex3f(.94, -0.2, 0.7);//g
		glVertex3f(.94, -0.2, -0.7);//g'
		glVertex3f(1.24, -.2, 0.7);//h
		glVertex3f(1.24, -.2, -0.7);//h'
		glVertex3f(1.38, -.48, 0.7);//i
		glVertex3f(1.38, -.48, -0.7);//i'
		glVertex3f(1.52, -.44, 0.7);//j
		glVertex3f(1.52, -.44, -0.7);//j'
		glVertex3f(1.52, .14, 0.7);//k
		glVertex3f(1.52, .14, -0.7);//k'
		glVertex3f(1.14, 0.22, 0.7);//l
		glVertex3f(1.14, 0.22, -0.7);//l'
		glVertex3f(0.76, .22, 0.7);//m
		glVertex3f(0.76, .22, -0.7);//m'
		glVertex3f(.52, 0.56, 0.7);//n
		glVertex3f(.52, 0.56, -0.7);//n'
		glVertex3f(-0.1, 0.6, 0.7);//0
		glVertex3f(-0.1, 0.6, -0.7);//o'
		glVertex3f(-1.02, 0.6, 0.7);//p
		glVertex3f(-1.02, 0.6, -0.7);//p'
		glVertex3f(-1.2, 0.22, 0.7);//q
		glVertex3f(-1.2, 0.22, -0.7);//q'
		glVertex3f(-1.2, -.28, 0.7);//r
		glVertex3f(-1.2, -.28, -0.7);//r'
	glEnd();


	 // car ceiling filling
	glBegin(GL_POLYGON);
		glVertex3f(-0.1, 0.6, 0.7);//o
		glVertex3f(-0.1, 0.6, -0.7);//o'
		glVertex3f(-1.02, 0.6, -0.7);//p'
		glVertex3f(-1.02, 0.6, 0.7);//p
	glEnd();


	glBegin(GL_POLYGON);
		glVertex3f(-0.1, 0.6, 0.7);//o
		glVertex3f(-0.1, 0.6, -0.7);//o'
		glVertex3f(.52, 0.56, -0.7);//n'
		glVertex3f(.52, 0.56, 0.7);//n
	glEnd();

	 //fill the back of the car
	glBegin(GL_POLYGON);
		glVertex3f(-1.2, 0.22, 0.7);//q
		glVertex3f(-1.2, 0.22, -0.7);//q'
		glVertex3f(-1.2, -.28, -0.7);//r'
		glVertex3f(-1.2, -.28, 0.7);//r
	glEnd();



	glBegin(GL_POLYGON);
		glVertex3f(1.52, .14, 0.7);//k
		glVertex3f(1.14, 0.22, 0.7);//l
		glVertex3f(1.14, 0.22, -0.7);//l'
		glVertex3f(1.52, .14, -0.7);//k'
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(0.76, .22, 0.7);//m
		glVertex3f(0.76, .22, -0.7);//m'
		glVertex3f(1.14, 0.22, -0.7);//l'
		glVertex3f(1.14, 0.22, 0.7);//l
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(-1.12, -.48, 0.7);//a
		glVertex3f(-0.86, -.48, 0.7);//b
		glVertex3f(-.74, -0.2, 0.7);//c
		glVertex3f(-0.64, 0.22, 0.7);//cc
		glVertex3f(-1.08, 0.22, 0.7);//dd
		glVertex3f(-1.2, 0.22, 0.7);//q
		glVertex3f(-1.2, -.28, 0.7);//r
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(-.74, -0.2, 0.7);//c
		glVertex3f(-0.64, 0.22, 0.7);//cc
		glVertex3f(-0.5, 0.22, 0.7);//hh
		glVertex3f(-0.5, -0.2, 0.7);//pp
	glEnd();

	 //Filling the wheel seams
	glBegin(GL_POLYGON);
		glVertex3f(0.0, 0.22, 0.7);//gg
		glVertex3f(1.14, 0.22, 0.7);//l
		glVertex3f(1.24, -.2, 0.7);//h
		glVertex3f(0.0, -0.2, 0.7);//oo
	glEnd();

	 //Filling the empty space on the left rear wheel
	glBegin(GL_POLYGON);
		glVertex3f(-1.12, -.48, -0.7);//a'
		glVertex3f(-0.86, -.48, -0.7);//b'
		glVertex3f(-.74, -0.2, -0.7);//c'
		glVertex3f(-0.64, 0.22, -0.7);//cc'
		glVertex3f(-1.08, 0.22, -0.7);//dd'
		glVertex3f(-1.2, 0.22, -0.7);//q'
		glVertex3f(-1.2, -.28, -0.7);//r'
	glEnd();

	 //fill in the rest
	glBegin(GL_POLYGON);
		glVertex3f(-.74, -0.2, -0.7);//c'
		glVertex3f(-0.64, 0.22, -0.7);//cc'
		glVertex3f(-0.5, 0.22, -0.7);//hh'
		glVertex3f(-0.5, -0.2, -0.7);//pp'
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(0.0, 0.22, -0.7);//gg'
		glVertex3f(1.14, 0.22, -0.7);//l'
		glVertex3f(1.24, -.2, -0.7);//h'
		glVertex3f(0.0, -0.2, -0.7);//oo'
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(-1.2, 0.22, 0.7);//q
		glVertex3f(-1.08, 0.22, 0.7);//dd
		glVertex3f(-0.98, 0.5, 0.7);//aa
		glVertex3f(-1.02, 0.6, 0.7);//p
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(-1.02, 0.6, 0.7);//p
		glVertex3f(-0.98, 0.5, 0.7);//aa
		glVertex3f(0.44, 0.5, 0.7);//jj
		glVertex3f(.52, 0.56, 0.7);//n
		glVertex3f(-0.1, 0.6, 0.7);//0
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(-0.64, 0.5, 0.7);//bb
		glVertex3f(-0.64, 0.22, 0.7);//cc
		glVertex3f(-0.5, 0.22, 0.7);//hh
		glVertex3f(-0.5, 0.5, 0.7);//ee
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(0.0, 0.5, 0.7);//ff
		glVertex3f(0.0, 0.22, 0.7);//gg
		glVertex3f(0.12, 0.22, 0.7);//ll
		glVertex3f(0.12, 0.5, 0.7);//ii
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(.52, 0.56, 0.7);//n
		glVertex3f(0.44, 0.5, 0.7);//jj
		glVertex3f(0.62, 0.22, 0.7);//kk
		glVertex3f(0.76, .22, 0.7);//m
	glEnd();

	 //car underside
	glBegin(GL_POLYGON);
		glVertex3f(-.42, -.2, 0.7);//d
		glVertex3f(.94, -0.2, 0.7);//g
		glVertex3f(.81, -0.48, 0.7);//f
		glVertex3f(-0.3, -.48, 0.7);//e
	glEnd();

	// the bottom of the car
	glBegin(GL_POLYGON);
		glVertex3f(1.14, 0.22, 0.7);//l
		glVertex3f(1.52, .14, 0.7);//k
		glVertex3f(1.52, -.44, 0.7);//j
		glVertex3f(1.38, -.48, 0.7);//i
		glVertex3f(1.24, -.2, 0.7);//h
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(-1.2, 0.22, -0.7);//q'
		glVertex3f(-1.08, 0.22, -0.7);//dd'
		glVertex3f(-0.98, 0.5, -0.7);//aa'
		glVertex3f(-1.02, 0.6, -0.7);//p'
	glEnd();

	 //Fill in the space where the ceiling meets the glass
	glBegin(GL_POLYGON);
		glVertex3f(-1.02, 0.6, -0.7);//p'
		glVertex3f(-0.98, 0.5, -0.7);//aa'
		glVertex3f(0.44, 0.5, -0.7);//jj'
		glVertex3f(.52, 0.56, -0.7);//n'
		glVertex3f(-0.1, 0.6, -0.7);//o'
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(-0.64, 0.5, -0.7);//bb'
		glVertex3f(-0.64, 0.22, -0.7);//cc'
		glVertex3f(-0.5, 0.22, -0.7);//hh'
		glVertex3f(-0.5, 0.5, -0.7);//ee'
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(0.0, 0.5, -0.7);//ff'
		glVertex3f(0.0, 0.22, -0.7);//gg'
		glVertex3f(0.12, 0.22, -0.7);//ll'
		glVertex3f(0.12, 0.5, -0.7);//ii'
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(.52, 0.56, -0.7);//n'
		glVertex3f(0.44, 0.5, -0.7);//jj'
		glVertex3f(0.62, 0.22, -0.7);//kk'
		glVertex3f(0.76, .22, -0.7);//m'
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(-.42, -.2, -0.7);//d'
		glVertex3f(.94, -0.2, -0.7);//g'
		glVertex3f(.81, -0.48, -0.7);//f'
		glVertex3f(-0.3, -.48, -0.7);//e'
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(1.14, 0.22, -0.7);//l'
		glVertex3f(1.52, .14, -0.7);//k'
		glVertex3f(1.52, -.44, -0.7);//j'
		glVertex3f(1.38, -.48, -0.7);//i'
		glVertex3f(1.24, -.2, -0.7);//h'
	glEnd();


	 // right rear door
	glBegin(GL_POLYGON);
		glVertex3f(-0.5, 0.22, 0.7);//hh
		glVertex3f(0.0, 0.22, 0.7);//gg
		glVertex3f(0.0, -0.2, 0.7);//oo
		glVertex3f(-0.5, -0.2, 0.7);//pp
	glEnd();

	//left rear door
	glBegin(GL_POLYGON);
		glVertex3f(-0.5, 0.22, -0.7);//hh'
		glVertex3f(0.0, 0.22, -0.7);//gg'
		glVertex3f(0.0, -0.2, -0.7);//oo'
		glVertex3f(-0.5, -0.2, -0.7);//pp'
	glEnd();


	glBegin(GL_POLYGON);
		glVertex3f(0.12, 0.22, 0.7);//ll
		glVertex3f(0.62, 0.22, 0.7);//kk
		glVertex3f(0.62, -0.2, 0.7);//mm
		glVertex3f(0.12, -0.2, 0.7);//nn
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(0.12, 0.22, -0.7);//ll'
		glVertex3f(0.62, 0.22, -0.7);//kk'
		glVertex3f(0.62, -0.2, -0.7);//mm'
		glVertex3f(0.12, -0.2, -0.7);//nn'
	glEnd();


	 // Filling in the blank in the front when viewed from the rear
	glBegin(GL_POLYGON);
		glVertex3f(1.52, .14, 0.7);//k
		glVertex3f(1.52, .14, -0.7);//k'
		glVertex3f(1.52, -.44, -0.7);//j'
		glVertex3f(1.52, -.44, 0.7);//j
	glEnd();

	 //tire drawing
	glTranslatef(-.58, -.52, 0.7); //first tire
	glColor3f(0.1, 0.1, 0.1); //tire color
	glutSolidTorus(0.12f, .14f, 10, 25);
	glTranslatef(1.68, 0.0, 0.0); //second tire
	glutSolidTorus(0.12f, .14f, 10, 25);

	glTranslatef(0.0, 0.0, -1.4);//third tire
	glutSolidTorus(0.12f, .14f, 10, 25);
	glTranslatef(-1.68, 0.0, 0.0); //fourth
	glutSolidTorus(0.12f, .14f, 10, 25);
	glTranslatef(.58, .52, 0.7);//original
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, -1.40);

	glutSolidTorus(0.2f, .2f, 10, 25); //tires on the back of the car. For decoration.

	glTranslatef(0.0, 0.0, 1.40);
	glRotatef(270.0, 0.0, 1.0, 0.0);


	//glColor3f(1.0, 1.0, 1.0);

	 //car window code
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //glass is translucent

	//windscreen //front windshield
	glBegin(GL_POLYGON);
	glColor4f(0.0, 0.0, 0.0, 0.7);   //color: translucent black
		glVertex3f(0.562, .5, .6);//AAA
		glVertex3f(.562, .5, -.6);//AAA'
		glVertex3f(.76, .22, -.6);//MMM'
		glVertex3f(.76, .22, .6);//MMM
	glEnd();

	 //rear windshield
	glBegin(GL_POLYGON);
		glVertex3f(-1.068, 0.5, 0.6);//pp
		glVertex3f(-1.068, 0.5, -0.6);//pp'
		glVertex3f(-1.2, 0.22, -0.6);//qq'
		glVertex3f(-1.2, 0.22, 0.6);//qq
	glEnd();

        //right rear seat glass
	glBegin(GL_POLYGON);
	glVertex3f(-0.98, 0.5, 0.7);//aa
	glVertex3f(-0.64, 0.5, 0.7);//bb
	glVertex3f(-0.64, 0.22, 0.7);//cc
	glVertex3f(-1.08, 0.22, 0.7);//dd
	glEnd();

	// left rear seat glass
	glBegin(GL_POLYGON);
		glVertex3f(-0.98, 0.5, -0.7);//aa
		glVertex3f(-0.64, 0.5, -0.7);//bb
		glVertex3f(-0.64, 0.22, -0.7);//cc
		glVertex3f(-1.08, 0.22, -0.7);//dd
	glEnd();


	// right middle glass
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, 0.5, 0.7);
	glVertex3f(0.0, 0.5, 0.7);
	glVertex3f(0.0, 0.22, 0.7);
	glVertex3f(-0.5, 0.22, 0.7);
	glEnd();

	// left middle glass
	glBegin(GL_POLYGON);
		glVertex3f(-0.5, 0.5, -0.7);
		glVertex3f(0.0, 0.5, -0.7);
		glVertex3f(0.0, 0.22, -0.7);
		glVertex3f(-0.5, 0.22, -0.7);
	glEnd();

	//Right front seat glass
	glBegin(GL_POLYGON);
		glVertex3f(0.12, 0.5, 0.7);//ii
		glVertex3f(0.44, 0.5, 0.7);//jj
		glVertex3f(0.62, 0.22, 0.7);//kk
		glVertex3f(0.12, 0.22, 0.7);//ll
	glEnd();


	//Left front seat glass

	glBegin(GL_POLYGON);
		glVertex3f(0.12, 0.5, -0.7);//ii'
		glVertex3f(0.44, 0.5, -0.7);//jj'
		glVertex3f(0.62, 0.22, -0.7);//kk'
		glVertex3f(0.12, 0.22, -0.7);//ll'
	glEnd();



	glColor3f(0.0, 0.0, 1.0);
}

void drawLine() { // Function to draw parking lines
	glLineWidth(5);

	// vertical line in front of the right car
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(12.5, 0.0, 5.5);
	glVertex3f(12.5, 0.0, -9.5);
	glEnd();
	// vertical line behind the right car
	glBegin(GL_LINE_LOOP);
	glVertex3f(17.5, 0.0, 5.5);
	glVertex3f(17.5, 0.0, -9.5);
	glEnd();

	// Draw a horizontal line from the blue car
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(12.5, 0.0, 5.5);
	glVertex3f(17.5, 0.0, 5.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(12.5, 0.0, 2.0);
	glVertex3f(17.5, 0.0, 2.0);
	glEnd();


	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(12.5, 0.0, -2.5);
	glVertex3f(17.5, 0.0, -2.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(12.5, 0.0, -6.0);
	glVertex3f(17.5, 0.0, -6.0);
	glEnd();

	//the last horizontal line of mint tea
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(12.5, 0.0, -9.5);
	glVertex3f(17.5, 0.0, -9.5);
	glEnd();
}


GLuint DisplayList() { // Speed ​​up using lists. found on the internet
	GLuint carDL; // Declare the abbreviation of the function name as a variable name.

	// list formation
	carDL = glGenLists(1);

	// list declaration. start.
	glNewList(carDL, GL_COMPILE);

	// Call a function to draw a car.
	drawCar();

	// list End
	glEndList();

	return(carDL);
}


void initScene()
{
	glEnable(GL_DEPTH_TEST); // Depth Buffer Formation
	carDisplayList = DisplayList(); // Function call on line 470
	//carDisplayList : Global variable on line 13
}


void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.7, 0.85, 1.0, 1.0); // Sky blue

	//drawing the ground

	glColor3f(0.25f, 0.25f, 0.25f);
	glBegin(GL_QUADS); // Square
		glVertex3f(-50.0f, 0.0f, -50.0f);
		glVertex3f(-50.0f, 0.0f, 50.0f);
		glVertex3f(50.0f, 0.0f, 50.0f);
		glVertex3f(50.0f, 0.0f, -50.0f);
	glEnd();
	drawLine();
	// drawing cars in parking lot
	for (int i = -2; i < 2; i++) {
		glPushMatrix();
		glTranslatef(-15, 0, (i) * 4.0); // Rotate it with Translatef and draw it.
		glColor3ub(c[i], b[i], b[i]); // Colors are entered as array values ​​declared as global variables
		glCallList(carDisplayList);	// List call.
		glPopMatrix();
	}
	for (int i = -2; i < 2; i++) {
			glPushMatrix();
			glTranslatef(0, 0, (i) * 4.0); // Rotate it with Translatef and draw it.
			glColor3ub(a[i], a[i], c[i]); // Colors are entered as array values ​​declared as global variables
			glCallList(carDisplayList);	// List call.
			glPopMatrix();
		}
	for (int i = -2; i < 0; i++) {
		glPushMatrix();
		glTranslatef(15, 0, (i) * 4.0); // Rotate it with Translatef and draw it.
		glColor3ub(a[i], b[i], c[i]); // Add color to the array value declared as a global variable.
		glCallList(carDisplayList);	// call the list.
		glPopMatrix();
	}
		glPushMatrix();
		glTranslatef(15, 0, 4.0); // Rotate and draw with Translatef.
		glColor3ub(2, 32, 122); // Color is assigned to an array value declared as a global variable..
		glCallList(carDisplayList);	//List call.
		glPopMatrix();

	if (fxincr != 0)
		theta1 = (atan(fzincr / fxincr) * 180) / 3.141;
	else if (fzincr>0)
		theta1 = -90.0;
	else
		theta1 = 90.0;

	if (fxincr>0 && fzincr<0) { //Allows the car to turn.
		theta1 = -theta1;
	}
	else if (fxincr<0 && fzincr<0) {
		theta1 = 180 - theta1;
	}
	else if (fxincr<0 && fzincr>0) {
		theta1 = -180 - theta1;
	}
	else if (fxincr>0 && fzincr>0) {
		theta1 = -theta1;
	}

	//else theta1=90;
	//glLoadIdentity(); skip

	glPushMatrix(); // moving car. Draw a car that needs to be parked.
	glTranslatef(fx, 0, fz);
	glRotatef(theta1, 0, 1, 0);
	glColor3f(1.0, 0.0, 0.0);
	glCallList(carDisplayList);
	glPopMatrix();

	glutSwapBuffers();
}

void orientMe(float ang) { // Function to rotate camera left and right
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f);
}
void orientMe2(float ang) { // Function to rotate the camera up and down
	ly = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z,
		x + lx , y + ly, z + lz,
		0.0f, 1.0f, 0.0f);
}
void moveMeFlat(int i) { // Function to move the camera along the x and z axes
	if (xxxx == 1)
		y = y + i*(lz)*0.1;

	if (yyyy == 1) {
		x = x + i*(lz)*0.1;
	}
	else {
		z = z + i*(lz)*0.5;
		x = x + i*(lx)*0.5;
	}
	glLoadIdentity();
	gluLookAt(x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f);
}

void processNormalKeys(unsigned char key, int x, int y) { //Screen movement function, function function
	glLoadIdentity();

	//static float x = 0.0f, y = 1.75f, z = 5.0f;
	//static float lx = 0.10f, ly = 0.10f, lz = -1.0f;
	if(key=='l')
        glutDisplayFunc(operations_window);
    if(key == 'c')
        glutDisplayFunc(renderScene);
	if (key == 'q')
		exit(0);
	if (key == 't')
		gluLookAt(1, 50, 10,	0, 0, 0,		0.0, 1.0, .0);
	if (key == 'a') moveMeFlat(2); xxxx = 0, yyyy = 1;
	if (key == 'd') moveMeFlat(-2); xxxx = 0, yyyy = 0;
	if (key == 'w') moveMeFlat(2); yyyy = 0; xxxx = 0;
	if (key == 's') moveMeFlat(-2); yyyy = 1; xxxx = 0;
}


void cameraKey(int key, int x, int y) { // screen movement function 2

	switch (key)
	{
	case GLUT_KEY_LEFT: angle -= 0.05f; orientMe(angle); break;
	case GLUT_KEY_RIGHT: angle += 0.05f; orientMe(angle); break;
	case GLUT_KEY_UP: angle += 0.05f; orientMe2(angle); break;
	case GLUT_KEY_DOWN: angle -= 0.05f; orientMe2(angle); break;
	}
}
void moveCar(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_LEFT: // Dome while advancing to the left
			temp = fxincr;
			fxincr = fxincr*cos(theta) + fzincr*sin(theta);
			fzincr = -temp*sin(theta) + fzincr*cos(theta);
			fx += fxincr;
			fz += fzincr;
			break;

		case GLUT_KEY_RIGHT: // Dome while advancing to the right
			temp = fxincr;
			fxincr = fxincr*cos(-theta) + fzincr*sin(-theta);
			fzincr = -temp*sin(-theta) + fzincr*cos(-theta);
			fx += fxincr;
			fz += fzincr;
			break;

		case GLUT_KEY_UP: // Advance
			fx += fxincr;
			fz += fzincr;
			break;

		case GLUT_KEY_DOWN: // junior
			fx -= fxincr;
			fz -= fzincr;
			break;
		}
	glutPostRedisplay();
}


void ProcessMenu(int value) { //Display recall

	glutPostRedisplay();
}

void ProcessMenu1(int value) { //menu callback function
	switch (value) {
		case 1:	 // If you press "Move Car" in the menu, it will run.
			if (moveCarVar == 0) { // If the value of var was 0,
			glutSpecialFunc(moveCar); // Moving the car by calling the moveCar function.
			moveCarVar = 1;
			}
			   else { // Otherwise, perform the camera function with the arrow keys
				   glutSpecialFunc(cameraKey);
				   moveCarVar = 0;
				   glutPostRedisplay();
			   }
			   break;
	}
}
void menu()
{
int control;
 int control1;
control= glutCreateMenu(ProcessMenu);
glutAddMenuEntry("*CONTROLS*",1);
glutAddMenuEntry("1) UP KEY:to move in Forward Direction.",1);
glutAddMenuEntry("2) DOWN KEY:to move in Backward Direction.",1);
glutAddMenuEntry("3) LEFT KEY:to Turn Left .",1);
glutAddMenuEntry("4) RIGHT KEY:to Turn Right .",1);
glutAddMenuEntry("5) d:moves Towards Right. ",1);
glutAddMenuEntry("6) a:moves Towards Left.",1);
glutAddMenuEntry("7) s:moves Away.",1);
glutAddMenuEntry("8) w:moves Near.",1);
glutAddMenuEntry("9) t:Top view.",1);
glutAddMenuEntry("10) q:Quit.",1);
glutAttachMenu(GLUT_RIGHT_BUTTON);
 control1=glutCreateMenu(ProcessMenu1);
glutAddMenuEntry("MOVE CAR",1);
glutAddMenuEntry("HOUSE",1);
glutAttachMenu(GLUT_LEFT_BUTTON);
}

//void welcomeDisplay()
//{
  //  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   // glColor3f(0,0,1);
   // glRasterPos3f(-0.8,1.5,0)
   // char msg1[]="i name vishwa";
   // for(int i=0;i<strlen(msg1);i++)
    //    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg1[i]);
    //glutSwapBuffers();
//}
void welcome_window()
{
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glClearColor(0,0,0,0);
 glColor3f(1.0,1.0,1.0);
 bitmap_output(-1.25,1.8,0.50,"VISVESVARAYA TECHNOLOGICAL UNIVERSITY");
 bitmap_output(-0.6,1.6,0.50,"BELGAUM,KARNATAKA");
 bitmap_output(-0.3,0.70,0.50,"Project On");
 bitmap_output(-0.85,0.50,0.50,"'SIMULATION OF A 3D BIKE'");
 bitmap_output(-0.6,-1.5,0.50,"PLEASE PRESS S TO START");
        glutSwapBuffers();
 glFlush();

}
void operations_window()
{
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glClearColor(0,0,0,0);
 glColor3f(1.0,1.0,1.0);
 bitmap_output(-1.25,1.7,0.50,"OPERATIONS THAT CAN BE PERFORMED BY THE BIKE");
 bitmap_output(-1.25,1.2,0.50,"1. RESET THE CAMERA - USE 'R' OR 'r'");
 bitmap_output(-1.25,1.0,0.50,"2. ACCELERATE THE BIKE - USE '+'");
 bitmap_output(-1.25,0.8,0.50,"3. DEACCELERATE THE BIKE - USE '-'");
        bitmap_output(-1.25,0.6,0.50,"4. TURN RIGHT - USE '2'");
        bitmap_output(-1.25,0.4,0.50,"5. TURN LEFT - USE '1'");
 bitmap_output(-1.25,0.2,0.50,"6. ZOOM IN - USE 'UPWARD ARROW'");
 bitmap_output(-1.25,0.0,0.50,"7. ZOOM OUT - USE 'DOWNWARD ARROW'");
 bitmap_output(-1.25,-0.2,0.50,"8. MOVE LEFT - USE 'LEFT ARROW'");



 bitmap_output(-1.25,-0.4,0.50,"9. MOVE RIGHT - USE 'RIGHT ARROW'");
 bitmap_output(-1.25,-0.6,0.50,"10. USE MOUSE TO CHANGE THE ANGLE OF VIEWING");
 bitmap_output(-1.25,-1.0,0.50,"PLEASE PRESS C TO CONTINUE");
        glutSwapBuffers();
 glFlush();
}


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1000, 500);
	glutCreateWindow("car parking");

	initScene();

	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(cameraKey);

	menu();
    glutDisplayFunc(welcome_window);
//	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

	glutMainLoop();

	return(0);
}

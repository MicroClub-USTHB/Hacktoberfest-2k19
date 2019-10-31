#include <iostream>
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <cmath>
#include <stdio.h>
#define _USE_MATH_DEFINES

using namespace std;
void drawGear();
float wheelRadius=0.8;
float frontWheelX=-1.6;
float backWheelX=1.6;
float wheelsY=0.5;
float rLight;
int power=0;
boolean lightLayers[5]={false};
boolean start = false;
boolean rotateRight=false;
boolean rotateLeft=false;
boolean rotateUp=false;
boolean rotateDown=false;
boolean zoomIN=false;
boolean zoomOUT=false;
float rotateAngleX,rotateAngleY;
float rotateSpeed=2;
float zoomSpeed=0.5;
boolean fullLight=false;

GLUquadricObj *quadOBJ = gluNewQuadric();

float angle = 0.0;
float mv = 0.0;
float zoom = 0.0;
bool movingLeft=false;
bool movingRight=false;
bool scaleIN=false;
bool scaleOUT=false;
double myScale=1;
void animer(){
    if(movingLeft){
    if(angle>360)
        angle=0.0;
        angle=angle+2; mv-=0.001;
        glutPostRedisplay();
    }
    if(movingRight){
        if(angle>360)
            angle=0.0;
        angle=angle-2; mv+=0.001;
        glutPostRedisplay();
    }
    if(scaleIN){
        myScale+=0.002;
        glutPostRedisplay();
    }
    if(scaleOUT){
        myScale-=0.002;
        glutPostRedisplay();
    }
    if(start){
        if(angle>360)
        angle=0.0;
    angle+=2;
    if(power<500)
    power+=1;
    /*if(!start){
        if(power>0)
            power-=1;
        else if(power<0)
            power=0;
    }*/
    glutPostRedisplay();
    }
    else{
        if(power>0)
            power-=1;
        else if(power<0)
            power=0;
            glutPostRedisplay();
    }

    if(rotateRight){
        rotateAngleY-=rotateSpeed;
        glutPostRedisplay();
    }
    if(rotateLeft){
        rotateAngleY+=rotateSpeed;
        glutPostRedisplay();
    }
    if(rotateUp){
        rotateAngleX+=rotateSpeed;
        glutPostRedisplay();
    }
    if(rotateDown){
        rotateAngleX-=rotateSpeed;
    }
    if(zoomIN){
        zoom+=zoomSpeed;
    }
    if(zoomOUT){
        zoom-=zoomSpeed;
    }
}

void specialKeyPressed(int button, int x, int y){
    switch (button){
    case GLUT_KEY_LEFT:
        //movingLeft=true;
        rotateLeft=true;
        break;
    case GLUT_KEY_RIGHT:
        //movingRight=true;
        rotateRight=true;
        break;
    case GLUT_KEY_UP:
        rotateUp=true;
        break;
    case GLUT_KEY_DOWN:
        rotateDown=true;
        break;
    case GLUT_KEY_PAGE_UP:
        zoomIN=true;
        break;
    case GLUT_KEY_PAGE_DOWN:
        zoomOUT=true;
        break;
    }
}

void keyPressed(unsigned char button, int  x, int y){
    switch(button)
    {
    case 'r':
        glClearColor(1.0f, 0.0f, 0.0f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT);
        break;
    case 'b':
        glClearColor(0.0f, 0.0f, 1.0f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT);
        break;
    case 'v':
        glClearColor(0.0f, 1.0f, 0.0f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT);
        break;
    case 'x':
        movingLeft=true;
        break;
    case 'i':
        scaleIN=true;
        break;
    case 'o':
        scaleOUT=true;
        break;
    case 32:
        start=true;
        break;
    case 27:
        exit(0);
    case 'k':
        glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    glutPostRedisplay();
}

void keyUp(unsigned char button, int x, int y){
    //glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    scaleIN=false;
    scaleOUT=false;
    start=false;
    //movingLeft=false;
    //movingRight=false;

    //glClear(GL_COLOR_BUFFER_BIT);
}

void specialKeyUp(int button, int x, int y){
    //glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    movingLeft=false;
    movingRight=false;
    rotateLeft=false;
    rotateRight=false;
    rotateUp=false;
    rotateDown=false;

    zoomIN=false;
    zoomOUT=false;
    //start=false;
    //glClear(GL_COLOR_BUFFER_BIT);
}

void mousePressed(int button, int etat, int x, int y){
    if(button == GLUT_LEFT_BUTTON){
        glClearColor(1.0, 0.0, 0.0, 0.5);
    }
    if(button == GLUT_RIGHT_BUTTON){
        glClearColor(0.0, 1.0, 0.0, 0.5);
    }
    glutPostRedisplay();
}

void drawBicycle(){
    //Wheels:
    glPushMatrix();
    glColor3f(0.01,0.01,0.01);
    glLineWidth(1);


    //FrontWheel
    glPushMatrix();
    glTranslatef(-1.6,0.5,0.0);
    //glRotatef(angle,0.0,0.0,1.0);
    for(int i=0;i<20;i++){
        glColor3f(1.,1.,1.);
        glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(wheelRadius*cos(i), wheelRadius*sin(i), 0);
        glEnd();
    }
    glColor3f(0.01,0.01,0.01);
    glutSolidTorus(0.08,wheelRadius,60,60);
    glPopMatrix();

    //BackWheel
    glPushMatrix();
    glTranslatef(1.6,0.5,0.0);
    glRotatef(angle,0.0,0.0,1.0);
    for(int i=0;i<20;i++){
        glColor3f(1.,1.,1.);
        glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(wheelRadius*cos(i), wheelRadius*sin(i), 0);
        glEnd();
    }
    glColor3f(0.01,0.01,0.01);
    glutSolidTorus(0.08,wheelRadius,60,60);
    glPopMatrix();

    //BackWheelChainHolder
    glPushMatrix();
    glTranslatef(1.6,0.5,-0.05);/////////////////TO BE CHECKED LATER !!!
    for(int i=0;i<6;i++){
        glColor3f(0.24,0.245,0.251);
        glLineWidth(5);
        glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(wheelRadius/2*cos(i), wheelRadius/2*sin(i), 0.0);
        glEnd();
    }
    glColor3f(0.45,0.45,0.41);
    glutSolidTorus(0.04,wheelRadius/2,60,60);
    glPopMatrix();

    glPopMatrix();
    //EndOfWheels.

    //MiddleChainHolder
    glPushMatrix();
    glTranslatef(0,0.5,-0.05);/////////////////TO BE CHECKED LATER !!!
    for(int i=0;i<6;i++){
        glColor3f(0.24,0.245,0.251);
        glLineWidth(5);
        glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(wheelRadius/2*cos(i), wheelRadius/2*sin(i), 0.0);
        glEnd();
    }
    glColor3f(0.45,0.45,0.41);
    glutSolidTorus(0.04,wheelRadius/2,60,60);
    glPopMatrix();

    //Pedals:
    glPushMatrix();
    glTranslatef(0,0.5,0);
    glRotatef(angle,0.0,0.0,1.0);
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.02,0.0245,0.0251);
    for(int i=0;i<360;i++){
        glVertex3f(0.06*cos(i), 0.06*sin(i), -0.45);
        glVertex3f(0.06*cos(i), 0.06*sin(i), 0.45);
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.5,-0.4);
    glRotatef(45,0,0,1);
    glRotatef(angle,0.0,0.0,1.0);
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.92,0.90245,0.90251);
    for(int i=0;i<360;i++){
        glVertex3f(0.0, 0.06*cos(i), 0.06*sin(i));
        glVertex3f(0.6, 0.06*cos(i), 0.06*sin(i));
    }
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(0,0.5,0.4);
    glRotatef(215,0,0,1);
    glRotatef(angle,0.0,0.0,1.0);
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.92,0.90245,0.90251);
    for(int i=0;i<360;i++){
        glVertex3f(0.0, 0.06*cos(i), 0.06*sin(i));
        glVertex3f(0.6, 0.06*cos(i), 0.06*sin(i));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glColor3f(0.8,0.1,0.1);
    //glRectf(0, wheelsY+0.06, backWheelX, wheelsY-0.06);
    glBegin(GL_POLYGON);
    glVertex3f(0,wheelsY+0.06,0);
    glVertex3f(0,wheelsY-0.06,0);
    glVertex3f(backWheelX,wheelsY-0.06,0.2);
    glVertex3f(backWheelX,wheelsY+0.06,0.2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0,wheelsY+0.06,0);
    glVertex3f(0,wheelsY-0.06,0);
    glVertex3f(backWheelX,wheelsY-0.06,-0.2);
    glVertex3f(backWheelX,wheelsY+0.06,-0.2);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUAD_STRIP);
    for(int i=0;i<360;i++){
        glVertex3f(0.06*cos(i),0.45,0.06*sin(i));
        glVertex3f(0.06*cos(i),2,0.06*sin(i));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUAD_STRIP);
    for(int i=0;i<360;i++){
        glVertex3f(0.06,2+0.06*cos(i),0.06*sin(i));
        glVertex3f(frontWheelX,2+0.06*cos(i),0.06*sin(i));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(45,0,0,1);
    glBegin(GL_QUAD_STRIP);
    for(int i=0;i<360;i++){
        glVertex3f(0.35+0.06*cos(i),0.35,0.06*sin(i));
        glVertex3f(0.35+0.06*cos(i),2.45,0.06*sin(i));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUAD_STRIP);
    for(int i=0;i<360;i++){
        glVertex3f(frontWheelX+0.06*cos(i),2,0.06*sin(i));
        glVertex3f(frontWheelX+0.06*cos(i),0.5+wheelRadius+0.1,0.06*sin(i));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(frontWheelX-0.06,wheelsY+wheelRadius+0.16,0);
    glVertex3f(frontWheelX+0.06,wheelsY+wheelRadius+0.16,0);
    glVertex3f(frontWheelX+0.06,wheelsY,0.2);
    glVertex3f(frontWheelX-0.06,wheelsY,0.2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(frontWheelX-0.06,wheelsY+wheelRadius+0.16,0);
    glVertex3f(frontWheelX+0.06,wheelsY+wheelRadius+0.16,0);
    glVertex3f(frontWheelX+0.06,wheelsY,-0.2);
    glVertex3f(frontWheelX-0.06,wheelsY,-0.2);
    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(backWheelX,0,0);
    glRotatef(45,0,0,1);
    glTranslatef(-backWheelX,0,0);
    glBegin(GL_QUAD_STRIP);
    for(int i=0;i<360;i++){
        glVertex3f(backWheelX+0.3+0.06*cos(i),0.35+2.2,0.06*sin(i));
        glVertex3f(backWheelX+0.3+0.06*cos(i),0.35+wheelRadius+0.1,0.06*sin(i));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(backWheelX+0.3-0.06,wheelsY+wheelRadius+0.16,0);
    glVertex3f(backWheelX+0.3+0.06,wheelsY+wheelRadius+0.16,0);
    glVertex3f(backWheelX+0.3+0.06,wheelsY,-0.2);
    glVertex3f(backWheelX+0.3-0.06,wheelsY,-0.2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(backWheelX+0.3-0.06,wheelsY+wheelRadius+0.16,0);
    glVertex3f(backWheelX+0.3+0.06,wheelsY+wheelRadius+0.16,0);
    glVertex3f(backWheelX+0.3+0.06,wheelsY,0.2);
    glVertex3f(backWheelX+0.3-0.06,wheelsY,0.2);
    glEnd();

    glPopMatrix();

    glPushMatrix();



    glBegin(GL_QUAD_STRIP);
    glColor3f(0.19,0.22,0.09);
    for(int i=0;i<360;i++){
        glVertex3f(frontWheelX+0.06*cos(i),2.5+0.06*sin(i),-0.5);
        glVertex3f(frontWheelX+0.06*cos(i),2.5+0.06*sin(i),0.5);
    }
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.32,0.32,0.32);
    for(int i=0;i<360;i++){
        glVertex3f(frontWheelX+0.06*cos(i),2,0.06*sin(i));
        glVertex3f(frontWheelX+0.06*cos(i),2.5,0.06*sin(i));
    }
    glEnd();

    glPopMatrix();


    glPushMatrix();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.1,0.15,0.15);
    for(int i=0;i<360;i++){
        glVertex3f(0.06*cos(i),2,0.06*sin(i));
        glVertex3f(0.06*cos(i),2.5,0.06*sin(i));
    }
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.2,2.5,0.2);
    glVertex3f(0.2,2.5,-0.2);
    glVertex3f(-0.5,2.5,-0.01);
    glVertex3f(-0.5,2.5,0.01);
    glEnd();
    glPopMatrix();






    glPushMatrix();

    glPopMatrix();
/*
    glPushMatrix();
    glRotatef(90,1,0,0);
    glTranslatef(0,0.0,-0.5-0.7-0.7);
    gluCylinder(quadOBJ,0.1,0.1,1.4,30,30);
    glPopMatrix();
////////////////
    glPushMatrix();
    glRotatef(90,1,0,0);
    glRotatef(45,0,1,0);
    glTranslatef(0.5,0.0,-0.5-0.7-0.7);
    gluCylinder(quadOBJ,0.05,0.05,1.8,30,30);
    glPopMatrix();
*/
}

void drawLampPost(){
    //Under Lamp Post
    glPushMatrix();
    glTranslatef(6.0,0.0,0.0);
    glutSolidCube(1);
    glPopMatrix();
        //Lamp Post
    glPushMatrix();
    glTranslatef(6.0,0.0,0.0);
    glRotatef(-90,1.0,0.0,0.0);
    //glColor3f(0.22,0.21,0.2);
    glColor3f(0.37,0.28,0.06);
    glBegin(GL_QUAD_STRIP);
    for(int i=0;i<180;i++){
        glVertex3f(0.25*cos(i),0.25*sin(i),0);
        glVertex3f(0.25*cos(i),0.25*sin(i),6);
    }
    glEnd();
    glRotatef(-90,0.0,1.0,0.0);
    glTranslatef(5.7,0.0,0.22);
    glColor3f(0.098,0.09,0.099);
    //glColor3f(0.37,0.28,0.06);
    glBegin(GL_QUAD_STRIP);
    for(int i=0;i<180;i++){
        glVertex3f(0.16*cos(i),0.16*sin(i),0);
        glVertex3f(0.16*cos(i),0.16*sin(i),2);
    }
    glEnd();

    glRotatef(-90,0.0,1.0,0.0);
    glTranslatef(1.6,0.0,0.1);
    glColor3f(0.098,0.09,0.099);
    //glColor3f(0.37,0.28,0.06);
    glBegin(GL_QUAD_STRIP);
    for(int i=0;i<180;i++){
        glVertex3f(0.1*cos(i),0.1*sin(i),0);
        glVertex3f(0.1*cos(i),0.1*sin(i),0.4);
    }
    glEnd();

    //LAMP:
    glTranslatef(0.0,0.0,0.7);
    glColor4f(1.0,1.0,1.0,0.1);
    glutSolidSphere(0.3,50,50);
    //float n = 1.6;
    //if(start){
		/*for (float i = 0.01; i < 0.2; i += 0.07) {
			rLight = exp(i*i);
			glColor4f(1.0, 1.0, 1.0, 1 - (i / n));
			glutSolidSphere(rLight, 50, 50);
		}*/
		//for(float i=0.1;i<0.9;i+=0.2){
                /*if(power%100==0){
            glColor4f(1.0, 1.0, 1.0, 1 - power*0.002);
			glutSolidSphere(power*0.02, 50, 50);
			printf("Power = %d\n",power);
                }*/

                switch(power){
                case 0:
                    lightLayers[0]=true;
                    lightLayers[1]=false;
                    lightLayers[2]=false;
                    lightLayers[3]=false;
                    lightLayers[4]=false;
                    lightLayers[5]=false;
                    glDisable(GL_LIGHT3);
                    break;
                case 100:
                    lightLayers[1]=true;
                    lightLayers[2]=false;
                    lightLayers[3]=false;
                    lightLayers[4]=false;
                    lightLayers[5]=false;
                    glDisable(GL_LIGHT3);
                    break;
                case 200:
                    lightLayers[2]=true;
                    lightLayers[3]=false;
                    lightLayers[4]=false;
                    lightLayers[5]=false;
                    glDisable(GL_LIGHT3);
                    break;
                case 300:
                    lightLayers[3]=true;
                    lightLayers[4]=false;
                    lightLayers[5]=false;
                    glDisable(GL_LIGHT3);
                    break;
                case 400:
                    lightLayers[4]=true;
                    lightLayers[5]=false;
                    glDisable(GL_LIGHT3);
                    fullLight=false;
                    break;
                case 500:
                    //glClearColor(1.0,1.0,1.0,0.1);
                    //glClearColor(0.4,0.4,0.95,1);
                    lightLayers[5]=true;
                    glEnable(GL_LIGHT3);
                    fullLight=true;
                    break;
                }
                for(int i=0;i<5;i++){
                    if(lightLayers[i]){
                    glColor4f(1.0, 1.0, 1.0, 1 - i*0.18);
                    glutSolidSphere(i*0.2, 50, 50);
                    }
                }
		//}
    //}
    /*if(start){
        for(int i=2;i<10;i++){
            glColor4f(1.0, 1.0, 1.0, 1 - i*0.1);
			glutSolidSphere(i*0.1, 50, 50);
        }
    }*/

    glPopMatrix();
    //End of Lamp Post
    }

void drawEngine(){
    glPushMatrix();
    glTranslatef(4,0,-0.6);
    glColor3f(0.1,0.1,0.1);
    glBegin(GL_QUAD_STRIP);
    for(int i=0;i<180;i++){
        glVertex3f(0.25*cos(i),-0.5,0.25*sin(i));
        glVertex3f(0.25*cos(i),0.5,0.25*sin(i));
    }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.02,0.05,0.02);
    glTranslatef(4,0.5,-0.6);
    glutSolidCube(0.8);
    glPopMatrix();
    drawGear();
}

void drawPlane(){
    glPushMatrix();
    if(!fullLight){
    glColor3f(0.215,0.215,0.215);
    }
    else{
    //BicycleShadow:
    glPushMatrix();
    glColor4f(0.05,0.05,0.05,0.2);
    glTranslatef(-1,-0.37,0.0);
    glBegin(GL_QUAD_STRIP);
    for(int i=0;i<480;i++){
        glVertex3f(3.5*cos(i),0,0.5*sin(i));
    }
    glEnd();
    glPopMatrix();
    glColor3f(0.315,0.315,0.315);
    }
    glBegin(GL_POLYGON);
        glVertex3f(-10,-0.38,-20);
        glVertex3f(-10,-0.38,20);
        glVertex3f(10,-0.38,20);
        glVertex3f(10,-0.38,-20);
    glEnd();
    glPopMatrix();
}

float chainPieceRadius=0.025;
void drawChain(){
    glPushMatrix();
    glTranslatef(0,0.5,-0.05);
    glColor3f(0.0,0.0,0.0);
    for(float i=0;i<2*M_PI/2;i+=0.1){
        glPushMatrix();
        glRotatef(90,0.0,0.0,1.0);
        glTranslatef(0.5*cos(i),0.5*sin(i),0);
        glutSolidTorus(0.01,chainPieceRadius,20,20);
        glPopMatrix();
    }

    glPopMatrix();
}

static void gear(GLfloat inner_radius, GLfloat outer_radius, GLfloat width, GLint teeth, GLfloat tooth_depth)
{
	GLint i;
	GLfloat r0, r1, r2;
	GLfloat angle, da;
	GLfloat u, v, len;

	r0 = inner_radius;
	r1 = outer_radius - tooth_depth / 2.0;
	r2 = outer_radius + tooth_depth / 2.0;

	da = 2.0 * M_PI / teeth / 4.0;

	glShadeModel(GL_FLAT);

	glNormal3f(0.0, 0.0, 1.0);

	//draw front face
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= teeth; i++) {
		angle = i * 2.0 * M_PI / teeth;
		glVertex3f(r0 * cos(angle), r0 * sin(angle), width * 0.5);
		glVertex3f(r1 * cos(angle), r1 * sin(angle), width * 0.5);
		glVertex3f(r0 * cos(angle), r0 * sin(angle), width * 0.5);
		glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), width * 0.5);
	}
	glEnd();

	// draw front sides of teeth
	glBegin(GL_QUADS);
	da = 2.0 * M_PI / teeth / 4.0;
	for (i = 0; i < teeth; i++) {
		angle = i * 2.0 * M_PI / teeth;

		glVertex3f(r1 * cos(angle), r1 * sin(angle), width * 0.5);
		glVertex3f(r2 * cos(angle + da), r2 * sin(angle + da), width * 0.5);
		glVertex3f(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da), width * 0.5);
		glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), width * 0.5);
	}
	glEnd();

	glNormal3f(0.0, 0.0, -1.0);

	//draw back face
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= teeth; i++) {
		angle = i * 2.0 * M_PI / teeth;
		glVertex3f(r1 * cos(angle), r1 * sin(angle), -width * 0.5);
		glVertex3f(r0 * cos(angle), r0 * sin(angle), -width * 0.5);
		glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), -width * 0.5);
		glVertex3f(r0 * cos(angle), r0 * sin(angle), -width * 0.5);
	}
	glEnd();

	// draw back sides of teeth
	glBegin(GL_QUADS);
	da = 2.0 * M_PI / teeth / 4.0;
	for (i = 0; i < teeth; i++) {
		angle = i * 2.0 * M_PI / teeth;

		glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), -width * 0.5);
		glVertex3f(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da), -width * 0.5);
		glVertex3f(r2 * cos(angle + da), r2 * sin(angle + da), -width * 0.5);
		glVertex3f(r1 * cos(angle), r1 * sin(angle), -width * 0.5);
	}
	glEnd();

	// draw outward faces of teeth
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i < teeth; i++) {
		angle = i * 2.0 * M_PI / teeth;

		glVertex3f(r1 * cos(angle), r1 * sin(angle), width * 0.5);
		glVertex3f(r1 * cos(angle), r1 * sin(angle), -width * 0.5);
		u = r2 * cos(angle + da) - r1 * cos(angle);
		v = r2 * sin(angle + da) - r1 * sin(angle);
		len = sqrt(u * u + v * v);
		u /= len;
		v /= len;
		glNormal3f(v, -u, 0.0);
		glVertex3f(r2 * cos(angle + da), r2 * sin(angle + da), width * 0.5);
		glVertex3f(r2 * cos(angle + da), r2 * sin(angle + da), -width * 0.5);
		glNormal3f(cos(angle), sin(angle), 0.0);
		glVertex3f(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da), width * 0.5);
		glVertex3f(r2 * cos(angle + 2 * da), r2 * sin(angle + 2 * da), -width * 0.5);
		u = r1 * cos(angle + 3 * da) - r2 * cos(angle + 2 * da);
		v = r1 * sin(angle + 3 * da) - r2 * sin(angle + 2 * da);
		glNormal3f(v, -u, 0.0);
		glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), width * 0.5);
		glVertex3f(r1 * cos(angle + 3 * da), r1 * sin(angle + 3 * da), -width * 0.5);
		glNormal3f(cos(angle), sin(angle), 0.0);
	}

	glVertex3f(r1 * cos(0), r1 * sin(0), width * 0.5);
	glVertex3f(r1 * cos(0), r1 * sin(0), -width * 0.5);

	glEnd();

	glShadeModel(GL_SMOOTH);

	//draw inside radius cylinder
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= teeth; i++) {
		angle = i * 2.0 * M_PI / teeth;

		glNormal3f(-cos(angle), -sin(angle), 0.0);
		glVertex3f(r0 * cos(angle), r0 * sin(angle), -width * 0.5);
		glVertex3f(r0 * cos(angle), r0 * sin(angle), width * 0.5);
	}
	glEnd();

}

void drawGear(){
    glPushMatrix();
    glTranslatef(4,0.5,0);
    glRotatef(angle,0.0,0.0,1.0);
    glColor3f(0.87,0.8,0.88);
    gear(0.2,0.36,0.4,12,0.025);
    glPopMatrix();
}

void drawBicycleChain(){
    glPushMatrix();
    glColor3f(0.0,0.05,0.01);
    glTranslatef(0.0,0.5,-0.2);
    glPushMatrix();
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_LINE_STRIP);
    for(float i=M_PI/2;i<3*M_PI/2;i+=0.16){
        glPushMatrix();
        glTranslatef(0.24*cos(i),0.24*sin(i),0);
        glutSolidTorus(0.025,0.04,10,10);
        glPopMatrix();
        //glVertex3f(3*cos(i),3*sin(i),0);
        //glVertex3f(0.5*cos(i),0.5*sin(i),4);
    }
    glEnd();
    glPopMatrix();

    glTranslatef(backWheelX,0.5,-0.2);
    glPushMatrix();
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_LINE_STRIP);
    for(float i=3*M_PI/2;i<5*M_PI/2;i+=0.16){
        glPushMatrix();
        glTranslatef(0.24*cos(i),0.24*sin(i),0);
        glutSolidTorus(0.025,0.04,10,10);
        glPopMatrix();
        //glVertex3f(3*cos(i),3*sin(i),0);
        //glVertex3f(0.5*cos(i),0.5*sin(i),4);
    }
    glEnd();
    glPopMatrix();

    glTranslatef(0,0.24,-0.2);
    glPushMatrix();
    //glColor3f(0,1,0);
    for(float i=0;i<backWheelX;i+=0.05){
        glPushMatrix();
        glTranslatef(i,0.5,0);
        glutSolidTorus(0.025,0.04,10,10);
        glPopMatrix();
    }
    glPopMatrix();

    //glTranslatef(0,0,-0.2);
    glPushMatrix();
    //glColor3f(0,1,0);
    for(float i=0;i<backWheelX;i+=0.05){
        glPushMatrix();
        glTranslatef(i,0.02,0);
        glutSolidTorus(0.025,0.04,10,10);
        glPopMatrix();
    }
    glPopMatrix();

    glPopMatrix();
}

void drawEngineChain(){
    glPushMatrix();
    //glTranslatef(0.0,0.0,0.1);
    glLineWidth(5);
    glBegin(GL_LINES);
      glVertex3f(backWheelX, 0.25+wheelRadius, 0.2);
      glVertex3f(4, 0.6, 0.2);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(0.0,0.0,0.1);
    glLineWidth(5);
    glBegin(GL_LINES);
      glVertex3f(backWheelX, 0.25-wheelRadius, 0.2);
      glVertex3f(4, 0, 0.2);
    glEnd();
    glPopMatrix();

    glPushMatrix();
     glBegin(GL_LINES);

    for (float i=3*M_PI/2;i<5*M_PI/2;i+=0.01){
        glVertex3f(4+0.5*cos(i), 0.25+0.35*sin(i), 0.1);
        glVertex3f(4+0.5*cos(i), 0.25+0.35*sin(i), 0.2);
    }
    glEnd();

    glPopMatrix();

}

drawElectricCable(){
    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    for(int i=0;i<360;i++){
        glVertex3f(4,-0.6+0.06*cos(i),-0.36+0.06*sin(i));
        glVertex3f(6,-0.6+0.06*cos(i),-0.36+0.06*sin(i));
    }
    glEnd();
    glPopMatrix();
}

void display(){

//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

/*glBegin(GL_QUAD_STRIP);
    for(int i=0;i<180;i++){
        glVertex3f(0.5*cos(i),0.5*sin(i),0);
        glVertex3f(0.5*cos(i),0.5*sin(i),4);
    }
glEnd();*/


//glutWireSphere(2,12,3);
//glutWireTorus(1,2,12,24);
//glutWireCone(2,2,24,12);
/*glColor3f(0.8f,0.1f,0.05f);
glutSolidTeapot(2);*/

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0,-1.0,zoom);
    glRotatef(rotateAngleY, 0.0, 1.0, 0.0);
    glRotatef(rotateAngleX, 1.0, 0.0, 0.0);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glPushMatrix();
    drawPlane();
    drawBicycle();
    drawLampPost();
    drawEngine();
    //drawGear();
    //drawChain();
    drawBicycleChain();
    drawEngineChain();
    drawElectricCable();


    glColor3f(0.8,0.1,0.2);

    glPopMatrix();
    //glEnable(GL_LIGHTING);
    glutSwapBuffers();
    glutPostRedisplay();


    //glFlush();
}


void light(void){
    GLfloat WHITE[] = { 1.0,1.0,1.0,1.0 };
	GLfloat light_couleur1[] = { 0.0,0.0,0.0,1.0 };
	GLfloat light_couleur2[] = { 1.0,1.0,1.0,1.0 };
	//GLfloat light_couleur3[] = {0.0,0.0,1.0,1.0};
	GLfloat light_position[] = { 0.0,0.0,5.0,0.0 };

	glLightfv(GL_LIGHT1, GL_POSITION, light_position);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_couleur2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_couleur2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_couleur2);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);

	glEnable(GL_COLOR_MATERIAL);

	float s[1] = { 50 };

	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, WHITE);

	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, s);
}

void light2(){
    GLfloat WHITE[] = { 1.0,1.0,1.0,1.0 };
    GLfloat light_color1[]={0.0, 0.0, 0.0, 1.0};
    GLfloat light_color2[]={1.0, 1.0, 1.0, 0.0};
    GLfloat light_color3[]={1.0, 0.95, 0.12, 0.0};
    GLfloat light_position[]={-4.0, 2.0, 3.0, 0.0};
    GLfloat light_position2[]={4.0, 2.0, 3.0, 0.0};
    GLfloat light_position3[]={4.4, 4.0, 0.0, 0.0};
    glLightfv(GL_LIGHT1, GL_POSITION, light_position);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_color1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_color2);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_color2);

    glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
    glLightfv(GL_LIGHT2, GL_AMBIENT, light_color1);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light_color2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light_color2);

    glLightfv(GL_LIGHT3, GL_POSITION, light_position2);
    glLightfv(GL_LIGHT3, GL_AMBIENT, light_color1);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, light_color3);
    glLightfv(GL_LIGHT3, GL_SPECULAR, light_color3);


    float s[1] = { 50 };

	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, WHITE);

	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, s);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
}

static void Reshape(int width, int height){

    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,1,0.1,100);
    //gluLookAt(10,8,10,0,0,0,0,1,0);
    gluLookAt(0,0,18,0,0,0,0,1,0);


}

int main()
{

    glutInitDisplayMode(GLUT_SINGLE | GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL Project (MIV)");
    //glClearColor(0.4,0.4,0.95,1);
    //glClearColor(0.0,0.66,0.88,1);
    glClearColor(0.12,0.14,0.1,1);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); glEnable( GL_BLEND );
    //light();
    light2();
    glutReshapeFunc(Reshape);
    glMatrixMode(GL_MODELVIEW);
    glutKeyboardFunc(keyPressed);
    glutSpecialFunc(specialKeyPressed);
    glutSpecialUpFunc(specialKeyUp);
    glutKeyboardUpFunc(keyUp);
    glutIdleFunc(animer);
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutMainLoop();
    //printf("%f\n",angle);


    return 0;
}




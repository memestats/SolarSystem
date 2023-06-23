#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
GLdouble xx=0.1;
GLdouble yy=0.1;
GLdouble zz=0;
GLdouble pos1,pos2;
GLfloat rotacao;
void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0,1.0,0.0);
    gluLookAt(xx,yy,zz,pos1,pos2,0,0,1,1);
 //SOL
    glScalef(0.5,0.5,0.5);
    glColor3f(1.0,1.0,0.0);
    glPushMatrix();
       // glScalef(1,1,1);
        //glRotatef(rotacao*1.4,0.0f,0.0f,0.0f);
        glutSolidSphere(0.1,30,30);
    glPopMatrix();
//MERCURIO
    glColor3f(0.168,0.168,0.168);
    glPushMatrix();
        glRotatef(rotacao*2,0.0f,1.0f,0.0f);
        glTranslatef(0.2,0,0);
        glutSolidSphere(0.02,30,30);
    glPopMatrix();
//VENUS
    glColor3f(1,0.5,0);
    glPushMatrix();
        glRotatef(rotacao*1.2,0.0f,0.5f,0.0f);
        glTranslatef(0.4,0,0);
        glutSolidSphere(0.04,30,30);
    glPopMatrix();
//TERRA
    glColor3f(0.2,0.2,1);
    glPushMatrix();
        glRotatef(rotacao*1.1,0.0f,0.5f,0.0f);
        glTranslatef(0.6,0,0);
        glutSolidSphere(0.06,30,30);
        glColor3f(0.2,0.2,0.2);
        glPushMatrix();
            glRotatef(rotacao*1.0,0.0f,0.5f,0.0f);
            glTranslatef(0.1,0,0);
            glutSolidSphere(0.01,30,30);
        glPopMatrix();
    glPopMatrix();
//MARTE
    glColor3f(1.0,0.0,0.0);
    glPushMatrix();
        glRotatef(rotacao*0.9,0.0f,0.5f,0.0f);
        glTranslatef(0.85,0.0f,0.0f);
        glutSolidSphere(0.055,30,30);
    glPopMatrix();
//JUPITER
    glColor3f(1,0.8,0);
    glPushMatrix();
        glRotatef(rotacao*0.8,0.0f,0.5f,0.0f);
        glTranslatef(1.2,0.0f,0.0f);
        glutSolidSphere(0.08,30,30);
    glPopMatrix();
//SATURNO
    glColor3f(0.8,0.8,0.8);
    glPushMatrix();
        glRotatef(rotacao*0.7,0.0f,0.5f,0.0f);
        glTranslatef(1.5,0.0f,0.0f);
        glutSolidSphere(0.06,30,30);
    glPopMatrix();
//URANO
    glColor3f(0.0,0.5,1.0);
    glPushMatrix();
        glRotatef(rotacao*0.6,0.0f,0.5f,0.0f);
        glTranslatef(1.8,0.0f,0.0f);
        glutSolidSphere(0.055,30,30);
    glPopMatrix();
//NETUNO
    glColor3f(0.0,0.5,0.8);
    glPushMatrix();
        glRotatef(rotacao*0.5,0.0f,0.5f,0.0f);
        glTranslatef(2.0f,0.0f,0.0f);
        glutSolidSphere(0.055,30,30);
    glPopMatrix();
//PLUTÃO
    glColor3f(0.168,0.168,0.168);
    glPushMatrix();
        glRotatef(rotacao*0.2,0.0f,0.5f,0.0f);
        glTranslatef(2.2f,0.0f,0.0f);
        glutSolidSphere(0.02,30,30);
    glPopMatrix();

    glutPostRedisplay();
    glFlush();
}

void inicializa(void)
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(5.0,-5.0,5.0,-5.0,5.0,-5.0);

}
void rotacionar(int valor)
{
    rotacao+=1;
    glutTimerFunc(10,rotacionar,1);
}
void teclado(unsigned char key,int x, int y)
{
    if(key=='q'){
        pos1+=0.1;
    }else if(key=='e')
    {
        pos1-=0.1;
    }else if(key=='w')
    {
        pos2+=0.1;
    }else if(key=='s')
    {
        pos2-=0.1;
    }
    glutPostRedisplay();
}
void setas(int key, int x, int y)
{
        if(key==GLUT_KEY_UP){
            yy=yy+0.1;}
        else if(key==GLUT_KEY_DOWN){
            yy=yy-0.1;}

       else if(key==GLUT_KEY_LEFT){
            xx=xx-0.1;}

       else if(key==GLUT_KEY_RIGHT){
            xx=xx+0.1;}

       else if(key==GLUT_KEY_PAGE_UP){
            zz=zz+0.1;}

       else if(key==GLUT_KEY_PAGE_DOWN){
            zz=zz-0.1;}

     glutPostRedisplay();
}

int main(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1280,720);
	glutCreateWindow("Primeiro Programa");
	glutDisplayFunc(display);
	glutKeyboardFunc(teclado);
	glutSpecialFunc(setas);
	glutTimerFunc(10,rotacionar,0);
	inicializa();
	glutMainLoop();
}

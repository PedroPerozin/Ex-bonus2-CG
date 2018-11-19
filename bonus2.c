#include <GL/glut.h>
#include <stdio.h>

// Exercício bonus 2 computação grafica
// Pedro Lopes Perozin
// RA 1648730  
// Para compilar basta escrever "gcc bonus2.c -o p -lGL -lglut -lGLU" onde bonus2.c é o nome do arquivo e depois
// ./p

static GLfloat spin = 0.0;

int init(void);
void display(void);
void createViewPortProjection(int xvmin, int yvmin, int vn);
void cameraPosition(float x0, float y0, float z0, float vx, float vy, float vz, int vn);
void spinDisplay(void);


int init(void){

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.72, -1.5, 1.5);
}

void createViewPortProjection(int xvmin, int yvmin, int vn){
    glViewport(xvmin, yvmin, 400, 400);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(vn == 5){
        gluPerspective(70, 1.0, 1.0, 50);
    } else {
        glOrtho(-3, 3, -3, 3, 1, 50); // xvmin, xvmax, xwmin, ywmax, near, far
    }
}



void cameraPosition(float x0, float y0, float z0, float vx, float vy, float vz, int vn){

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt( x0,  y0,  z0,
              0.0, 0.0, 0.0,
               vx,  vy,  vz);

    float sizeTeaPoat = 2.0;

    if(vn == 4){
        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        float rotatioA = spin;
        int rotatioB = rotatioA;
        int angulo = rotatioB % 365;

        glRotatef(spin, 0.0, 0.0, 1.0);
        glRotatef(angulo, 1.0, 0.0, 0.0);
        //glRotatef(45, 1.0, 0.0, 0.0);

        sizeTeaPoat = 0.6;
    }

    glutWireTeapot(sizeTeaPoat);
}

void spinDisplay(void){
   spin = spin + 0.4;
   if (spin > 360.0)
      spin = 0;

   glutPostRedisplay();
}

void createViewPort(){

    createViewPortProjection(000, 400, 1);
    cameraPosition(0.0, 1.0, 0.0, 0.0, 0.0, -1.0, 1);

    createViewPortProjection(400, 400, 2);
    cameraPosition(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 2);

    createViewPortProjection(000, 000, 3);
    cameraPosition(0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 3);

    createViewPortProjection(400, 000, 4);
    cameraPosition(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 4);
}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT |  GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0f, 0.0f, 0.0f);
    createViewPort();

    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
    glutInitWindowSize(800, 800); // window size
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Exercicio bonus 2");

    glutIdleFunc(spinDisplay);
    glutDisplayFunc(display);

    init();
    glutMainLoop();
    return 0;
}

#include <stdio.h>
#include <GL/freeglut.h>

float alpha=0, beta=0, delta=1;


int init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);     //define a cor de fundo
    glEnable(GL_DEPTH_TEST);           //remoção de superfície oculta

    glMatrixMode(GL_PROJECTION);          //define que a matriz é a de projeção

    
    glLoadIdentity();                     //carrega a matriz de identidade
    
    glOrtho(-5,5,-5,5,-5,5);          //define uma projeção ortográfica
    

}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer


            glMatrixMode   (GL_PROJECTION);
    glViewport( 0, 0, -3, 3); 

    glMatrixMode(GL_MODELVIEW);       //define que a matriz é a de modelo

    glLoadIdentity();                //carrega matriz identidade

    

    glColor3f(1, 0, 0);
    glutWireTeapot(1);      //desenha esfera wired e centrada na origem(raio, slices, stacks)

    glFlush();                       //desenha os comandos não executados
}



int main(int argc, char** argv){
    glutInit(&argc,argv);                           //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);    //configura o modo de display
    glutInitWindowPosition(200,0);                  //seta a posição inicial da janela
    glutInitWindowSize(800,800);                    //configura a largura e altura da janela de exibição
    glutCreateWindow("3D");                 //cria a janela de exibição

    init();                                         //executa função de inicialização
    
    glutDisplayFunc(display);
    glutMainLoop();                                  //mostre tudo e espere
    return 0;
}

#include <GL/glut.h>
#include <unistd.h>

#include "Line.h"

// Variables globales

void initTriangle() {}

void plotAxis(){
    Line::Draw({-255,0},{255,0});
    Line::Draw({0,-255},{0,255});
}
void dibujaEscenario() {
    /* triangle.draw(); */
    plotAxis();
}

// actualizar variables de control
void update() {
  // hacer algo
  glFlush();
  usleep(90000);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  dibujaEscenario();
  update();
}

void init() {
  glColor3f(0.0, 0.0, 0.0);
  glPointSize(1.0);
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-255, 255, -255, 255);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int main(int argc, char **argv) {

  initTriangle();
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500); /* ventana 500x500 pixeles */
  glutInitWindowPosition(
      0, 0); /* coloca la ventana de despliegue en esq. sup. izq */
  glutCreateWindow("Movimiento"); /* título de la ventana*/
  init();                         /* fija o establece los atributos */
  /*llama a la funcion display cuando se abre la ventana */
  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutMainLoop(); /* entra a un ciclo de evento */
}

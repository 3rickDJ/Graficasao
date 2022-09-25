#include "Point.h"
#include <GL/glut.h>

Point::Point() {}
Point::Point(int x, int y) {
  this->x = x;
  this->y = y;
}
void Point::draw() {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}
void Point::Draw(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

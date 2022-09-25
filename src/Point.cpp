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
Point Point::operator+(const Point &p2) {
  Point P;
  P.x = this->x + p2.x;
  P.y = this->y + p2.y;
  return P;
}
void Point::operator=(const Point &p2) {
  x = p2.x;
  y = p2.y;
}

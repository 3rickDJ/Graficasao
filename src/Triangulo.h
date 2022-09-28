#pragma once
#include "Figuras.h"

class Triangulo : public Figuras {
public:
  Triangulo();
  Triangulo(Point p1, Point p2, Point p3);
  Point Puntos[3];
  void getPlotPoints();
  void draw();
  void update();

};

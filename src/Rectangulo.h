#pragma once
#include "Figuras.h"

class Rectangulo : public Figuras {
  public:
    Rectangulo();
    Rectangulo(Point p1, Point p2, Point p3, Point p4);
    Point Puntos[4];
    void draw();
    void update();
};

#pragma once
#include "Triangulo.h"
class Montagna : public Triangulo {
  public:
    Montagna();
    Montagna(Point p1, Point p2, Point p3, Point position);
    Point Puntos[3];
    Point inicialTraslacion;
    void draw() override;
    void update() override;
};

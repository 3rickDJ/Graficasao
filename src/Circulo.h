#pragma once
#include "Figuras.h"
#include "Point.h"
class Circulo : public Figuras {
  public:
    float radio;
    Circulo();
    Circulo(float radio, Point pos, Point displacement, Point escala);
    void getPlotPoints();
    void draw();
    void update();
};

#pragma once
#include "Circulo.h"
#include "Point.h"

class Sol {
  public:
    Sol();
    Sol(Point pos, float Deltagrado, Point escalado, float radio);
    Circulo sol;
    /* Point pos; */
    /* float angulo; */
    void draw();
    void update();
};

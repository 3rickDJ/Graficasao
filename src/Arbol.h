#pragma once
#include "Triangulo.h"
#include "Rectangulo.h"

class Arbol {
    public:
    Arbol();
    Arbol(Point pos, Point DeltaTraslacion);
    Triangulo triangulos[2];
    Rectangulo tronco;
    Point posOriginal;
    Point escalado;
    Point traslacion;
    Point DeltaEscalado;
    Point DeltaTraslacion;
    void draw();
    void update();
};

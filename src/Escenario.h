#pragma once
#include "Arbol.h"
#include "Circulo.h"
#include "Line.h"
#include "Montagna.h"
#include "Sol.h"
#include "Triangulo.h"

class Escenario {
  public:
    Montagna montagnas[6];
    Arbol arboles[10];
    Line carretera[2];
    Circulo circulo;
    Sol sol;
    Escenario();
    void draw();
};

#pragma once
#include "Point.h"
class Figuras {
public:
    //Constructor vacio
    Figuras();
  // matriz de transformacion
  float A[3][3];
  // variables de control
  Point Traslacion;
  Point Escalamiento;
  float Angulo;
  // deltas de las variables de control
  Point DeltaTraslacion;
  Point DeltaEscalamiento;
  float DeltaAngulo;
  // metodos de transformacion
  void mover(Point deltaT);
  void escalar(Point deltaE);
  void mover(float deltaAngulo);
  virtual void draw() = 0;
  virtual void update() = 0;
};

#include "Triangulo.h"
#include "Line.h"
#include "Matrix.h"
Triangulo::Triangulo() {
  Traslacion = {0, 0};
  Escalamiento = {1, 1};
  Angulo = 0;
  DeltaTraslacion = {0, 0};
  DeltaEscalamiento = {0, 0};
  DeltaAngulo = 0;
}
Triangulo::Triangulo(Point p1, Point p2, Point p3) {
  Puntos[0] = p1;
  Puntos[1] = p2;
  Puntos[2] = p3;

  Traslacion = {0, 0};
  Escalamiento = {1, 1};
  Angulo = 0;
  DeltaTraslacion = {0, 0};
  DeltaEscalamiento = {0, 0};
  DeltaAngulo = 0;
}
void Triangulo::draw() {
  Matrix::LoadID(A);
  rotar(DeltaAngulo);
  escalar(DeltaEscalamiento);
  mover(DeltaTraslacion);
  Point p0, p1, p2;
  //plotear
  p0 = Matrix::getPoint(A, Puntos[0]);
  p1 = Matrix::getPoint(A, Puntos[1]);
  p2 = Matrix::getPoint(A, Puntos[2]);
  Line::Draw(p0, p1);
  Line::Draw(p1, p2);
  Line::Draw(p0, p2);
  update();
}
void Triangulo::update() {
  if (DeltaAngulo>=0 && Angulo > 360) {
    DeltaAngulo = -4;
  } else if(DeltaAngulo <=0 && Angulo <=0){
    DeltaAngulo = 4;
  }
}

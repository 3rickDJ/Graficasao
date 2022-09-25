#include "Figuras.h"
#include "Matrix.h"
Figuras::Figuras() {
  Traslacion = {0, 0};
  Escalamiento = {1, 1};
  Angulo = 0;
  DeltaTraslacion = {0, 0};
  DeltaEscalamiento = {0, 0};
  DeltaAngulo = 0;
}
void Figuras::mover(Point deltaT) {
  Traslacion = Traslacion + deltaT;
  Matrix::Mover(Traslacion, A);
}
void Figuras::escalar(Point deltaE) {
  Escalamiento = Escalamiento + deltaE;
  Matrix::Escalar(Escalamiento, A);
}
void Figuras::rotar(float deltaAngulo) {
  Angulo = Angulo + deltaAngulo;
  Matrix::Rotar(Angulo, A);
}

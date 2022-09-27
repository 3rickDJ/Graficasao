#include "Rectangulo.h"
#include "Line.h"
#include "Matrix.h"
Rectangulo::Rectangulo() {
    Traslacion = {0, 0};
    Escalamiento = {1, 1};
    Angulo = 0;
    DeltaTraslacion = {0, 0};
    DeltaEscalamiento = {0, 0};
    DeltaAngulo = 0;
}
Rectangulo::Rectangulo(Point p1, Point p2, Point p3, Point p4) {
    Puntos[0] = p1;
    Puntos[1] = p2;
    Puntos[2] = p3;
    Puntos[3] = p4;

    Traslacion = {0, 0};
    Escalamiento = {1, 1};
    Angulo = 0;
    DeltaTraslacion = {0, 0};
    DeltaEscalamiento = {0, 0};
    DeltaAngulo = 0;
}
void Rectangulo::draw() {
    Matrix::LoadID(A);
    rotar(DeltaAngulo);
    escalar(DeltaEscalamiento);
    mover(DeltaTraslacion);
    Point p0, p1, p2, p3;
    // plotear
    p0 = Matrix::getPoint(A, Puntos[0]);
    p1 = Matrix::getPoint(A, Puntos[1]);
    p2 = Matrix::getPoint(A, Puntos[2]);
    p3 = Matrix::getPoint(A, Puntos[3]);
    Line::Draw(p0, p1);
    Line::Draw(p1, p2);
    Line::Draw(p2, p3);
    Line::Draw(p3, p0);
    update();
}
void Rectangulo::update() {}

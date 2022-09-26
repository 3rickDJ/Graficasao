#include "Montagna.h"
#include "Line.h"
#include "Matrix.h"

Montagna::Montagna() {
    Traslacion = {0, 0};
    Escalamiento = {1, 1};
    Angulo = 0;
    DeltaTraslacion = {0, 0};
    DeltaEscalamiento = {0, 0};
    DeltaAngulo = 0;
}
Montagna::Montagna(Point p1, Point p2, Point p3, Point position) {
    Puntos[0] = p1;
    Puntos[1] = p2;
    Puntos[2] = p3;

    Traslacion = position;
    inicialTraslacion = position;
    Escalamiento = {1, 1};
    Angulo = 0;
    DeltaTraslacion = {0, 0};
    DeltaEscalamiento = {0, 0};
    DeltaAngulo = 0;
}
void Montagna::draw() {
    Matrix::LoadID(A);
    escalar(DeltaEscalamiento);
    mover(DeltaTraslacion);
    Point p0, p1, p2;
    // plotear
    p0 = Matrix::getPoint(A, Puntos[0]);
    p1 = Matrix::getPoint(A, Puntos[1]);
    p2 = Matrix::getPoint(A, Puntos[2]);
    // Dibujar triangulo
    Line::Draw(p0, p1);
    Line::Draw(p1, p2);
    Line::Draw(p0, p2);
    update();
}
void Montagna::update() {
    if (Traslacion.x >=inicialTraslacion.x +10) {
        DeltaTraslacion.x -= 1;
    }
    if (Traslacion.x <=inicialTraslacion.x +10) {
        DeltaTraslacion.x += 1;
    }
    if (Escalamiento.x <= 1) {
        DeltaEscalamiento.y += 0.013;
        DeltaEscalamiento.x += 0.019;
    }
    if (Escalamiento.x >= 1.4) {
        DeltaEscalamiento.y -= 0.013;
        DeltaEscalamiento.x -= 0.019;
    }
}

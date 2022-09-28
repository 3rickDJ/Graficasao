#include "Arbol.h"
#include "Line.h"
#include "Matrix.h"
Arbol::Arbol(Point pos, Point DeltaTraslacion) {
    this->DeltaTraslacion = DeltaTraslacion;
    this->posOriginal = pos;
    triangulos[0].Puntos[0] = {-17, 0};
    triangulos[0].Puntos[1] = {0, 18};
    triangulos[0].Puntos[2] = {17, 0};
    triangulos[0].Traslacion = pos;

    triangulos[1].Puntos[0] = {-10, 12};
    triangulos[1].Puntos[1] = {0, 16 + 20};
    triangulos[1].Puntos[2] = {10, 12};
    triangulos[1].Traslacion = pos;

    tronco.Puntos[0] = {-4, 0};
    tronco.Puntos[1] = {-4, 18};
    tronco.Puntos[2] = {4, 18};
    tronco.Puntos[3] = {4, 0};
    Point pTronco = {pos.x, pos.y - 18};
    tronco.Traslacion = pTronco;
    DeltaEscalado = {0.011, 0.011};
}

void Arbol::draw() {
    // Dibujar 2 triangulos
    // cargar identidad
    Matrix::LoadID(triangulos[0].A);
    triangulos[0].escalar(DeltaEscalado);
    triangulos[0].mover(DeltaTraslacion);
    triangulos[0].getPlotPoints();

    Matrix::LoadID(triangulos[1].A);
    triangulos[1].escalar(DeltaEscalado);
    triangulos[1].mover(DeltaTraslacion);
    triangulos[1].getPlotPoints();

    Matrix::LoadID(tronco.A);
    tronco.escalar(DeltaEscalado);
    tronco.mover(DeltaTraslacion);
    tronco.getPlotPoints();
    update();
}
void Arbol::update() {
    if (triangulos[1].Traslacion.y <= -250) {
        Point escalaOriginal = {0.9, 0.9};
        triangulos[0].Traslacion = posOriginal;
        triangulos[0].Escalamiento = escalaOriginal;
        triangulos[1].Traslacion = posOriginal;
        triangulos[1].Escalamiento = escalaOriginal;
        Point pTronco = {posOriginal.x, posOriginal.y - 18};
        tronco.Traslacion = pTronco;
        tronco.Escalamiento = escalaOriginal;
    }
}

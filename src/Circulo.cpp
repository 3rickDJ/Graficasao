#include "Circulo.h"
#include "Line.h"
#include "Matrix.h"
#include "Point.h"
#include "math.h"
Circulo::Circulo(float radio, Point pos, Point Displacement, Point escala) {
    this->radio = radio;
    this->Traslacion = pos;
    Escalamiento = {1, 1};
    Angulo = 0;
    DeltaTraslacion = Displacement;
    DeltaEscalamiento = escala;
    DeltaAngulo = 0;
}
void Circulo::getPlotPoints() {
    float radianes;
    Point p1, p2, p1Aux, p2Aux;
    p1 = {radio, 0};
    for (int i = 0; i < 360; i += 2) {
        radianes = i * 0.01745329252;
        p2.x = radio * cos(radianes);
        p2.y = radio * sin(radianes);
        p1Aux = Matrix::getPoint(A, p2);
        p2Aux = Matrix::getPoint(A, p1);
        Line::Draw(p1Aux,p2Aux);
        p1 = p2;
    }
}
void Circulo::draw() {
    Matrix::LoadID(A);
    rotar(DeltaAngulo);
    escalar(DeltaEscalamiento);
    mover(DeltaTraslacion);
    // plotear
    getPlotPoints();
    update();
}
void Circulo::update() {
    if(Traslacion.y>=200){
        DeltaTraslacion.y = -3;
        DeltaEscalamiento = {0.004,0.004};
    }
    if(Traslacion.y<=-193){
        DeltaTraslacion.y = 5;
        DeltaEscalamiento = {-0.004,-0.004};
    }
    if(Traslacion.x>=30){
        DeltaTraslacion.x = -3;
    }
    if(Traslacion.x<=-20){
        DeltaTraslacion.x = 4;
    }
}

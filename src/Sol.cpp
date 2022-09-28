#include "Sol.h"
#include "Matrix.h"
#include "Point.h"
Sol::Sol(Point pos, float DeltaGrados, Point escalado, float radio) {
    sol.radio = radio;
    sol.Traslacion = pos;
    sol.Angulo = 360;
    sol.DeltaAngulo = DeltaGrados;
    sol.Escalamiento = escalado;
    sol.DeltaEscalamiento = {1, 1};
}
void Sol::draw() {

    Matrix::LoadID(sol.A);
    sol.mover({0,0});
    sol.rotar(sol.DeltaAngulo);
    sol.getPlotPoints();
    update();
}

void Sol::update() {
    if(sol.Angulo>=360){
        sol.DeltaAngulo = -0.3;
    }

    if(sol.Angulo<=310){
        sol.DeltaAngulo = 0.3;
    }
}

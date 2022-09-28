#include "Escenario.h"
#include "Line.h"
#include "Triangulo.h"
#include "Montagna.h"
#include "Arbol.h"
#include "Circulo.h"
#include "Sol.h"
Escenario::Escenario() {
    montagnas[0]=Montagna({-50, -25}, {0, 41}, {48, -25}, {-222,200});
    montagnas[1]=Montagna({-48, -25}, {0, 53}, {53, -25}, {-180,200});
    montagnas[2]=Montagna({-60, -25}, {0, 54}, {52, -25}, {187,200});
    montagnas[3]=Montagna({-53, -25}, {0, 52}, {53, -25}, {210,200});
    arboles[0]= Arbol({200,250}, {0.64,-7});
    arboles[1]= Arbol({-200,250}, {-0.64,-7});
    arboles[2]= Arbol({-169,265}, {-0.64,-7});
    arboles[3]= Arbol({142,268}, {0.64,-7});
    arboles[4]= Arbol({141,350}, {0.64,-7});
    carretera[0]=Line({-112,-255}, {-58, 255});
    carretera[1]=Line({112,-255}, {58, 255});
    circulo = Circulo(23, {0,-194}, {1,-1}, {1,1});
    sol = Sol({-110,220},2,{1,1},20);
}

void Escenario::draw(){
    for (int i = 0; i <4; i++){
        montagnas[i].draw();
    }
    for (int i = 0; i <5; i++){
        arboles[i].draw();
    }
    for (int i = 0; i <2; i++){
        carretera[i].draw();
    }
    circulo.draw();
    sol.draw();
}

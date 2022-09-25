#include "Matrix.h"
#include <math.h>
// cargar identidad a la matriz A
void Matrix::LoadID(float A[3][3]){
    for (int i = 0; i <3; i++){
        for (int j = 0; j <3; j++){
            if(j==i){
                A[i][j]=1;
            }else{
                A[i][j]=0;
            }
        }
    }
}
// carga de unos al vector A
void Matrix::LoadOnes(float A[3]){
    for (int i = 0; i <3; i++){
                A[i]=1;
    }

}
// llena de zeros la matriz A
void Matrix::LoadZero(float A[3][3]){
    for (int i = 0; i <3; i++){
        for (int j = 0; j <3; j++){
                A[i][j]=0;
        }
    }
}
//llena de zeros el vector A
void Matrix::LoadZero(float A[3]){
    for (int i = 0; i <3; i++){
                A[i]=0;
    }
}
// multiplicacion de matrices (transformaciones)
// B<-A*B
void Matrix::Mult(float A[3][3], float B[3][3]){
    float temp[3][3];
    LoadZero(temp);
    for (int i = 0; i <3; i++){
        for (int j = 0; j <3; j++){
            for (int k = 0; k <3; k++){
                temp[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    CopyMatrix(temp,B);
}
// multiplicacion de matriz de transformacion por un punto
// P' <- A*P
// retorna Punto modificado por la matriz de transformacion
Point Matrix::Mult(float A[3][3], const Point &P){
    Point pT;
    float temp[3],  vectorP[3];
    LoadZero(temp);
    LoadOnes(vectorP);
    vectorP[0]= P.x;
    vectorP[1]=P.y;
    for (int i = 0; i <3; i++){
        for (int j = 0; j <3; j++){
            temp[i] += A[i][j]*vectorP[j];
        }
    }
    pT.x = temp[0];
    pT.y = temp[1];
    return pT;
}
// Copia los valores de A a B
void Matrix::CopyMatrix(float A[3][3], float B[3][3]){
    for (int i = 0; i <3; i++){
        for (int j = 0; j <3; j++){
            B[i][j] = A[i][j];
        }
    }
}

void Matrix::Mover(Point VectorTraslacion, float A[3][3]){
    float temp[3][3];
    LoadID(temp);
    temp[0][2] = VectorTraslacion.x;
    temp[1][2] = VectorTraslacion.y;
    Mult(temp,A);
}
void Matrix::Escalar(Point VectorEscalamiento, float A[3][3]){
    float temp[3][3];
    LoadID(temp);
    temp[0][0] = VectorEscalamiento.x;
    temp[1][1] = VectorEscalamiento.y;
    Mult(temp,A);
}
void Matrix::Rotar(float Angulo, float A[3][3]){
    float temp[3][3];
    LoadID(temp);
    float radians = Angulo*PI/180;
    float cosine = cos(radians);
    float sine = sin(radians);
    temp[0][0] = cosine;
    temp[0][1] = -sine;
    temp[1][0] = sine;
    temp[1][1] = cosine;
    Mult(temp,A);
}

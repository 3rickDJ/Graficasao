#pragma once
#include "Point.h"
#define PI 3.1415926535
class Matrix {
  // carga de unos al vector A
  static void LoadOnes(float A[3]);
  // llena de zeros la matriz A
  static void LoadZero(float A[3][3]);
  // llena de zeros el vector A
  static void LoadZero(float A[3]);
  // multiplicacion de matrices (transformaciones)
  // B<-A*B
  static void Mult(float A[3][3], float B[3][3]);
  // Copia los valores de A a B
  static void CopyMatrix(float A[3][3], float B[3][3]);

public:
  // cargar identidad a la matriz A
  static void LoadID(float A[3][3]);
  // multiplicacion de matriz de transformacion por un punto
  // P' <- A*P
  // retorna Punto modificado por la matriz de transformacion
  static Point getPoint(float A[3][3], const Point &P);
  // Con el vector de traslacion. Crear una matriz T
  // A<-T*A
  static void Mover(Point VectorTraslacion, float A[3][3]);
  // Con el vector de escalamiento. Crear una matriz E
  // A<-E*A
  static void Escalar(Point VectorEscalamiento, float A[3][3]);
  // Con el Angulo de rotacion. Crear una matriz R
  // A<-T*A
  static void Rotar(float Angulo, float A[3][3]);
};

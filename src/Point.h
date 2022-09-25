#pragma once
class Point {
public:
  //coordenadas del punto
  int x;
  int y;
  // constructores del punto
  Point();
  Point(int x,int y);
  // graficar punto (x,y)
  void draw();
  void static Draw(int x, int y);
};

#pragma once
class Point {
public:
  // coordenadas del punto
  float x;
  float y;
  // constructores del punto
  Point();
  Point(float  x, float y);
  // graficar punto (x,y)
  void draw();
  void static Draw(int x, int y);

  Point operator+(const Point &p2);
  void operator=(const Point &p2);
};

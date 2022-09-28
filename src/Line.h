#pragma once
#include "Point.h"
class Line {
    Point pe1;
    Point pe2;
    public:
    Line();
    Line(Point p1, Point p2);
    void draw();
    static void Draw(Point p1, Point p2);
};

#include "Line.h"
#include "Point.h"
// dibuja linea desde p1 hasta p2
void Line::Draw(Point p1, Point p2) {
  int x1 = p1.x;
  int y1 = p1.y;
  int x2 = p2.x;
  int y2 = p2.y;
  int dx, dy, i, e;
  int incx, incy, inc1, inc2;
  int x, y;
  // Diferencial en X (Distancia)
  dx = x2 - x1;
  // Diferencial en Y (Distancia)
  dy = y2 - y1;
  // Si la diferencial de x2 - x1 es menor que 0, la diferencial tomara su valor
  // en positivo
  if (dx < 0)
    dx = -dx;
  // Si la diferencial de y2 - y1 es menor que 0, la diferencial tomara su valor
  // en positivo
  if (dy < 0)
    dy = -dy;
  incx = 1; // el incremento en x se supone que sera de 1
  // Si el punto 2 en su coordenada x esta a la izquierda del punto 1 en su
  // coordenada x sera decremento en -1
  if (x2 < x1)
    incx = -1;
  incy = 1; // el incremento en y se supone que sera de 1
  // Si el punto 2 en su coordenada y esta a la izquierda del punto 1 en su
  // coordenada y sera decremento en -1
  if (y2 < y1)
    incy = -1;

  // Se comenzara a graficar desde el punto 1 (x1,y1)
  x = x1;
  y = y1;

  // Si la distancia entre entre los puntos X's es mayor a la distancia entre
  // los puntos Y's
  if (dx > dy) // Caso 1
  {
    Point::Draw(x, y);
    // Se pinta un pixel (vertice en la coordenadas de (x1,y1))
    /*El primer punto medio a ser considerado sera (Xinicial+1, Yinicial
     * +(1/2))*/
    /*Despejando de la formula F(Xinicial + 1, Yinicial +(1/2)) se tiene dy -
    (dx/2) pero para eliminar valores flotantes se multiplica todo por 2*/
    e = 2 * dy - dx;
    /*Se obtienen las posibles soluciones
    Enew = Eold + Incremento, donde el Incrento sera
    2*dy si Eold <0
    2*(dy-dx) Si Eold >0*/
    inc1 = 2 * (dy - dx);
    inc2 = 2 * dy;
    // Lo valores solo se necesitan calcular una vez, ya que el incremento sera
    // el mismo.
    for (i = 0; i < dx; i++) {
      // Se opta por dibujar el pixel en el punto medio superior si la recta
      // queda exactamente en el punto medio
      if (e >= 0) {
        y += incy;
        e += inc1;
      } else
        e += inc2;
      /*La siguiente coordenada X a ser dibujada sera definida ya sea 1 o -1
      dependiendo la posicion de punto 2 en el eje X */
      x += incx;
      Point::Draw(x, y);
    }
  } else // Si la distancia entre entre los puntos X's es menor a la distancia
         // entre los puntos Y's
  {
    Point::Draw(x, y);
    // Se pinta un pixel (vertice en la coordenadas de (x1,y1))
    e = 2 * dx - dy;
    inc1 = 2 * (dx - dy);
    inc2 = 2 * dx;
    for (i = 0; i < dy; i++) {
      if (e >= 0) {
        x += incx;
        e += inc1;
      } else
        e += inc2;
      /*La siguiente coordenada Y a ser dibujada sera definida ya sea 1 o -1
       dependiendo la posicion de punto 2 en el eje Y */
      y += incy;
      Point::Draw(x, y);
    }
  }
}

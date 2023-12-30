
#include "Point.hpp"

/*
    w1 = (Ax(Cy - Ay) + (Py - Ay)(Cx - Ax) - Px(Cy - Ay)) / ((By - Ay)(Cx - Ax) - (Bx - Ax)(Cy - Ay))

    w2 = (Py - Ay - w1(By - Ay)) / (Cy - Ay)

    Point P is inside triangle ABC if:
    w1 > 0 and w2 > 0 and (w1 + w2) < 1

    The formula is taken from this video:
        https://www.youtube.com/watch?v=HYAgJN3x4GA
*/
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed Ax = a.getX();
    Fixed Ay = a.getY();
    Fixed Bx = b.getX();
    Fixed By = b.getY();
    Fixed Cx = c.getX();
    Fixed Cy = c.getY();
    Fixed Px = point.getX();
    Fixed Py = point.getY();
    
    Fixed w1_numerator = Ax * (Cy - Ay) + (Py - Ay) * (Cx - Ax) - Px * (Cy - Ay);
    Fixed w1_denominator = (By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay);
    Fixed w1 = w1_numerator / w1_denominator;

    Fixed w2_numerator = Py - Ay - w1 * (By - Ay);
    Fixed w2_denominator = Cy - Ay;
    Fixed w2 = w2_numerator / w2_denominator;

    Fixed zero(0.0f);
    Fixed one(1.0f);

    if (w1 > zero && w2 > zero && (w1 + w2) < one)
        return (true);
    return (false);
}

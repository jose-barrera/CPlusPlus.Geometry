#ifndef POINT_H
#define POINT_H

/*
 *    -------------------------------------------------
 *    |                    Point                      |
 *    |-----------------------------------------------|
 *    | x: numeric                                    |
 *    | y: numeric                                    |
 *    |-----------------------------------------------|
 *    | <<constructor> Point()                        |
 *    | <<constructor> Point(x: numeric, y: numeric)  |
 *    | translate(dx: numeric, dy: numeric)           |
 *    | distanceto(other: Point): numeric             |
 *    -------------------------------------------------
 *
 */

class Point
{
    public:
        Point();
        Point(double x, double y);
        double getX();
        double getY();
        void translate(double dx, double dy);
        double distanceTo(Point other);

    /*
     * REMEMBER: Internal fields are variables that ALWAYS must be
     *           private (encapsulation) and they are used to store
     *           object data.
     */

    private:
        double x;
        double y;
};

#endif // POINT_H

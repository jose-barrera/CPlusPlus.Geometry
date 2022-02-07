#ifndef REGULARHEPTAGON_H
#define REGULARHEPTAGON_H

#include "Point.h"

/*
 *    ----------------------------------------------------------------
 *    |                        REgularHeptagon                       |
 *    |--------------------------------------------------------------|
 *    | center: Point                                                |
 *    | radius: numeric                                              |
 *    | apothem: numeric                                             |
 *    | side: numeric                                                |
 *    | vertices: Point (collection)                                 |
 *    | area: numeric                                                |
 *    | perimeter: numeric                                           |
 *    |--------------------------------------------------------------|
 *    | <<constructor> RegularHeptagon(center: Point, vertex: Point) |
 *    | translate(dx: numeric, dy: numeric)                          |
 *    | resize(radius: numeric)                                      |
 *    | rotate(angle: numeric)                                       |
 *    ----------------------------------------------------------------
 *
 */

class RegularHeptagon
{
    public:
        RegularHeptagon(Point center, Point vertex);
        Point getCenter();
        double getRadius();
        double getApothem();
        double getSide();
        Point getVertex(int i);
        double getArea();
        double getPerimeter();
        void translate(double dx, double dy);
        void resize(double radius);
        void rotate(double angle);

    /*
     * REMEMBER: Internal fields are variables that ALWAYS must be
     *           private (encapsulation) and they are used to store
     *           object data.
     */

    private:
        Point center;
        double radius;
        double apothem;
        double side;
        Point vertices[7];
        double area;
        double perimeter;
};

#endif // REGULARHEPTAGON_H

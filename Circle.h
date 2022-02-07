#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"

/*
 *    ----------------------------------------------------------
 *    |                          Circle                        |
 *    |--------------------------------------------------------|
 *    | center: Point                                          |
 *    | radius: numeric                                        |
 *    | diameter: numeric                                      |
 *    | area: numeric                                          |
 *    | perimeter: numeric                                     |
 *    |--------------------------------------------------------|
 *    | <<constructor> Circle(center: Point, radius: numeric)  |
 *    | translate(dx: numeric, dy: numeric)                    |
 *    | translate(center: Point)                               |
 *    | resize(radius: numeric)                                |
 *    ----------------------------------------------------------
 *
 */

class Circle
{
    public:
        Circle(Point center, double radius);
        Point getCenter();
        double getRadius();
        double getDiameter();
        double getArea();
        double getPerimeter();
        void translate(double dx, double dy);
        void translate(Point center);
        void resize(double radius);

    /*
     * REMEMBER: Internal fields are variables that ALWAYS must be
     *           private (encapsulation) and they are used to store
     *           object data.
     */

    private:
        Point center;
        double radius;
        double diameter;
        double area;
        double perimeter;
};

#endif // CIRCLE_H

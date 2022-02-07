#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <string>
#include "Point.h"

using namespace std;

/*
 *    ----------------------------------------------------------------
 *    |                        Ellipse                               |
 *    |--------------------------------------------------------------|
 *    | center: Point                                                |
 *    | semi-major axis: numeric                                     |
 *    | semi-minor axis: numeric                                     |
 *    | orientation: text                                            |
 *    | eccentricity: numeric                                        |
 *    | focus1: Point                                                |
 *    | focus2: Point                                                |
 *    | vertex1: Point                                               |
 *    | vertex2: Point                                               |
 *    | covertex1: Point                                             |
 *    | covertex2: Point                                             |
 *    | area: numeric                                                |
 *    | perimeter: numeric                                           |
 *    |--------------------------------------------------------------|
 *    | <<constructor> Ellipse(center: Point,                        |
 *    |                        semi-major axis: numeric,             |
 *    |                        semi-minor axis: numeric,             |
 *    |                        orientation: text)                    |
 *    | translate(dx: numeric, dy: numeric)                          |
 *    | resize(factor: numeric)                                      |
 *    ----------------------------------------------------------------
 *
 */

class Ellipse
{
    public:
        Ellipse(Point center, double semiMajorAxis, double semiMinorAxis,
                string orientation);
        Point getCenter();
        double getSemiMajorAxis();
        double getSemiMinorAxis();
        string getOrientation();
        double getEccentricity();
        Point getFocus1();
        Point getFocus2();
        Point getVertex1();
        Point getVertex2();
        Point getCovertex1();
        Point getCovertex2();
        double getArea();
        double getPerimeter();
        void translate(double dx, double dy);
        void resize(double factor);

    /*
     * REMEMBER: Internal fields are variables that ALWAYS must be
     *           private (encapsulation) and they are used to store
     *           object data.
     */

    private:
        Point center;
        double semiMajorAxis;
        double semiMinorAxis;
        string orientation;
        double eccentricity;
        Point focus1;
        Point focus2;
        Point vertex1;
        Point vertex2;
        Point covertex1;
        Point covertex2;
        double area;
        double perimeter;
};

#endif // ELLIPSE_H

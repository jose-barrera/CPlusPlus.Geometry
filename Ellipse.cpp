#define _USE_MATH_DEFINES

#include "Ellipse.h"
#include <math.h>
#include <stdexcept>

using namespace std;

//{ PROPERTIES

/* REMEMBER: Properties are a protection mechanism to accomplish
 *           encapsulation. Any property may have 2 components:
 *           a) ACCESSOR, responsible to give access to the
 *              internal field (read).
 *           b) MUTATOR, responsible to allow modification of
 *              the internal field (write).
 *           Properties with both accessor and mutator are READ/WRITE.
 *           Properties with only accessor are READ-ONLY.
 *           Properties with only mutator are WRITE-ONLY.
 */

Point Ellipse::getCenter()
{
    return this->center;
}
double Ellipse::getSemiMajorAxis()
{
    return this->semiMajorAxis;
}
double Ellipse::getSemiMinorAxis()
{
    return this->semiMinorAxis;
}
string Ellipse::getOrientation()
{
    return this->orientation;
}
double Ellipse::getEccentricity()
{
    return this->eccentricity;
}
Point Ellipse::getFocus1()
{
    return this->focus1;
}
Point Ellipse::getFocus2()
{
    return this->focus2;
}
Point Ellipse::getVertex1()
{
    return this->vertex1;
}
Point Ellipse::getVertex2()
{
    return this->vertex2;
}
Point Ellipse::getCovertex1()
{
    return this->covertex1;
}
Point Ellipse::getCovertex2()
{
    return this->covertex2;
}
double Ellipse::getArea()
{
    return this->area;
}
double Ellipse::getPerimeter()
{
    return this->perimeter;
}

//}

//{ CONSTRUCTORS

/* REMEMBER: Constructors are special functions whose name is
 *           always the same of the class. Its responsibility
 *           is to establish an initial VALID state of the object.
 */

Ellipse::Ellipse(Point center, double semiMajorAxis, double semiMinorAxis,
                 string orientation)
{
    // Axes must be positive values, major axis must be greater
    // than minor axis, and valid orientations are "Horizontal"
    // and "Vertical". If any of these conditions is not met,
    // object cannot be created and an error will be generated.
    if (semiMajorAxis > 0 && semiMinorAxis > 0)
    {
        if (semiMajorAxis > semiMinorAxis)
        {
            // Stores the data.
            this->center = center;
            this->semiMajorAxis = semiMajorAxis;
            this->semiMinorAxis = semiMinorAxis;
            this->orientation = orientation;
            // Makes general calculations.
            double linearEccentricity = sqrt(pow(semiMajorAxis, 2) -
                                             pow(semiMinorAxis, 2));
            this->eccentricity = linearEccentricity / semiMajorAxis;
            this->area = M_PI * semiMajorAxis * semiMinorAxis;
            // Calculates the approximation of perimeter
            double h = pow(this->semiMajorAxis - this->semiMinorAxis, 2) /
                       pow(this->semiMajorAxis + this->semiMinorAxis, 2);
            double seriesApproximation = 1 + h / 4 + pow(h, 2) / 64 +
                pow(h, 3) / 256 + 25 * pow(h, 4) / 16384 +
                49 * pow(h, 5) / 655536 + 441 * pow(h, 6) / 1048576;
            this->perimeter = M_PI * (semiMajorAxis + semiMinorAxis) * seriesApproximation;
            // Calculates points according to orientation.
            if (orientation == "Horizontal")
            {
                Point focus1(center.getX() - linearEccentricity, center.getY());
                Point focus2(center.getX() + linearEccentricity, center.getY());
                Point vertex1(center.getX() - semiMajorAxis, center.getY());
                Point vertex2(center.getX() + semiMajorAxis, center.getY());
                Point covertex1(center.getX(), center.getY() - semiMinorAxis);
                Point covertex2(center.getX(), center.getY() + semiMinorAxis);
                this->focus1 = focus1;
                this->focus2 = focus2;
                this->vertex1 = vertex1;
                this->vertex2 = vertex2;
                this->covertex1 = covertex1;
                this->covertex2 = covertex2;
            }
            else if (orientation == "Vertical")
            {
                Point focus1(center.getX(), center.getY() - linearEccentricity);
                Point focus2(center.getX(), center.getY() + linearEccentricity);
                Point vertex1(center.getX(), center.getY() - semiMajorAxis);
                Point vertex2(center.getX(), center.getY() + semiMajorAxis);
                Point covertex1(center.getX() - semiMinorAxis, center.getY());
                Point covertex2(center.getX() + semiMinorAxis, center.getY());
                this->focus1 = focus1;
                this->focus2 = focus2;
                this->vertex1 = vertex1;
                this->vertex2 = vertex2;
                this->covertex1 = covertex1;
                this->covertex2 = covertex2;
            }
            else
            {
                throw runtime_error("ERR: Orientation is invalid.");
            }
        }
        else
        {
            throw runtime_error("ERR: Semi-major axis cannot be equal or smaller than semi-minor axis.");
        }
    }
    else
    {
        throw runtime_error("ERR: Semi-axes cannot be zero or negative.");
    }
}

//}

//{ METHODS

/* REMEMBER: Methods are functions inside the class that defines
 *           the behaviour of the objects.
 */

// Moves the ellipse offsetting its center a given horizontal
// and vertical distance. It is necessary to recalculate some of
// its properties.
void Ellipse::translate(double dx, double dy)
{
    // Updates the data.
    this->center.translate(dx, dy);
    double linearEccentricity = sqrt(pow(this->semiMajorAxis, 2) -
                                     pow(this->semiMinorAxis, 2));
    // Calculates points according to orientation.
    if (this->orientation == "Horizontal")
    {
        Point focus1(center.getX() - linearEccentricity, center.getY());
        Point focus2(center.getX() + linearEccentricity, center.getY());
        Point vertex1(center.getX() - semiMajorAxis, center.getY());
        Point vertex2(center.getX() + semiMajorAxis, center.getY());
        Point covertex1(center.getX(), center.getY() - semiMinorAxis);
        Point covertex2(center.getX(), center.getY() + semiMinorAxis);
        this->focus1 = focus1;
        this->focus2 = focus2;
        this->vertex1 = vertex1;
        this->vertex2 = vertex2;
        this->covertex1 = covertex1;
        this->covertex2 = covertex2;
    }
    else if (this->orientation == "Vertical")
    {
        Point focus1(center.getX(), center.getY() - linearEccentricity);
        Point focus2(center.getX(), center.getY() + linearEccentricity);
        Point vertex1(center.getX(), center.getY() - semiMajorAxis);
        Point vertex2(center.getX(), center.getY() + semiMajorAxis);
        Point covertex1(center.getX() - semiMinorAxis, center.getY());
        Point covertex2(center.getX() + semiMinorAxis, center.getY());
        this->focus1 = focus1;
        this->focus2 = focus2;
        this->vertex1 = vertex1;
        this->vertex2 = vertex2;
        this->covertex1 = covertex1;
        this->covertex2 = covertex2;
    }
}

// Resizes the ellipse multiplying their axes by a factor.
// If factor > 1 the ellipse grows, if factor < 1 the ellipse
// shrinks. It is necessary to recalculate some of its properties.
void Ellipse::resize(double factor)
{
    // Factor must be positive; otherwise, the ellipse cannot be
    // resized and an error will be generated.
    if (factor > 0)
    {
        // Updates the data.
        this->semiMajorAxis *= factor;
        this->semiMinorAxis *= factor;
        double linearEccentricity = sqrt(pow(this->semiMajorAxis, 2) -
                                         pow(this->semiMinorAxis, 2));
        this->eccentricity = linearEccentricity / this->semiMajorAxis;
        this->area = M_PI * this->semiMajorAxis * this->semiMinorAxis;
        // Calculates the approximation of perimeter
        double h = pow(this->semiMajorAxis - this->semiMinorAxis, 2) /
                   pow(this->semiMajorAxis + this->semiMinorAxis, 2);
        double seriesApproximation = 1 + h / 4 + pow(h, 2) / 64 +
            pow(h, 3) / 256 + 25 * pow(h, 4) / 16384 +
            49 * pow(h, 5) / 655536 + 441 * pow(h, 6) / 1048576;
        this->perimeter = M_PI * (this->semiMajorAxis + this->semiMinorAxis) * seriesApproximation;
        // Calculates points according to orientation.
        if (this->orientation == "Horizontal")
        {
            Point focus1(center.getX() - linearEccentricity, center.getY());
            Point focus2(center.getX() + linearEccentricity, center.getY());
            Point vertex1(center.getX() - semiMajorAxis, center.getY());
            Point vertex2(center.getX() + semiMajorAxis, center.getY());
            Point covertex1(center.getX(), center.getY() - semiMinorAxis);
            Point covertex2(center.getX(), center.getY() + semiMinorAxis);
            this->focus1 = focus1;
            this->focus2 = focus2;
            this->vertex1 = vertex1;
            this->vertex2 = vertex2;
            this->covertex1 = covertex1;
            this->covertex2 = covertex2;
        }
        else if (this->orientation == "Vertical")
        {
            Point focus1(center.getX(), center.getY() - linearEccentricity);
            Point focus2(center.getX(), center.getY() + linearEccentricity);
            Point vertex1(center.getX(), center.getY() - semiMajorAxis);
            Point vertex2(center.getX(), center.getY() + semiMajorAxis);
            Point covertex1(center.getX() - semiMinorAxis, center.getY());
            Point covertex2(center.getX() + semiMinorAxis, center.getY());
            this->focus1 = focus1;
            this->focus2 = focus2;
            this->vertex1 = vertex1;
            this->vertex2 = vertex2;
            this->covertex1 = covertex1;
            this->covertex2 = covertex2;
        }
    }
    else
    {
        throw runtime_error("ERR: Factor cannot be zero or negative.");
    }
}

//}

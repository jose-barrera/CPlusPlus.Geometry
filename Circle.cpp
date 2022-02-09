#define _USE_MATH_DEFINES

#include "Circle.h"
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

Point Circle::getCenter()
{
    return this->center;
}
double Circle::getRadius()
{
    return this->radius;
}
double Circle::getDiameter()
{
    return this->diameter;
}
double Circle::getArea()
{
    return this->area;
}
double Circle::getPerimeter()
{
    return this->perimeter;
}

//}

//{ CONSTRUCTORS

/* REMEMBER: Constructors are special functions whose name is
 *           always the same of the class. Its responsibility
 *           is to establish an initial VALID state of the object.
 */

Circle::Circle(Point center, double radius)
{
    // Radius must be a positive value, if not,
    // we cannot create the object and an error
    // is generated.
    if (radius > 0)
    {
        // Store the data received
        this->center = center;
        this->radius = radius;
        // Diameter, area, and perimeter
        // are calculated from radius
        this->diameter = radius * 2;
        this->area = M_PI * radius * radius;
        this->perimeter = M_PI * 2 * radius;
    }
    else
    {
        throw runtime_error("ERR: Radius cannot be zero or negative.");
    }
}

//}

//{ METHODS

/* REMEMBER: Methods are functions inside the class that defines
 *           the behaviour of the objects.
 */

// Moves the circle displacing its center by horizontal
// and vertical distance.
void Circle::translate(double dx, double dy)
{
    this->center.translate(dx, dy);
}
// Moves the circle changing its center directly.
void Circle::translate(Point center)
{
    this->center = center;
}
// Change size of circle establishing a new radius.
void Circle::resize(double radius)
{
    // Radius must be a positive value, if not,
    // we cannot create the object and an error
    // is generated.
    if (radius > 0)
    {
        // Store the data received
        this->radius = radius;
        // Diameter, area, and perimeter
        // are calculated from radius
        this->diameter = radius * 2;
        this->area = M_PI * radius * radius;
        this->perimeter = M_PI * 2 * radius;
    }
    else
    {
        throw runtime_error("ERR: Radius cannot be zero or negative.");
    }
}

//}

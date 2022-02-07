#include "Point.h"
#include <math.h>

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

double Point::getX()
{
    return this->x;
}
double Point::getY()
{
    return this->y;
}

//}

//{ CONSTRUCTORS

/* REMEMBER: Constructors are special functions whose name is
 *           always the same of the class. Its responsibility
 *           is to establish an initial VALID state of the object.
 */

// This is the default constructor; builds the
// origin point.
Point::Point()
{
    this->x = 0;
    this->y = 0;
}
Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

//}

//{ METHODS

/* REMEMBER: Methods are functions inside the class that defines
 *           the behaviour of the objects.
 */

// Moves the point displacing it by horizontal and vertical distance.
void Point::translate(double dx, double dy)
{
    this->x += dx;
    this->y += dy;
}
// Calculates the distance between this point
// and other point.
double Point::distanceTo(Point other)
{
    return sqrt(pow(other.x - this->x, 2) +
                pow(other.y - this->y, 2));
}

//}

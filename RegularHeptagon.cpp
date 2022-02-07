#define _USE_MATH_DEFINES

#include "RegularHeptagon.h"
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

Point RegularHeptagon::getCenter()
{
    return this->center;
}
double RegularHeptagon::getRadius()
{
    return this->radius;
}
double RegularHeptagon::getApothem()
{
    return this->apothem;
}
double RegularHeptagon::getSide()
{
    return this->side;
}
double RegularHeptagon::getArea()
{
    return this->area;
}
double RegularHeptagon::getPerimeter()
{
    return this->perimeter;
}
Point RegularHeptagon::getVertex(int i)
{
    return this->vertices[i];
}

//}

//{ CONSTRUCTORS

/* REMEMBER: Constructors are special functions whose name is
 *           always the same of the class. Its responsibility
 *           is to establish an initial VALID state of the object.
 */

// Builds a heptagon from its center and first vertex, calculating
// other vertices counterclockwise.
RegularHeptagon::RegularHeptagon(Point center, Point vertex)
{
    // Center and vertex cannot be the same point.
    if (!(center.getX() == vertex.getX() && center.getY() == vertex.getY()))
    {
        // Stores the center.
        this->center = center;
        // Calculates radius (distance from center to vertex).
        this->radius = center.distanceTo(vertex);
        // Calculates vertices.
        this->vertices[0] = vertex;
        double x, y;
        double angle = M_PI * 2 / 7;
        for (int i = 1; i < 7; i++)
        {
            x = cos(i * angle) * (vertex.getX() - center.getX()) -
                sin(i * angle) * (vertex.getY() - center.getY()) +
                center.getX();
            y = sin(i * angle) * (vertex.getX() - center.getX()) +
                cos(i * angle) * (vertex.getY() - center.getY()) +
                center.getY();
            Point vertex(x,y);
            this->vertices[i] = vertex;
        }
        // Calculates apothem (radius multiplied by the cosine of PI/7).
        this->apothem = this->radius * cos(M_PI / 7);
        // Calculates side (distance between 2 consecutive vertices).
        this->side = this->vertices[0].distanceTo(this->vertices[1]);
        // Calculates perimeter (side length multiplied by seven).
        this->perimeter = this->side * 7;
        // Calculates area (half the product of its perimeter and its apothem).
        this->area = this->perimeter * this->apothem / 2;
    }
    else
    {
        throw "ERR: Center and vertex cannot be the same point.";
    }
}

//}

//{ METHODS

/* REMEMBER: Methods are functions inside the class that defines
 *           the behaviour of the objects.
 */

// Moves the heptagon offsetting its center and vertices a given
// horizontal and vertical distance. All other properties remains
// the same.
void RegularHeptagon::translate(double dx, double dy) {
    this->center.translate(dx, dy);
    for (int i=0; i < 7; i++)
    {
        this->vertices[i].translate(dx, dy);
    }
}

// Resizes the heptagon based on its circumscribed radius. Some
// of its properties must be recalculated.
void RegularHeptagon::resize(double radius) {
    // The radius must be positive.
    if (radius > 0)
    {
        // Stores the radius.
        this->radius = radius;
        // Calculate the slope of the segment from center
        // to first vertex, and then the new vertex in that
        // direction from center.
        double slope, theta;
        double dx = this->vertices[0].getX() - this->center.getX();
        double dy = this->vertices[0].getY() - this->center.getY();
        if (dx != 0)
        {
            slope = dy / dx;
            theta = atan(slope);
        }
        else if (dy > 0)
            theta = M_PI / 2;
        else
            theta = 3 * M_PI / 2;
        double x = this->center.getX() + radius * cos(theta);
        double y = this->center.getY() + radius * sin(theta);
        // Calculates the new vertices.
        Point vertex(x, y);
        this->vertices[0] = vertex;
        double angle = M_PI * 2 / 7;
        for (int i = 1; i < 7; i++)
        {
            x = cos(i * angle) * (vertex.getX() - this->center.getX()) -
                sin(i * angle) * (vertex.getY() - this->center.getY()) +
                this->center.getX();
            y = sin(i * angle) * (vertex.getX() - this->center.getX()) +
                cos(i * angle) * (vertex.getY() - this->center.getY()) +
                this->center.getY();
            Point vertex(x, y);
            this->vertices[i] = vertex;
        }
        // Calculates apothem (radius multiplied by the cosine of PI/7).
        this->apothem = this->radius * cos(M_PI / 7);
        // Calculates side (distance between 2 consecutive vertices).
        this->side = this->vertices[0].distanceTo(this->vertices[1]);
        // Calculates perimeter (side length multiplied by seven).
        this->perimeter = this->side * 7;
        // Calculates area (half the product of its perimeter and its apothem).
        this->area = this->perimeter * this->apothem / 2;
    }
    else
    {
        throw "ERR: Radius cannot be zero or negative.";
    }
}

// Rotates the heptagon around its center (the parameters is in degrees).
void RegularHeptagon::rotate(double angle) {
    double x, y;
    double theta = angle * M_PI / 180;
    for(int i=0; i < 7; i++)
    {
        x = cos(theta) * (this->vertices[i].getX() - this->center.getX()) -
            sin(theta) * (this->vertices[i].getY() - this->center.getY()) +
            this->center.getX();
        y = sin(theta) * (this->vertices[i].getX() - this->center.getX()) +
            cos(theta) * (this->vertices[i].getY() - this->center.getY()) +
            this->center.getY();
        Point vertex(x, y);
        this->vertices[i] = vertex;
    }
}

// </editor-fold>

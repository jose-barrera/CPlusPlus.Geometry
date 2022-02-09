#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "Ellipse.h"
#include "RegularHeptagon.h"

using namespace std;

void testingClassPoint();
void testingClassCircle();
void testingClassEllipse();
void testingClassRegularHeptagon();

int main()
{
    testingClassPoint();
    testingClassCircle();
    testingClassEllipse();
    testingClassRegularHeptagon();

    cout << "ALL DONE!" << endl;
    return 0;
}

void testingClassPoint()
{
    cout << "***********************" << endl;
    cout << "***   CLASS Point   ***" << endl;
    cout << "***********************" << endl;
    cout << endl;
    cout << "1. Create the origin point" << endl;
    Point pointA;
    cout << "   (" << pointA.getX() << "," << pointA.getY() << ")" << endl;
    cout << endl;
    cout << "2. Create the point in -3.4 y 4.35" << endl;
    Point pointB(-3.4, 4.35);
    cout << "   (" << pointB.getX() << "," << pointB.getY() << ")" << endl;
    cout << endl;
    cout << "3. Calculate distance between them" << endl;
    cout << "   " << pointA.distanceTo(pointB) << endl;
    cout << endl;
    cout << "4. Move both points 1.4 right and 3.7 down" << endl;
    pointA.translate(1.4, -3.7);
    pointB.translate(1.4, -3.7);
    cout << "   (" << pointA.getX() << "," << pointA.getY() << ")" << endl;
    cout << "   (" << pointB.getX() << "," << pointB.getY() << ")" << endl;
    cout << endl;
    cout << "5. Calculate distance again" << endl;
    cout << "   " << pointA.distanceTo(pointB) << endl;
    cout << endl;
}

void testingClassCircle()
{
    cout << "************************" << endl;
    cout << "***   CLASS Circle   ***" << endl;
    cout << "************************" << endl;
    cout << endl;
    cout << "1. Create circle in (-3,-7.4) with 3.77 radius" << endl;
    Point center(-3, -7.4);
    Circle circle(center, 3.77);
    cout << endl;
    cout << "2. Print its information" << endl;
    cout << "   Center: (" << circle.getCenter().getX() << "," <<
                              circle.getCenter().getY() << ")" << endl;
    cout << "   Radius: " << circle.getRadius() << endl;
    cout << "   Diameter: " << circle.getDiameter() << endl;
    cout << "   Area: " << circle.getArea() << endl;
    cout << "   Perimeter: " << circle.getPerimeter() << endl;
    cout << endl;
    cout << "3. Move its center to (3,3) and after move its center 1.4 right and 3.7 down" << endl;
    Point center2(3,3);
    circle.translate(center2);
    circle.translate(1.4, -3.7);
    cout << endl;
    cout << "4. Print its information" << endl;
    cout << "   Center: (" << circle.getCenter().getX() << "," <<
                              circle.getCenter().getY() << ")" << endl;
    cout << "   Radius: " << circle.getRadius() << endl;
    cout << "   Diameter: " << circle.getDiameter() << endl;
    cout << "   Area: " << circle.getArea() << endl;
    cout << "   Perimeter: " << circle.getPerimeter() << endl;
    cout << endl;
    cout << "5. Resize its radius to 10" << endl;
    circle.resize(10);
    cout << endl;
    cout << "6. Print its information" << endl;
    cout << "   Center: (" << circle.getCenter().getX() << "," <<
                              circle.getCenter().getY() << ")" << endl;
    cout << "   Radius: " << circle.getRadius() << endl;
    cout << "   Diameter: " << circle.getDiameter() << endl;
    cout << "   Area: " << circle.getArea() << endl;
    cout << "   Perimeter: " << circle.getPerimeter() << endl;
    cout << endl;
    cout << endl;
}

void testingClassEllipse()
{
    cout << "*************************" << endl;
    cout << "***   CLASS Ellipse   ***" << endl;
    cout << "*************************" << endl;
    cout << endl;
    cout << "1. Create an horizontal ellipse with center in (7.5, -2.3)," << endl;
    cout << "   semi-major axis 3.5, and semi-minor axis 2" << endl;
    Point center(7.5, -2.3);
    Ellipse ellipse(center, 3.5, 2, "Horizontal");
    cout << endl;
    cout << "2. Print its information" << endl;
    cout << "   Center: (" << ellipse.getCenter().getX() << "," << ellipse.getCenter().getY() << ")" << endl;
    cout << "   Semi-major axis: " << ellipse.getSemiMajorAxis() << endl;
    cout << "   Semi-minor axis: " << ellipse.getSemiMinorAxis() << endl;
    cout << "   Orientation: " << ellipse.getOrientation() << endl;
    cout << "   Eccentricity: " << ellipse.getEccentricity() << endl;
    cout << "   Area: " << ellipse.getArea() << endl;
    cout << "   Perimeter: " << ellipse.getPerimeter() << endl;
    cout << "   Focus 1: (" << ellipse.getFocus1().getX() << "," << ellipse.getFocus1().getY() << ")" << endl;
    cout << "   Focus 2: (" << ellipse.getFocus2().getX() << "," << ellipse.getFocus2().getY() << ")" << endl;
    cout << "   Vertex 1: (" << ellipse.getVertex1().getX() << "," << ellipse.getVertex1().getY() << ")" << endl;
    cout << "   Vertex 2: (" << ellipse.getVertex2().getX() << "," << ellipse.getVertex2().getY() << ")" << endl;
    cout << "   Covertex 1: (" << ellipse.getCovertex1().getX() << "," << ellipse.getCovertex1().getY() << ")" << endl;
    cout << "   Covertex 2: (" << ellipse.getCovertex2().getX() << "," << ellipse.getCovertex2().getY() << ")" << endl;
    cout << endl;
    cout << "3. Move the ellipse 1.4 right and 3.7 down" << endl;
    ellipse.translate(1.4, -3.7);
    cout << endl;
    cout << "4. Print its information" << endl;
    cout << "   Center: (" << ellipse.getCenter().getX() << "," << ellipse.getCenter().getY() << ")" << endl;
    cout << "   Semi-major axis: " << ellipse.getSemiMajorAxis() << endl;
    cout << "   Semi-minor axis: " << ellipse.getSemiMinorAxis() << endl;
    cout << "   Orientation: " << ellipse.getOrientation() << endl;
    cout << "   Eccentricity: " << ellipse.getEccentricity() << endl;
    cout << "   Area: " << ellipse.getArea() << endl;
    cout << "   Perimeter: " << ellipse.getPerimeter() << endl;
    cout << "   Focus 1: (" << ellipse.getFocus1().getX() << "," << ellipse.getFocus1().getY() << ")" << endl;
    cout << "   Focus 2: (" << ellipse.getFocus2().getX() << "," << ellipse.getFocus2().getY() << ")" << endl;
    cout << "   Vertex 1: (" << ellipse.getVertex1().getX() << "," << ellipse.getVertex1().getY() << ")" << endl;
    cout << "   Vertex 2: (" << ellipse.getVertex2().getX() << "," << ellipse.getVertex2().getY() << ")" << endl;
    cout << "   Covertex 1: (" << ellipse.getCovertex1().getX() << "," << ellipse.getCovertex1().getY() << ")" << endl;
    cout << "   Covertex 2: (" << ellipse.getCovertex2().getX() << "," << ellipse.getCovertex2().getY() << ")" << endl;
    cout << endl;
    cout << "5. Resize the ellipse by 1.7 factor" << endl;
    ellipse.resize(1.7);
    cout << endl;
    cout << "6. Print its information" << endl;
    cout << "   Center: (" << ellipse.getCenter().getX() << "," << ellipse.getCenter().getY() << ")" << endl;
    cout << "   Semi-major axis: " << ellipse.getSemiMajorAxis() << endl;
    cout << "   Semi-minor axis: " << ellipse.getSemiMinorAxis() << endl;
    cout << "   Orientation: " << ellipse.getOrientation() << endl;
    cout << "   Eccentricity: " << ellipse.getEccentricity() << endl;
    cout << "   Area: " << ellipse.getArea() << endl;
    cout << "   Perimeter: " << ellipse.getPerimeter() << endl;
    cout << "   Focus 1: (" << ellipse.getFocus1().getX() << "," << ellipse.getFocus1().getY() << ")" << endl;
    cout << "   Focus 2: (" << ellipse.getFocus2().getX() << "," << ellipse.getFocus2().getY() << ")" << endl;
    cout << "   Vertex 1: (" << ellipse.getVertex1().getX() << "," << ellipse.getVertex1().getY() << ")" << endl;
    cout << "   Vertex 2: (" << ellipse.getVertex2().getX() << "," << ellipse.getVertex2().getY() << ")" << endl;
    cout << "   Covertex 1: (" << ellipse.getCovertex1().getX() << "," << ellipse.getCovertex1().getY() << ")" << endl;
    cout << "   Covertex 2: (" << ellipse.getCovertex2().getX() << "," << ellipse.getCovertex2().getY() << ")" << endl;
    cout << endl;
    cout << endl;
}

void testingClassRegularHeptagon()
{
    cout << "*********************************" << endl;
    cout << "***   CLASS RegularHeptagon   ***" << endl;
    cout << "*********************************" << endl;
    cout << endl;
    cout << "1. Create an heptagon with center in (1,1) and first vertex in (1,6)" << endl;
    Point center(1, 1);
    Point vertex(1, 6);
    RegularHeptagon heptagon(center, vertex);
    cout << endl;
    cout << "2. Print its information" << endl;
    cout << "   Center: (" << heptagon.getCenter().getX() << "," << heptagon.getCenter().getY() << ")" << endl;
    cout << "   Radius: " << heptagon.getRadius() << endl;
    cout << "   Apothem: " << heptagon.getApothem() << endl;
    cout << "   Side: " << heptagon.getSide() << endl;
    cout << "   Perimeter: " << heptagon.getPerimeter() << endl;
    cout << "   Area: " << heptagon.getArea() << endl;
    cout << "   Vertices:" << endl;
    for (int i = 0; i < 7; i++)
        cout << "      Vertex " << (i + 1) << ": (" <<
                                  heptagon.getVertex(i).getX() << "," <<
                                  heptagon.getVertex(i).getY() << ")" << endl;
    cout << endl;
    cout << "3. Move the heptagon 1.4 right and 3.7 down"<< endl;
    heptagon.translate(1.4, -3.7);
    cout << endl;
    cout << "4. Print its information"<< endl;
    cout << "   Center: (" << heptagon.getCenter().getX() << "," << heptagon.getCenter().getY() << ")" << endl;
    cout << "   Radius: " << heptagon.getRadius() << endl;
    cout << "   Apothem: " << heptagon.getApothem() << endl;
    cout << "   Side: " << heptagon.getSide() << endl;
    cout << "   Perimeter: " << heptagon.getPerimeter() << endl;
    cout << "   Area: " << heptagon.getArea() << endl;
    cout << "   Vertices:" << endl;
    for (int i = 0; i < 7; i++)
        cout << "      Vertex " << (i + 1) << ": (" <<
                                  heptagon.getVertex(i).getX() << "," <<
                                  heptagon.getVertex(i).getY() << ")" << endl;
    cout << endl;
    cout << "5. Resize the heptagon to have 7.7 radius"<< endl;
    heptagon.resize(7.7);
    cout << endl;
    cout << "6. Print its information"<< endl;
    cout << "   Center: (" << heptagon.getCenter().getX() << "," << heptagon.getCenter().getY() << ")" << endl;
    cout << "   Radius: " << heptagon.getRadius() << endl;
    cout << "   Apothem: " << heptagon.getApothem() << endl;
    cout << "   Side: " << heptagon.getSide() << endl;
    cout << "   Perimeter: " << heptagon.getPerimeter() << endl;
    cout << "   Area: " << heptagon.getArea() << endl;
    cout << "   Vertices:" << endl;
    for (int i = 0; i < 7; i++)
        cout << "      Vertex " << (i + 1) << ": (" <<
                                  heptagon.getVertex(i).getX() << "," <<
                                  heptagon.getVertex(i).getY() << ")" << endl;
    cout << endl;
    cout << "7. Rotate the heptagon 37 degrees counterclockwise"<< endl;
    heptagon.rotate(37);
    cout << endl;
    cout << "8. Print its information"<< endl;
    cout << "   Center: (" << heptagon.getCenter().getX() << "," << heptagon.getCenter().getY() << ")" << endl;
    cout << "   Radius: " << heptagon.getRadius() << endl;
    cout << "   Apothem: " << heptagon.getApothem() << endl;
    cout << "   Side: " << heptagon.getSide() << endl;
    cout << "   Perimeter: " << heptagon.getPerimeter() << endl;
    cout << "   Area: " << heptagon.getArea() << endl;
    cout << "   Vertices:" << endl;
    for (int i = 0; i < 7; i++)
        cout << "      Vertex " << (i + 1) << ": (" <<
                                  heptagon.getVertex(i).getX() << "," <<
                                  heptagon.getVertex(i).getY() << ")" << endl;
    cout << endl;
    cout << endl;
}

